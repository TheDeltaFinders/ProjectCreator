#pragma once
#include <string>
#include <map>
class Base
{
private:
	static const std::string Keylist[10];
	std::string valuelist[10];

	std::map <std::string, std::string> Stamp;

	std::string ProjectName;
	void CreateRootDir();
	void CreateReadme();
	void ConstructKey();
	std::string ParseAndReplace(std::string);
	static const std::string ReadmeTplPath;
	static const std::string MakefileTplPath;

public:
	Base(std::string = ".");
	~Base();
	void CreateProjectTree();
};