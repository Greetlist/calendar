#include "calendar.h"

Calendar::Calendar() : week_day_index(0) {}


void Calendar::PrintYear(int year) {
  for (int i = 1; i <= 12; ++i) {
    PrintMonth(year, i);
  }
}

void Calendar::PrintMonth(int year, int month) {
  std::cout << "===========================================" << std::endl;
  ResetWeekDayIndex();
  CalcStartWeekDay(year, month);
  auto& v = IsLeapYear(year) ? leap_year_days : non_leap_year_days;
  PrintHeader(year, month);
  PrintDays(v[month-1]);
  std::cout << "===========================================" << std::endl;
}

void Calendar::PrintHeader(int year, int month) {
  std::cout << "<" << year << "> [" << month_str[month] << "]" << std::endl;
  std::cout << "Mon Tue Wed Thu Fri Sat Sun" << std::endl;
}

void Calendar::PrintDays(int days) {
  int line_count;
  if (days <= 28) {
    line_count = 4;
  } else if ((week_day_index >= 6 && days >= 30) || (week_day_index >= 5 && days >= 31)) {
    line_count = 6;
  } else {
    line_count = 5;
  }
  int start_day = 1;

  std::string first_line;
  for (int i = 0; i < week_day_index; ++i) {
    first_line += "    ";
  }
  for (int i = week_day_index; i < 7; ++i) {
    std::string date_str = std::to_string(start_day++);
    first_line += std::string(static_cast<int>(3 - date_str.size()), ' ') + date_str + " ";
  }
  std::cout << first_line << std::endl;

  for (int i = 1; i <= line_count-2; ++i) {
    std::string line_str;
    for (int j = 1; j <= 7; ++j) {
      //std::cout << i << " " << j << " " << start_day << std::endl;
      std::string date_str = std::to_string(start_day++);
      line_str += std::string(static_cast<int>(3 - date_str.size()), ' ') + date_str + " ";
    }
    std::cout << line_str << std::endl;
  }
  std::string last_line;
  for (; start_day <= days;) {
    std::string date_str = std::to_string(start_day++);
    last_line += std::string(static_cast<int>(3 - date_str.size()), ' ') + date_str + " ";
  }
  std::cout << last_line << std::endl;
}

void Calendar::CalcStartWeekDay(int year, int month) {
  for (int i = min_years; i < year; ++i) {
    int day_count = IsLeapYear(i) ? 366 : 365;
    week_day_index = (week_day_index + day_count) % 7;
  }

  auto& v = IsLeapYear(year) ? leap_year_days : non_leap_year_days;
  for (int i = 1; i < month; ++i) {
    week_day_index = (week_day_index + v[i-1]) % 7;
  }
}

int Calendar::GetWeekDayIndex() {
  return week_day_index;
}

bool Calendar::IsLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    return true;
  }
  return false;
}

void Calendar::ResetWeekDayIndex() {
  week_day_index = 0;
}
