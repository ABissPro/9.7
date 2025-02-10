#include <iostream>
#include <string>

int main()
{
    system("chcp 1251"); // Установить кодировку
    std::string line;
    std::cout << "Введите строку:\n";
    std::getline(std::cin, line);
    
    int words = 0;
    int i;
    bool in = false;
 
    if (line.length() >= 0 && line.length() <= 100) {
        for (i = 0; i < line.length(); i++) {
            if (line[i] != ' ') {
                if (!in) {
                    words++;
                    in = true;
                }                                
            }
            else {
                in = false;
            }
            
        }
        
        std::cout << words; //<< "\n" << whitespace << "\n" << sigil;
        
    }
    else {
        std::cout << "Ошибка!!";
    }
    

}