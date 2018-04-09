#include "sample.h"

int cmp_date(datetime a, datetime b) {
  if (a.error == 1 && b.error == 1)
    return 1;
  else if (a.error == 0 && b.error == 0)
    return (a.year == b.year && a.month == b.month && a.day == b.day);
  else
    return 0;
}

datetime NextDate(int year, int month, int day) {
  datetime next;
  return next;
}
