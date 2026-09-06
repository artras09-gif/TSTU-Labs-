#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_STUDENTS = 100;


class Student {
private:
    string surname;
    string name;
    string group;
    double average;

public:

    Student() {
        string surnames[6] = { "Иванов", "Петров", "Сидоров", "Кузнецов", "Смирнов", "Попов" };
        string names[6]    = { "Александр", "Дмитрий", "Мария", "Анна", "Сергей", "Ольга" };
        string groups[3]   = { "ИС-21", "ИС-22", "ПМ-11" };

        surname = surnames[rand() % 6];
        name = names[rand() % 6];
        group = groups[rand() % 3];
        average = 2.0 + (rand() % 301) / 100.0; // случайное число от 2.00 до 5.00
    }


    Student(string s, string n, string g, double a) {
        surname = s;
        name = n;
        group = g;
        average = a;
    }

 
    string getSurname() const { return surname; }
    string getName() const { return name; }
    string getGroup() const { return group; }
    double getAverage() const { return average; }

    // изменение значений атрибутов
    void setSurname(string s) { surname = s; }
    void setName(string n) { name = n; }
    void setGroup(string g) { group = g; }
    void setAverage(double a) { average = a; }

   
    void print() const {
        cout << surname << " " << name << " " << group << " " << average << endl;
    }


    void printToFile(ofstream& out) const {
        out << surname << " " << name << " " << group << " " << average << endl;
    }
};


class StudentGroup {
private:
    Student list[MAX_STUDENTS];
    int count;

public:
    StudentGroup() {
        count = 0;
    }

    
    void fillRandom(int n) {
        if (n > MAX_STUDENTS) n = MAX_STUDENTS;
        count = n;
        for (int i = 0; i < count; i++) {
            list[i] = Student();
        }
    }

    
    void fillFromKeyboard(int n) {
        if (n > MAX_STUDENTS) n = MAX_STUDENTS;
        count = n;
        string s, nm, g;
        double a;
        for (int i = 0; i < count; i++) {
            cout << "Студент " << i + 1 << ":\n";
            cout << "Фамилия: "; cin >> s;
            cout << "Имя: "; cin >> nm;
            cout << "Группа: "; cin >> g;
            cout << "Средний балл: "; cin >> a;
            list[i] = Student(s, nm, g, a);
        }
    }


    void fillFromFile(string filename) {
        ifstream in(filename.c_str());
        if (!in) {
            cout << "Не удалось открыть файл " << filename << endl;
            return;
        }
        count = 0;
        string s, nm, g;
        double a;
        while (count < MAX_STUDENTS && in >> s >> nm >> g >> a) {
            list[count] = Student(s, nm, g, a);
            count++;
        }
        in.close();
    }

    
    void display() const {
        if (count == 0) {
            cout << "Список пуст.\n";
            return;
        }
        cout << "Фамилия Имя Группа Балл\n";
        for (int i = 0; i < count; i++) {
            list[i].print();
        }
    }

    
    void displayToFile(string filename) const {
        ofstream out(filename.c_str());
        if (!out) {
            cout << "Не удалось создать файл " << filename << endl;
            return;
        }
        out << "Фамилия Имя Группа Балл\n";
        for (int i = 0; i < count; i++) {
            list[i].printToFile(out);
        }
        out.close();
    }

    
    void saveToFile(string filename) const {
        ofstream out(filename.c_str());
        if (!out) {
            cout << "Не удалось создать файл " << filename << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            out << list[i].getSurname() << " "
                << list[i].getName() << " "
                << list[i].getGroup() << " "
                << list[i].getAverage() << endl;
        }
        out.close();
        cout << "Данные сохранены в файл " << filename << endl;
    }

    
    void sortBySurname() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (list[j].getSurname() > list[j + 1].getSurname()) {
                    Student temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
    }

    
    void sortByAverage() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (list[j].getAverage() > list[j + 1].getAverage()) {
                    Student temp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = temp;
                }
            }
        }
    }

    
    void searchByGroup(string targetGroup) const {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (list[i].getGroup() == targetGroup) {
                list[i].print();
                found = true;
            }
        }
        if (!found) cout << "Студентов группы " << targetGroup << " не найдено.\n";
    }

    
    void searchByAverageRange(double minA, double maxA) const {
        bool found = false;
        for (int i = 0; i < count; i++) {
            double a = list[i].getAverage();
            if (a >= minA && a <= maxA) {
                list[i].print();
                found = true;
            }
        }
        if (!found) cout << "Студентов с таким баллом не найдено.\n";
    }
};

int main() {
    srand((unsigned)time(0));

    StudentGroup group;
    group.fillRandom(5);

    cout << "===== Случайные студенты =====\n";
    group.display();

    group.sortBySurname();
    cout << "\n===== После сортировки по фамилии =====\n";
    group.display();

    cout << "\n===== Студенты группы ИС-21 =====\n";
    group.searchByGroup("ИС-21");

    cout << "\n===== Отличники (4.5 - 5.0) =====\n";
    group.searchByAverageRange(4.5, 5.0);

    group.saveToFile("students.txt");
    group.displayToFile("report.txt");

    StudentGroup group2;
    group2.fillFromFile("students.txt");
    cout << "\n===== Прочитано из файла =====\n";
    group2.display();

    int n;
    cout << "\nСколько студентов ввести с клавиатуры? ";
    cin >> n;

    StudentGroup group3;
    group3.fillFromKeyboard(n);
    cout << "\n===== Студенты, введённые с клавиатуры =====\n";
    group3.display();

    return 0;
}
