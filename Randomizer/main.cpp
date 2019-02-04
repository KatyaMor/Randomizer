#include <iostream>
#include <vector>
#include "hist.h"
#include "rand.h"

using namespace std;

int main()
{
	int choice = 0;
	
	while (choice != 666)
	{
		cout << "\nEnter a number of method(1 - 10), please:  ";
		cout << "\n__Enter 666 if you want to exit))\n";
		cin >> choice;
		switch (choice)
		{
		case 1: histogram(rand1, 0, 1, 10);break;
		case 2: histogram(rand2, 0, 1, 10);break;
		case 3: histogram(rand3, 0, 1, 10);break;
		case 4: histogram(rand4, 0, 1, 10);break;
		case 5: histogram(rand5, 0, 1, 10);break;
		case 6: histogram(rand6, -3, 3, 10);break;
		case 7: histogram(rand7, -3, 3, 60);break;
		case 8: histogram(rand8, -3, 3, 60);break;
		case 9: histogram(rand9, 0, 100, 100);break;
		case 10: histogram(rand10, 0, 100, 100);break;
		default: cout << "\n!!!Something wrong, try again!!!\n";
		}
	}
	system("pause");
	return 0;
}