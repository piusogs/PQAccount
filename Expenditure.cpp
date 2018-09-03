#include "stdafx.h"
#include "Expenditure.h"


Expenditure::Expenditure() :
	_expense_date_added(boost::gregorian::day_clock::local_day()),
	_type(Expense_type::UNDEFINED),
	_is_settled(false),
	_description("THIS IS AN EMPTY EXPENDITURE PLEASE EDIT"),
	_expense_id(boost::uuids::to_string(boost::uuids::random_generator()())),
	_closing_date(boost::gregorian::date(boost::gregorian::not_a_date_time)),
	___account_id(" ")

	
{
	Money m;
	this->_amount = m;
	boost::uuids::uuid namespa;
	boost::uuids::name_generator gen(namespa);
	boost::uuids::uuid u_id = gen("expense");
	this->_name = boost::uuids::to_string(u_id);


}

Expenditure::Expenditure(Money & amount, bool ispendable,
	Expense_type type, std::string description,
	std::string name, std::string closing_date,
	bool has_closing_date,bool is_settled) :

	_expense_id(boost::uuids::to_string(boost::uuids::random_generator()())),
	_expense_date_added(boost::gregorian::day_clock::local_day()),
	_amount(amount),
	_is_pendable(ispendable),
	_type(type),
	_has_closing_date(has_closing_date),
	_description(description),
	_is_settled(is_settled),
	___account_id(" ")
	
{
boost::gregorian::date da1;
da1 = boost::gregorian::from_simple_string(closing_date);
this->_closing_date = da1;
this->_name = name;
}

Expenditure::Expenditure(Money & amount, Expense_type type):
_amount(amount),
_type(Expense_type::UNDEFINED),
_expense_id(boost::uuids::to_string(boost::uuids::random_generator()())),
_expense_date_added(boost::gregorian::day_clock::local_day()),
_is_pendable(false),
_has_closing_date(true),
_description("SET EXPENSE DESCRIPTION AND DEFINE EXPENSE TYPE AND DATES"),
_is_settled(false),
_name("SET EXPENSE NAME")
{
	boost::gregorian::date da1;
	da1 = boost::gregorian::date(boost::gregorian::date(boost::gregorian::not_a_date_time));
	this->_closing_date = da1;
}

Expenditure::Expenditure(Expense_descriptor & from_desciptor)
{
	this->_amount = from_desciptor._amount;
	this->_closing_date = from_desciptor._closing_date;
	this->_description = from_desciptor._description;
	this->_expense_date_added = from_desciptor._expense_date_added;
	this->_expense_id = from_desciptor._expense_id;
	this->_name = from_desciptor._name;
	this->_type = from_desciptor._type;
	this->_is_settled = from_desciptor._is_settled;
	this->_has_closing_date = from_desciptor._has_closing_date;
	this->_is_pendable = from_desciptor._is_pendable;
	this->___account_id = from_desciptor.___account_id;
}


bool Expenditure::is_closed() {
	
	return _closing_date <= boost::gregorian::day_clock::local_day();

	
}

bool Expenditure::is_pending() {
	return _closing_date>boost::gregorian::day_clock::local_day();

}

bool Expenditure::is_settled() {
	return _is_settled;
}
bool Expenditure::settle() {
	_is_settled = true;
	return true;
}

bool Expenditure::setdescription(std::string description)
{
	if (description.length() <= 0) {
		return false;
	}
	_description = description;
	return true;
}

void Expenditure::setaccountid(std::string & account__id)
{
	this->___account_id = account__id;
}

std::string Expenditure::getaccountid()
{
	return this->___account_id;
}

std::string Expenditure::get_description()
{
	if (_description.length() <= 0) {
		return "DESCRIPTION IS YET TO BE SET";
	}
	else {
		return _description;
	}
}

std::string Expenditure::get_name()
{
	if (_name.length() < 0) {
		return "NOT SET";
	}
	else
		return _name;
}

Money Expenditure::getamount()
{
	if (_amount.get_amount() == NULL) {
		Money mscoped(0);
		return mscoped;
	}
	else {
		return _amount;
	}

}

bool Expenditure::setamount(Money money)
{
	if (money.get_amount() != NULL && money.get_currency() != Currency::C_UNDEFINED) {
		_amount = money;
		return true;
	}
	else return false;
}

boost::gregorian::date Expenditure::get_closing_date()
{
	if (_closing_date != boost::gregorian::date(boost::gregorian::not_a_date_time)) {
		return _closing_date;

	}
	else return boost::gregorian::date(boost::gregorian::not_a_date_time);
}

bool Expenditure::set_closing_date(std::string closing_date)
{
	try{
		boost::gregorian::date d;
		d = boost::gregorian::from_simple_string(closing_date);
		_closing_date = d;
		return true;
	}
	catch (std::exception &e) {
		std::cout << e.what();
		return false;
	}
	return false;
}

boost::gregorian::date Expenditure::get_date_added()
{
	if (_expense_date_added != boost::gregorian::date(boost::gregorian::not_a_date_time)) {
		return _expense_date_added;
	}
	else return boost::gregorian::date(boost::gregorian::not_a_date_time);
}

Expense_descriptor Expenditure::get_descriptor()
{
	 Expense_descriptor expence(_name,_expense_id,_description,_amount,_expense_date_added,_closing_date,_is_settled,_has_closing_date,_is_pendable,_type);
	 return expence;
}

bool Expenditure::set_date_added(std::string date_string)
{
	try {
		boost::gregorian::date d;
		d = boost::gregorian::from_simple_string(date_string);
		_expense_date_added = d;
		return true;
	}
	catch (std::exception &e) {
		std::cout<<e.what();
		return false;
	}
	return false;
}

bool Expenditure::set_expensetype(Expense_type type)
{
	if (type == Expense_type::UNDEFINED) {
		return false;
	}
	else
		_type = type;
	return true;
}

Expenditure::~Expenditure()
{
	
}
