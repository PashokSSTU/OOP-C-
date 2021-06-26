#include <iostream>
#include "Tree.h"

int main()
{
	Tree obj;

	obj.Add(10);
	obj.Add(0);
	obj.Add(1);
	obj.Add(2);
	obj.Add(-10);
	obj.Add(-100);
	obj.Add(5);
	obj.Add(1024);

	obj.PrefixTree();
	std::cout << std::endl;
	obj.InfixTree();
	std::cout << std::endl;
	obj.PostfixTree();
	

	return 0;
}