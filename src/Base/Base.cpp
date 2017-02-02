#include "Base/Base.h"
#include <iostream>
#include <fstream>
#include "Utility/FileSystem.h"
const std::string Base::ReadmeTplPath = "./res/readme.tpl";
const std::string MakefileTplPath = "./res/makefile.tpl";

Base::Base(std::string pName){
	ProjectName = pName;
	ConstructKey();
	//std::cout<<"In Constructor"<<std::endl;
}

Base::~Base(){
	//std::cout<<"In Destructor"<<std::endl;
}

void Base::CreateRootDir(){
	FileSystem().CreateDirectory(ProjectName);
}

void Base::CreateProjectTree(){
	//Creates Project Tree
	if (ProjectName != "."){
		CreateRootDir();
	}
	FileSystem().CreateDirectory(ProjectName+R"(\src)");
	FileSystem().CreateDirectory(ProjectName+R"(\include)");
	CreateReadme();		
}

void Base::CreateReadme(){
	std::ifstream ReadMeTemplate;
	ReadMeTemplate.open(ReadmeTplPath, std::ios::in);
	if(ReadMeTemplate){
		std::string CurrentLine;
		while(std::getline(ReadMeTemplate, CurrentLine)){
			std::cout<<CurrentLine<<std::endl;
			std::string ParsedString = ParseAndReplace(CurrentLine);
		}
	} else {
		std::cout<<" No file "<<std::endl;
	}




}

std::string Base::ParseAndReplace(std::string RawLine){
	int StrLen = RawLine.length();
	std::string StartString, EndString; 
	if (StrLen>4){
		for (int i=0; i<StrLen-4; i++){
				if (StartString == "{{") break;			
		}
		
		}
	}



}

void Base::ConstructKey(){
	Stamp = {
		{"ProjectName",ProjectName}, 
		{"Author","SciMad"}, 
		{"Now","1234"}, 
		{"Email", "scimad@sci.pk"}
	};


	for( auto itr = Stamp.begin(); itr != Stamp.end();itr++){
		std::string Key = itr->first;
		std::string Value = itr->second;
		std::cout<<Key<<" is "<<Value<<std::endl;
	}
}