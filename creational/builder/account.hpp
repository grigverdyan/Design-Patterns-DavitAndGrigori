#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class AccountBuilder;

class Account
{
    public:
        friend class AccountBuilder;
        friend std::ostream& operator<<(std::ostream& os, Account& obj);
        static AccountBuilder create(const std::string& email, const std::string& password);

    private:
        /*
         *  Account Details
        */
        std::string     _login;
        std::string     _email;
        std::string     _password;

        /*
         * Personal information
        */
        std::string     _name;
        std::string     _middleName;
        std::string     _surname;
        std::string     _country;
        std::string     _city;
        unsigned int    _age;

        Account(const std::string& email, const std::string& password) 
            : _email(email), _password(password) {}
};

#endif  /* ACCOUNT_H */
