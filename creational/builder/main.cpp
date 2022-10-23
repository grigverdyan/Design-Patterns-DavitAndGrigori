#include "account.hpp"
#include "account_builder.hpp"
#include <iostream>

int main()
{
	Account acc = Account::create("targaryenonpower@info.wt", "queenOfashes101")
		.loginIs("essosWes")
		.usName("Rhaynera")
		.usSurname("Targaryen")
		.usMiddleName("Vyserys")
		.isOld(32)
		.livesCountry("Westeros")
		.livesCity("King Landing");

	std::cout << acc << std::endl;
	return EXIT_SUCCESS;
}
