#include "stdafx.h"
#include "loader.h"


bool loader::_is_exist(std::string & _file_directory_)
{
	std2::filesystem::path account_(_file_directory_ + "//Accounts");
	std2::filesystem::path expenditure_(_file_directory_ + "//Expenditures");

	if (std2::filesystem::exists(account_) && std2::filesystem::exists(expenditure_)) {
		return true;
	}
	return false;
}

loader::loader(std::string _file_path_)
{
	if (!_is_exist(_file_path_)) {
		std2::filesystem::path account_(_file_path_ + "//Accounts");
		std2::filesystem::path expenditure_(_file_path_ + "//Expenditures");
		std2::filesystem::create_directory(account_);
		std2::filesystem::create_directory(expenditure_);
	}
}

loader::loader()
{
 std2::filesystem::path current=	std2::filesystem::current_path();
// std::string pq = "//PQaccounts";
// std2::filesystem::path pq2 = std2::filesystem::path(pq);
 this->_file_directory = std2::filesystem::path(current).string();
 std2::filesystem::path account_(_file_directory + "//Accounts");
 std2::filesystem::path expenditure_(_file_directory + "//Expenditures");
 if (!this->_is_exist(current.string())) {
	 std2::filesystem::create_directory(account_);
		std2::filesystem::create_directory(expenditure_);
 }
}

std::string loader::getfiledirectory()
{
	return this->_file_directory;
	
}

void loader::setfiledirectory(std::string _file_directory_)
{
	this->_file_directory = _file_directory_;
}

bool loader::isloaded()
{
	std2::filesystem::path account_(_file_directory + "//Accounts");
	std2::filesystem::path expenditure_(_file_directory + "//Expenditures");
	if (std2::filesystem::file_size(account_) > 1 && std2::filesystem::file_size(expenditure_) > 1 && this->_is_exist(this->_file_directory) == true) {
		return true;
	}
	return false;
}

//the experimental file system is not working properly need to stop here
//std::string loader::findfile(std::string _file_name_)
//{
//	std2::filesystem::path account_(_file_directory);
	//std2::filesystem::path expenditure_(_file_path_ + "//Expenditures");
//	auto file = std::find_if(std::begin(std2::filesystem::recursive_directory_iterator(account_)), std::end(std2::filesystem::recursive_directory_iterator(account_)), []() {
//	});
	
//}


bool loader::deletefile(std::string _file_name_)
{
	std2::filesystem::path p(this->_file_directory + "//" + _file_name_);
	if (_is_exist(p.string)) {
		if (std2::filesystem::remove(p)) {
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

loader::~loader()
{
}
