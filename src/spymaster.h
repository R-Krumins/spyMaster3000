#pragma once

#include <map>
#include <string>

constexpr int INFINITE_LEN = -1;

typedef std::string(*EncryptFunc)(std::string, std::string);
typedef	std::string(*DecryptFunc)(std::string, std::string);

enum class Algo { AES128, AES192, AES256, DES, TDES_2KEY, TDES_3KEY, PLAYFAIR, CAESER };

struct AlgoSpec {
	const char* name;
	const int keySize; 
	const int blockSize; 
	EncryptFunc encrypt_ptr;
	DecryptFunc decrypt_ptr;
	AlgoSpec(const char* n, int k, int b): name(n), keySize(k), blockSize(b) {};
};

const std::map<Algo, AlgoSpec> algoSpecs = {
	{Algo::AES128, AlgoSpec("AES128", 128, 128)},
	{Algo::AES192, AlgoSpec("AES192", 192, 128)},
	{Algo::AES256, AlgoSpec("AES256", 256, 128)},
	{Algo::DES, AlgoSpec("AES256", 64, 64)},
	{Algo::TDES_2KEY, AlgoSpec("Triple DES 2Key",128, 64)},
	{Algo::TDES_3KEY, AlgoSpec("Triple DES 2Key", 192, 64)},
	{Algo::PLAYFAIR, AlgoSpec("Playfair", 26, INFINITE_LEN)},
	{Algo::CAESER, AlgoSpec("Caeser", INFINITE_LEN, INFINITE_LEN)},
};






