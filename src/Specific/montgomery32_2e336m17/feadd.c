static void feadd(uint32_t out[11], const uint32_t in1[11], const uint32_t in2[11]) {
  { const uint32_t x22 = in1[10];
  { const uint32_t x23 = in1[9];
  { const uint32_t x21 = in1[8];
  { const uint32_t x19 = in1[7];
  { const uint32_t x17 = in1[6];
  { const uint32_t x15 = in1[5];
  { const uint32_t x13 = in1[4];
  { const uint32_t x11 = in1[3];
  { const uint32_t x9 = in1[2];
  { const uint32_t x7 = in1[1];
  { const uint32_t x5 = in1[0];
  { const uint32_t x42 = in2[10];
  { const uint32_t x43 = in2[9];
  { const uint32_t x41 = in2[8];
  { const uint32_t x39 = in2[7];
  { const uint32_t x37 = in2[6];
  { const uint32_t x35 = in2[5];
  { const uint32_t x33 = in2[4];
  { const uint32_t x31 = in2[3];
  { const uint32_t x29 = in2[2];
  { const uint32_t x27 = in2[1];
  { const uint32_t x25 = in2[0];
  { uint32_t x45; uint8_t x46 = _addcarryx_u32(0x0, x5, x25, &x45);
  { uint32_t x48; uint8_t x49 = _addcarryx_u32(x46, x7, x27, &x48);
  { uint32_t x51; uint8_t x52 = _addcarryx_u32(x49, x9, x29, &x51);
  { uint32_t x54; uint8_t x55 = _addcarryx_u32(x52, x11, x31, &x54);
  { uint32_t x57; uint8_t x58 = _addcarryx_u32(x55, x13, x33, &x57);
  { uint32_t x60; uint8_t x61 = _addcarryx_u32(x58, x15, x35, &x60);
  { uint32_t x63; uint8_t x64 = _addcarryx_u32(x61, x17, x37, &x63);
  { uint32_t x66; uint8_t x67 = _addcarryx_u32(x64, x19, x39, &x66);
  { uint32_t x69; uint8_t x70 = _addcarryx_u32(x67, x21, x41, &x69);
  { uint32_t x72; uint8_t x73 = _addcarryx_u32(x70, x23, x43, &x72);
  { uint32_t x75; uint8_t x76 = _addcarryx_u32(x73, x22, x42, &x75);
  { uint32_t x78; uint8_t x79 = _subborrow_u32(0x0, x45, 0xffffffef, &x78);
  { uint32_t x81; uint8_t x82 = _subborrow_u32(x79, x48, 0xffffffff, &x81);
  { uint32_t x84; uint8_t x85 = _subborrow_u32(x82, x51, 0xffffffff, &x84);
  { uint32_t x87; uint8_t x88 = _subborrow_u32(x85, x54, 0xffffffff, &x87);
  { uint32_t x90; uint8_t x91 = _subborrow_u32(x88, x57, 0xffffffff, &x90);
  { uint32_t x93; uint8_t x94 = _subborrow_u32(x91, x60, 0xffffffff, &x93);
  { uint32_t x96; uint8_t x97 = _subborrow_u32(x94, x63, 0xffffffff, &x96);
  { uint32_t x99; uint8_t x100 = _subborrow_u32(x97, x66, 0xffffffff, &x99);
  { uint32_t x102; uint8_t x103 = _subborrow_u32(x100, x69, 0xffffffff, &x102);
  { uint32_t x105; uint8_t x106 = _subborrow_u32(x103, x72, 0xffffffff, &x105);
  { uint32_t x108; uint8_t x109 = _subborrow_u32(x106, x75, 0xffff, &x108);
  { uint32_t _; uint8_t x112 = _subborrow_u32(x109, x76, 0x0, &_);
  { uint32_t x113 = cmovznz32(x112, x108, x75);
  { uint32_t x114 = cmovznz32(x112, x105, x72);
  { uint32_t x115 = cmovznz32(x112, x102, x69);
  { uint32_t x116 = cmovznz32(x112, x99, x66);
  { uint32_t x117 = cmovznz32(x112, x96, x63);
  { uint32_t x118 = cmovznz32(x112, x93, x60);
  { uint32_t x119 = cmovznz32(x112, x90, x57);
  { uint32_t x120 = cmovznz32(x112, x87, x54);
  { uint32_t x121 = cmovznz32(x112, x84, x51);
  { uint32_t x122 = cmovznz32(x112, x81, x48);
  { uint32_t x123 = cmovznz32(x112, x78, x45);
  out[0] = x123;
  out[1] = x122;
  out[2] = x121;
  out[3] = x120;
  out[4] = x119;
  out[5] = x118;
  out[6] = x117;
  out[7] = x116;
  out[8] = x115;
  out[9] = x114;
  out[10] = x113;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}
