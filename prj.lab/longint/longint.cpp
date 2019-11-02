#include "longnum.h"

#include <algorithm>
#include <cmath>

void LongInt::delete_zeroes() {
    int how_much = 0;
    while (num[num.size() - 1] == 0 and how_much < num.size() - 1) {
        num.pop_back();
    }
}

LongInt::LongInt(int64_t new_num) {
    if (new_num < 0) {
        is_negative = true;
        new_num *= -1;
    }

    new_num = abs(new_num);
    while(new_num > 0) {
        num.push_back(new_num % BASE);
        new_num /= BASE;
    }
}

LongInt& LongInt::operator=(const LongInt &second) {
    num = second.num;
    is_negative = second.is_negative;

    return *this;
}

LongInt::LongInt(const std::string& st) {
    bool res = from_string(st, *this);
    if (!res) {
        throw std::invalid_argument("bad string in  constructor");
    }
}

std::string LongInt::to_string() const {
    int len_base = std::to_string(BASE).size() - 1;
    bool is_first = true;
    std::string res = "";
    if (is_negative) {
        res += "-";
    }

    for (int i = num.size() - 1; i > -1; --i) {
        std::string st = std::to_string(num[i]);
        if (st.size() < len_base && !is_first) {
            int finish = st.size();
            for (int k = 0; k < len_base - finish; ++k) {
                st = "0" + st;
            }
        }

        is_first = false;
        res += st;
    }

    return res;
}

bool LongInt::from_string(const std::string &str, LongInt &value) {
    if (str.size() == 0) {
        return false;
    }

    int pos_last = 0;
    if (str[0] == '-') {
        value.is_negative = true;
        pos_last = 1;
    }

    int step = std::to_string(BASE).size() - 1;
    for (int i = str.size(); i > pos_last; i -= step) {
        int start = i - step < 0 ? 0 : i - step;
        int finish = i < step ? i : step;

        std::string now_num = str.substr(start, finish);
        for (int j = 0; j < now_num.size(); ++j) {
            if (now_num[j] < '0' || now_num[j] > '9') {
                return false;
            }
        }

        value.num.push_back(abs(stoi(now_num)));
    }

    return true;
}

std::istream& operator>>(std::istream& in, LongInt& num)  {
    std::string s;
    in >> s;
    num = LongInt(s);

    return in;
}

std::ostream& operator<<(std::ostream &out, const LongInt& long_num) {
    out << long_num.to_string();
    return out;
}

bool LongInt::operator==(const LongInt &second) const {
    if ((num.size() != second.num.size()) || (is_negative != second.is_negative)) {
        return false;
    }

    for (size_t i = 0; i < second.num.size(); ++i) {
        if (num[i] != second.num[i]) {
            return false;
        }
    }

    return true;
}

bool LongInt::operator!=(const LongInt &second) const {
    return !(operator==(second));
}

bool LongInt::operator<(const LongInt &second) const {
    if (second.is_negative && !is_negative) {
        return false;
    } else if (!second.is_negative && is_negative) {
        return true;
    } else if (second.num.size() != num.size()) {
        return !is_negative ? num.size() < second.num.size() : num.size() > second.num.size();
    } else {
        for (int i = num.size() - 1; i > -1; --i) {
            if (num[i] != second.num[i]) {
                return !is_negative ? num[i] < second.num[i] : num[i] > second.num[i];
            }
        }
    }

    return false;
}

bool LongInt::operator>(const LongInt &second) const {
    return (*this != second) && !(*this < second);
}

bool LongInt::operator>=(const LongInt &second) const {
    return (*this == second) || (*this > second);
}

bool LongInt::operator<=(const LongInt &second) const {
    return (*this == second) || (*this < second);
}

LongInt LongInt::operator-() const {
    LongInt res = *this;
    res.is_negative = !is_negative;
    return res;
}

LongInt operator+(const LongInt& first, const LongInt& second) {
    if (first.is_negative && !second.is_negative) {
        return second - (-first);
    } else if (!first.is_negative && second.is_negative) {
        return first - (-second);
    }

    int now_s = 0;

    LongInt res = second > first ? second : first;
    const LongInt& min_num = second < first ? second : first;
    for (int i = 0; i < min_num.num.size(); ++i) {
        now_s = now_s + res.num[i] + min_num.num[i];
        res.num[i] = now_s % res.BASE;
        now_s /= res.BASE;
    }

    if (now_s != 0) {
        res.num.push_back(now_s);
    }

    return res;
}

LongInt operator-(const LongInt& first, const LongInt& second) {
    if ((!first.is_negative && second.is_negative) || (first.is_negative && !second.is_negative)) {
        return first + (-second);
    }

    if (second.num.size() > first.num.size()
        || (second.num.size() == first.num.size() && second.num[second.num.size() - 1] > first.num[first.num.size() - 1])
       )
    {
        return -(second - first);
    }

    LongInt res_num = first;

    int prev_diff = 0;
    for (int i = 0; i < res_num.num.size() && i < second.num.size(); ++i) {
        int res = res_num.num[i] - second.num[i] - prev_diff;
        if (res < 0) {
            res += res_num.BASE;
            prev_diff = res_num.BASE;
        } else {
            prev_diff = 0;
        }

        res_num.num[i] = res;
    }

    res_num.delete_zeroes();

    return res_num;
}

LongInt operator*(const LongInt& first, const LongInt& second) {
    LongInt res;

    for (int i = 0; i < second.num.size(); ++i) {
        LongInt now;
        now.num.pop_back();
        for (int j = 0; j < i; ++j) {
            now.num.push_back(0);
        }

        int ost = 0;
        for (int j = 0; j < first.num.size(); ++j) {
            int arg = first.num[j]*second.num[i] + ost;
            ost = arg / first.BASE;
            now.num.push_back(arg % first.BASE);
        }
        if (ost != 0) {
            now.num.push_back(ost);
        }
        res += now;
    }

    res.is_negative = first.is_negative != second.is_negative;
    res.delete_zeroes();

    return res;
}

LongInt operator*(const LongInt& first, const int64_t second) {
    LongInt res;
    res.num.pop_back();
    int ost = 0;
    for (int j = 0; j < first.num.size(); ++j) {
        int arg = first.num[j]*abs(second) + ost;
        ost = arg / first.BASE;
        res.num.push_back(arg % first.BASE);
    }
    if (ost != 0) {
        res.num.push_back(ost);
    }

    res.is_negative = first.is_negative != second < 0;
    res.delete_zeroes();

    return res;
}

std::pair<LongInt, LongInt> LongInt::DivAndMod(const LongInt& first, const LongInt& second) const{
    if (second == LongInt()) {
        throw std::invalid_argument("divide zero");
    }

    LongInt divided = first;
    LongInt res;
    LongInt dividerAbs = second;
    dividerAbs.is_negative = false;
    divided.is_negative = false;
    while (divided >= dividerAbs) {
        LongInt nowNum;
        nowNum.num.pop_back();
        for (int i = dividerAbs.num.size(); i > 0; --i) {
            nowNum.num.push_back(divided.num[divided.num.size() - i]);
        }
        if (nowNum < dividerAbs) {
            nowNum = nowNum * nowNum.BASE + divided.num[divided.num.size() - nowNum.num.size() - 1];
        }

        int64_t start = 1, finish = divided.BASE + 1;
        while (finish - start > 1) {
            int64_t mid = (start + finish) / 2;
            if (dividerAbs * mid <= nowNum) {
                start = mid;
            } else {
                finish = mid;
            }
        }

        res.num.push_back(start);
        nowNum = nowNum - dividerAbs * start;
        for (int i = nowNum.num.size(); i < divided.num.size() - nowNum.num.size(); ++i) {
            nowNum.num.push_back(divided.num[i]);
        }

        divided = nowNum;
    }

    reverse(res.num.begin(), res.num.end());
    res.delete_zeroes();
    res.is_negative = first.is_negative != second.is_negative;
    return std::make_pair(res, divided);
}

LongInt operator/(const LongInt& first, const LongInt& second) {
    return first.DivAndMod(first, second).first;
}

LongInt operator%(const LongInt& first, const LongInt& second) {
    return first.DivAndMod(first, second).second;
}

LongInt& LongInt::operator+=(const LongInt &second) {
    *this = *this + second;
    return *this;
}

LongInt& LongInt::operator-=(const LongInt &second) {
    *this = *this - second;
    return *this;
}

LongInt& LongInt::operator*=(const LongInt &second) {
    *this = *this * second;
    return *this;
}

LongInt& LongInt::operator /=(const LongInt &second) {
    *this = *this / second;
    return *this;
}

LongInt& LongInt::operator%=(const LongInt &second) {
    *this = *this % second;
    return *this;
}
