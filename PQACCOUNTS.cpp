// PQACCOUNTS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Account.h"

int main()
{
	Account p("new account");
	std::cout << p.get_descriptor()._account_code;
	while(1){}
    return 0;
}

