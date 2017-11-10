static void freeze(uint32_t out[8], const uint32_t in1[8]) {
  { const uint32_t x13 = in1[7];
  { const uint32_t x14 = in1[6];
  { const uint32_t x12 = in1[5];
  { const uint32_t x10 = in1[4];
  { const uint32_t x8 = in1[3];
  { const uint32_t x6 = in1[2];
  { const uint32_t x4 = in1[1];
  { const uint32_t x2 = in1[0];
  { uint32_t x16, uint8_t x17 = Op (Syntax.SubWithGetBorrow 29 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (0x0, Return x2, 0x1ffffffb);
  { uint32_t x19, uint8_t x20 = Op (Syntax.SubWithGetBorrow 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x17, Return x4, 0xfffffff);
  { uint32_t x22, uint8_t x23 = Op (Syntax.SubWithGetBorrow 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x20, Return x6, 0xfffffff);
  { uint32_t x25, uint8_t x26 = Op (Syntax.SubWithGetBorrow 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x23, Return x8, 0xfffffff);
  { uint32_t x28, uint8_t x29 = Op (Syntax.SubWithGetBorrow 29 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x26, Return x10, 0x1fffffff);
  { uint32_t x31, uint8_t x32 = Op (Syntax.SubWithGetBorrow 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x29, Return x12, 0xfffffff);
  { uint32_t x34, uint8_t x35 = Op (Syntax.SubWithGetBorrow 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x32, Return x14, 0xfffffff);
  { uint32_t x37, uint8_t x38 = Op (Syntax.SubWithGetBorrow 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x35, Return x13, 0xfffffff);
  { uint32_t x39 = cmovznz32(x38, 0x0, 0xffffffff);
  { uint32_t x40 = (x39 & 0x1ffffffb);
  { uint32_t x42, uint8_t x43 = Op (Syntax.AddWithGetCarry 29 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (0x0, Return x16, Return x40);
  { uint32_t x44 = (x39 & 0xfffffff);
  { uint32_t x46, uint8_t x47 = Op (Syntax.AddWithGetCarry 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x43, Return x19, Return x44);
  { uint32_t x48 = (x39 & 0xfffffff);
  { uint32_t x50, uint8_t x51 = Op (Syntax.AddWithGetCarry 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x47, Return x22, Return x48);
  { uint32_t x52 = (x39 & 0xfffffff);
  { uint32_t x54, uint8_t x55 = Op (Syntax.AddWithGetCarry 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x51, Return x25, Return x52);
  { uint32_t x56 = (x39 & 0x1fffffff);
  { uint32_t x58, uint8_t x59 = Op (Syntax.AddWithGetCarry 29 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x55, Return x28, Return x56);
  { uint32_t x60 = (x39 & 0xfffffff);
  { uint32_t x62, uint8_t x63 = Op (Syntax.AddWithGetCarry 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x59, Return x31, Return x60);
  { uint32_t x64 = (x39 & 0xfffffff);
  { uint32_t x66, uint8_t x67 = Op (Syntax.AddWithGetCarry 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x63, Return x34, Return x64);
  { uint32_t x68 = (x39 & 0xfffffff);
  { uint32_t x70, uint8_t _ = Op (Syntax.AddWithGetCarry 28 (Syntax.TWord 3) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 5) (Syntax.TWord 3)) (Return x67, Return x37, Return x68);
  out[0] = x42;
  out[1] = x46;
  out[2] = x50;
  out[3] = x54;
  out[4] = x58;
  out[5] = x62;
  out[6] = x66;
  out[7] = x70;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}
