#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>

#define SPACE_SHIFT "-----------------------\n"

using namespace std;

void Random_field(int**& field, int n1, int n2);
void Standart_field(int**& field, int n1, int n2);
bool Chek_NULL_field(int**& field, int n1, int n2);
void Show_field(int**& field, int n1, int n2);
void Move(int**& field, int n1, int n2);
void Zero_koord(int& a, int& b, int**& field);
bool win(int**& field);


int main()
{
	setlocale(LC_ALL, "ru");
	const int n1 = 4;
	const int n2 = 4;
	int** field = new int* [n1] {};
	for (int i = 0; i < n1; i++)
	{
		field[i] = new int [n2] {};
	}
	cout << "1)Стандартное расположение чисел\n2)Случайное расположение чисел\n";
	int a = _getch();
	system("cls");
	switch (a)
	{
	case '1':
	{
		Standart_field(field, n1, n2);
		Show_field(field, n1, n2);
		break;
	}
	case '2':
	{
       Random_field(field, n1, n2);
	   Show_field(field, n1, n2);
	   break;
	}
    }
	
	
}

void Move(int**& field, int n1, int n2)
{
	static int schet = 0;
	if (win(field) == true && schet>1)
	{
		char sw = 0;
		bool a = false;
		cout << "\n\n\tWIN ("<< schet <<" ходов)!\nЕще разочек? y/n\n";
		do 
		{
			sw = _getch();
			if (sw == 'y' || sw == 'n') a = true;
		} while (a == false);
		switch (sw)
		{
		case 'y':
		{
			system("cls");
			for (int i = 0; i < 4; i++)
			{
				delete[] field[i];	
			}
			delete[] field;
			schet = 0;
			main();
		}
		case 'n':
		{
			exit(0);
		}
		}
	}
	schet++;


	bool c = false;
	char a = 0;
	do
	{
		cout << "\t\tW\n\n\tA\tS\tD\n\nСделайте ход\t\t\t\t\t\t\t\tНажмите Esc для выхода\n";
		a = _getch();
		if (a == 'w' || a == 'a' || a == 's' || a == 'd'|| a == 27) c = true;
	} while (c == false);
	
	switch (a)
	{
	 case 'w':
	 {
		 int a = 0;
		 int b = 0;
		 Zero_koord(a, b, field);
		 if (a == 0)
		 {
			 cout << "\nПопытка выхода за пределы поля, выберите другое направление\n";
			 schet--;
			 Move(field, 4, 4);
		 }
		 else
		 {
			 field[a][b] = field[a - 1][b];
			 field[a - 1][b] = 0;

		 }
		 Show_field(field, 4, 4);
	 }
	 case 's':
	 {
		 int a = 0;
		 int b = 0;
		 Zero_koord(a, b, field);
		 if (a == 3)
		 {
			 cout << "\nПопытка выхода за пределы поля, выберите другое направление\n";
			 schet--;
			 Move(field, 4, 4);
		 }
		 else
		 {
			 field[a][b] = field[a + 1][b];
			 field[a + 1][b] = 0;

		 }
		 Show_field(field, 4, 4);
	 }
	 case 'a':
	 {
		 int a = 0;
		 int b = 0;
		 Zero_koord(a, b, field);
		 if (b == 0)
		 {
			 cout << "\nПопытка выхода за пределы поля, выберите другое направление\n";
			 schet--;
			 Move(field, 4, 4);
		 }
		 else
		 {
			 field[a][b] = field[a][b-1];
			 field[a][b-1] = 0;

		 }
		 Show_field(field, 4, 4);
	 }
	 case 'd':
	 {
		 int a = 0;
		 int b = 0;
		 Zero_koord(a, b, field);
		 if (b == 3)
		 {
			 cout << "\nПопытка выхода за пределы поля, выберите другое направление\n";
			 schet--;
			 Move(field, 4, 4);
		 }
		 else
		 {
			 field[a][b] = field[a][b + 1];
			 field[a][b + 1] = 0;

		 }
		 Show_field(field, 4, 4);
	 }
	 case 27:
	 {
		 exit(0);
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
void Standart_field(int**& field, int n1, int n2)
{
	int schetchik = 1;
	for (int i = 0; schetchik < 16; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{
			field[i][j] = schetchik;
			schetchik++;
		}
	}
	field[3][3] = 0;
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
void Zero_koord(int& a, int& b, int**& field)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (field[i][j] == 0)
			{
				a = i;
				b = j;
			}
		}
	}
}
bool win(int**& field)
{
	int schetchik = 1;
	for (int i = 0; i < 4; i++)
	{

		for (int j = 0; j < 4; j++)
		{
			if (schetchik == 16)return true;
			if (field[i][j] != schetchik)return false;
			schetchik++;
		}
	}
	return true;
}

