#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class LongInt {
public:
    LongInt() { num.push_back(0); }
   // LongInt(const LongInt& new_num);
    explicit LongInt(const std::string& st);
    LongInt(int64_t new_num);
    LongInt& operator=(const LongInt& second);
    LongInt operator-() const;
    ~LongInt() = default;


    LongInt& operator+=(const LongInt& second);
    LongInt& operator-=(const LongInt& second);
    LongInt& operator*=(const LongInt& second);
    LongInt& operator/=(const LongInt& second);
    LongInt&operator%=(const LongInt& second);

    bool operator<(const LongInt& second) const;
    bool operator>(const LongInt& second) const;
    bool operator<=(const LongInt& second) const;
    bool operator>=(const LongInt& second) const;
    bool operator==(const LongInt& second) const;
    bool operator!=(const LongInt& second) const;

    friend std::ostream& operator<<(std::ostream& out, const LongInt& long_num);
    friend LongInt operator+(const LongInt& first, const LongInt& second);
    friend LongInt operator-(const LongInt& first, const LongInt& second);
    friend LongInt operator*(const LongInt& first, const LongInt& second);
    friend LongInt operator/(const LongInt& first, const LongInt& second);
    friend LongInt operator*(const LongInt& first, const int64_t second);
    friend LongInt operator%(const LongInt& first, const LongInt& second);

private:
    static const int BASE = 1000;
    std::vector<int> num;
    bool is_negative = false;

    void delete_zeroes();
    std::pair<LongInt, LongInt> DivAndMod(const LongInt& first, const LongInt& second) const;
    static bool from_string(const std::string& str, LongInt& value);
    std::string to_string() const;

};

std::istream& operator>>(std::istream& in, LongInt& num);