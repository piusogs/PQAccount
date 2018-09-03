#include "stdafx.h"
#include "Money.h"


Money::Money(double amount, Currency currency):
	_amount(amount),
	_currency(currency)

{

}

Money::Money(double amount)
	:_amount(amount),
	_currency(Currency::C_UNDEFINED)
{

}

Money::Money()
{
}

Money & Money::operator-(Money & rhs)
{
	this->_amount = this->_amount - rhs.get_amount();
	return *this;

	// TODO: insert return statement here
}

Money & Money::operator+(Money & rhs)
{
	this->_amount = this->_amount + rhs.get_amount();
	return *this;
	// TODO: insert return statement here
}

Money & Money::operator=(Money & rhs)
{
	this->_amount = rhs._amount;
	return *this;
}

long double Money::get_amount()
{
	return this->_amount;
}

void Money::set_amount(long double amount)
{
	this->_amount = amount;
}

const Currency Money::get_currency()
{
	return this->_currency;
}

 void Money::set_currency(Currency currency)
{
	 this->_currency=currency;
}


Money::~Money()
{
}
