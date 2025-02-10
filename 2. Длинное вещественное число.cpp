
#include <iostream>

int main()
{
    system("chcp 1251"); // Установить кодировку
    std::string str;
    std::cout << "Введите вещественное число: ";
    std::cin >> str;

    bool first = true;
    bool dot = false;
    bool digit = true;


    if ((str[0] < '0' || str[0] > '9') && str[0] != '.' && str[0] != '-') {
        first = false;
        std::cout << "первый символ неверен\n";
    } //проверка первого символа
    else {
        std::cout << "первый символ верен\n";
        for (int i = 0; i < str.length(); i++) {
            //проверка на цифры
            if ('0' <= str[i] && str[i] <= '9') {
                digit = true;
                std::cout << "есть цифра\n";
            }
            else if (str[i] == '.') { //проверка точки
                if (!dot) {
                    dot = true;
                    std::cout << "есть точка\n";
                }
                else {
                    dot = false; //проверка на вторую точку
                    std::cout << "есть вторая точка\n";
                }
            }
            else {
                digit = false;
                dot = false; //неверный символ
            }
        }
    }

    if (digit == true && dot == true && first == true) {
        std::cout << "Yes!";
    }
    else if (digit == false || dot == false || first == false){
        std::cout << "No!";
    }

    
}

