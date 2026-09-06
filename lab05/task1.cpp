#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Rus");
    
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);
    
    int digitCount = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            digitCount++;
        }
    }
    
    std::cout << "Количество цифр: " << digitCount << std::endl;
    
    char replacement;
    if (digitCount < 10) {
        replacement = digitCount + '0';  
    } else {
                replacement = '#';
    }
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            str[i] = replacement;
        }
    }
    
    // 3. Вывод
    std::cout << "Результат: " << str << std::endl;
    
    return 0;
}
