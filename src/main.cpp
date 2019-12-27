#include "include/chapter1.h"

#include <map>
#include <functional>

#define STR(s) #s
#define COMBINE(chapter, execise) std::string("TestC") + STR(chapter) + "E" + STR(execise)

void BuildFunctionMap(std::map< std::string, std::function<void()> > *function_map) {
	function_map->insert({ "TestC1E1", TestC1E1 });
	function_map->insert({ "TestC1E2", TestC1E2 });
	function_map->insert({ "TestC1E3", TestC1E3 });
}

int main()
{
	std::map< std::string, std::function<void()> > funtion_map;
	BuildFunctionMap(&funtion_map);
	funtion_map[COMBINE(1, 3)]();
	return 0;
}
