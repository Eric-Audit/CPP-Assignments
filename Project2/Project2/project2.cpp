//Eric Audit
//COP2535.DM1
//project 2 String Bound Exceptions

#include<iostream>
#include<string>
using namespace std;

class BCheckString
{
private:
	string input;
public:
	//exception class
	class BoundsException
	{};
	//member functions
	BCheckString(string input)
	{
		this->input = input;
	}
	char operator[](int k)
	{
		if (k < 0 || k >= input.length())
			throw BoundsException();
		return input[k];
	}
};
			

int main()
{
	char element;
	string userInput;
	int userValue;
	cout << "This program demonstrates bounds checking on a string object.\n";
	cout << "Enter a string: ";
	getline(cin, userInput);
	cout << "Legitimate string positions are: 0.." << (userInput.size() - 1) << "\n";
	BCheckString string1(userInput);
	cout << "Enter an integer describing a position inside or outside the string: ";
	cin >> userValue;
	try
	{
		element = string1[userValue];
		cout << "The character at position " << userValue << " is: " << element << "\n";
	}
	catch (BCheckString::BoundsException)
	{
		cout << "Access violation in string.\n";
	}
}