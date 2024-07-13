#include <iostream>

#include "project_metadata.h"

#include "mylib/lib_functions.h"

int main(){
	std::cout << std::endl;
	std::cout << "Hello, CMake!\n";

	std::cout << "Project name: " << metadata::projectName << '\n';
	std::cout << "Version: " << metadata::version << '\n';
	std::cout << "Major: " << metadata::versionMajor << '\n';
	std::cout << "Minor: " << metadata::versionMinor << '\n';
	std::cout << "Patch: " << metadata::versionPatch << '\n';
	std::cout << std::endl;
	 
	static constexpr auto cv = 90;
	std::cout << "static constexpr auto cv = " << cv << '\n';
	std::cout << "getFrom3WayOperator(): " << std::boolalpha << getFrom3WayOperator() << '\n';
	std::cout << "Call to lib function: " << getInt() << '\n';

	return 0;
}