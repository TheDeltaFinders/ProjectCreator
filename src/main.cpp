#include<iostream>
#include "Base/Base.h"
int main(){
	std::cout<<"Hello World!"<<std::endl;
	Base base("MyProject");
	base.CreateProjectTree();
}