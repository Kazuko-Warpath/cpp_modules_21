#include "PhoneBook.h"

PhoneBook::PhoneBook() : SIZE(8) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::getString(std::string message) {
    std::string input = "";

    while (input.empty()) {
        std::cout << message;
        std::getline(std::cin, input);
    }

    return input;
}

void PhoneBook::add(int current) {
    Contact contact;

    contact.setFirstName(getString("FirstName\t-> "));
    contact.setLastName(getString("LastName\t-> "));
    contact.setNickName(getString("NickName\t-> "));
    contact.setPhone(getString("Phone\t\t-> "));
    contact.setSecret(getString("Secret\t\t-> "));

    this->contacts[current % SIZE] = contact;
}

void PhoneBook::fillCell(std::string message, std::string separator, std::string filler, int width) {
    int i = 0;

    while (i < (int) message.length() && i < width - 1) {
        std::cout << message[i];
        i++;
    }

    if ((int) message.length() == width) {
        std::cout << message[i];
    } else if ((int) message.length() > width) {
        std::cout << ".";
    } else {
        while (i < width) {
            std::cout << filler;
            i++;
        }
    }

    std::cout << separator;
}

void PhoneBook::showTable(int current) {
    std::cout << "|index     |first name|last name |nickname  |" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < std::min(current, this->SIZE); i++) {
        std::cout << "|";
        fillCell(std::to_string(i), "|", " ", 10);
        fillCell(this->contacts[i].getFirstName(), "|", " ", 10);
        fillCell(this->contacts[i].getLastName(), "|", " ", 10);
        fillCell(this->contacts[i].getNickName(), "|", " ", 10);
        std::cout << std::endl;
    }
}

void PhoneBook::search(int current) {
    int index = -1;

    showTable(current);

    std::cout << "Enter index -> ";
    std::cin >> index;

    if (index < std::min(current, this->SIZE)) {
        fillCell(this->contacts[index].getFirstName(), "\n", "", 1000);
        fillCell(this->contacts[index].getLastName(), "\n", "", 1000);
        fillCell(this->contacts[index].getNickName(), "\n", "", 1000);
        fillCell(this->contacts[index].getPhone(), "\n", "", 1000);
        fillCell(this->contacts[index].getSecret(), "\n", "", 1000);
    } else {
        std::cout << "Invalid index!" << std::endl;
    }
}

