#include <iostream>
#include <cstdlib>

int main()
{
    int arr[10];
    for (int i=0; i<10; ++i)
    {
        arr[i] = rand()%(3-(-15)+1)+(-15);
        std::cout<< arr[i]<< std::endl;//-15 до 3
    }
    std::cout<< "Результаты Вычислений: "<<std::endl;
    int fac = 1;
     for (int i=0; i<10; ++i)
     {
         fac*=(i+1);
         arr[i]=arr[i]+fac;
         std::cout<< arr[i] <<std::endl;
     }
}
