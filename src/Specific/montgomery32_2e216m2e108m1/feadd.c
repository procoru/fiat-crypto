static void feadd(uint32_t out[7], const uint32_t in1[7], const uint32_t in2[7]) {
  { const uint32_t x14 = in1[6];
  { const uint32_t x15 = in1[5];
  { const uint32_t x13 = in1[4];
  { const uint32_t x11 = in1[3];
  { const uint32_t x9 = in1[2];
  { const uint32_t x7 = in1[1];
  { const uint32_t x5 = in1[0];
  { const uint32_t x26 = in2[6];
  { const uint32_t x27 = in2[5];
  { const uint32_t x25 = in2[4];
  { const uint32_t x23 = in2[3];
  { const uint32_t x21 = in2[2];
  { const uint32_t x19 = in2[1];
  { const uint32_t x17 = in2[0];
  { uint32_t x29; uint8_t x30 = _addcarryx_u32(0x0, x5, x17, &x29);
  { uint32_t x32; uint8_t x33 = _addcarryx_u32(x30, x7, x19, &x32);
  { uint32_t x35; uint8_t x36 = _addcarryx_u32(x33, x9, x21, &x35);
  { uint32_t x38; uint8_t x39 = _addcarryx_u32(x36, x11, x23, &x38);
  { uint32_t x41; uint8_t x42 = _addcarryx_u32(x39, x13, x25, &x41);
  { uint32_t x44; uint8_t x45 = _addcarryx_u32(x42, x15, x27, &x44);
  { uint32_t x47; uint8_t x48 = _addcarryx_u32(x45, x14, x26, &x47);
  { uint32_t x50; uint8_t x51 = _subborrow_u32(0x0, x29, 0xffffffff, &x50);
  { uint32_t x53; uint8_t x54 = _subborrow_u32(x51, x32, 0xffffffff, &x53);
  { uint32_t x56; uint8_t x57 = _subborrow_u32(x54, x35, 0xffffffff, &x56);
  { uint32_t x59; uint8_t x60 = _subborrow_u32(x57, x38, 0xffffefff, &x59);
  { uint32_t x62; uint8_t x63 = _subborrow_u32(x60, x41, 0xffffffff, &x62);
  { uint32_t x65; uint8_t x66 = _subborrow_u32(x63, x44, 0xffffffff, &x65);
  { uint32_t x68; uint8_t x69 = _subborrow_u32(x66, x47, 0xffffff, &x68);
  { uint32_t _; uint8_t x72 = _subborrow_u32(x69, x48, 0x0, &_);
  { uint32_t x73 = cmovznz32(x72, x68, x47);
  { uint32_t x74 = cmovznz32(x72, x65, x44);
  { uint32_t x75 = cmovznz32(x72, x62, x41);
  { uint32_t x76 = cmovznz32(x72, x59, x38);
  { uint32_t x77 = cmovznz32(x72, x56, x35);
  { uint32_t x78 = cmovznz32(x72, x53, x32);
  { uint32_t x79 = cmovznz32(x72, x50, x29);
  out[0] = x79;
  out[1] = x78;
  out[2] = x77;
  out[3] = x76;
  out[4] = x75;
  out[5] = x74;
  out[6] = x73;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}
