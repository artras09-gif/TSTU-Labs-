#include <iostream>

int main(){
    setlocale(LC_ALL,"Rus");
    int n;
    std::cout<< "Введите размерность : ";
    std::cin>> n;
    int** A = new int*[n];
    for(int i=0; i<n; i++){
        A[i] = new int[n];
    }
    int count = 1;
    for(int i=0; i<n; i++){
        if(i % 2==0){
            for(int j=0; j<n; j++){
                A[j][i] = count++;
            }
        }
        else{
            for(int j = n-1; j>=0; j--){
                A[j][i] = count++;
                }
            }
        }
    std::cout<< "Матрица : "<< std::endl;
    for( int i=0; i<n; i++){
        for( int j=0; j<n; j++){
            std::cout<< A[i][j] << " ";
        }
        std::cout<< std::endl;
    }
        for(int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    return 0;
    }
