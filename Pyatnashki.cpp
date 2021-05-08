#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>

#define SPACE_SHIFT "-----------------------\n"

using namespace std;

void Random_field(int**& field, int n1, int n2);
bool Chek_NULL_field(int**& field, int n1, int n2);
void Show_field(int**& field, int n1, int n2);
void Move(int**& field, int n1, int n2);


int main()
{
	setlocale(LC_ALL, "ru");
	const int n1 = 4;
	const int n2 = 4;
	int** field = new int* [n1]{};
	for (int i = 0; i < n1; i++)
	{
		field[i] = new int [n2] {};
	}
	Random_field(field, n1, n2);
	Show_field(field, n1, n2);
	
}

void Move(int**& field, int n1, int n2)
{
	bool c = false;
	char a = 0;
	do
	{
		cout << "\tW\n\tA\tS\tD\n\nСделайте ход\n";
		a = _getch();
		if (a == 'W' || a == 'A' || a == 'S' || a == 'D') c = true;
	} while (false);
	
	switch (a)
	{
	 case 'W':
	 {
	    
	 }
	 case 'S':
	 {

	 }
	 case 'A':
	 {

	 }
	 case 'D':
	 {

	 }
	}
}

void Random_field(int**& field, int n1, int n2)
{
	for (int i = 1; i < 16; i++)
	{
		bool c = false;
		do
		{
			int m1 = rand() % 4;
			int m2 = rand() % 4;
			if (Chek_NULL_field(field, m1, m2))
			{
				field[m1][m2] = i;
				c = true;
			}
		} while (c == false);
	}
}
bool Chek_NULL_field(int**& field, int n1,int n2)
{		
	return field[n1][n2] == 0 ? true : false;
}
void Show_field(int**& field, int n1, int n2)
{
	system("cls");
	cout << endl << endl << endl << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << "\t" << "\t" << "\t";

		for (int j = 0; j < 4; j++)
		{
			if (field[i][j] == 0)cout << "\t" << "|*|";
			else cout << "\t" << field[i][j] ;
		}
		cout << endl << endl;
	}
	Move(field, 4, 4);
}
