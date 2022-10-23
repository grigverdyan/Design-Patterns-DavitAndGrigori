#ifndef ACCOUNT_BUILDER_H
#define ACCOUNT_BUILDER_H

#include "account.hpp"

class AccountBuilder
{
    public:
        AccountBuilder(const std::string& login, const std::string& password)
            : account(login, password) {}

        operator Account() const
        {
			return std::move(account);
		}
		AccountBuilder& loginIs(const std::string& login);
		AccountBuilder& usName(const std::string& name);
		AccountBuilder& usMiddleName(const std::string& middleName);
		AccountBuilder& usSurname(const std::string& surname);
		AccountBuilder& isOld(unsigned int age);
		AccountBuilder& livesCountry(const std::string& country);
		AccountBuilder& livesCity(const std::string& city);
    private:
        Account account;
};

#endif  /* ACCOUNT_BUILDER_H */
