//Eric Audit
//COP2535.DM1 
//stacks
#include<iostream>
#include<fstream>
#include<stack>
#include<string>
using namespace std;

// Function prototypes
string fillArray(string &input);
bool balanced(string);

int main() 
{
	string input;
	fillArray(input);
	if (balanced(input))
		cout << "Balanced\n";
	else
		cout << "Not Balanced\n";
}

//*****************************************fucntion definitions*******************************//

string fillArray(string& input)
{
	ifstream inputFile("inputString.txt");
	if (!inputFile)
		cout << "Error opening data file.\n";
	else
	{ // Fill the string with data from the file
		getline(inputFile, input);
		inputFile.close();
	}
	return input;
}

bool balanced(string input)
{
	stack<char> Stack; //make a stack to load '(' and ')' into
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(') //if you find '(' push it into the stack
			Stack.push(input[i]);
		else if (input[i] == ')')  
		{
			if (Stack.empty()) // if you find ')' and the stack doesn't have any '(' return false.
				return false;
			else
				Stack.pop(); //if you find ')' and the stack has a '(' remove it.
		}
	}
	return true;
}