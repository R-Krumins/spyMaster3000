#pragma once

#include <cstdint>
#include <string>
#include <vector>

class Text {
public:
	Text();

//Factory methods
public:
	static Text fromASCII(const std::string& str);
	static Text fromHex(const std::string& str);
	static Text fromBase64(const std::string& str);

// Class methods
public:
	void pad(int blockSize);
	void unpad();
	int size();
	std::vector<uint8_t> getBytes();

	std::string toASCII();
	std::string toHex();
	std::string toBase64();

private:
	std::vector<uint8_t> bytes;

	Text(std::vector<uint8_t> _bytes): bytes(_bytes) {};
};
