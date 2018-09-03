#pragma once
#include<string>
#include<list>
#include<algorithm>
#include<iterator>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<exception>
#include<boost\uuid\uuid.hpp>
#include<boost\uuid\uuid_generators.hpp>
#include<boost\date_time\gregorian\gregorian.hpp>
#include<sqlite_modern_cpp.h>
#include "Money.h"
#include "Expenditure.h"
#include"expense_descriptor.h"
#include"account_descriptor.h"


class Expenditure;





class Account
{

private:
	
	std::list<Expenditure> _expense_list;
	std::string _account_name;
	std::string _account_code;
	//boost::uuids::uuid _account_code;
	boost::gregorian::date _date_created;
	Currency _currency;
	bool _is_open = true;
	Money _account_balance;
	std::string _account_description;
	void set_balance(Money m);
	Account * acccptr;
public:
	Account(/* from loader*/);
	Account(std::string name,Money& balance);
	Account(std::string name);
	Account(std::list<Expenditure> expense_list);
	Account(Account_Descriptor &from_descriptor);
	//////////////////////////////////////////////////////////////////
													//
	/////////////////////////////////////////////////////////////////
	
	Account_Descriptor get_descriptor();
	bool add_expenditure(Expenditure& expenses);
	//void add_some_expenditure(std::list<Expenditure> expenses);
	void set_Descriptor(Account_Descriptor& descriptor);
	bool execute_all_expenditures();
	bool execute_expenditure(Expenditure & expen);
	//Account_Descriptor try_execute_all_expenditures ();
	bool execute_some_expenditures(std::list<Expenditure>& expense_list);
	//Account_Descriptor try_execute_expenditure(Expenditure& expense);
	void update_account();
	void remove_settled();
	void remove_outdated();
	
	void remove_expenditure(Expenditure& exp);
	Expenditure find_expenditure(std::string name);
	bool find_expenditureb(Expenditure & expense);
	bool isclosed();
	bool setClosed();
	bool saveExpenditureTodb(Expenditure &_expense_description);
	bool updateExpenditure(Expenditure &_expense_description);
	bool deletefromexpenditure(Expenditure &_expense_description);
	bool updateAccount();
	bool saveAccountTodb();
	~Account();
};

