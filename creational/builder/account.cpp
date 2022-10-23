#include "account.hpp"
#include "account_builder.hpp"

#include <iostream>

AccountBuilder Account::create(const std::string& email, const std::string& password)
{
    return AccountBuilder(email, password);
}

std::ostream& operator<<(std::ostream& os, Account& obj)
{
    return os << "---Account Information---" << std::endl
              << "-------------------------" <<std::endl
              << "LOGIN: " << obj._login << std::endl
              << "PASSWORD: " << obj._password << std::endl << std::endl
              << "---Personal Information---" << std::endl
              << "--------------------------" << std::endl
              << "NAME: " << obj._name << std::endl
              << "MIDDLE NAME: " << obj._middleName << std::endl
              << "SURNAME: " << obj._surname << std::endl
              << "COUNTRY: " << obj._country << std::endl
              << "CITY: " << obj._city << std::endl
              << "AGE: " << obj._age << std::endl;
}
