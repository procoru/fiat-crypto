static void feadd(uint32_t out[6], const uint32_t in1[6], const uint32_t in2[6]) {
  { const uint32_t x12 = in1[5];
  { const uint32_t x13 = in1[4];
  { const uint32_t x11 = in1[3];
  { const uint32_t x9 = in1[2];
  { const uint32_t x7 = in1[1];
  { const uint32_t x5 = in1[0];
  { const uint32_t x22 = in2[5];
  { const uint32_t x23 = in2[4];
  { const uint32_t x21 = in2[3];
  { const uint32_t x19 = in2[2];
  { const uint32_t x17 = in2[1];
  { const uint32_t x15 = in2[0];
  { uint32_t x25; uint8_t x26 = _addcarryx_u32(0x0, x5, x15, &x25);
  { uint32_t x28; uint8_t x29 = _addcarryx_u32(x26, x7, x17, &x28);
  { uint32_t x31; uint8_t x32 = _addcarryx_u32(x29, x9, x19, &x31);
  { uint32_t x34; uint8_t x35 = _addcarryx_u32(x32, x11, x21, &x34);
  { uint32_t x37; uint8_t x38 = _addcarryx_u32(x35, x13, x23, &x37);
  { uint32_t x40; uint8_t x41 = _addcarryx_u32(x38, x12, x22, &x40);
  { uint32_t x43; uint8_t x44 = _subborrow_u32(0x0, x25, 0xffffffef, &x43);
  { uint32_t x46; uint8_t x47 = _subborrow_u32(x44, x28, 0xffffffff, &x46);
  { uint32_t x49; uint8_t x50 = _subborrow_u32(x47, x31, 0xffffffff, &x49);
  { uint32_t x52; uint8_t x53 = _subborrow_u32(x50, x34, 0xffffffff, &x52);
  { uint32_t x55; uint8_t x56 = _subborrow_u32(x53, x37, 0xffffffff, &x55);
  { uint32_t x58; uint8_t x59 = _subborrow_u32(x56, x40, 0x3fff, &x58);
  { uint32_t _; uint8_t x62 = _subborrow_u32(x59, x41, 0x0, &_);
  { uint32_t x63 = cmovznz32(x62, x58, x40);
  { uint32_t x64 = cmovznz32(x62, x55, x37);
  { uint32_t x65 = cmovznz32(x62, x52, x34);
  { uint32_t x66 = cmovznz32(x62, x49, x31);
  { uint32_t x67 = cmovznz32(x62, x46, x28);
  { uint32_t x68 = cmovznz32(x62, x43, x25);
  out[0] = x68;
  out[1] = x67;
  out[2] = x66;
  out[3] = x65;
  out[4] = x64;
  out[5] = x63;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}
