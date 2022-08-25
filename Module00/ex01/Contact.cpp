#include "Contact.h"
#include <iostream>

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone,
                 std::string secret) : firstName(firstName), lastName(lastName), nickName(nickName),
                 phone(phone), secret(secret) {}

Contact::~Contact() {}

void Contact::setFirstName(std::string firstName) {
    this->firstName = firstName;
}
std::string Contact::getFirstName(void) const {
    return firstName;
}

void Contact::setLastName(std::string lastName) {
    this->lastName = lastName;
}
std::string Contact::getLastName(void) const {
    return lastName;
}

void Contact::setNickName(std::string nickName) {
    this->nickName = nickName;
}
std::string Contact::getNickName(void) const {
    return nickName;
}

void Contact::setPhone(std::string phone) {
    this->phone = phone;
}
std::string Contact::getPhone(void) const {
    return phone;
}

void Contact::setSecret(std::string secret) {
    this->secret = secret;
}
std::string Contact::getSecret(void) const {
    return secret;
}