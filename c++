#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool openFile(ifstream &fin);
//void countLines(istream& inf, string arr[15][26][200], int arrS[15][26]);


int main() {


	string array[25][26][400];

	int array_size[25][26] = { 0 };

	string searchKey;



	ifstream fin;

	if (openFile(fin)) {
		int size;
		string line;
		char letter;
		while (getline(fin, line)) {
			size = line.size();
			cout << size << endl;
			letter = line[0];
			if (letter > 90)
				letter = letter - 97;
			else
				letter = letter - 65;

			array[size-1][letter][array_size[size-1][letter]] = line;
			array_size[size-1][letter]++;
		}

	}
	else
		cout << "File could not be opened. Goodbye.";
	bool match = false;
	int tempSize;
	int sum = 0;
	int sum2 = 0;

	int tempchar;
		do {
			sum = 0;
			cout << "Enter the word to search for: ";
			cin >> searchKey;
			int tempSize = searchKey.size();
			for (int i = 0; i < tempSize; i++)
				sum += searchKey[i];

			int tempchar = searchKey[0] - 97;

			cout << "temchar is " << tempchar << " tempsize is " << tempSize << endl;
			cout << "sum is " << sum << endl;
			for (int l = 0; l < tempSize; l++) {

				tempchar = searchKey[l] - 97;

				for (int i = 0; i < array_size[tempSize - 1][tempchar]; i++)
				{
					sum2 = 0;
					for (int j = 0; j < tempSize; j++) {
						sum2 += array[tempSize - 1][tempchar][i][j];

					}

				//	cout << "sum 2 is " << sum2 << endl;
					if (sum == sum2) {
						cout << searchKey << " is an anagram with " << array[tempSize - 1][tempchar][i] << endl;
						match = true;
					}

				}
				if (match == false)
					cout << "no mwatch was found.";
			}
		} while (searchKey != "exit!");



/*
	cout << "a is at " << array[0][0][0] << endl;
	cout << "a is at " << array[5][25][0] << endl;
	cout << "a is at " << array[2][3][0] << endl;
	cout << "a is at " << array[5][2][0] << endl;
	int d = 1;
	for (int i = 0; i < array_size[4][1]; i++)
		cout << array[4][1][i] <<  "    " << array[4][1][i][0] * 1<< "       "<<  d++ <<  endl;
		*/
	system("pause");
}

bool openFile(ifstream &fin)
{
	string file_name;
	cout << "Enter file name including the path: ";
	getline(cin, file_name);

	fin.open(file_name);

	if (fin.fail())
		return false;
	else
		return true;


}
