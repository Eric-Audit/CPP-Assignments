//Eric Audit
//COP2535.DM1 (XX = your section number)
//hopefully work! Also sort some stuff.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Function prototypes
void linearSearchList(const int[], int, int);
void binarySearch(const int[], int, int);
void bubbleSortArray(int[], int);
void selectionSort(int[], int);
void fillArray(int[], int);

int main()
{
	const int SIZE = 200;
	int array1[SIZE];
	int array2[SIZE];
	int magicNumber = 869;
	fillArray(array1, SIZE);
	fillArray(array2, SIZE);
	bubbleSortArray(array1, SIZE);
	selectionSort(array2, SIZE);
	linearSearchList(array1, SIZE, magicNumber);
	linearSearchList(array2, SIZE, magicNumber);
	binarySearch(array1, SIZE, magicNumber);
	binarySearch(array2, SIZE, magicNumber);
	return 0;

}

//******************************function definitions********************************//
	void fillArray(int array[], int size)
	{
		int count;
		ifstream inputFile("random.txt");
		if (!inputFile)
			cout << "Error opening data file.\n";
		else
		{ // Fill the array with data from the file
			for (count = 0; count < size; count++)
				inputFile >> array[count];
			inputFile.close();
		}
	}
	void linearSearchList(const int list[], int size, int value)
	{
		int count = 0; // lets see how many tries it takes.
		int index = 0; // Used as a subscript to search array
		bool found = false; // Flag to indicate if the value was found
		while (index < size && !found)
		{
			if (list[index] == value) // If the value is found
			{
				found = true; // Set the flag
			}
			index++; // We go again.
			count++; 
		}
		cout << "linear search of the array found 869 in " << count << " comparisons\n"; // lets see how many times it counted.
	}
	void binarySearch(const int array[], int size, int value)
	{
		int first = 0, // First array element
			last = size - 1, // Last array element
			middle, // Midpoint of search
			count = 1; // lets see how many tries it takes.
		bool found = false; // Flag
		while (!found && first <= last)
		{
			middle = (first + last) / 2; // Calculate midpoint
			if (array[middle] == value) // If value is found at mid
			{
				found = true;
			}
			else if (array[middle] > value) // If value is in lower half
			{
				last = middle - 1;
				count++;
			}
			else
			{
				first = middle + 1; // If value is in upper half
				count++;
			} 
		}
		cout << "binary search of the array found 869 in " << count << " comparisons\n";
	}
	void bubbleSortArray(int array[], int size)
	{
		int counter = 0;
		int temp;
		bool swap;
		do
		{
			swap = false;
			for (int count = 0; count < (size - 1); count++)
			{
				if (array[count] > array[count + 1])
				{
					temp = array[count];
					array[count] = array[count + 1];
					array[count + 1] = temp;
					swap = true;
					counter++;
				}
			}
		} while (swap); // Loop again if a swap occurred on this pass.
		cout << "bubble sort performed in " << counter << " exchanges.\n";
	}
	void selectionSort(int array[], int size)
	{
		int counter = 0;
		int startScan, minIndex, minValue;
		for (startScan = 0; startScan < (size - 1); startScan++)
		{
			minIndex = startScan;
			minValue = array[startScan];
			for (int index = startScan + 1; index < size; index++)
			{
				if (array[index] < minValue)
				{
					minValue = array[index];
					minIndex = index;
					counter++;
				}
			}
			array[minIndex] = array[startScan];
			array[startScan] = minValue;
		}
		cout << "selection sort performed in " << counter << " exchanges.\n";
	}

