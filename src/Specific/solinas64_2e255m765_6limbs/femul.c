static void femul(uint64_t out[6], const uint64_t in1[6], const uint64_t in2[6]) {
  { const uint64_t x12 = in1[5];
  { const uint64_t x13 = in1[4];
  { const uint64_t x11 = in1[3];
  { const uint64_t x9 = in1[2];
  { const uint64_t x7 = in1[1];
  { const uint64_t x5 = in1[0];
  { const uint64_t x22 = in2[5];
  { const uint64_t x23 = in2[4];
  { const uint64_t x21 = in2[3];
  { const uint64_t x19 = in2[2];
  { const uint64_t x17 = in2[1];
  { const uint64_t x15 = in2[0];
  { uint128_t x24 = (((uint128_t)x5 * x22) + (((uint128_t)x7 * x23) + (((uint128_t)x9 * x21) + (((uint128_t)x11 * x19) + (((uint128_t)x13 * x17) + ((uint128_t)x12 * x15))))));
  { uint128_t x25 = ((((uint128_t)x5 * x23) + ((0x2 * ((uint128_t)x7 * x21)) + (((uint128_t)x9 * x19) + ((0x2 * ((uint128_t)x11 * x17)) + ((uint128_t)x13 * x15))))) + (0x2fd * (0x2 * ((uint128_t)x12 * x22))));
  { uint128_t x26 = ((((uint128_t)x5 * x21) + (((uint128_t)x7 * x19) + (((uint128_t)x9 * x17) + ((uint128_t)x11 * x15)))) + (0x2fd * (((uint128_t)x13 * x22) + ((uint128_t)x12 * x23))));
  { uint128_t x27 = ((((uint128_t)x5 * x19) + ((0x2 * ((uint128_t)x7 * x17)) + ((uint128_t)x9 * x15))) + (0x2fd * ((0x2 * ((uint128_t)x11 * x22)) + (((uint128_t)x13 * x23) + (0x2 * ((uint128_t)x12 * x21))))));
  { uint128_t x28 = ((((uint128_t)x5 * x17) + ((uint128_t)x7 * x15)) + (0x2fd * (((uint128_t)x9 * x22) + (((uint128_t)x11 * x23) + (((uint128_t)x13 * x21) + ((uint128_t)x12 * x19))))));
  { uint128_t x29 = (((uint128_t)x5 * x15) + (0x2fd * ((0x2 * ((uint128_t)x7 * x22)) + (((uint128_t)x9 * x23) + ((0x2 * ((uint128_t)x11 * x21)) + (((uint128_t)x13 * x19) + (0x2 * ((uint128_t)x12 * x17))))))));
  { uint64_t x30 = (uint64_t) (x29 >> 0x2b);
  { uint64_t x31 = ((uint64_t)x29 & 0x7ffffffffff);
  { uint128_t x32 = (x30 + x28);
  { uint64_t x33 = (uint64_t) (x32 >> 0x2a);
  { uint64_t x34 = ((uint64_t)x32 & 0x3ffffffffff);
  { uint128_t x35 = (x33 + x27);
  { uint64_t x36 = (uint64_t) (x35 >> 0x2b);
  { uint64_t x37 = ((uint64_t)x35 & 0x7ffffffffff);
  { uint128_t x38 = (x36 + x26);
  { uint64_t x39 = (uint64_t) (x38 >> 0x2a);
  { uint64_t x40 = ((uint64_t)x38 & 0x3ffffffffff);
  { uint128_t x41 = (x39 + x25);
  { uint64_t x42 = (uint64_t) (x41 >> 0x2b);
  { uint64_t x43 = ((uint64_t)x41 & 0x7ffffffffff);
  { uint128_t x44 = (x42 + x24);
  { uint64_t x45 = (uint64_t) (x44 >> 0x2a);
  { uint64_t x46 = ((uint64_t)x44 & 0x3ffffffffff);
  { uint64_t x47 = (x31 + (0x2fd * x45));
  { uint64_t x48 = (x47 >> 0x2b);
  { uint64_t x49 = (x47 & 0x7ffffffffff);
  { uint64_t x50 = (x48 + x34);
  { uint64_t x51 = (x50 >> 0x2a);
  { uint64_t x52 = (x50 & 0x3ffffffffff);
  out[0] = x49;
  out[1] = x52;
  out[2] = (x51 + x37);
  out[3] = x40;
  out[4] = x43;
  out[5] = x46;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
}
