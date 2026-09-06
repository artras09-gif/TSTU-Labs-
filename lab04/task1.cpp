#include <iostream>


long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


double calcMember(int n) {
    long long factN = factorial(n);
    long long factN1 = factorial(n + 1);
    
    long long numerator = factN * factN;
    double denominator = 1.0 + factN1;
    
    return numerator / denominator;
}


double calcSum(int count) {
    double sum = 0.0;
    
    std::cout << "Члены ряда:" << std::endl;
    
    for (int n = 1; n <= count; n++) {
        double member = calcMember(n);
        sum += member;
        std::cout << member << std::endl;
    }
    
    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");
    
    int count = 10;
    
    std::cout << "Суммируем " << count << " членов ряда" << std::endl;
    
    double sum = calcSum(count);
    
    std::cout << "Сумма = " << sum << std::endl;
    
    return 0;
}
