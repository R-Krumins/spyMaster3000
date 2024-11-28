#include <cmath>
#include <cstdint>
#include <map>
#include <stdexcept>
#include <string>

enum class Algo { AES128, AES192, AES256, DES, TDES_2KEY, TDES_3KEY, PLAYFAIR, CAESER };
struct AlgoSpec {
	const char* name;
	const int keySize; 
	const int blockSize; 
	AlgoSpec(char* n, int k, int b): name(n), keySize(k), blockSize(b) {};
};

constexpr int INFINITE = -1;
const std::map<Algo, AlgoSpec> algoSpecs = {
	{Algo::AES128, AlgoSpec("AES128", 128, 128)},
	{Algo::AES192, AlgoSpec("AES192", 192, 128)},
	{Algo::AES256, AlgoSpec("AES256", 256, 128)},
	{Algo::DES, AlgoSpec("AES256", 64, 64)},
	{Algo::TDES_2KEY, AlgoSpec("Triple DES 2Key",128, 64)},
	{Algo::TDES_3KEY, AlgoSpec("Triple DES 2Key", 192, 64)},
	{Algo::PLAYFAIR, AlgoSpec("Playfair", 26, INFINITE)},
	{Algo::CAESER, AlgoSpec("Caeser", INFINITE, INFINITE)},
};

struct AlgoArgs {
	Algo selectedAlgo;
	uint8_t* key = nullptr;
	int keySize = 0;
	std::string input;
};

class AlgoArgsBuilder {
private:
	AlgoArgs args;
	AlgoSpec spec;
public:
	AlgoArgsBuilder(Algo _selectedAlgo): spec(algoSpecs.at(_selectedAlgo)) {
		args.selectedAlgo = _selectedAlgo; 
	}

	void setKey(std::string keyStr) {
		bool isInvalidKeySize = keyStr.length() != spec.keySize 
			&& spec.keySize != -1; // -1 means infinite
		if(isInvalidKeySize) {
			std::string msg = algoNames.at(args.selectedAlgo) + " key lenght must be " + std::to_string(spec.keySize);  
			throw std::invalid_argument(msg);
		}

		args.key = (uint8_t*)keyStr.data();
		args.keySize = keyStr.length();
	}

	void setInput_PlainText(std::string _input) {
		args.input = _input;
	}

	AlgoArgs build() {
		if(args.key == nullptr) throw "Key is not given";
		if(args.input.empty()) throw "Input is not given";
		return args;
	}
};
