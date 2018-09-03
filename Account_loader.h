#pragma once
#include<iostream>
#include<string>
#include<boost\property_tree\ptree.hpp>
#include<boost\property_tree\xml_parser.hpp>
#include<boost\foreach.hpp>
#include<boost\date_time.hpp>
#include"Account.h"
#include"loader.h"
#include"Expenditure.h"
class Account_loader
{
	loader _loader;
	Account_Descriptor _account_descriptor;
	boost::property_tree::ptree tree;

public:
	Account_loader();
	Account_Descriptor load(std::string _file_name_);
	void save(std::string _file_name_,Account_Descriptor &_descroptor);
	
	~Account_loader();
};

