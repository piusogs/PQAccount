#include "stdafx.h"
#include "Account.h"


void Account::set_balance(Money  m)
{
	this->_account_balance = m;
}

Account::Account()
{
}

Account::Account(std::string name, Money & balance):
_account_name(name),
_account_balance(balance),
_account_code(boost::uuids::to_string(boost::uuids::random_generator()())),
_date_created(boost::gregorian::day_clock::local_day()),
_currency(Currency::C_UNDEFINED)
{

}

Account::Account(std::string name):
_account_name(name),
_account_code(boost::uuids::to_string(boost::uuids::random_generator()())),
_date_created(boost::gregorian::day_clock::local_day()),
_currency(Currency::C_UNDEFINED)

{
	_account_balance.set_amount(0.0);

}

Account::Account(std::list<Expenditure> expense_list)
	:
	_account_name("PLEASE CHANGE"),
	_account_code(boost::uuids::to_string(boost::uuids::random_generator()())),
	_date_created(boost::gregorian::day_clock::local_day()),
	_currency(Currency::C_UNDEFINED)
{
	if (expense_list.size() < 1) {
		//does not make any sense, looking for fix;
		_expense_list = _expense_list;
	}
	else {
	_expense_list = expense_list;

	}
	}

Account::Account(Account_Descriptor & from_descriptor):
	_account_balance(from_descriptor._account_balance),
	_account_code(from_descriptor._account_code),
	_account_name(from_descriptor._account_name),
	_expense_list(from_descriptor._expense_list),
	_date_created(from_descriptor._date_created),
	_account_description(from_descriptor._account_description)
{
}


Account::~Account()
{
}

Account_Descriptor Account::get_descriptor()
{
	Account_Descriptor _account_des={_expense_list,
	_account_name,
	_account_code,
	_date_created,
	_account_balance};
	return _account_des;
}

bool Account::add_expenditure(Expenditure & expenses)
{
	//perform check here in the future
	
	std::fill_n(std::back_inserter(this->_expense_list),1, expenses);

	return true;
}

void Account::set_Descriptor(Account_Descriptor & descriptor)
{
	if(descriptor._account_name.length()<1){
	return ;
	}
	else {
		_account_balance = descriptor._account_balance;
		_account_name = descriptor._account_name;
		_date_created = descriptor._date_created;
		_expense_list= descriptor._expense_list;

	}
}

bool Account::execute_all_expenditures()
{
	if (_expense_list.size() < 0) {
		return false;
	}
	else
		std::for_each(std::begin(_expense_list), std::end(_expense_list), [&](Expenditure &ex) {
		ex.settle();
		
	});
	return true;
}

bool Account::execute_expenditure(Expenditure & expen)
{
	return false;
}

/*Account_Descriptor Account::try_execute_all_expenditures()
{
	Account_Descriptor temporary_descriptor = get_descriptor();
	//to be on a safer side because IDK what am doing
	Account_Descriptor td2 = temporary_descriptor;
	td2._expense_list.clear();
	std::for_each(temporary_descriptor._expense_list.begin()
		, temporary_descriptor._expense_list.end(), [&](Expenditure& expend) {
		expend.settle();
		Money m1 = td2._account_balance;
		Money m2 = expend.getamount();
		if (expend.get_descriptor()._type == Expense_type::DEBIT) {
			m1 = m1 - m2;
			td2._account_balance = m1;
		}
		else if (expend.get_descriptor()._type == Expense_type::CREDIT)
		{
			m1 = m1 + m2;
			td2._account_balance = m1;
		}

		else
		{
			return td2;
		}


	});
	return td2;
}*/

bool Account::execute_some_expenditures(std::list<Expenditure>& expense_list)
{
	if (!std::all_of(std::begin(expense_list), std::end(expense_list), [&](Expenditure& exp) {
		return exp.get_date_added() != boost::gregorian::date(boost::gregorian::not_a_date_time);
	})) {

	}

	std::for_each(std::begin(expense_list), std::end(expense_list), [&](Expenditure& exp) {
		
		exp.settle();

	});

	return true;
}

/*Account_Descriptor Account::try_execute_expenditure(Expenditure & expense)
{
	Account_Descriptor temporary_descriptor = get_descriptor();
	//to be on a safer side because IDK what am doing
	Account_Descriptor td2 = temporary_descriptor;
	expense.settle();
	std::replace_if(std::begin(td2._expense_list)
		, std::end(td2._expense_list), [&](Expenditure& expen) {
		if (expen.get_descriptor() == expense.get_descriptor()) {
			return true;
		}
	}, expense);
	return td2;
}*/

void Account::update_account()
{

	std::for_each(_expense_list.begin(), _expense_list.end(),[&](Expenditure& expen) {
		Money m1 = this->_account_balance;
		Money m2 = expen.getamount();
		if (expen.get_descriptor()._type == Expense_type::DEBIT) {
			m1 = m1 - m2;
			this->_account_balance = m1;
			return;
		}
		else if (expen.get_descriptor()._type == Expense_type::CREDIT)
		{
			m1 = m1 + m2;
			this->_account_balance = m1;
			return;
		}
		else
			return;
	});
	return;
}

void Account::remove_settled()
{
	std::remove_if(_expense_list.begin(), _expense_list.end(), [&](Expenditure& expen) {
	return	expen.is_settled();
	});
}

void Account::remove_outdated()
{
	std::remove_if(_expense_list.begin(), _expense_list.end(), [&](Expenditure& expen) {
		return expen.is_closed();
	});
}

void Account::remove_expenditure(Expenditure & expense)
{
std::remove_if(std::begin(_expense_list), std::end(_expense_list), [&](Expenditure &ex) {
		if (expense.get_descriptor()==ex.get_descriptor())
			return true;
	});
}

Expenditure Account::find_expenditure(std::string name)
{
	Expenditure expen;
	std::find_if(std::begin(_expense_list), std::end(_expense_list), [&](Expenditure &ex) {
		if (ex.get_name() == name) {
			expen=ex;
			return true;

		}
	});
	return expen;
}

bool Account::find_expenditureb(Expenditure & expense)
{
	if (expense.get_date_added() == boost::gregorian::date(boost::gregorian::not_a_date_time)) {
		return false;
	}
	std::find_if(std::begin(_expense_list), std::end(_expense_list), [&](Expenditure& exp) {
		if (exp.get_descriptor() == expense.get_descriptor()) { return true; }
	});
	return true;
}

bool Account::isclosed()
{
	return !_is_open;
}

bool Account::setClosed()
{
	if (this->_is_open) {
		_is_open = true;
		return _is_open;
	}
	else
	{
		return _is_open;
	}
}
bool Account::saveExpenditureTodb(Expenditure &_expense_description)
{
	try
	{
		//sqlite::database db("Accounts.db");
		//db << "insert into Expenditure(Name,ExpenseCode,Accountid,Amount,DateAdded,ClosingDate,IsSettled) values(?,?,?,?,?,?,?)"
		//	<< _expense_description._name
		//	<< this->_account_code
		//	<< _expense_description._amount.get_amount()
		//	<< boost::gregorian::to_simple_string(_expense_description._expense_date_added)
		//	<< boost::gregorian::to_simple_string(_expense_description._closing_date)
		//	<< _expense_description._is_settled;

		

	}
	catch (const std::exception&e)
	{
		std::cout<<e.what();
		return false;
	}
	return true;
}

bool Account::updateExpenditure(Expenditure & _expense_description)
{
	try
	{
		sqlite::database db("Accounts.db");
		db << "delete from Expenditure where ExpenseCode= ?" << _expense_description._expense_id;

		db << "insert into Expenditure (Name,ExpenseCode,Accountid,Amount,DateAdded,ClosingDate,IsSettled) values(?,?,?,?,?,?,?)"
			//	<< _expense_description._name
			//	<< _expense_description._expense_id
			//	<< this->_account_code
			//	<< _expense_description._amount.get_amount()
			//	<< _expense_description._expense_date_added
			//	<< _expense_description._closing_date
			//	<< _expense_description.is_settled();

			;
	}
	catch (const std::exception&e)
	{
		std::cout << e.what();
		return false;
	}
	return true;
}

bool Account::deletefromexpenditure(Expenditure & _expense_description)
{
	try {
		sqlite::database db("Accounts.db");
		db << "delete from Expenditure where ExpenseCode=?" << _expense_description._expense_id;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
	return true;
}

bool Account::updateAccount()
{
	try
	{
		//sqlite::database db("Accounts.db");
		//db << "delete from Accounts where AccountCode=?" << this->_account_code;

	//	db << "insert into Accounts (Name,AccountCode,DateCreated,Balance,AccountDescription,IsOpen,Currency) values(?,?,?,?,?,?,?)"
		//	<< this->_account_name
		//	<< this->_account_code
		//	<< this->_date_created
		//	<< this->_account_balance.get_amount()
		//	<< this->_account_description
			//<< this->_is_open
			//<< this->_currency;


	}
	catch (const std::exception&e)
	{
		std::cout << e.what();
		return false;
	}
	return true;
}


bool Account::saveAccountTodb()
{ try{
	sqlite::database db("Accounts.db");
	//db << "insert into Accounts (Name,AccountCode,DateCreated,Balance,AccountDescription,IsOpen,Currency) values (?,?,?,?,?,?,?)"
	//	<< this->_account_name
	//	<< this->_account_code
	//	<< this->_date_created
	//	<< this->_account_balance.get_amount()
		//<< this->_account_description
	//	<< this->_is_open
	//	<< this->_currency;
}
catch (std::exception &e) {
	std::cout << e.what();
}
return true;
}
