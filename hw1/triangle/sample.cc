#include <stdio.h>
#include <string.h>

#include "sample.h"

#define MIN 1
#define MAX 200

char ans[100] = {0};

char* OutRange(int kind) {
    char ty[] = "a";
    ty[0] += kind;
    strcpy(ans, "Value of ");
    strcat(ans, ty);
    strcat(ans, " is not in the range of permited values");
    return ans;
}

char* Msg(const char* s) {
    strcpy(ans, s);
    return ans;
}

char* IsTriangle(int a, int b, int c) {
    // check the value range
    if (a < MIN || a > MAX) return OutRange(0);
    if (b < MIN || b > MAX) return OutRange(1);
    if (c < MIN || c > MAX) return OutRange(2);
    // check can make a triangle or not
    if ((a < (b + c)) && (b < (a + c)) && (c < (a + b))) {
        // check the triangle type
        if (a == b && b == c) return Msg("Equilateral");
        else if (a == b || b == c || a == c) return Msg("Isosceles");
        else return Msg("Scalene");
    }
    else return Msg("Not a triangle");
}

