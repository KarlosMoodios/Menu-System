
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP  (vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 0 : 1)

using namespace std;

void gotoxy(int, int);              //declare a function called gotoxy
void clrscr(void);                 //declare clear screen function
void textcolor(int);               //declare text colour function
void hline(int, int, int, int);
void vline(int, int, int, int);
void invader1(int, int, int);        //draw invader(x,y,colour)
void invader2(int, int, int);        //draw invader(x,y,colour)
char z = 219;

int a[80][25];
int b[80][25];
int x, y, c = 0, i;


void main(void)//main program start
{
	int choice;

	do
	{
		do
		{
			textcolor(15);
			clrscr();
			gotoxy(30, 18);
			cout << "Press (1) Flying Ironman";
			gotoxy(30, 20);
			cout << "Press (2) Game of Life";
			gotoxy(30, 22);
			cout << "Press (3) Random blocks";
			gotoxy(30, 24);
			cout << "Press (4) Exit";
			gotoxy(30, 26);
			cout << "Enter 1, 2, 3, or 4 - ";
			choice = _getch();
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
		//------------------------------------------------------------------1-----------------------------------------------------------
		if (choice == '1') {
			int x = 10, y = 10, vx = 1, vt = 0;


			DWORD   t1, t2;

			t1 = GetTickCount();
			do
			{
				t2 = GetTickCount();//check time
				if (t2 - t1>100)
				{
					t1 = t2;
					if (KEY_DOWN(VK_LEFT)){
						x--;
						if (x<1) x = 1;
					}
					if (KEY_DOWN(VK_RIGHT)){
						x++;
						if (x>49) x = 49;
					}
					if (KEY_DOWN(VK_UP)){
						y--;
						if (y<1) y = 1;
					}
					if (KEY_DOWN(VK_DOWN)){
						y++;
						if (y>23) y = 23;
					}

					//now draw 
					clrscr();
					if (vt == 0)//vt is a flip flop switch to draw vader1 then vader2 
					{
						invader1(x, y, 10);
						vt = 1;
					}
					else
					{
						invader2(x, y, 12);
						vt = 0;
					}

				}
			} while (!KEY_DOWN(VK_ESCAPE));
		}
		//------------------------------------------------------------------2-----------------------------------------------------------
		if (choice == '2') {
			//randomise the random number generator
			srand((unsigned)time(NULL));
			//randomly set array a
			for (x = 0; x<80; x++)
			{
				for (y = 0; y<25; y++)
				{
					a[x][y] = (int)((rand() / (float)RAND_MAX)*2.0);
					//cout<<a[x][y]<<" ";
				}
			}
			{
				do {
					clrscr();
					//view array a
					for (x = 0; x<80; x++)
					{
						for (y = 0; y<25; y++)
						{
							gotoxy(x, y);
							if (a[x][y] == 1) cout << z;
							textcolor(3);
						}
					}
					//calculate next generation
					for (x = 1; x<79; x++)
					{
						for (y = 1; y<24; y++)
						{
							c = 0;
							if (a[x - 1][y - 1] == 1) c++;//top left
							if (a[x][y - 1] == 1) c++;//top middle
							if (a[x + 1][y - 1] == 1) c++;//top right
							if (a[x - 1][y] == 1) c++;//middle left
							if (a[x + 1][y] == 1) c++;//middle right
							if (a[x - 1][y + 1] == 1) c++;//bottom left
							if (a[x][y + 1] == 1) c++;//bottom middle
							if (a[x + 1][y + 1] == 1) c++;//bottom right

														  //game of life rules
							if (a[x][y] == 1 && c<2) b[x][y] = 0;
							if (a[x][y] == 1 && (c == 2 || c == 3)) b[x][y] = 1;
							if (a[x][y] == 1 && c>3) b[x][y] = 0;
							if (a[x][y] == 0 && c == 3) b[x][y] = 1;
						}
					}

					//copy b to a
					for (x = 0; x<80; x++)
					{
						for (y = 0; y<25; y++)
						{
							a[x][y] = b[x][y];
						}
					}
					Sleep(5);
					if (KEY_DOWN(VK_SPACE))
					{
						for (x = 0; x<80; x++)
						{
							for (y = 0; y<25; y++)
							{
								a[x][y] = rand() % 2;
								//cout<<a[x][y]<<" ";
							}
						}
					}


				} while (!KEY_DOWN(VK_ESCAPE));
			}
		}
		//------------------------------------------------------------------3-----------------------------------------------------------
		if (choice == '3')

		{
			//randomise the random number generator
			srand((unsigned)time(NULL));
			clrscr();
			do
			{
            x=rand()%80;
			y=rand()%50;
			c=rand()%16;
			gotoxy(x,y);
			z=rand()%222+32;
			textcolor(c);
			cout<<z;
			}
			while (!KEY_DOWN(VK_ESCAPE));
			z=219;
			
			/*//randomly set array a
			for (x = 0; x < 80; x++)
			{
				for (y = 0; y < 25; y++)
				{
					a[x][y] = (int)((rand() / (float)RAND_MAX)*2.0);
					//cout<<a[x][y]<<" ";
				}
			}
			{
				for (i = 0; i < 1000; i++) {
					clrscr();
					//view array a
					for (x = 0; x < 80; x++)
					{
						for (y = 0; y < 25; y++)
						{
							gotoxy(x, y);
							if (a[x][y] == 1) cout << z;
							textcolor(rand() % 16);

						}
					}
					Sleep(500);
				}
			}*/
	}//end of choice 3
	
	}
		while (choice != '4');
}//end of the main code


 //put functions here


 //Alter the code below at your peril!!!! 
 //It defines the textcolor,gotoxy and clrscr functions
void textcolor(int c)
{
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
}
void gotoxy(int x, int y)         //define gotoxy function
{
	static HANDLE hStdout = NULL;
	COORD coord;

	coord.X = x;
	coord.Y = y;
	if (!hStdout) { hStdout = GetStdHandle(STD_OUTPUT_HANDLE); }
	SetConsoleCursorPosition(hStdout, coord);
}
void clrscr(void)
{
	static HANDLE hStdout = NULL;
	static CONSOLE_SCREEN_BUFFER_INFO csbi;
	const COORD startCoords = { 0,0 };
	DWORD dummy;

	if (!hStdout)
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdout, &csbi);
	}
	FillConsoleOutputCharacter(hStdout, ' ', csbi.dwSize.X * csbi.dwSize.Y, startCoords, &dummy);
	gotoxy(0, 0);
}


void hline(int x, int y, int l, int c)
{
	int i;//notice i is moved from main() to hline()

	textcolor(c);
	for (i = 0; i<l; i++)
	{
		gotoxy(i + x, y);
		cout << z;
	}
}

void invader1(int x, int y, int c)

{ //grey outline
	hline(x + 14, y, 3, 8);
	hline(x + 12, y + 1, 7, 8);
	hline(x + 11, y + 2, 9, 8);
	hline(x + 10, y + 3, 11, 8);
	hline(x + 10, y + 4, 11, 8);
	hline(x + 9, y + 5, 13, 8);
	hline(x + 9, y + 6, 13, 8);
	hline(x + 9, y + 7, 13, 8);
	hline(x + 10, y + 8, 11, 8);
	hline(x + 8, y + 9, 15, 8);
	hline(x + 5, y + 10, 22, 8);
	hline(x, y + 11, 31, 8);
	hline(x, y + 12, 31, 8);
	hline(x + 1, y + 13, 29, 8);
	hline(x + 9, y + 14, 14, 8);
	hline(x + 10, y + 15, 11, 8);
	hline(x + 10, y + 16, 11, 8);
	hline(x + 11, y + 17, 9, 8);
	hline(x + 11, y + 18, 9, 8);
	hline(x + 11, y + 19, 9, 8);
	hline(x + 10, y + 20, 11, 8);
	hline(x + 9, y + 21, 13, 8);
	hline(x + 9, y + 22, 6, 8);
	hline(x + 8, y + 23, 7, 8);
	hline(x + 6, y + 24, 8, 8);
	hline(x + 5, y + 25, 9, 8);
	hline(x + 5, y + 26, 9, 8);
	hline(x + 16, y + 22, 6, 8);
	hline(x + 17, y + 23, 6, 8);
	hline(x + 17, y + 24, 8, 8);
	hline(x + 17, y + 25, 9, 8);
	hline(x + 17, y + 26, 9, 8);

	//red
	hline(x + 14, y + 1, 3, 12);
	hline(x + 14, y + 2, 3, 12);
	hline(x + 15, y + 3, 1, 12);
	hline(x + 11, y + 4, 9, 12);
	hline(x + 10, y + 5, 2, 12);
	hline(x + 19, y + 5, 2, 12);
	hline(x + 10, y + 6, 1, 12);
	hline(x + 20, y + 6, 1, 12);
	hline(x + 10, y + 7, 11, 12);
	hline(x + 11, y + 8, 1, 12);
	hline(x + 19, y + 8, 1, 14);
	hline(x + 11, y + 9, 2, 12);
	hline(x + 18, y + 9, 2, 14);
	hline(x + 8, y + 10, 2, 12);
	hline(x + 11, y + 10, 2, 12);
	hline(x + 18, y + 10, 2, 12);
	hline(x + 21, y + 10, 2, 12);
	hline(x + 6, y + 11, 2, 12);
	hline(x + 10, y + 11, 1, 12);
	hline(x + 12, y + 11, 1, 12);
	hline(x + 18, y + 11, 1, 12);
	hline(x + 20, y + 11, 1, 12);
	hline(x + 23, y + 11, 2, 12);
	hline(x + 1, y + 12, 3, 12);
	hline(x + 7, y + 12, 1, 12);
	hline(x + 10, y + 12, 2, 12);
	hline(x + 13, y + 12, 5, 12);
	hline(x + 19, y + 12, 8, 12);
	hline(x + 28, y + 12, 2, 12);
	hline(x + 9, y + 13, 14, 12);
	hline(x + 10, y + 14, 3, 12);
	hline(x + 18, y + 14, 3, 12);
	hline(x + 11, y + 15, 2, 12);
	hline(x + 18, y + 15, 2, 12);
	hline(x + 11, y + 16, 3, 12);
	hline(x + 17, y + 16, 3, 12);
	hline(x + 12, y + 17, 3, 12);
	hline(x + 16, y + 17, 3, 12);
	hline(x + 12, y + 18, 7, 12);
	hline(x + 13, y + 19, 5, 12);
	hline(x + 10, y + 22, 1, 12);
	hline(x + 9, y + 23, 3, 12);
	hline(x + 8, y + 24, 5, 12);
	hline(x + 6, y + 25, 7, 12);
	hline(x + 20, y + 23, 2, 12);
	hline(x + 18, y + 24, 5, 12);
	hline(x + 18, y + 25, 7, 12);

	//white
	hline(x + 12, y + 6, 3, 15);
	hline(x + 16, y + 6, 3, 15);
	hline(x + 14, y + 15, 3, 15);
	hline(x + 15, y + 16, 1, 15);

	//yellow
	hline(x + 12, y + 2, 2, 14);
	hline(x + 17, y + 2, 2, 14);
	hline(x + 11, y + 3, 4, 14);
	hline(x + 16, y + 3, 4, 14);
	hline(x + 12, y + 4, 7, 14);
	hline(x + 14, y + 5, 3, 14);
	hline(x + 11, y + 6, 1, 14);
	hline(x + 19, y + 6, 1, 14);
	hline(x + 11, y + 7, 9, 14);
	hline(x + 12, y + 8, 7, 14);
	hline(x + 13, y + 9, 5, 14);
	hline(x + 13, y + 10, 1, 14);
	hline(x + 17, y + 10, 1, 14);
	hline(x + 5, y + 11, 1, 14);
	hline(x + 8, y + 11, 2, 14);
	hline(x + 14, y + 11, 3, 14);
	hline(x + 21, y + 11, 2, 14);
	hline(x + 25, y + 11, 2, 14);
	hline(x + 5, y + 12, 2, 14);
	hline(x + 8, y + 12, 2, 14);
	hline(x + 22, y + 12, 1, 14);
	hline(x + 24, y + 12, 2, 14);
	hline(x + 12, y + 19, 1, 14);
	hline(x + 19, y + 19, 1, 14);
	hline(x + 11, y + 20, 9, 14);
	hline(x + 10, y + 21, 5, 14);
	hline(x + 16, y + 21, 5, 14);
	hline(x + 11, y + 22, 3, 14);
	hline(x + 17, y + 22, 4, 14);
	hline(x + 12, y + 23, 2, 14);
	hline(x + 18, y + 23, 2, 14);
}

void invader2(int x, int y, int c)

{ //grey outline
	hline(x + 14, y, 3, 8);
	hline(x + 12, y + 1, 7, 8);
	hline(x + 11, y + 2, 9, 8);
	hline(x + 10, y + 3, 11, 8);
	hline(x + 10, y + 4, 11, 8);
	hline(x + 9, y + 5, 13, 8);
	hline(x + 9, y + 6, 13, 8);
	hline(x + 9, y + 7, 13, 8);
	hline(x + 10, y + 8, 11, 8);
	hline(x + 8, y + 9, 15, 8);
	hline(x + 5, y + 10, 22, 8);
	hline(x, y + 11, 31, 8);
	hline(x, y + 12, 31, 8);
	hline(x + 1, y + 13, 29, 8);
	hline(x + 9, y + 14, 14, 8);
	hline(x + 10, y + 15, 11, 8);
	hline(x + 10, y + 16, 11, 8);
	hline(x + 11, y + 17, 9, 8);
	hline(x + 11, y + 18, 9, 8);
	hline(x + 11, y + 19, 9, 8);
	hline(x + 10, y + 20, 11, 8);
	hline(x + 9, y + 21, 13, 8);
	hline(x + 9, y + 22, 6, 8);
	hline(x + 8, y + 23, 7, 8);
	hline(x + 6, y + 24, 8, 8);
	hline(x + 5, y + 25, 9, 8);
	hline(x + 5, y + 26, 9, 8);
	hline(x + 16, y + 22, 6, 8);
	hline(x + 17, y + 23, 6, 8);
	hline(x + 17, y + 24, 8, 8);
	hline(x + 17, y + 25, 9, 8);
	hline(x + 17, y + 26, 9, 8);

	//red
	hline(x + 14, y + 1, 3, 12);
	hline(x + 14, y + 2, 3, 12);
	hline(x + 15, y + 3, 1, 12);
	hline(x + 11, y + 4, 9, 12);
	hline(x + 10, y + 5, 2, 12);
	hline(x + 19, y + 5, 2, 12);
	hline(x + 10, y + 6, 1, 12);
	hline(x + 20, y + 6, 1, 12);
	hline(x + 10, y + 7, 11, 12);
	hline(x + 11, y + 8, 1, 12);
	hline(x + 19, y + 8, 1, 14);
	hline(x + 11, y + 9, 2, 12);
	hline(x + 18, y + 9, 2, 14);
	hline(x + 8, y + 10, 2, 12);
	hline(x + 11, y + 10, 2, 12);
	hline(x + 18, y + 10, 2, 12);
	hline(x + 21, y + 10, 2, 12);
	hline(x + 6, y + 11, 2, 12);
	hline(x + 10, y + 11, 1, 12);
	hline(x + 12, y + 11, 1, 12);
	hline(x + 18, y + 11, 1, 12);
	hline(x + 20, y + 11, 1, 12);
	hline(x + 23, y + 11, 2, 12);
	hline(x + 1, y + 12, 3, 12);
	hline(x + 7, y + 12, 1, 12);
	hline(x + 10, y + 12, 2, 12);
	hline(x + 13, y + 12, 5, 12);
	hline(x + 19, y + 12, 8, 12);
	hline(x + 28, y + 12, 2, 12);
	hline(x + 9, y + 13, 14, 12);
	hline(x + 10, y + 14, 3, 12);
	hline(x + 18, y + 14, 3, 12);
	hline(x + 11, y + 15, 2, 12);
	hline(x + 18, y + 15, 2, 12);
	hline(x + 11, y + 16, 3, 12);
	hline(x + 17, y + 16, 3, 12);
	hline(x + 12, y + 17, 3, 12);
	hline(x + 16, y + 17, 3, 12);
	hline(x + 12, y + 18, 7, 12);
	hline(x + 13, y + 19, 5, 12);
	hline(x + 10, y + 22, 1, 12);
	hline(x + 9, y + 23, 3, 12);
	hline(x + 8, y + 24, 5, 12);
	hline(x + 6, y + 25, 7, 12);
	hline(x + 20, y + 23, 2, 12);
	hline(x + 18, y + 24, 5, 12);
	hline(x + 18, y + 25, 7, 12);

	//white
	hline(x + 12, y + 6, 3, 12);
	hline(x + 16, y + 6, 3, 12);
	hline(x + 14, y + 15, 3, 15);
	hline(x + 15, y + 16, 1, 15);

	//yellow
	hline(x + 12, y + 2, 2, 14);
	hline(x + 17, y + 2, 2, 14);
	hline(x + 11, y + 3, 4, 14);
	hline(x + 16, y + 3, 4, 14);
	hline(x + 12, y + 4, 7, 14);
	hline(x + 14, y + 5, 3, 14);
	hline(x + 11, y + 6, 1, 14);
	hline(x + 19, y + 6, 1, 14);
	hline(x + 11, y + 7, 9, 14);
	hline(x + 12, y + 8, 7, 14);
	hline(x + 13, y + 9, 5, 14);
	hline(x + 13, y + 10, 1, 14);
	hline(x + 17, y + 10, 1, 14);
	hline(x + 5, y + 11, 1, 14);
	hline(x + 8, y + 11, 2, 14);
	hline(x + 14, y + 11, 3, 14);
	hline(x + 21, y + 11, 2, 14);
	hline(x + 25, y + 11, 2, 14);
	hline(x + 5, y + 12, 2, 14);
	hline(x + 8, y + 12, 2, 14);
	hline(x + 22, y + 12, 1, 14);
	hline(x + 24, y + 12, 2, 14);
	hline(x + 12, y + 19, 1, 14);
	hline(x + 19, y + 19, 1, 14);
	hline(x + 11, y + 20, 9, 14);
	hline(x + 10, y + 21, 5, 14);
	hline(x + 16, y + 21, 5, 14);
	hline(x + 11, y + 22, 3, 14);
	hline(x + 17, y + 22, 4, 14);
	hline(x + 12, y + 23, 2, 14);
	hline(x + 18, y + 23, 2, 14);
}