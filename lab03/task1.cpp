#include <iostream>
#include <cstdlib>  
#include <cmath> 

int main()
{
    int n,i;
    srand(time(0));
    std::cout<<"Введите размерность матрицы A: ";
    std::cin>> n;
    int A[n];
    double Z[n];
    std::cout<< "Матрица A: "<<std::endl;
    for(i=0; i<n; ++i)
    {
        A[i]=rand()%(19-(-8)+1)-8;
        
        std::cout<< A[i]<< "\n";
        
        if(fabs(A[i])>=1)
        {
            Z[i]=A[i];
        }
        else
        {
            Z[i]=2.5;
        }
        
    }
    std::cout<< "Матрица Z: "<< std::endl;
    double min=fabs(Z[0]);
    for(i=0; i<n; ++i)
    {
        std::cout<< Z[i]<< "\n";
        if(min>fabs(Z[i]))
        {
            min=fabs(Z[i]);
        }
        
    }
    std::cout<< "Минимум из Z Матрицы: "<<min;
    
    
    return 0;
}
