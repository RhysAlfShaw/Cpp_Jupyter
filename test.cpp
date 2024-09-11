#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

double integral(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}
int main() {

    std::cout << "Hello, World!" << std::endl;

    auto f = [](double x) { return std::sin(x); };
    double pi = 3.14159265358979323846;
    std::cout << integral(f, 0, pi, 100) << std::endl;
    return 0;
}