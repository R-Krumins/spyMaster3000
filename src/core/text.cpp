#include "text.h"
#include <cstdint>
#include <iomanip>
#include <iostream>

static const std::string base64_chars =
	           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	           "abcdefghijklmnopqrstuvwxyz"
	           "0123456789+/";

Text Text::fromASCII(const std::string& str) {
	return Text(std::vector<uint8_t>(str.begin(), str.end()));
}

Text Text::fromHex(const std::string& str) {
	std::vector<uint8_t> bytes;
	for(int i = 0; i < str.length(); i += 2) {
		std::string buff = str.substr(i, 2);	
		uint8_t byte = (uint8_t)std::stoi(buff.c_str(), NULL, 16);
		bytes.push_back(byte);
	}
	return Text(bytes);
}

static inline bool is_base64(uint8_t c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
}

//stole this from:
//stackoverflow.com/questions/180947/base64-decode-snippet-in-c
Text Text::fromBase64(std::string const& str) {
	int in_len = str.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	uint8_t char_array_4[4], char_array_3[3];
	std::vector<uint8_t> ret;

	while (in_len-- && ( str[in_] != '=') && is_base64(str[in_])) {
	  char_array_4[i++] = str[in_]; in_++;
	  if (i ==4) {
	    for (i = 0; i <4; i++)
	      char_array_4[i] = base64_chars.find(char_array_4[i]);

	    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
	    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
	    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

	    for (i = 0; (i < 3); i++)
	        ret.push_back(char_array_3[i]);
	    i = 0;
	  }
	}

	if (i) {
	  for (j = i; j <4; j++)
	    char_array_4[j] = 0;

	  for (j = 0; j <4; j++)
	    char_array_4[j] = base64_chars.find(char_array_4[j]);

	  char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
	  char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
	  char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

	  for (j = 0; (j < i - 1); j++) ret.push_back(char_array_3[j]);
	}

	return Text(ret);
}

std::string Text::toBase64() {
	std::string ret;
	int i = 0;
	int j = 0;
	uint8_t char_array_3[3];
	uint8_t char_array_4[4];
	uint8_t const* buf = &bytes[0];
	unsigned int bufLen = bytes.size();

	while (bufLen--) {
	  char_array_3[i++] = *(buf++);
	  if (i == 3) {
	    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
	    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
	    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
	    char_array_4[3] = char_array_3[2] & 0x3f;

	    for(i = 0; (i <4) ; i++)
	      ret += base64_chars[char_array_4[i]];
	    i = 0;
	  }
	}

	if (i)
	{
	  for(j = i; j < 3; j++)
	    char_array_3[j] = '\0';

	  char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
	  char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
	  char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
	  char_array_4[3] = char_array_3[2] & 0x3f;

	  for (j = 0; (j < i + 1); j++)
	    ret += base64_chars[char_array_4[j]];

	  while((i++ < 3))
	    ret += '=';
	}

	return ret;
}

std::string Text::toASCII() {
	return std::string(bytes.begin(), bytes.end());
}


std::string Text::toHex() {
	std::ostringstream output;
	for (uint8_t byte : bytes)
		output << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
	return output.str();
}

int Text::size() {
	return bytes.size();
}

int main() {
	Text text = Text::fromHex("0123455abd");
	std::cout << text.toBase64() << "\n";
}
