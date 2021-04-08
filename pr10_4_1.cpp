#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

void CreateTXT(char* fname);
void PrintTXT(char* fname);
int ProcessTXTCheck(char* fname);

int main()
{
	char fname[61];
	char ch;
	do
	{
		cout << "--------------------------------\n";
		cout << "Main Menu\n";
		cout << "Please make your selection\n" << endl;
		cout << "[1] - Enter & Save Data\n" << endl;
		cout << "[2] - Load & Print Data\n" << endl;
		cout << "[3] - File Check\n" << endl;
		cout << "[0] - Exit\n";
		cout << "--------------------------------\n";
		cout << "Your Choise: "; cin >> ch;
		switch (ch)
		{
		case '0':
			cout << endl;
			cout << "Goodbye! See Ya Later, Aligator!!!";
			break;
		case '1':
			cout << "You Chosen [1] - Enter & Save Data:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			CreateTXT(fname);
			break;
		case '2':
			cout << "You Chosen [2] - Load & Print Data:\n";
			cin.get();
			cin.sync();
			cout << "Enter file name: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			PrintTXT(fname);
			break;
		case '3':
			cout << "You Chosen [3] - File Check:\n";
			cin.get();
			cin.sync();
			cout << "Enter File Name: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			ProcessTXTCheck(fname);
			break;
		default:
			cout << endl;
			cout << "--------------------------------\n";
			cout << "Main Menu\n";
			cout << "Please make your selection\n";
			cout << "[1] - Enter & Save Data\n" << endl;
			cout << "[2] - Load & Print Data\n" << endl;
			cout << "[3] - File Check\n" << endl;
			cout << "[0] - Exit\n";
			cout << "--------------------------------\n";
			cout << "Your Choise: "; cin >> ch;
		}
	} while (ch != '0');
	return 0;
}
void CreateTXT(char* fname)
{
	ofstream fout(fname);
	char ch;
	string s;
	do
	{
		cin.get();
		cin.sync();
		cout << "Enter Line: "; getline(cin, s);
		fout << s << endl;
		cout << "Continue? (Y/N): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}
void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string s;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << endl;
}
bool isNumberNormal(string s)
{
	for (int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]) == false) {
			return false;
		}
	}
	return true;
}
bool isNumberModified(string s)
{
	for (int i = 1; i < s.length(); i++) {
		if (isdigit(s[i]) == false) {
			return false;
		}
	}
	return true;
}
int ProcessTXTCheck(char* fname)
{
	ifstream fin(fname);
	string s;
	int minusnumb = 0;
	int plusnumb = 0;
	int zeronumb = 0;
	int word = 0;
	while (fin >> s)
	{
		if (s[0] == '-') {
			if (isNumberModified(s)) {
				minusnumb++;
			}
			else {
				word++;
			}
		}
		else if (s[0] == '+') {
			if (isNumberModified(s)) {
				plusnumb++;
			}
			else {
				word++;
			}
		}
		else if (s[0] == '0') {
			zeronumb++;
		}
		else if (isNumberNormal(s)) {
			plusnumb++;
		}
		else {
			word++;
		}
	}

	ofstream MyFile("result.txt");

	MyFile << "-=-=-=-=-=-(Result list)-=-=-=-=-=- \n";
	MyFile << plusnumb  << " - Positive Numbers Found \n";
	MyFile << minusnumb << " - Negative Numbers Found \n";
	MyFile << zeronumb << " - Zeros Found \n";
	MyFile << word << " - Words Found \n";

	MyFile.close();

	string myText;

	ifstream MyReadFile("result.txt");

	while (getline(MyReadFile, myText)) {
		cout << myText << '\n';
	}

	return 0;
}