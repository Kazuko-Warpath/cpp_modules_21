#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
    Contact contacts[8];
    std::string getString(std::string message);
    void showTable(int current);
    void fillCell(std::string message, std::string separator, std::string filler, int width);
    int const SIZE;

public:
    PhoneBook();
    ~PhoneBook();

   void add(int current);
   void search(int current);
};


#endif //PHONEBOOK_H
