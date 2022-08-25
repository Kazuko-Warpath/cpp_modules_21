#include <iostream>
#include "PhoneBook.h"

int main(void) {
    std::string input;
    PhoneBook phoneBook;
    int current;

    current = 0;

    while (std::cin) {
        std::cout << "Type a command (ADD, SEARCH, EXIT): " << std::endl;
        std::getline(std::cin, input);

        for (int i = 0; i < (int) input.length(); i++) {
            input[i] = std::toupper(input[i]);
        }

        if (!input.compare("ADD")) {
            phoneBook.add(current);
            current++;
        } else if (!input.compare("SEARCH")) {
            phoneBook.search(current);
            std::getline(std::cin, input);
        }
        else if (!input.compare("EXIT")) {
            break;
        }
    }

    std::cout << "You left phonebook." << std::endl;

    return 0;
}