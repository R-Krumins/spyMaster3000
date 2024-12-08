#include <cstdint>
#include <cstring>
#include <iostream>
#include <string>
#include "../../util/memdebug.h"

typedef uint32_t word;
typedef uint8_t byte;


word rotr(word x, byte n) { 
	return (x >> n) | (x  << (32 - n)); 
}

word rotl(word x, byte n) { 
	return (x << n) | (x  >> (32 - n)); 
}

word ch(word x, word y, word z) {
	return (x & y) ^ (x & z); 
}

word maj(word x, word y, word z) {
	return (x & y) ^ (x & z) ^ (y & z); 
}

word SIGMA0(word x) {
	return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22); 
}

word SIGMA1(word x) {
	return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25); 
}

word sigma0(word x) {
	return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3); 
}

word sigma1(word x) {
	return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10); 
}

void pad(std::string& M) {
	uint64_t l = M.size() * 8;
	M.push_back(0x80);

	while (M.size() % 64 != 56) {
		std::cout << M.size() % 64 << "\n";
        M.push_back(0x00);
    }

	for (int i = 7; i >= 0; --i) {
		M.push_back((byte)((l >> (i * 8)) & 0xFF));
	}
}

void prepMsgSchedule(word* W, byte* M) {
	// Copy 16 words from M to W, ensuring big endian
	for (int i = 0, j = 0; i < 16; i++, j += 4) { 
		W[i] = (M[j] << 24)
			 | (M[j + 1] << 16)
			 | (M[j + 2] << 8)
			 | (M[j + 3]);
	}
	// Compute the other 48 words
    for(int t = 16; t < 64; t++) {
		W[t] =  W[t-16] + sigma0(W[t-15]) + W[t-7] + sigma1(W[t-2]);
	}
}
#include "../../../tests/fixture_sha256.cpp"
int main() {
	std::string msg = "abc";
	pad(msg);
	int blockCount = msg.size() / 64;
	byte* blocks = (byte*)msg.data();
	word W[64];
	prepMsgSchedule(W, blocks);


	MemDebugger<word> mem("hex");

	for(int i = 0; i < 64; i++) {
		std::cout << "W" << i << "\n";
		mem.compare(W[i], expected_W[i]);
	}
}
