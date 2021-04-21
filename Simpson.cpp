//
// Created by vadim on 20.04.2021.
//

#include "Simpson.h"

Simpson::Simpson(double (*user_f)(double)) : _user_f(user_f) {}

double Simpson::Calc(double a, double b, double eps, int n) {
    double h = (b - a) / n;
    double s0 = _user_f(a) + _user_f(b),
            s1 = 0,
            s2 = 0;

    for (int i = 1; i <= n / 2; i++)
        s1 += _user_f(a + (2 * i - 1) * h);

    for (int i = 1; i < n / 2; i++)
        s2 += _user_f(a + 2 * i * h);

    double i1, i2 = h / 3 * (s0 + 4 * s1 + 2 * s2);

    do {
        i1 = i2;
        n *= 2;
        h = (b - a) / n;
        s2 = s1 + s2;
        s1 = 0;
        for (int i = 1; i <= n / 2; i++)
            s1 += _user_f(a + (2 * i - 1) * h);
        i2 = h / 3 * (s0 + 4 * s1 + 2 * s2);
    } while (fabs(i2 - i1) >= 15.0 / 16.0 * eps);
    return i2;
}
