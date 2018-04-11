#include <stdio.h>
#include <string.h>

#include "sample.h"

#define MAXY 2018
#define MINY 1918
#define MAXM 12
#define MINM 1

char ans[100];

char* OutRange(int year) {
    char ty[15] = {0};
    sprintf(ty, "%d", year);
    strcpy(ans, ty);
    strcat(ans, " is over");
    return ans;
}

char* Msg(datetime x, int error) {
    if (error) strcpy(ans, "Cannot have ");
    else strcpy(ans, "Tomorrow's date is ");
    char ty[15] = {0};
    sprintf(ty, "%04d %02d %02d", x.year, x.month, x.day);
    strcat(ans, ty);
    return ans;
}

// check the year is leap year or not
int IsLeap(int year) {
    if (year % 4) return 0;
    if (year % 4 == 0 && year % 100) return 1;
    if (year % 100 == 0 && year % 400) return 0;
    if (year % 400 == 0) return 1;
}

char* NextDate(int year, int month, int day) {
    memset(ans, 0, sizeof(ans));
    datetime next(year, month, day);
    // check year is over
    if (year < MINY || year > MAXY) return OutRange(year);
    // check month is valid
    if (month < MINM || month > MAXM) return Msg(next, 1);
    // check day is large than zero
    if (day < 1) return Msg(next, 1);
    int leapyear = IsLeap(year);
    switch (month) {
        // M2 case
        case 1: case 3: case 5: case 7: case 8: case 10:
            if (day < 31) next.day++;
            else if (day == 31) {
                next.day = 1;
                next.month++;
            }
            else return Msg(next, 1);
            break;
        // M1 case
        case 4: case 6: case 9: case 11:
            if (day < 30) next.day++;
            else if (day == 30){
                next.day = 1;
                next.month++;
            }
            else return Msg(next, 1);
            break;
        // M3 case
        case 12:
            if (day < 31) next.day++;
            else if (day == 31) {
                next.day = 1;
                next.month = 1;
                next.year++;
                if (next.year > MAXY) return OutRange(next.year);
            }
            else return Msg(next, 1);
            break;
        // M4 case
        case 2:
            if (day < 28) next.day++;
            else {
                if (day == 28) {
                    if (leapyear) next.day++;
                    else {
                        next.day = 1;
                        next.month++;
                    }
                }
                else if (day == 29) {
                    if (leapyear) {
                        next.day = 1;
                        next.month++;
                    }
                    else return Msg(next, 1);
                }
                else return Msg(next, 1);
            }
            break;
    }
    return Msg(next, 0);
}
