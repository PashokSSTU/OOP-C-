#include <iostream>
#include "Calculate.h"

int main()
{
	Calculate obj1;
	Calculate obj2;
	Calculate obj3;

	obj1.setValues(6,1);
	obj2.setValues(34,3623);

	obj3 = obj1 + obj2++;
	obj3.printValues();
	
	std::cout << std::endl;

	obj2.printValues();

	return 0;
}