#include <stdio.h>

double integrate(double (*f)(double),float n1,float n2) {
    double step = 0.001, sum=0.0;
    for (double x=n1; x<n2; x+=step){
        sum += f(x)*step;//x^2*step
    }
    return sum;
// ...
}

double square(double x) {
    return x*x;
}

int main() {
    printf("integrate(square, 0.0, 2.0)=%f\n", integrate(square, 0.0, 2.0));  // 1/3 x^3
}
