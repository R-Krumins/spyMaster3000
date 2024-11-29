#include <cmath>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <map>
#include "spymaster.h"

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
			std::string msg = std::string(spec.name) + " key lenght must be " + std::to_string(spec.keySize);  
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
