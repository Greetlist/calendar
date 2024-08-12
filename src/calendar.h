#ifndef __CALENDAR_
#define __CALENDAR_

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

class Calendar {
public:
  Calendar();
  ~Calendar() = default;
  void PrintYear(int year);
  void PrintMonth(int year, int month);
  inline int GetWeekDayIndex();
private:
  void PrintHeader(int year, int month);
  void PrintDays(int days);
  void CalcStartWeekDay(int year, int month);
  inline bool IsLeapYear(int year);
  inline void ResetWeekDayIndex();
  int week_day_index;
  int min_years = 1900;
  int max_years = 3000;
  std::vector<int> leap_year_days{31,29,31,30,31,30,31,31,30,31,30,31};
  std::vector<int> non_leap_year_days{31,28,31,30,31,30,31,31,30,31,30,31};
  std::unordered_map<int, std::string> month_str{
    {1, "January"}, {2, "February"}, {3, "March"}, {4, "April"},
    {5, "May"}, {6, "June"}, {7, "July"}, {8, "August"},
    {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}
  };
};

#endif

