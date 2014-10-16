#include "sparse_multiplier.h"

void sparse_multiplier(const Real * A, const Real * Vm, Real* w) {
  w[0] = A[0] * Vm[0] +  A[14] * Vm[1] +  A[28] * Vm[2] +  A[42] * Vm[3] +  A[56] * Vm[4] +  A[70] * Vm[5] +  A[84] * Vm[6] +  A[98] * Vm[7] +  A[112] * Vm[8] +  A[126] * Vm[9] +  A[140] * Vm[10] +  A[154] * Vm[11] +  A[168] * Vm[12] +  A[182] * Vm[13];
  w[1] = A[1] * Vm[0] +  A[15] * Vm[1] +  A[29] * Vm[2] +  A[43] * Vm[3] +  A[57] * Vm[4] +  A[71] * Vm[5] +  A[85] * Vm[6] +  A[99] * Vm[7] +  A[113] * Vm[8] +  A[127] * Vm[9] +  A[141] * Vm[10] +  A[155] * Vm[11] +  A[169] * Vm[12] +  A[183] * Vm[13];
  w[2] = A[2] * Vm[0] +  A[16] * Vm[1] +  A[30] * Vm[2] +  A[44] * Vm[3] +  A[58] * Vm[4] +  A[72] * Vm[5] +  A[86] * Vm[6] +  A[100] * Vm[7] +  A[114] * Vm[8] +  A[128] * Vm[9] +  A[142] * Vm[10] +  A[156] * Vm[11] +  A[170] * Vm[12] +  A[184] * Vm[13];
  w[3] = A[3] * Vm[0] +  A[17] * Vm[1] +  A[31] * Vm[2] +  A[45] * Vm[3] +  A[59] * Vm[4] +  A[73] * Vm[5] +  A[87] * Vm[6] +  A[101] * Vm[7] +  A[115] * Vm[8] +  A[129] * Vm[9] +  A[143] * Vm[10] +  A[157] * Vm[11] +  A[171] * Vm[12] +  A[185] * Vm[13];
  w[4] = A[4] * Vm[0] +  A[18] * Vm[1] +  A[32] * Vm[2] +  A[46] * Vm[3] +  A[60] * Vm[4] +  A[74] * Vm[5] +  A[88] * Vm[6] +  A[102] * Vm[7] +  A[116] * Vm[8] +  A[130] * Vm[9] +  A[144] * Vm[10] +  A[158] * Vm[11] +  A[172] * Vm[12] +  A[186] * Vm[13];
  w[5] = A[5] * Vm[0] +  A[19] * Vm[1] +  A[33] * Vm[2] +  A[47] * Vm[3] +  A[61] * Vm[4] +  A[75] * Vm[5] +  A[89] * Vm[6] +  A[103] * Vm[7] +  A[117] * Vm[8] +  A[131] * Vm[9] +  A[145] * Vm[10] +  A[159] * Vm[11] +  A[173] * Vm[12] +  A[187] * Vm[13];
  w[6] = A[6] * Vm[0] +  A[20] * Vm[1] +  A[34] * Vm[2] +  A[48] * Vm[3] +  A[62] * Vm[4] +  A[76] * Vm[5] +  A[90] * Vm[6] +  A[104] * Vm[7] +  A[118] * Vm[8] +  A[132] * Vm[9] +  A[146] * Vm[10] +  A[160] * Vm[11] +  A[174] * Vm[12] +  A[188] * Vm[13];
  w[7] = A[7] * Vm[0] +  A[21] * Vm[1] +  A[35] * Vm[2] +  A[49] * Vm[3] +  A[63] * Vm[4] +  A[77] * Vm[5] +  A[91] * Vm[6] +  A[105] * Vm[7] +  A[119] * Vm[8] +  A[133] * Vm[9] +  A[147] * Vm[10] +  A[161] * Vm[11] +  A[175] * Vm[12] +  A[189] * Vm[13];
  w[8] = A[8] * Vm[0] +  A[22] * Vm[1] +  A[36] * Vm[2] +  A[50] * Vm[3] +  A[64] * Vm[4] +  A[78] * Vm[5] +  A[92] * Vm[6] +  A[106] * Vm[7] +  A[120] * Vm[8] +  A[134] * Vm[9] +  A[148] * Vm[10] +  A[162] * Vm[11] +  A[176] * Vm[12] +  A[190] * Vm[13];
}

#ifdef COMPILE_TESTING_METHODS
  int test_sparse_multiplier(){
    Real A[NN * NN] = {ZERO};
    Real v[NN] = {ZERO};
    Real w[NN] = {ZERO};
    Real w2[NN] = {ZERO};
    v[0] = 0;
    A[0] = 0;
    A[14] = 14;
    A[28] = 28;
    A[42] = 42;
    A[56] = 56;
    A[70] = 70;
    A[84] = 84;
    A[98] = 98;
    A[112] = 112;
    A[126] = 126;
    A[140] = 140;
    A[154] = 154;
    A[168] = 168;
    A[182] = 182;
    v[1] = 1;
    A[1] = 1;
    A[15] = 15;
    A[29] = 29;
    A[43] = 43;
    A[57] = 57;
    A[71] = 71;
    A[85] = 85;
    A[99] = 99;
    A[113] = 113;
    A[127] = 127;
    A[141] = 141;
    A[155] = 155;
    A[169] = 169;
    A[183] = 183;
    v[2] = 2;
    A[2] = 2;
    A[16] = 16;
    A[30] = 30;
    A[44] = 44;
    A[58] = 58;
    A[72] = 72;
    A[86] = 86;
    A[100] = 100;
    A[114] = 114;
    A[128] = 128;
    A[142] = 142;
    A[156] = 156;
    A[170] = 170;
    A[184] = 184;
    v[3] = 3;
    A[3] = 3;
    A[17] = 17;
    A[31] = 31;
    A[45] = 45;
    A[59] = 59;
    A[73] = 73;
    A[87] = 87;
    A[101] = 101;
    A[115] = 115;
    A[129] = 129;
    A[143] = 143;
    A[157] = 157;
    A[171] = 171;
    A[185] = 185;
    v[4] = 4;
    A[4] = 4;
    A[18] = 18;
    A[32] = 32;
    A[46] = 46;
    A[60] = 60;
    A[74] = 74;
    A[88] = 88;
    A[102] = 102;
    A[116] = 116;
    A[130] = 130;
    A[144] = 144;
    A[158] = 158;
    A[172] = 172;
    A[186] = 186;
    v[5] = 5;
    A[5] = 5;
    A[19] = 19;
    A[33] = 33;
    A[47] = 47;
    A[61] = 61;
    A[75] = 75;
    A[89] = 89;
    A[103] = 103;
    A[117] = 117;
    A[131] = 131;
    A[145] = 145;
    A[159] = 159;
    A[173] = 173;
    A[187] = 187;
    v[6] = 6;
    A[6] = 6;
    A[20] = 20;
    A[34] = 34;
    A[48] = 48;
    A[62] = 62;
    A[76] = 76;
    A[90] = 90;
    A[104] = 104;
    A[118] = 118;
    A[132] = 132;
    A[146] = 146;
    A[160] = 160;
    A[174] = 174;
    A[188] = 188;
    v[7] = 7;
    A[7] = 7;
    A[21] = 21;
    A[35] = 35;
    A[49] = 49;
    A[63] = 63;
    A[77] = 77;
    A[91] = 91;
    A[105] = 105;
    A[119] = 119;
    A[133] = 133;
    A[147] = 147;
    A[161] = 161;
    A[175] = 175;
    A[189] = 189;
    v[8] = 8;
    A[8] = 8;
    A[22] = 22;
    A[36] = 36;
    A[50] = 50;
    A[64] = 64;
    A[78] = 78;
    A[92] = 92;
    A[106] = 106;
    A[120] = 120;
    A[134] = 134;
    A[148] = 148;
    A[162] = 162;
    A[176] = 176;
    A[190] = 190;
    v[9] = 9;
    v[10] = 10;
    v[11] = 11;
    v[12] = 12;
    v[13] = 13;
    for (uint i = 0; i < NN; ++i) {
       for (uint j = 0; j < NN; ++j) {
          w2[i] += A[i + (j * NN)] * v[j];
       }
    }
    sparse_multiplier(A, v, w);
    for (uint i = 0; i < NN; ++i) {
       if (w[i] != w2[i]) 
         return 0;
    }
    return 1;
  }
#endif
