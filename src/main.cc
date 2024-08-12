#include <iostream>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include "calendar.h"

using namespace std;

DEFINE_int32(year, -1, "arg year, range: [1900, 3000]");
DEFINE_int32(month, 0, "arg month");

int main(int argc, char** argv)
{
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  Calendar c;
  CHECK(FLAGS_year >= 1900 && FLAGS_year <= 3000) << "Years Arg out-of-range: [1900, 3000]";
  CHECK(FLAGS_month >= 0 && FLAGS_month <= 12) << "Month Arg out-of-range: [0, 12]";
  if (FLAGS_month == 0) {
    c.PrintYear(FLAGS_year);
  } else {
    c.PrintMonth(FLAGS_year, FLAGS_month);
  }
  return 0;
}
