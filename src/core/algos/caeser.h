#pragma once

#include <string>

namespace Caeser {
	std::string encrypt(std::string input, std::string key);
	std::string decrypt(std::string input, std::string key);	
}
