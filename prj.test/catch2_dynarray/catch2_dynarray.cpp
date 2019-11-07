#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <dynarray/dynarray.h>
#include  <limits>

constexpr std::ptrdiff_t big_size = std::ptrdiff_t(std::numeric_limits<int>::max()) + 1;

TEST_CASE("DynArray<int> ctor", "[dynarray]") {
CHECK(0 == DynArray<int>().size());
CHECK(15 == DynArray<int>(15).size());
CHECK(big_size == DynArray<int>(big_size).size());

DynArray<int> ar(10);
CHECK(ar[0] == Approx(0.0f));
CHECK(ar[ar.size() - 1] == Approx(0.0f));
}

TEST_CASE("DynArray<int> copy ctor", "[dynarray]") {
DynArray<int> ar(10);
for (int i(0); i < ar.size(); i += 1) {
ar[i] = float(i);
}
DynArray<int> ar_copy(ar);
CHECK(ar.size() == ar_copy.size());
for (int i(0); i < ar.size(); i += 1) {
CHECK(ar[i] == ar_copy[i]);
}
for (int i(0); i < ar.size(); i += 1) {
ar[i] += 0.5f;
}
for (int i(0); i < ar.size(); i += 1) {
CHECK(ar[i] != ar_copy[i]);
}
}

TEST_CASE("DynArray<int> operator=", "[dynarray]") {
DynArray<int> ar(10);
for (int i(0); i < ar.size(); i += 1) {
ar[i] = float(i);
}
// check self assignment
ar = ar;
for (int i(0); i < ar.size(); i += 1) {
CHECK(ar[i] == float(i));
}

DynArray<int> ar_copy;
CHECK(ar.size() != ar_copy.size());
ar_copy = ar;
for (int i(0); i < ar.size(); i += 1) {
CHECK(ar[i] == ar_copy[i]);
}
for (int i(0); i < ar.size(); i += 1) {
ar[i] += 0.5f;
}
for (int i(0); i < ar.size(); i += 1) {
CHECK(ar[i] != ar_copy[i]);
}

DynArray<int> ar100(100);
for (int i(0); i < ar100.size(); i += 1) {
ar100[i] = float(i);
}
ar_copy = ar100;
for (int i(0); i < ar.size(); i += 1) {
CHECK(ar100[i] == ar_copy[i]);
}

}

TEST_CASE("DynArray<int> operator[]", "[dynarray]") {
DynArray<int> ar(10);
CHECK_NOTHROW(ar[0]);
CHECK_NOTHROW(ar[ar.size() - 1]);
CHECK_THROWS(ar[-1]);
CHECK_THROWS(ar[ar.size()]);
const auto& car = ar;
CHECK_NOTHROW(car[0]);
CHECK_NOTHROW(car[car.size() - 1]);
CHECK_THROWS(car[-1]);
CHECK_THROWS(car[car.size()]);
}

TEST_CASE("DynArray<int> resize()", "[dynarray]") {
DynArray<int> ar(10);
for (int i(0); i < ar.size(); i += 1) {
ar[i] = float(i);
}
ar.resize(5);
for (int i(0); i < ar.size(); i += 1) {
CHECK(ar[i] == float(i));
}
ar.resize(25);
for (int i(0); i < 5; i += 1) {
CHECK(ar[i] == float(i));
}
for (int i(5); i < 25; i += 1) {
CHECK(ar[i] == 0.0f);
}
}
