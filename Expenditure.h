#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include<boost\uuid\uuid.hpp>
#include<boost\uuid\uuid_generators.hpp>
#include<boost\uuid\uuid_io.hpp>
#include<boost\date_time\gregorian\gregorian.hpp>
#include "Money.h"
#include "Account.h"
#include"expense_descriptor.h"
class Expenditure;

class Expenditure
{
private:
	friend class Account;
	std::string _name;
	std::string _description;
	std::string _expense_id;
	std::string ___account_id;
	//boost::uuids::uuid _expense_id;
	Money _amount;
	boost::gregorian::date _expense_date_added;
	boost::gregorian::date _closing_date;
	bool _is_settled = false;
	bool _is_pendable=false;
	bool _has_closing_date=false;
	Expense_type _type;
public:
	Expenditure();
	Expenditure(Money& amount, bool ispendable,Expense_type type,
		        std::string description,std::string name,
				std::string closing_date,
		        bool has_closing_date=true , bool is_settled=false);

	Expenditure(Money& amount, Expense_type type);
	Expenditure(Expense_descriptor& from_desciptor);
	bool is_closed();
	bool is_pending();
	bool is_settled();
	bool settle();
	bool setdescription(std::string description);
	void setaccountid(std::string & account__id);
	std::string getaccountid();
	std::string get_description();
	std::string get_name();
	Money getamount();
	bool setamount(Money money);
	boost::gregorian::date get_closing_date();
	bool set_closing_date(std::string closing_date);
	boost::gregorian::date get_date_added();
	Expense_descriptor get_descriptor();
	bool set_date_added(std::string date_string);
	bool set_expensetype(Expense_type type);
	~Expenditure();
};

