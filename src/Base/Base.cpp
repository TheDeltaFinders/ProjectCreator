#include "Base/Base.h"
#include <iostream>
#include <fstream>
#include "Utility/FileSystem.h"
#include "Utility/DateTime.h"

Project::Project(){

}

Project::~Project(){

}

const std::string Base::ReadmeTplPath = "./res/readme.tpl";
const std::string MakefileTplPath = "./res/makefile.tpl";
/*Base::Base(std::string pName){
	ProjectName = pName;
	ConstructKey();
	//std::cout<<"In Constructor"<<std::endl;
}*/

Base::Base(Project tProj){
    ProjectName = tProj.ProjectName;
    ConstructKey(tProj);
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
	FileSystem().CreateDirectory(ProjectName+R"(/src)");
	FileSystem().CreateDirectory(ProjectName+R"(/include)");
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
            std::cout<<ParsedString<<std::endl;
		}
	} else {
		std::cout<<" No file "<<std::endl;
	}
}

std::string Base::ParseAndReplace(std::string RawLine){
	int i,j, StrLen = RawLine.length();
	std::cout<<"Strlen = "<<StrLen<<std::endl;
    bool Found = false;
    std::string StartString, EndString, ParsedString = RawLine, TempKey; 
	if (StrLen>4){
		for (i=0; i<StrLen-4; i++){
            StartString = RawLine.substr(i,2);    
			if (StartString == "{{"){
                Found = true;
                break;
            }
		}
        if (Found){
            for (j=i; j<StrLen-4; j++){
                EndString = RawLine.substr(j,2);
                if (EndString == "}}"){
                    TempKey = RawLine.substr(i+2,j-(i+2));
                    //ParsedString = RawLine.substr(0,i) + Value from Key-Value pair + RawLine.substr(j+2)
                    ParsedString = RawLine.substr(0,i) + Stamp[TempKey] + RawLine.substr(j+2);
                    break;
                }
            }
        }  
	}
    return ParsedString;
}

void Base::ConstructKey(Project tProj){
	Stamp = {
		{"ProjectName",tProj.ProjectName}, 
		{"Author",tProj.Author}, 
		{"Now",DateTime().getTimeStamp()}, 
		{"Email", tProj.Email}
	};

	for( auto itr = Stamp.begin(); itr != Stamp.end();itr++){
		std::string Key = itr->first;
		std::string Value = itr->second;
		std::cout<<Key<<" is "<<Value<<std::endl;
	}
}