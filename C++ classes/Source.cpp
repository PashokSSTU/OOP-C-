#include <iostream>
#include "Calculate.h"

int main()
{
	Calculate obj1;
	Calculate obj2;
	Calculate obj3;

	obj1.setValues(6,1);
	obj2.setValues(34, 3623);

	if (!obj1)
	{
		std::cout << "obj1 is null " << std::endl;
	}
	else
	{
		std::cout << "obj1 is not null " << std::endl;
	}

	if (!obj2)
	{
		std::cout << std::endl << "obj2 is null " << std::endl;
	}
	else
	{
		std::cout << std::endl << "obj2 is not null " << std::endl;
	}

	if (!obj3)
	{
		std::cout << std::endl << "obj3 is null " << std::endl;
	}
	else
	{
		std::cout << std::endl << "obj3 is not null " << std::endl;
	}

	obj3 = obj1 + obj2;
	std::cout << std::endl << "obj3 = obj1 + obj2: " << std::endl;
	obj3.printValues();

	obj3 = obj1 - obj2;
	std::cout << std::endl << "obj3 = obj1 - obj2: " << std::endl;
	obj3.printValues();

	obj3 = -obj3;
	std::cout << std::endl << "obj3 = -obj3: " << std::endl;
	obj3.printValues();

	return 0;
}