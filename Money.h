#pragma once

enum Currency
{
	Naira,
	C_UNDEFINED


};

class Money
{
private:
   long	double _amount;
	Currency _currency;

public:
	Money(double amount, Currency currency);
	Money(double amount);
	Money();
	Money& operator- (Money& rhs);
	Money& operator+ (Money& rhs);
	Money& operator= (Money& rhs);

	long double get_amount();
	void set_amount( long double amount);
	const Currency get_currency();
	 void set_currency(Currency currency);

	~Money();
};






