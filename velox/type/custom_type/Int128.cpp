#include "velox/type/custom_type/Int128.h"
#include "folly/Likely.h"
#include "velox/common/base/Exceptions.h"

namespace facebook::velox {
type::int128 checkedPlus(
    const type::int128& a,
    const type::int128& b,
    const char* typeName) {
  type::int128 result;
  bool overflow = type::add_overflow(a, b, &result);
  if (UNLIKELY(overflow)) {
    VELOX_ARITHMETIC_ERROR("{} overflow: {} + {}", typeName, a, b);
  }
  return result;
}

type::int128 checkedMinus(
    const type::int128& a,
    const type::int128& b,
    const char* typeName) {
  type::int128 result;
  bool overflow = type::sub_overflow(a, b, &result);
  if (UNLIKELY(overflow)) {
    VELOX_ARITHMETIC_ERROR("{} overflow: {} - {}", typeName, a, b);
  }
  return result;
}

} // namespace facebook::velox

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

namespace std {
double log(facebook::velox::type::int128 value) {
        return 0.0;
}
} // namespace std

facebook::velox::type::uint128::operator int128() const {
        return int128(this->hi_, this->lo_);
}