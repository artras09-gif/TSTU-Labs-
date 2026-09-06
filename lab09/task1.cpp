#include <iostream>
#include <string>
using namespace std;

struct Request {
    string destination;
    int flightNumber;
    string passenger;
    string date;
    Request* next;
};

Request* head = NULL;

void addRequest(string destination, int flightNumber, string passenger, string date) {
    Request* newRequest = new Request;
    newRequest->destination = destination;
    newRequest->flightNumber = flightNumber;
    newRequest->passenger = passenger;
    newRequest->date = date;
    newRequest->next = NULL;

    if (head == NULL) {
        head = newRequest;
    } else {
        Request* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newRequest;
    }
    cout << "Заявка добавлена.\n";
}

void removeRequest(int flightNumber, string passenger) {
    Request* p = head;
    Request* prev = NULL;

    while (p != NULL) {
        if (p->flightNumber == flightNumber && p->passenger == passenger) {
            if (prev == NULL) {
                head = p->next;
            } else {
                prev->next = p->next;
            }
            delete p;
            cout << "Заявка удалена.\n";
            return;
        }
        prev = p;
        p = p->next;
    }
    cout << "Заявка не найдена.\n";
}

void printRequest(Request* p) {
    cout << p->destination << "  рейс " << p->flightNumber << "  "
         << p->passenger << "  " << p->date << endl;
}

void printAll() {
    if (head == NULL) {
        cout << "Список заявок пуст.\n";
        return;
    }
    Request* p = head;
    while (p != NULL) {
        printRequest(p);
        p = p->next;
    }
}

void printByFlightAndDate(int flightNumber, string date) {
    bool found = false;
    Request* p = head;
    while (p != NULL) {
        if (p->flightNumber == flightNumber && p->date == date) {
            printRequest(p);
            found = true;
        }
        p = p->next;
    }
    if (!found) cout << "Заявок с такими данными не найдено.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n1 - Добавить заявку\n";
        cout << "2 - Удалить заявку\n";
        cout << "3 - Найти заявки по рейсу и дате\n";
        cout << "4 - Показать все заявки\n";
        cout << "0 - Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            string destination, passenger, date;
            int flightNumber;
            cout << "Пункт назначения: "; cin >> destination;
            cout << "Номер рейса: "; cin >> flightNumber;
            cout << "Фамилия пассажира: "; cin >> passenger;
            cout << "Дата вылета: "; cin >> date;
            addRequest(destination, flightNumber, passenger, date);
        }
        else if (choice == 2) {
            string passenger;
            int flightNumber;
            cout << "Номер рейса: "; cin >> flightNumber;
            cout << "Фамилия пассажира: "; cin >> passenger;
            removeRequest(flightNumber, passenger);
        }
        else if (choice == 3) {
            int flightNumber;
            string date;
            cout << "Номер рейса: "; cin >> flightNumber;
            cout << "Дата вылета: "; cin >> date;
            printByFlightAndDate(flightNumber, date);
        }
        else if (choice == 4) {
            printAll();
        }
    }

    return 0;
}
