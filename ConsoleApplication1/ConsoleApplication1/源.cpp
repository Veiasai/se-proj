#include <iostream>
#include"516030910237.h"
using namespace std;

int main()
{
	int arr[6] = { 2,3,3,4,3,5 };
	List list1(arr, 6);
	list1.insert(3, 6);
	list1.printAll();
	// Your output should be: 2 3 3 6 4 3 5
	cout << list1.remove(3) << endl;
	// Your output should be: 3
	cout << list1.length() << endl;
	// Your output should be: 4
	return 0;
}