#include <array>
#include <string>

namespace sha256 {
	std::array<uint8_t, 32> hash(std::string input);
}
