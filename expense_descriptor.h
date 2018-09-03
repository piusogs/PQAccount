#pragma once
#include<string>
#include<boost\date_time.hpp>
#include<boost\uuid\uuid.hpp>
#include<boost\uuid\uuid_generators.hpp>
#include<boost\uuid\uuid_io.hpp>
#include<boost\date_time\gregorian\gregorian.hpp>
typedef enum {
	CREDIT,
	DEBIT,
	UNDEFINED
}Expense_type;

struct Expense_descriptor {
	/*TO DO*/
	/*---Add a function to check if the values are valid
	i.e check all date against boost::gregorian::date(boost::gregorian::not_a_date_time)
	and money againt NULL,description against NULL*/
	Expense_descriptor(std::string _name_,/*boost::uuids::uuid*/ std::string _expense_id_,
		std::string _description_, Money _amount_, boost::gregorian::date _expense_date_added_,
		boost::gregorian::date _closing_date_, bool _is_settled_, bool _has_closing_date_, bool _is_pendable_, Expense_type _type_) :
		_name(_name_),
		_expense_id(_expense_id_),
		_description(_description_),
		_amount(_amount_),
		_expense_date_added(_expense_date_added_),
		_closing_date(_closing_date_),
		_is_settled(_is_settled_),
		_type(_type_),
		_is_pendable(_is_pendable_),
		_has_closing_date(_has_closing_date_)
	{


	}

	std::string _name;
	std::string _expense_id;
	//boost::uuids::uuid _expense_id;
	std::string _description;
	std::string ___account_id;
	Money _amount;
	boost::gregorian::date _expense_date_added;
	boost::gregorian::date _closing_date;
	bool _is_settled = false;
	bool _has_closing_date;
	bool _is_pendable;
	Expense_type _type;

	/*Operators*/
	bool operator==(Expense_descriptor &rhs) {
		if (_name == rhs._name&&
			_expense_id == rhs._expense_id
			&&_description == rhs._description
			&&_amount.get_amount() == rhs._amount.get_amount()
			&& _expense_date_added == rhs._expense_date_added
			&&_closing_date == rhs._closing_date
			&&_is_settled == rhs._is_settled
			&&_type == rhs._type
			&&_has_closing_date == rhs._has_closing_date
			&&_is_pendable == rhs._is_pendable)
		{
			return true;
		}
		return false;
	}
};