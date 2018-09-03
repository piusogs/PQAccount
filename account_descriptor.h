#pragma once
#include<list>
#include<string>
#include<boost\uuid\uuid.hpp>
#include<boost\uuid\uuid_generators.hpp>
#include<boost\uuid\uuid_io.hpp>
#include<boost\date_time\gregorian\gregorian.hpp>
#include"Money.h"
#include"Expenditure.h"

class Expenditure;

struct Account_Descriptor {
	std::list<Expenditure> _expense_list;
	std::string _account_name;
	std::string _account_code;
	//boost::uuids::uuid _account_code;
	boost::gregorian::date _date_created;
	Money _account_balance;
	std::string _account_description;

};