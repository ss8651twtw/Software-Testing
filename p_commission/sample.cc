#include <stdio.h>
#include <string.h>

#include "sample.h"

#define MINL 1
#define MAXL 70
#define MINS 1
#define MAXS 80
#define MINB 1
#define MAXB 90

#define PL 45
#define PS 30
#define PB 25

#define LEVEL1 1000
#define LEVEL2 1800

char ans[100] = {0};

char* Output(double x) {
    char ty[50] = {0};
    sprintf(ty, "%.6lf", x);
    strcpy(ans, "Commission is $");
    strcat(ans, ty);
    return ans;
}

char* Msg(const char* s) {
    strcpy(ans, s);
    return ans;
}

char* Commission(int lock, int stock, int barrel) {
    memset(ans, 0, sizeof(ans));
    // check lock, stock and barrel is valid
    if (lock < MINL || stock < MINS || barrel < MINB) {
        return Msg("Have to sell at least one lock, one stock, and one barrel");
    }
    if (lock > MAXL || stock > MAXS || barrel > MAXB) {
        return Msg("Exceed production limits");
    }
    // calculate commission by total sales
    double sales = lock * PL + stock * PS + barrel * PB;
    double commission = 0;
    if (sales > LEVEL2) commission = (sales - LEVEL2) * 0.2 + (LEVEL2 - LEVEL1) * 0.15 + LEVEL1 * 0.1;
    else if (sales > LEVEL1) commission = (sales - LEVEL1) * 0.15 + LEVEL1 * 0.1;
    else commission = sales * 0.1;
    return Output(commission);
}
