#pragma once

struct datetime {
  int year, month, day;
  int error;
  datetime(int y = 1900, int m = 1, int d = 1, int e = 0) : year(y), month(m), day(d), error(e) {}
};

datetime NextDate(int year, int month, int day);

int cmp_date(datetime a, datetime b);
