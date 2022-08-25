#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Contact {
private:
    std::string     firstName;
    std::string     lastName;
    std::string     nickName;
    std::string     phone;
    std::string     secret;

public:
    Contact();
    Contact(std::string firstName, std::string lastName, std::string nickName, std::string phone, std::string secret);
    ~Contact();

    void setFirstName(std::string firstName);
    std::string getFirstName() const;

    void setLastName(std::string lastName);
    std::string getLastName() const;

    void setNickName(std::string nickName);
    std::string getNickName() const;

    void setPhone(std::string phone);
    std::string getPhone() const;

    void setSecret(std::string secret);
    std::string getSecret() const;
};


#endif //CONTACT_H
