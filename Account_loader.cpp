#include "stdafx.h"
#include "Account_loader.h"


Account_loader::Account_loader()
{
	this->_loader = loader();
	this->_account_descriptor = Account_Descriptor();

}

Account_Descriptor Account_loader::load(std::string _file_name_)
{
	std::string _fullpath_ = _loader.getfiledirectory() + _file_name_;
	boost::property_tree::read_xml(_fullpath_, tree);
_account_descriptor._account_name=	tree.get<std::string>("Account.name");
_account_descriptor._account_code=	tree.get<std::string>("Account.code");
_account_descriptor._date_created =boost::gregorian::from_simple_string(tree.get<std::string>("Account.date"));
	tree.get("Account.balance", 0.000000);
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, tree.get_child("Account.expenditure")) {
		
	
	}

}


Account_loader::~Account_loader()
{
}
