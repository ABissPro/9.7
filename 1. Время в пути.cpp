
#include <iostream>

int main()
{
    system("chcp 1251"); // Установить кодировку
    std::string depTime, arTime;
    std::cout << "Введите время отправления и прибытия в формате HH:MM\n";
    std::cin >> depTime >> arTime;
    int durHours;
    int durMin;

    if (depTime.length() != 5 || depTime[2] != ':' || depTime[0] < '0'
        || depTime[0] > '9' || depTime[1] < '0' || depTime[1] > '9'
        || depTime[3] < '0' || depTime[3] > '9' || depTime[4] < '0'
        || depTime[4] > '9'
        || arTime.length() != 5 || arTime[2] != ':' || arTime[0] < '0'
        || arTime[0] > '9' || arTime[1] < '0' || arTime[1] > '9'
        || arTime[3] < '0' || arTime[3] > '9' || arTime[4] < '0'
        || arTime[4] > '9') {
        std::cout << "Ошибка!!\n";
    }
    else {
        durHours = (10 * (arTime[0] - '0') + (arTime[1] - '0'))
            - (10 * (depTime[0] - '0') + (depTime[1] - '0'));
        durMin = (10 * (arTime[3] - '0') + (arTime[4] - '0'))
            - (10 * (depTime[3] - '0') + (depTime[4] - '0'));
        durMin = 60 * durHours + durMin;
        durHours = durMin / 60;
        durMin = durMin % 60;
        if (arTime < depTime) {
            int difHours = (10 * (depTime[0] - '0') + (depTime[1] - '0')) 
                 - (10 * (arTime[0] - '0') + (arTime[1] - '0'));
            int difMin = (10 * (depTime[3] - '0') + (depTime[4] - '0')) 
                - (10 * (arTime[3] - '0') + (arTime[4] - '0'));
            durHours = 23 - difHours;
            durMin = 60 - difMin;
        }
        else if (arTime == depTime) {
            durHours = 24;
            durMin = 0;
        }
        
        std::cout << "Поездка составила " << durHours << " ч. " << durMin << " мин.";
    }
}
