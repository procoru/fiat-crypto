Require Import QhasmCommon QhasmUtil State.
Require Import ZArith Sumbool.
Require Import Bedrock.Word.
Require Import Logic.Eqdep_dec ProofIrrelevance.

Module EvalUtil.
  Definition evalTest {n} (o: TestOp) (a b: word n): bool :=
    let c := (N.compare (wordToN a) (wordToN b)) in

    let eqBit := match c with | Eq => true | _ => false end in
    let ltBit := match c with | Lt => true | _ => false end in
    let gtBit := match c with | Gt => true | _ => false end in

    match o with
    | TEq => eqBit
    | TLt => ltBit
    | TLe => orb (eqBit) (ltBit)
    | TGt => gtBit
    | TGe => orb (eqBit) (gtBit)
    end.

  Definition evalIntOp {b} (io: IntOp) (x y: word b): (word b) * option bool :=
    match io with
    | Add =>
      let v := (wordToN x + wordToN y)%N in
      let c := (overflows b (&x + &y)%N)%w in

      match c as c' return c' = c -> _ with
      | right _ => fun _ => (NToWord b v, Some false)
      | left _ => fun _ => (NToWord b v, Some true)
      end eq_refl

    | Sub => (wminus x y, None)
    | Xor => (wxor x y, None)
    | And => (wand x y, None)
    | Or => (wor x y, None)
    end.

  Definition evalCarryOp {b} (io: CarryOp) (x y: word b) (c: bool): (word b) * bool :=
    match io with
    | AddWidthCarry =>
      let c' := (overflows b (&x + &y + (if c then 1 else 0))%N)%w in
      let v := addWithCarry x y c in

      match c' as c'' return c' = c'' -> _ with
      | right _ => fun _ => (v, false)
      | left _ => fun _ => (v, true)
      end eq_refl
    end.

  Definition highBits {n} (m: nat) (x: word n) := snd (break m x).

  Definition multHigh {n} (x y: word n): word n.
    refine (@extend _ n _ ((highBits (n/2) x) ^* (highBits (n/2) y)));
      abstract omega.
  Defined.

  Definition evalDualOp {n} (duo: DualOp) (x y: word n) :=
    match duo with
    | Mult => (x ^* y, multHigh x y)
    end.

  Definition evalRotOp {b} (ro: RotOp) (x: word b) (n: nat) :=
    match ro with
    | Shl => NToWord b (N.shiftl_nat (wordToN x) n)
    | Shr => NToWord b (N.shiftr_nat (wordToN x) n)
    end.

  (* Width decideability *)

  Definition getWidth (n: nat): option (Width n) :=
    match n with
    | 32 => Some W32
    | 64 => Some W64
    | _ => None
    end.

  Lemma getWidth_eq {n} (a: Width n): Some a = getWidth n.
  Proof. induction a; unfold getWidth; simpl; intuition. Qed.

  Lemma width_eq {n} (a b: Width n): a = b.
  Proof. 
    assert (Some a = Some b) as H by (
      replace (Some a) with (getWidth n) by (rewrite getWidth_eq; intuition);
      replace (Some b) with (getWidth n) by (rewrite getWidth_eq; intuition);
      intuition).
    inversion H; intuition.
  Qed. 

  (* Mapping Conversions *)

  Definition wordToM {n: nat} {spec: Width n} (w: word n): Mapping n :=
    constM _ (constant spec w).

  Definition regToM {n: nat} {spec: Width n} (r: Reg n): Mapping n :=
    regM _ r.

  Definition stackToM {n: nat} {spec: Width n} (s: Stack n): Mapping n :=
    stackM _ s.

  Definition constToM {n: nat} {spec: Width n} (c: Const n): Mapping n :=
    constM _ c.

  Definition mapping_dec {n} (a b: Mapping n): {a = b} + {a <> b}.
    refine (match (a, b) as p' return (a, b) = p' -> _ with
    | (regM v, regM v') => fun _ => 
        if (Nat.eq_dec (regName v) (regName v'))
        then left _
        else right _

    | (stackM v, stackM v') => fun _ => 
        if (Nat.eq_dec (stackName v) (stackName v'))
        then left _
        else right _

    | (constM v, constM v') => fun _ => 
        if (Nat.eq_dec (constValueN v) (constValueN v'))
        then left _
        else right _

    | (memM _ v i, memM _ v' i') => fun _ => 
        if (Nat.eq_dec (memName v) (memName v')) 
        then if (Nat.eq_dec (memLength v) (memLength v'))
        then if (Nat.eq_dec (proj1_sig i) (proj1_sig i'))
        then left _ else right _ else right _ else right _

    | _ => fun _ => right _
    end (eq_refl (a, b))); abstract (
      inversion_clear _H;
      unfold regName, stackName, constValueN, memName, memLength in *;
      intuition; try inversion H;
      destruct v, v'; subst;
      try assert (w = w0) by (apply width_eq); do 3 first [
          contradict _H0; inversion H1
        | rewrite <- (natToWord_wordToNat w0);
          rewrite <- (natToWord_wordToNat w2);
          assert (w = w1) by (apply width_eq); subst;
          rewrite _H0
        | apply (inj_pair2_eq_dec _ Nat.eq_dec) in H3
        | inversion H; subst; intuition
        | destruct i, i'; simpl in _H2; subst;
          replace l with l0 by apply proof_irrelevance
        | intuition ]).
  Defined.

  Definition dec_lt (a b: nat): {(a < b)%nat} + {(a >= b)%nat}.
    assert ({(a <? b)%nat = true} + {(a <? b)%nat <> true})
      by abstract (destruct (a <? b)%nat; intuition);
      destruct H.

    - left; abstract (apply Nat.ltb_lt in e; intuition).

    - right; abstract (rewrite Nat.ltb_lt in n; intuition).
  Defined.

  Fixpoint stackNames {n} (lst: list (Mapping n)): list nat :=
    match lst with
    | nil => nil
    | cons c cs =>
      match c with
      | stackM v => cons (stackName v) (stackNames cs)
      | _ => stackNames cs
      end
    end.

  Fixpoint regNames {n} (lst: list (Mapping n)): list nat :=
    match lst with
    | nil => nil
    | cons c cs =>
      match c with
      | regM v => cons (regName v) (regNames cs)
      | _ => regNames cs
      end
    end.

End EvalUtil.

Module QhasmEval.
  Export EvalUtil FullState.

  Definition evalCond (c: Conditional) (state: State): option bool :=
    match c with
    | CTrue => Some true
    | CZero n r =>
      omap (getReg r state) (fun v =>
        if (Nat.eq_dec O (wordToNat v))
        then Some true
        else Some false) 
    | CReg n o a b =>
      omap (getReg a state) (fun va =>
        omap (getReg b state) (fun vb =>
          Some (evalTest o va vb)))
    | CConst n o a c => 
      omap (getReg a state) (fun va =>
        Some (evalTest o va (constValueW c)))
    end.

  Definition evalOperation (o: Operation) (state: State): option State :=
    match o with
    | IOpConst _ o r c =>
      omap (getReg r state) (fun v =>
        let (v', co) := (evalIntOp o v (constValueW c)) in
        Some (setCarryOpt co (setReg r v' state)))

    | IOpReg _ o a b =>
      omap (getReg a state) (fun va =>
        omap (getReg b state) (fun vb =>
            let (v', co) := (evalIntOp o va vb) in
            Some (setCarryOpt co (setReg a v' state))))

    | IOpStack _ o a b =>
      omap (getReg a state) (fun va =>
        omap (getStack b state) (fun vb =>
            let (v', co) := (evalIntOp o va vb) in
            Some (setCarryOpt co (setReg a v' state))))

    | IOpMem _ _ o r m i => 
      omap (getReg r state) (fun va =>
        omap (getMem m i state) (fun vb =>
            let (v', co) := (evalIntOp o va vb) in
            Some (setCarryOpt co (setReg r v' state))))

    | DOp _ o a b (Some x) => 
      omap (getReg a state) (fun va =>
        omap (getReg b state) (fun vb =>
            let (low, high) := (evalDualOp o va vb) in
            Some (setReg x high (setReg a low state))))

    | DOp _ o a b None => 
      omap (getReg a state) (fun va =>
        omap (getReg b state) (fun vb =>
            let (low, high) := (evalDualOp o va vb) in
            Some (setReg a low state)))

    | ROp _ o r i => 
      omap (getReg r state) (fun v =>
        let v' := (evalRotOp o v i) in
        Some (setReg r v' state))

    | COp _ o a b => 
      omap (getReg a state) (fun va =>
        omap (getReg b state) (fun vb =>
            match (getCarry state) with
            | None => None
            | Some c0 => 
            let (v', c') := (evalCarryOp o va vb c0) in
            Some (setCarry c' (setReg a v' state))
            end))
    end.

  Definition evalAssignment (a: Assignment) (state: State): option State :=
    match a with
    | ARegMem _ _ r m i => 
      omap (getMem m i state) (fun v => Some (setReg r v state))
    | AMemReg _ _ m i r =>
      omap (getReg r state) (fun v => Some (setMem m i v state))
    | AStackReg _ a b =>
      omap (getReg b state) (fun v => Some (setStack a v state))
    | ARegStack _ a b =>
      omap (getStack b state) (fun v => Some (setReg a v state))
    | ARegReg _ a b => 
      omap (getReg b state) (fun v => Some (setReg a v state))
    | AConstInt _ r c =>
      Some (setReg r (constValueW c) state)
    end.

End QhasmEval.
