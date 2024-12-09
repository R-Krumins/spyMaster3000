#include <cstdint>

const uint32_t expected_W[] = {
	0b01100001011000100110001110000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000000000,
	0b00000000000000000000000000011000,
	0b01100001011000100110001110000000,
	0b00000000000011110000000000000000,
	0b01111101101010000110010000000101,
	0b01100000000000000000001111000110,
	0b00111110100111010111101101111000,
	0b00000001100000111111110000000000,
	0b00010010110111001011111111011011,
	0b11100010111000101100001110001110,
	0b11001000001000010101110000011010,
	0b10110111001101100111100110100010,
	0b11100101101111000011100100001001,
	0b00110010011001100011110001011011,
	0b10011101001000001001110101100111,
	0b11101100100001110010011011001011,
	0b01110000001000010011100010100100,
	0b11010011101101111001011100111011,
	0b10010011111101011001100101111111,
	0b00111011011010001011101001110011,
	0b10101111111101001111111111000001,
	0b11110001000010100101110001100010,
	0b00001010100010110011100110010110,
	0b01110010101011111000001100001010,
	0b10010100000010011110001100111110,
	0b00100100011001000001010100100010,
	0b10011111010001111011111110010100,
	0b11110000101001100100111101011010,
	0b00111110001001000110101001111001,
	0b00100111001100110011101110100011,
	0b00001100010001110110001111110010,
	0b10000100000010101011111100100111,
	0b01111010001010010000110101011101,
	0b00000110010111000100001111011010,
	0b11111011001111101000100111001011,
	0b11001100011101100001011111011011,
	0b10111001111001100110110000110100,
	0b10101001100110010011011001100111,
	0b10000100101110101101111011011101,
	0b11000010000101000110001010111100,
	0b00010100100001110100011100101100,
	0b10110010000011110111101010011001,
	0b11101111010101111011100111001101,
	0b11101011111001101011001000111000,
	0b10011111111000110000100101011110,
	0b01111000101111001000110101001011,
	0b10100100001111111100111100010101,
	0b01100110100010110010111111111000,
	0b11101110101010111010001011001100,
	0b00010010101100011110110111101011,
};

const uint32_t abc_working_variables[64][8] = {
	{0x5d6aebcd, 0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xfa2a4622, 0x510e527f, 0x9b05688c, 0x1f83d9ab},
	{0x5a6ad9ad, 0x5d6aebcd, 0x6a09e667, 0xbb67ae85, 0x78ce7989, 0xfa2a4622, 0x510e527f, 0x9b05688c},
	{0xc8c347a7, 0x5a6ad9ad, 0x5d6aebcd, 0x6a09e667, 0xf92939eb, 0x78ce7989, 0xfa2a4622, 0x510e527f},
	{0xd550f666, 0xc8c347a7, 0x5a6ad9ad, 0x5d6aebcd, 0x24e00850, 0xf92939eb, 0x78ce7989, 0xfa2a4622},
	{0x04409a6a, 0xd550f666, 0xc8c347a7, 0x5a6ad9ad, 0x43ada245, 0x24e00850, 0xf92939eb, 0x78ce7989},
	{0x2b4209f5, 0x04409a6a, 0xd550f666, 0xc8c347a7, 0x714260ad, 0x43ada245, 0x24e00850, 0xf92939eb},
	{0xe5030380, 0x2b4209f5, 0x04409a6a, 0xd550f666, 0x9b27a401, 0x714260ad, 0x43ada245, 0x24e00850},
	{0x85a07b5f, 0xe5030380, 0x2b4209f5, 0x04409a6a, 0x0c657a79, 0x9b27a401, 0x714260ad, 0x43ada245},
	{0x8e04ecb9, 0x85a07b5f, 0xe5030380, 0x2b4209f5, 0x32ca2d8c, 0x0c657a79, 0x9b27a401, 0x714260ad},
	{0x8c87346b, 0x8e04ecb9, 0x85a07b5f, 0xe5030380, 0x1cc92596, 0x32ca2d8c, 0x0c657a79, 0x9b27a401},
	{0x4798a3f4, 0x8c87346b, 0x8e04ecb9, 0x85a07b5f, 0x436b23e8, 0x1cc92596, 0x32ca2d8c, 0x0c657a79},
	{0xf71fc5a9, 0x4798a3f4, 0x8c87346b, 0x8e04ecb9, 0x816fd6e9, 0x436b23e8, 0x1cc92596, 0x32ca2d8c},
	{0x87912990, 0xf71fc5a9, 0x4798a3f4, 0x8c87346b, 0x1e578218, 0x816fd6e9, 0x436b23e8, 0x1cc92596},
	{0xd932eb16, 0x87912990, 0xf71fc5a9, 0x4798a3f4, 0x745a48de, 0x1e578218, 0x816fd6e9, 0x436b23e8},
	{0xc0645fde, 0xd932eb16, 0x87912990, 0xf71fc5a9, 0x0b92f20c, 0x745a48de, 0x1e578218, 0x816fd6e9},
	{0xb0fa238e, 0xc0645fde, 0xd932eb16, 0x87912990, 0x07590dcd, 0x0b92f20c, 0x745a48de, 0x1e578218},
	{0x21da9a9b, 0xb0fa238e, 0xc0645fde, 0xd932eb16, 0x8034229c, 0x07590dcd, 0x0b92f20c, 0x745a48de},
	{0xc2fbd9d1, 0x21da9a9b, 0xb0fa238e, 0xc0645fde, 0x846ee454, 0x8034229c, 0x07590dcd, 0x0b92f20c},
	{0xfe777bbf, 0xc2fbd9d1, 0x21da9a9b, 0xb0fa238e, 0xcc899961, 0x846ee454, 0x8034229c, 0x07590dcd},
	{0xe1f20c33, 0xfe777bbf, 0xc2fbd9d1, 0x21da9a9b, 0xb0638179, 0xcc899961, 0x846ee454, 0x8034229c},
	{0x9dc68b63, 0xe1f20c33, 0xfe777bbf, 0xc2fbd9d1, 0x8ada8930, 0xb0638179, 0xcc899961, 0x846ee454},
	{0xc2606d6d, 0x9dc68b63, 0xe1f20c33, 0xfe777bbf, 0xe1257970, 0x8ada8930, 0xb0638179, 0xcc899961},
	{0xa7a3623f, 0xc2606d6d, 0x9dc68b63, 0xe1f20c33, 0x49f5114a, 0xe1257970, 0x8ada8930, 0xb0638179},
	{0xc5d53d8d, 0xa7a3623f, 0xc2606d6d, 0x9dc68b63, 0xaa47c347, 0x49f5114a, 0xe1257970, 0x8ada8930},
	{0x1c2c2838, 0xc5d53d8d, 0xa7a3623f, 0xc2606d6d, 0x2823ef91, 0xaa47c347, 0x49f5114a, 0xe1257970},
	{0xcde8037d, 0x1c2c2838, 0xc5d53d8d, 0xa7a3623f, 0x14383d8e, 0x2823ef91, 0xaa47c347, 0x49f5114a},
	{0xb62ec4bc, 0xcde8037d, 0x1c2c2838, 0xc5d53d8d, 0xc74c6516, 0x14383d8e, 0x2823ef91, 0xaa47c347},
	{0x77d37528, 0xb62ec4bc, 0xcde8037d, 0x1c2c2838, 0xedffbff8, 0xc74c6516, 0x14383d8e, 0x2823ef91},
	{0x363482c9, 0x77d37528, 0xb62ec4bc, 0xcde8037d, 0x6112a3b7, 0xedffbff8, 0xc74c6516, 0x14383d8e},
	{0xa0060b30, 0x363482c9, 0x77d37528, 0xb62ec4bc, 0xade79437, 0x6112a3b7, 0xedffbff8, 0xc74c6516},
	{0xea992a22, 0xa0060b30, 0x363482c9, 0x77d37528, 0x0109ab3a, 0xade79437, 0x6112a3b7, 0xedffbff8},
	{0x73b33bf5, 0xea992a22, 0xa0060b30, 0x363482c9, 0xba591112, 0x0109ab3a, 0xade79437, 0x6112a3b7},
	{0x98e12507, 0x73b33bf5, 0xea992a22, 0xa0060b30, 0x9cd9f5f6, 0xba591112, 0x0109ab3a, 0xade79437},
	{0xfe604df5, 0x98e12507, 0x73b33bf5, 0xea992a22, 0x59249dd3, 0x9cd9f5f6, 0xba591112, 0x0109ab3a},
	{0xa9a7738c, 0xfe604df5, 0x98e12507, 0x73b33bf5, 0x085f3833, 0x59249dd3, 0x9cd9f5f6, 0xba591112},
	{0x65a0cfe4, 0xa9a7738c, 0xfe604df5, 0x98e12507, 0xf4b002d6, 0x085f3833, 0x59249dd3, 0x9cd9f5f6},
	{0x41a65cb1, 0x65a0cfe4, 0xa9a7738c, 0xfe604df5, 0x0772a26b, 0xf4b002d6, 0x085f3833, 0x59249dd3},
	{0x34df1604, 0x41a65cb1, 0x65a0cfe4, 0xa9a7738c, 0xa507a53d, 0x0772a26b, 0xf4b002d6, 0x085f3833},
	{0x6dc57a8a, 0x34df1604, 0x41a65cb1, 0x65a0cfe4, 0xf0781bc8, 0xa507a53d, 0x0772a26b, 0xf4b002d6},
	{0x79ea687a, 0x6dc57a8a, 0x34df1604, 0x41a65cb1, 0x1efbc0a0, 0xf0781bc8, 0xa507a53d, 0x0772a26b},
	{0xd6670766, 0x79ea687a, 0x6dc57a8a, 0x34df1604, 0x26352d63, 0x1efbc0a0, 0xf0781bc8, 0xa507a53d},
	{0xdf46652f, 0xd6670766, 0x79ea687a, 0x6dc57a8a, 0x838b2711, 0x26352d63, 0x1efbc0a0, 0xf0781bc8},
	{0x17aa0dfe, 0xdf46652f, 0xd6670766, 0x79ea687a, 0xdecd4715, 0x838b2711, 0x26352d63, 0x1efbc0a0},
	{0x9d4baf93, 0x17aa0dfe, 0xdf46652f, 0xd6670766, 0xfda24c2e, 0xdecd4715, 0x838b2711, 0x26352d63},
	{0x26628815, 0x9d4baf93, 0x17aa0dfe, 0xdf46652f, 0xa80f11f0, 0xfda24c2e, 0xdecd4715, 0x838b2711},
	{0x72ab4b91, 0x26628815, 0x9d4baf93, 0x17aa0dfe, 0xb7755da1, 0xa80f11f0, 0xfda24c2e, 0xdecd4715},
	{0xa14c14b0, 0x72ab4b91, 0x26628815, 0x9d4baf93, 0xd57b94a9, 0xb7755da1, 0xa80f11f0, 0xfda24c2e},
	{0x4172328d, 0xa14c14b0, 0x72ab4b91, 0x26628815, 0xfecf0bc6, 0xd57b94a9, 0xb7755da1, 0xa80f11f0},
	{0x05757ceb, 0x4172328d, 0xa14c14b0, 0x72ab4b91, 0xbd714038, 0xfecf0bc6, 0xd57b94a9, 0xb7755da1},
	{0xf11bfaa8, 0x05757ceb, 0x4172328d, 0xa14c14b0, 0x6e5c390c, 0xbd714038, 0xfecf0bc6, 0xd57b94a9},
	{0x7a0508a1, 0xf11bfaa8, 0x05757ceb, 0x4172328d, 0x52f1ccf7, 0x6e5c390c, 0xbd714038, 0xfecf0bc6},
	{0x886e7a22, 0x7a0508a1, 0xf11bfaa8, 0x05757ceb, 0x49231c1e, 0x52f1ccf7, 0x6e5c390c, 0xbd714038},
	{0x101fd28f, 0x886e7a22, 0x7a0508a1, 0xf11bfaa8, 0x529e7d00, 0x49231c1e, 0x52f1ccf7, 0x6e5c390c},
	{0xf5702fdb, 0x101fd28f, 0x886e7a22, 0x7a0508a1, 0x9f4787c3, 0x529e7d00, 0x49231c1e, 0x52f1ccf7},
	{0x3ec45cdb, 0xf5702fdb, 0x101fd28f, 0x886e7a22, 0xe50e1b4f, 0x9f4787c3, 0x529e7d00, 0x49231c1e},
	{0x38cc9913, 0x3ec45cdb, 0xf5702fdb, 0x101fd28f, 0x54cb266b, 0xe50e1b4f, 0x9f4787c3, 0x529e7d00},
	{0xfcd1887b, 0x38cc9913, 0x3ec45cdb, 0xf5702fdb, 0x9b5e906c, 0x54cb266b, 0xe50e1b4f, 0x9f4787c3},
	{0xc062d46f, 0xfcd1887b, 0x38cc9913, 0x3ec45cdb, 0x7e44008e, 0x9b5e906c, 0x54cb266b, 0xe50e1b4f},
	{0xffb70472, 0xc062d46f, 0xfcd1887b, 0x38cc9913, 0x6d83bfc6, 0x7e44008e, 0x9b5e906c, 0x54cb266b},
	{0xb6ae8fff, 0xffb70472, 0xc062d46f, 0xfcd1887b, 0xb21bad3d, 0x6d83bfc6, 0x7e44008e, 0x9b5e906c},
	{0xb85e2ce9, 0xb6ae8fff, 0xffb70472, 0xc062d46f, 0x961f4894, 0xb21bad3d, 0x6d83bfc6, 0x7e44008e},
	{0x04d24d6c, 0xb85e2ce9, 0xb6ae8fff, 0xffb70472, 0x948d25b6, 0x961f4894, 0xb21bad3d, 0x6d83bfc6},
	{0xd39a2165, 0x04d24d6c, 0xb85e2ce9, 0xb6ae8fff, 0xfb121210, 0x948d25b6, 0x961f4894, 0xb21bad3d},
	{0x506e3058, 0xd39a2165, 0x04d24d6c, 0xb85e2ce9, 0x5ef50f24, 0xfb121210, 0x948d25b6, 0x961f4894},
};

const uint32_t abc_msg_digest[] {
	0xba7816bf, 0x8f01cfea, 0x414140de, 0x5dae2223, 0xb00361a3, 0x96177a9c, 0xb410ff61, 0xf20015ad
};

//msg: abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq
const uint32_t long_msg_digest[] {
	0x248d6a61, 0xd20638b8, 0xe5c02693, 0x0c3e6039, 0xa33ce459, 0x64ff2167, 0xf6ecedd4, 0x19db06c1
};
