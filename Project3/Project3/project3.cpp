//Eric Audit
//COP2535.DM1
//project 3 linked lists

#include<iostream>
#include<string>
#include<list>
#include<fstream>
using namespace std;
int main()
{
	//LinkedList<string> lister;
	list<char> myList,myList2;
	list<char>::iterator iter;
	// Open the file
	ifstream charFile("LinkedText.txt");
	if (!charFile)
	{
		cout << "Error in opening the file of numbers.";
		exit(1);
	}
	// Read the file into a linked list
	cout << "The contents of the file are: " << endl;
	char letter;
	while (charFile >> letter)
	{
		myList.push_back(letter);
	}
	for (iter = myList.begin(); iter != myList.end(); iter++)
		cout << *iter;
	cout << endl;
	myList.swap(myList2);
	myList2.reverse();
	cout << "The contents of the file reversed are: " << endl;
	for (iter = myList2.begin(); iter != myList2.end(); iter++)
		cout << *iter;
	cout << endl;
	charFile.close();
	return 0;
}