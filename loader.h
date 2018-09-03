#pragma once
#include<string>
#include<filesystem>
#include<algorithm>
namespace std2 = std::experimental;
enum FILETYPE{ACCOUNTS,EXPENDITURES};
class loader
{
	
protected:
    std::string _file_directory;
	bool _is_exist(std::string & _file_directory_);
	//std::string _get_root();
public:
	loader(std::string _file_directory_);
	loader();
	std::string getfiledirectory();
	void setfiledirectory(std::string _file_directory_);
	bool isloaded();
	//std::string findfile(std::string _file_name_);
	bool deletefile(std::string _file_name_);
	virtual ~loader();
};

