#pragma once
#include <string>
#include <map>
class Project{
public:
	std::string ProjectName;
	//std::string Path;
	std::string Author;
	std::string Email;
	std::string TimeStamp;

	Project();
	~Project();
};

class Base{
private:
	static const std::string Keylist[10];
	std::string valuelist[10];

	std::map <std::string, std::string> Stamp;

	std::string ProjectName;
	void CreateRootDir();
	void CreateReadme();
	void ConstructKey(Project);
	std::string ParseAndReplace(std::string);
	static const std::string ReadmeTplPath;
	static const std::string MakefileTplPath;

public:
	//Base(std::string = ".");
	Base(Project);
	~Base();
	void CreateProjectTree();
};