#include <compare>

#include "lib_functions.h"

int getInt(){
	static constexpr int v = 77;
	return v;
}

bool getFrom3WayOperator(){
	static constexpr int v = 11;
	return (v <=> 22) < 0;
}
