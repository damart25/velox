/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * Simple data structure for representing 128-bit numbers as 2 64-bit integers.
 */

#ifndef TYPE_INT128_H__
#define TYPE_INT128_H__

#include <stdint.h>
#include <utility>
#include <cmath>
#include <boost/multiprecision/number.hpp>
#include <folly/hash/Hash.h>

// #ifndef DUCK_DB
 //#include <folly/dynamic.h>
// #endif



namespace facebook::velox::type {
using int128_t = boost::multiprecision::int128_t;

bool mul_overflow(int128_t a , int128_t b ,int64_t result) {
  return true;
}
bool add_overflow(int128_t a , int128_t b ,int128_t* result) {
  return true;

}bool sub_overflow(int128_t a , int128_t b ,int128_t* result) {
  return true;

}
bool mul_overflow(int128_t a , int128_t b ,int128_t *result) {
  return true;

} // namespace facebook


} // namespace facebook::velox::type

 namespace std {

// template <>
// struct is_pod<facebook::velox::type::int128> : std::true_type {};

 template <>
 struct hash<boost::multiprecision::uint128_t> {
   // TODO: davidmar implement hashing operation for 128 bits.
  size_t operator()(const boost::multiprecision::uint128_t& obj) const {
     return 0;
   }
 };
 template <>
 struct hash<boost::multiprecision::int128_t> {
   // TODO: davidmar implement hashing operation for 128 bits.
   size_t operator()(const boost::multiprecision::int128_t& obj) const {
     return 0;
   }
 };

// // TODO: add std::make_unsiged capabilities
// template <>
// struct make_unsigned<facebook::velox::type::int128> {
//   using type = facebook::velox::type::uint128; 
// };
// // TODO: add std::make_unsiged capabilities
// template <>
// struct make_unsigned<facebook::velox::type::uint128> {
//   using type = facebook::velox::type::uint128; 
// };
// // TODO: add std::make_signed capabilities
// template <>
// struct make_signed<facebook::velox::type::uint128> {
//   using type = facebook::velox::type::int128; 
// };
// // TODO: Implemente std::log for int128 
// double log(facebook::velox::type::int128 value) {
//   return 0.0;
// }


 } // namespace std
// #ifndef DUCK_DB
namespace folly {
using b_int128_t = boost::multiprecision::int128_t;
using b_uint128_t = boost::multiprecision::uint128_t;

template <>
struct hasher<b_int128_t> : detail::integral_hasher<b_int128_t> {
   std::size_t operator()(const b_int128_t& obj) const {
     return 0;
   }
};

template <>
struct hasher<b_uint128_t> : detail::integral_hasher<b_uint128_t> {
   std::size_t operator()(const b_uint128_t& obj) const {
     return 0;
   }
};
} // namespace folly

//Can't expand functionality of boost::multiprecision::number as include also initialize an object before being able to update it.

//template <>
//struct boost::multiprecision::number<boost::multiprecision::cpp_int_backend<
//    128,
//    128,
//    boost::multiprecision::signed_magnitude,
//    boost::multiprecision::unchecked,
//    void>> {
//   operator folly::dynamic() const {
//     folly::dynamic dynamicobject = folly::dynamic::object;
//     dynamicobject["lo"] = 0;
//     dynamicobject["hi"] = 1;
//     return dynamicobject;
//   }
//}


namespace folly {

using b_int128_t = boost::multiprecision::int128_t;
using b_uint128_t = boost::multiprecision::uint128_t;

template <>
struct is_arithmetic<b_int128_t> : std::true_type {};
template <>
struct is_arithmetic<b_uint128_t> : std::true_type {};

template <>
struct is_integral<b_int128_t> : std::true_type {};
template <>
struct is_integral<b_uint128_t> : std::true_type {};

template <>
struct is_signed<b_int128_t> : std::true_type {};
template <>
struct is_signed<b_uint128_t> : std::false_type {};
template <>
struct is_unsigned<b_int128_t> : std::false_type {};
template <>
struct is_unsigned<b_uint128_t> : std::true_type {};

template <>
struct make_signed<b_int128_t> {
   using type = int128_t;
};
template <>
struct make_signed<b_uint128_t> {
   using type = int128_t;
};

template <>
struct make_unsigned<b_int128_t> {
   using type = uint128_t;
};
template <>
struct make_unsigned<b_uint128_t> {
   using type = uint128_t;
};

}
#endif /* TYPE_INT128_H__ */
