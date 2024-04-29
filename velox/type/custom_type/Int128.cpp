#include "velox/type/custom_type/Int128.h"

namespace facebook::velox::type {

int128 tryTo(folly::StringPiece sp) {
  return int128(0);
}

bool add_overflow(int128 a, int128 b, int128* result) {
	return true;
}
bool sub_overflow(int128 a, int128 b, int128* result) {
	return true;
}
bool mul_overflow(int128 a, int128 b, int64_t result) {
	return true;
}
bool mul_overflow(int128 a, int128 b, int128* result) {
	return true;
}
} // namespace facebook::velox::type

uint128::operator int128() const { return int128(this->hi_, this->lo_); }