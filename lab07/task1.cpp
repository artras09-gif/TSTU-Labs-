#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

using namespace std;

struct STUDENT {
    char fio[50];
    char group[20];
    int grades[5];
};

void inputStudents(STUDENT students[], int size) {
    cin.ignore(numeric_limits<streamsize>::max(), 10);

    for (int i = 0; i < size; i++) {
        cout << "Студент №" << i + 1 << endl;
        cout << "Фамилия и инициалы: ";
        cin.getline(students[i].fio, 50);

        cout << "Номер группы: ";
        cin.getline(students[i].group, 20);

        cout << "5 оценок через пробел: ";
        for (int j = 0; j < 5; j++) {
            while (!(cin >> students[i].grades[j])) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), 10);
                cout << "Ошибка. Введите оценку числом: ";
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), 10);
    }
}

void sortStudents(STUDENT students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(students[j].fio, students[j + 1].fio) > 0) {
                STUDENT temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void printStudents(const STUDENT students[], int size, ostream& out) {
    if (size <= 0) {
        out << "Нет данных для вывода." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        out << students[i].fio << " | группа " << students[i].group << " | оценки: ";
        for (int j = 0; j < 5; j++) {
            out << students[i].grades[j] << " ";
        }
        out << endl;
    }
}

void printStudentsWithTwo(const STUDENT students[], int size, ostream& out) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        bool hasTwo = false;

        for (int j = 0; j < 5; j++) {
            if (students[i].grades[j] == 2) {
                hasTwo = true;
                break;
            }
        }

        if (hasTwo) {
            out << students[i].fio << " | группа " << students[i].group << endl;
            found = true;
        }
    }

    if (!found) {
        out << "Таких студентов нет." << endl;
    }
}

void saveText(const STUDENT students[], int size, const char* fileName) {
    ofstream fout(fileName);
    fout << size << endl;

    for (int i = 0; i < size; i++) {
        fout << students[i].fio << endl;
        fout << students[i].group << endl;

        for (int j = 0; j < 5; j++) {
            fout << students[i].grades[j] << " ";
        }

        fout << endl;
    }
}

int loadText(STUDENT students[], int maxSize, const char* fileName) {
    ifstream fin(fileName);
    int size = 0;

    if (!fin || !(fin >> size) || size < 0) {
        return 0;
    }

    fin.ignore(numeric_limits<streamsize>::max(), 10);
    if (size > maxSize) size = maxSize;

    for (int i = 0; i < size; i++) {
        if (!fin.getline(students[i].fio, 50)) return i;
        if (!fin.getline(students[i].group, 20)) return i;

        for (int j = 0; j < 5; j++) {
            if (!(fin >> students[i].grades[j])) return i;
        }

        fin.ignore(numeric_limits<streamsize>::max(), 10);
    }

    return size;
}

void saveBinary(const STUDENT students[], int size, const char* fileName) {
    ofstream fout(fileName, ios::binary);
    fout.write((char*)&size, sizeof(size));
    fout.write((char*)students, sizeof(STUDENT) * size);
}

int loadBinary(STUDENT students[], int maxSize, const char* fileName) {
    ifstream fin(fileName, ios::binary);
    int size = 0;

    if (!fin.read((char*)&size, sizeof(size)) || size < 0) {
        return 0;
    }

    if (size > maxSize) size = maxSize;

    if (!fin.read((char*)students, sizeof(STUDENT) * size)) {
        return 0;
    }

    return size;
}

void saveResult(const STUDENT students[], int size, const char* fileName) {
    ofstream fout(fileName);
    fout << "--- Студенты по алфавиту ---" << endl;
    printStudents(students, size, fout);
    fout << endl << "--- Студенты с оценкой 2 ---" << endl;
    printStudentsWithTwo(students, size, fout);
}

int main() {
    setlocale(LC_ALL, "Rus");

    const int MAX_SIZE = 10;
    STUDENT students[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        cout << endl << "1. Ввести данные" << endl;
        cout << "2. Записать в текстовый файл" << endl;
        cout << "3. Прочитать из текстового файла" << endl;
        cout << "4. Записать в бинарный файл" << endl;
        cout << "5. Прочитать из бинарного файла" << endl;
        cout << "6. Вывести результат в файл" << endl;
        cout << "7. Показать студентов" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), 10);
            cout << "Ошибка. Введите номер пункта меню." << endl;
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1:
                inputStudents(students, MAX_SIZE);
                size = MAX_SIZE;
                sortStudents(students, size);
                break;

            case 2:
                saveText(students, size, "students.txt");
                cout << "Данные записаны в текстовый файл." << endl;
                break;

            case 3:
                size = loadText(students, MAX_SIZE, "students.txt");
                if (size > 0) {
                    cout << "Данные прочитаны из текстового файла." << endl;
                } else {
                    cout << "Файл students.txt не найден или в нем нет данных." << endl;
                }
                break;

            case 4:
                saveBinary(students, size, "students.dat");
                cout << "Данные записаны в бинарный файл." << endl;
                break;

            case 5:
                size = loadBinary(students, MAX_SIZE, "students.dat");
                if (size > 0) {
                    cout << "Данные прочитаны из бинарного файла." << endl;
                } else {
                    cout << "Файл students.dat не найден или в нем нет данных." << endl;
                }
                break;

            case 6:
                saveResult(students, size, "result.txt");
                cout << "Результат записан в файл result.txt." << endl;
                break;

            case 7:
                printStudents(students, size, cout);
                break;

            case 0:
                break;

            default:
                cout << "Такого пункта меню нет." << endl;
        }
    } while (choice != 0);

    return 0;
}
