static void feadd(uint64_t out[8], const uint64_t in1[8], const uint64_t in2[8]) {
  { const uint64_t x16 = in1[7];
  { const uint64_t x17 = in1[6];
  { const uint64_t x15 = in1[5];
  { const uint64_t x13 = in1[4];
  { const uint64_t x11 = in1[3];
  { const uint64_t x9 = in1[2];
  { const uint64_t x7 = in1[1];
  { const uint64_t x5 = in1[0];
  { const uint64_t x30 = in2[7];
  { const uint64_t x31 = in2[6];
  { const uint64_t x29 = in2[5];
  { const uint64_t x27 = in2[4];
  { const uint64_t x25 = in2[3];
  { const uint64_t x23 = in2[2];
  { const uint64_t x21 = in2[1];
  { const uint64_t x19 = in2[0];
  { uint64_t x33; uint8_t x34 = _addcarryx_u64(0x0, x5, x19, &x33);
  { uint64_t x36; uint8_t x37 = _addcarryx_u64(x34, x7, x21, &x36);
  { uint64_t x39; uint8_t x40 = _addcarryx_u64(x37, x9, x23, &x39);
  { uint64_t x42; uint8_t x43 = _addcarryx_u64(x40, x11, x25, &x42);
  { uint64_t x45; uint8_t x46 = _addcarryx_u64(x43, x13, x27, &x45);
  { uint64_t x48; uint8_t x49 = _addcarryx_u64(x46, x15, x29, &x48);
  { uint64_t x51; uint8_t x52 = _addcarryx_u64(x49, x17, x31, &x51);
  { uint64_t x54; uint8_t x55 = _addcarryx_u64(x52, x16, x30, &x54);
  { uint64_t x57; uint8_t x58 = _subborrow_u64(0x0, x33, 0xffffffffffffff45L, &x57);
  { uint64_t x60; uint8_t x61 = _subborrow_u64(x58, x36, 0xffffffffffffffffL, &x60);
  { uint64_t x63; uint8_t x64 = _subborrow_u64(x61, x39, 0xffffffffffffffffL, &x63);
  { uint64_t x66; uint8_t x67 = _subborrow_u64(x64, x42, 0xffffffffffffffffL, &x66);
  { uint64_t x69; uint8_t x70 = _subborrow_u64(x67, x45, 0xffffffffffffffffL, &x69);
  { uint64_t x72; uint8_t x73 = _subborrow_u64(x70, x48, 0xffffffffffffffffL, &x72);
  { uint64_t x75; uint8_t x76 = _subborrow_u64(x73, x51, 0xffffffffffffffffL, &x75);
  { uint64_t x78; uint8_t x79 = _subborrow_u64(x76, x54, 0x7fffffffffffffffL, &x78);
  { uint64_t _; uint8_t x82 = _subborrow_u64(x79, x55, 0x0, &_);
  { uint64_t x83 = cmovznz64(x82, x78, x54);
  { uint64_t x84 = cmovznz64(x82, x75, x51);
  { uint64_t x85 = cmovznz64(x82, x72, x48);
  { uint64_t x86 = cmovznz64(x82, x69, x45);
  { uint64_t x87 = cmovznz64(x82, x66, x42);
  { uint64_t x88 = cmovznz64(x82, x63, x39);
  { uint64_t x89 = cmovznz64(x82, x60, x36);
  { uint64_t x90 = cmovznz64(x82, x57, x33);
  out[0] = x90;
  out[1] = x89;
  out[2] = x88;
  out[3] = x87;
  out[4] = x86;
  out[5] = x85;
  out[6] = x84;
  out[7] = x83;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}
