#include <cassert>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

namespace AES {
union Block{
	uint8_t bytes[4][4];
	uint32_t words[4];

	Block(std::string text) {
		assert(text.length() == 16);
		std::memcpy(&words[0], text.data() + 0, 4);
		std::memcpy(&words[1], text.data() + 4, 4);
		std::memcpy(&words[2], text.data() + 8, 4);
		std::memcpy(&words[3], text.data() + 12, 4);
	}
	
};


Block subBytes(Block b) {};
Block shiftRows(Block b) {};
Block mixColumns(Block b) {};
Block addRoundKey(Block b, Block w) {};
void keyExpansion() {};

Block cipher(std::string in, int Nr, Block* w) {
	Block state(in);

	// Pre-round
	state = addRoundKey(state, w[0]);

	//Round 0 to Nr-1
	for(int round = 0; round < Nr - 1; round++) {
		state = subBytes(state);
		state = shiftRows(state);
		state = mixColumns(state);
		state = addRoundKey(state, w[round]);
	}

	//Last round
	state = subBytes(state);
	state = shiftRows(state);
	state = addRoundKey(state, w[Nr-1]);

	return state;
};
	
}


using namespace AES;

// Print the block for debugging
void dbg(Block& b) {
	std::cout << "Bytes (2D):\n";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			std::cout << std::hex << std::setw(2) << std::setfill('0') 
				<< static_cast<int>(b.bytes[i][j]) << " ";
		}
		std::cout << "\n";
	}
	std::cout << "Words:\n";
	for (int i = 0; i < 4; ++i) {
		std::cout << std::hex << std::setw(8) << std::setfill('0') << b.words[i] << " ";
	}
	std::cout << std::dec << "\n";
}
int main () {
	Block block("abcdabcdabcdabcd");

	dbg(block);

	std::cout << std::hex << static_cast<int>(block.bytes[3][2]);

}
