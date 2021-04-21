//
// Created by vadim on 20.04.2021.
//

#ifndef INTEGRATE_SIMPSON_H
#define INTEGRATE_SIMPSON_H

#include <cmath>
#include <vector>

class Simpson {
    double (*_user_f)(double v);

public:
    explicit Simpson(double (*user_f)(double));
    double Calc(double a, double b, double eps, int n);
};


#endif //INTEGRATE_SIMPSON_H
