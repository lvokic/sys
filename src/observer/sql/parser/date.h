#pragma once

#include <string>

const int kYearBegin = 1970;
const int kYearEnd = 2038;
const int kYearCount = kYearEnd - kYearBegin + 1;
const int kMonthCount = 12;
const int kSecondsInDay = 24 * 60 * 60;

class Date {
public:
    /// @brief 存储时间戳
    int value;
    auto operator<=>(const Date &o) const = default;
    Date(const std::string &s, const std::string &format = "%F");   // "%F"表示日期的完整格式，包括年份、月份和日期，例如"2022-05-01"。
    Date(int val) : value(val) {}
    Date() = default;
    static std::string to_string(const Date &date, const std::string &format = "%F");
    static int compare_date(const Date *a, const Date *b);
};
const Date INVALID_DATE(-1);