#include <iostream>
#include <cstring>

struct STUDENT {
    char fio[50];
    char group[20];
    int grades[5];
};

int main() {
    setlocale(LC_ALL, "Rus");
    
    const int SIZE = 10;
    STUDENT students[SIZE];
    
    std::cout << "Введите данные о " << SIZE << " студентах:\n" << std::endl;
    
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Студент №" << i + 1 << std::endl;
        
        std::cout << "  Фамилия и инициалы: ";
        std::cin.getline(students[i].fio, 50);
        
        std::cout << "  Номер группы: ";
        std::cin.getline(students[i].group, 20);
        
        std::cout << "  5 оценок через пробел: ";
        for (int j = 0; j < 5; j++) {
            std::cin >> students[i].grades[j];
        }
        std::cin.ignore(); 
        std::cout << std::endl;
    }
    
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (strcmp(students[j].fio, students[j + 1].fio) > 0) {
                STUDENT temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    std::cout << "\n--- Студенты по алфавиту ---" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << students[i].fio << " | группа " << students[i].group << std::endl;
    }

    std::cout << "\n--- Студенты с оценкой 2 ---" << std::endl;
    bool found = false;
    
    for (int i = 0; i < SIZE; i++) {
        bool hasTwo = false;
        for (int j = 0; j < 5; j++) {
            if (students[i].grades[j] == 2) {
                hasTwo = true;
                break;
            }
        }
        if (hasTwo) {
            std::cout << students[i].fio << " | группа " << students[i].group << std::endl;
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "Таких студентов нет." << std::endl;
    }
    
    return 0;
}
