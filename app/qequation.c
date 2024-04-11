
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "qequation.h"

void solveQuadraticEquation(double a, double b, double c, double* x1, double* x2, int* errorCode) {

    if (a == 0 && b == 0 && c == 0){
        *errorCode = 1;
        return;
    }

    if (a == 0 && b == 0){
         *errorCode = 1;
         return;
    }

    if (a == 0) {
        *x1 = *x2 = -c/b;
        *errorCode = 0;
        return;
    }

    double d = b*b - 4 * a * c;

    if (d < 0) {
        *errorCode = 1;
        return;
    }
    if (d == 0) {
        *x1 = *x2 = (-b) / (2 * a);
        *errorCode = 0;
        return ;
    }
    *x1 = ((-b) + sqrt(d)) / (2 * a);
    *x2 = ((-b) - sqrt(d)) / (2 * a);
    *errorCode = 0;
    return;
}

void printQuadraticEquationSolution(double a, double b, double c) {

    if (a == 0 && b == 0 && c == 0){
        printf("%s", "All coefficients are equal zero\n");
        return;
    }

    if (a == 0 && b == 0){
         printf("%s", "A and B coefficients are equal zero\n");
         return;
    }

    double x1, x2;

    if (a == 0) {
        x1 = -c/b;
        printf("%s %.2f%s", "Linear equation: x =", x1, "\n");
        return;
    }

    double d = b*b - 4 * a * c;

    if (d < 0) {
        printf("%s", "No real roots\n");
        return;
    }
    if (d == 0) {
        x1 = (-b) / (2 * a);
        printf("%s %.2f%s", "Two equal real roots: x1 = x2 =", x1, "\n");
        return;
    }
    x1 = ((-b) + sqrt(d)) / (2 * a);
    x2 = ((-b) - sqrt(d)) / (2 * a);
    printf("%s %.2f %s %.2f%s", "Two real roots: x1 =", x1, "x2 =", x2, "\n");
    return;
}

