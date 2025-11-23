#include "sequential_list.h"

using namespace std;

int main() 
{
	SequentialList myList;
	initializeList(&myList, 10);

	for (int i = 0; i < 10; i++)
	{
		insertElement(&myList, i, i * 10);
	}

	cout << "Size: " << getSize(&myList) << endl;
	cout << "Is empty: " << isEmpty(&myList) << endl;

	return 0;
}