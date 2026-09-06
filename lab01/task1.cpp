#include <iostream>

int main()
{
    double n,x,y,t;
    std::cout<< "Вычисление стоимости поездки на дачу и обратно:" << std::endl;
    std::cout<< "Введите растояние до дачи - ";
    std::cin>> x; 
    std::cout<< "Введите расход бензина (л) на 100км - ";
    std::cin>> y; 
    std::cout<< "Введите цену литра бензина - ";
    std::cin>> n;
    t=(x/100)*y*2*n;
    std::cout<< "Цена поездки = " << t << std::endl;
    return 0;
}
