#include<iostream>
#include "Base/Base.h"
int main(){
    Project newProject;
	std::cout<<"CreateProjectTree"<<std::endl;
	std::cout<<"-----------------"<<std::endl;
    std::cout<<"Name of Project:";
    std::cin>>newProject.ProjectName;
    std::cout<<"Author:";
    std::cin>>newProject.Author;
    std::cout<<"Email:";
    std::cin>>newProject.Email;

    Base base(newProject);
	base.CreateProjectTree();
}