#include "account_builder.hpp"

AccountBuilder& AccountBuilder::loginIs(const std::string& login)
{
	account._login = login;
	return *this;
}

AccountBuilder& AccountBuilder::usName(const std::string& name)
{
	account._name = name;
	return *this;
}

AccountBuilder& AccountBuilder::usMiddleName(const std::string& middleName)
{
	account._middleName = middleName;
	return *this;
}

AccountBuilder& AccountBuilder::usSurname(const std::string& surname)
{
	account._surname = surname;
	return *this;
}

AccountBuilder& AccountBuilder::isOld(unsigned int age)
{
	account._age = age;
	return *this;
}

AccountBuilder& AccountBuilder::livesCountry(const std::string& country)
{
	account._country = country;
	return *this;
}

AccountBuilder& AccountBuilder::livesCity(const std::string& city)
{
	account._city = city;
	return *this;
}
