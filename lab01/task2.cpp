#include <iostream>

int main()
{
    double x,y;
    std::cout<< "Введите число: ";
    std::cin>> x;
    if(x>0)
    {
        ++x;
    }
    else if(x<0)
    {
        x=x-2;
    }
    else
    {
        x=10;
    }
    std::cout<< "Ваше число: "<< x << std::endl;
    return 0;
}
