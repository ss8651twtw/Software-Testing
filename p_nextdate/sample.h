#pragma once

struct datetime {
    int year, month, day;
    datetime(int y = 1900, int m = 1, int d = 1) : year(y), month(m), day(d) {}
};

char* NextDate(int year, int month, int day);
