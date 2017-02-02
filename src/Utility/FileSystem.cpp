#include <cstdlib>
#include "Utility/FileSystem.h"

FileSystem::FileSystem(){}
FileSystem::~FileSystem(){}


void FileSystem::CreateDirectory(std::string Folder){
	std::system(("mkdir " + Folder).c_str());
}
