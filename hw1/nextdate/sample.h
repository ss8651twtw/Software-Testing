#pragma once

struct datetime {
  int year, month, day;
  datetime(int y = 1812, int m = 1, int d = 1) : year(y), month(m), day(d) {}
  int cmp(const datetime* a, const datetime* b) {
    return (a->year == b->year && a->month == b->month && a->day == b->day);
  }
};

datetime NextDate(int year, int month, int day);
