#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    int n, m;
    std::cout << "Введите количество строк (n): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;

    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    std::cout << "\nСгенерированная матрица:\n";
    int maxVal = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
        {
            matrix[i][j] = std::rand() % 11; 
            if (matrix[i][j] > maxVal) 
            {
                maxVal = matrix[i][j];
            }
           std::cout << matrix[i][j] << "\t"; 
        }
        std::cout << std::endl;
    }

  
    std::cout << "\nНаибольшее значение: " << maxVal << std::endl;
    std::cout << "Индексы (строка, столбец) элементов с этим значением:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == maxVal) {
                std::cout << "(" << i+1 << ", " << j+1 << ") ";
            }
        }
    }
    std::cout << std::endl;

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
