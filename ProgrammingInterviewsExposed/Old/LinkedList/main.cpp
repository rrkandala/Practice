#include "LinkedList.h"
#include "Node.cpp"
#include "LinkedList.cpp"

int main(int argc, const char *argv[])
{
	LinkedList<int> list1;
	
	cout << "Created an empty list" << endl;
	cout << "List 1: ";
	list1.traverse();
	
	LinkedList<string> list2("10");
	
	cout << "Created Second list" << endl;
	list2.add("20");
	list2.add("30");
	cout << "List 2: ";
	list2.traverse();

	LinkedList<double> list3(1.2);

	cout << "Created Third list" << endl;
	list3.add(2.3);
	list3.add(3.4);
	cout << "List 3: ";
	list3.traverse();
	
	system("pause");
	return 0;
}