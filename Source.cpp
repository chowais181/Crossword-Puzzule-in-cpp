#include <iostream>
#include<fstream>
#include<windows.h>
#include<ctime>
#include<cstring>
#include<string>
#include<iomanip>

using namespace std;


void start();
void game();
void end();
void center();
void halfcenter();
void resume();
void quick();
void time();
void survival();
void besttime();
void highscore();
void instruction();
void setting();
void level();
void bgcolor();
void sound();
void changebgcolor(char);
void backup();
char getlevel();
void easymode();
void mediummode();
void hardmode();
void clear(int arr[][2]);
void loadsavedfile(char puz[][16], string words[][4]);
void playgame(char puz[][16], string words[][4]);
void display(char puz[][16], string words[][4]);
void print(int chkchr[][2], int, int, char puz[][16]);
void print(int, int, string[][4]);
void loadarray(int arr[][2]);
void savedatavalue(int, int, int, int);
void savedatakey(int, int);
void inputchecking(int, int, int, int);
void newgame();
void newload();
void rowstring(int, int, int, int);
void colstring(int, int, int, int);
void digstring(int, int, int, int);
void rowstringinv(int, int, int, int);
void colstringinv(int, int, int, int);
void digstringinv(int, int, int, int);
void antidigstring(int, int, int, int);
void antidigstringinv(int, int, int, int);
void strtochr(char[], string);
void clearsavedmaze();
void clearsavedkey();
void beep();
void newbesttime(string);
void newhighscore(int);
void coldisplay();
void colnumdisplay();
void rownumdisplay(int);






//cmtmain
int main()
{
	start();
	game();
	end();


	return 0;
}



//cmtstart
void start()
{
	for (int a = 3; a <= 100; a += 10)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		system("cls");
		cout << "\n\n\n\n\n";
		center();
		cout << "WELCOME TO WORD SEARCH" << endl;
		center();
		cout << "WELCOME TO WORD SEARCH" << endl;
		center();
		cout << "LOADING YOUR SETTINGS" << endl;
		Sleep(500);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
//cmtend
void end()
{
	for (int a = 3; a <= 100; a += 10)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
		system("cls");
		cout << "\n\n\n\n\n";
		for (int x = 0; x < 50; x++)
			cout << " ";
		cout << "THANK YOU FOR PLAYING" << endl;
		center();
		cout << "THANK YOU FOR PLAYING" << endl;
		center();
		cout << "SAVING YOUR SETTINGS..." << endl;
		Sleep(500);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}





//cmtreqfunctions
//cmtcenter
void center()
{
	for (int x = 0; x < 50; x++)
		cout << " ";
}
//cmthalfcenter
void halfcenter()
{
	for (int x = 0; x < 20; x++)
		cout << " ";
}
//cmtbackup
void backup()
{
	char chr;
	fstream file;
	file.open("bgcolor.txt");
	file.get(chr);
	changebgcolor(chr);
	file.close();
}








//cmtgamefunctions
//cmtgame
void game()
{
	int opt;
	for (; true;)
	{
		backup();
		system("cls");
		cout << endl;
		center();
		cout << "WORD SEARCH" << endl;
		cout << "\n\n\n\n\n";
		center();
		cout << "1 RESUME GAME" << endl;
		center();
		cout << "2 QUICK  PLAY" << endl;
		center();
		cout << "3 TIME ATTACK" << endl;
		center();
		cout << "4 SURVIVAL MODE" << endl;
		center();
		cout << "5 BEST TIME" << endl;
		center();
		cout << "6 HIGH SCORE" << endl;
		center();
		cout << "7 INSTRUCTIONS" << endl;
		center();
		cout << "8 SETTING" << endl;
		center();
		cout << "9 QUIT" << endl;
		center();
		cout << "press the option  :";
		cin >> opt;
		if (opt == 1)
			resume();
		else if (opt == 2)
			quick();
		else if (opt == 3)
			time();
		else if (opt == 4)
			survival();
		else if (opt == 5)
			besttime();
		else if (opt == 6)
			highscore();
		else if (opt == 7)
			instruction();
		else if (opt == 8)
			setting();
		else if (opt == 9)
			break;
		else
		{
			system("cls");
			cout << "\n\n\n\n\n";
			center();
			cout << "INVALID ENTERY";
			Sleep(600);
		}
	}
}










//cmtfunction-1
//cmtresume
void resume()
{
	char puz[14][16];
	string words[11][4];

	loadsavedfile(puz, words);
	playgame(puz, words);
}
//cmtloadsavedfile
void loadsavedfile(char puz[][16], string words[][4])
{
	fstream file, file2;
	string str;
	char chr;
	file.open("savedmaze.txt");
	file2.open("savedkey.txt");

	if (file.is_open())
	{
		for (int x = 0; x < 14; x++)
		{
			for (int y = 0; y < 16;)
			{
				chr = file.get();
				if (chr != ' '&&chr != '\n')
				{
					puz[x][y] = chr;
					y++;
				}

			}
		}
	}
	file.close();

	if (file2.is_open())
	{
		for (int x = 0; x < 11; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				getline(file2, str, ' ');
				words[x][y] = str;
			}
		}
	}
	file2.close();

}
//cmtplaygame
void playgame(char puz[][16], string words[][4])
{
	for (; true;)
	{
		display(puz, words);
		int a, b, c, d;
		cout << endl;
		center();
		cout << "input starting row of word  :";
		cin >> a;
		if (a == -1)
			break;
		center();
		cout << "input starting col of word  :";
		cin >> b;
		if (b == -1)
			break;
		system("cls");
		backup();
		display(puz, words);
		cout << endl;
		center();
		cout << "input ending row of word  :";
		cin >> c;
		if (c == -1)
			break;
		center();
		cout << "input ending col of word  :";
		cin >> d;
		if (d == -1)
			break;
		inputchecking(a, b, c, d);
	}
}
//cmtdisplay
void display(char puz[][16], string words[][4])
{
	int arr[224][2];
	loadarray(arr);
	system("cls");
	cout << "\n\n";
	coldisplay();
	for (int a = 0; a < 14; a++)
	{
		if (a == 0)
			colnumdisplay();
		rownumdisplay(a);
		if (a < 14)
			for (int x = 0; x < 16; x++)
			{
				print(arr, a, x, puz);
				cout << " ";
			}
		cout << "       ";
		if (a < 11)
			for (int y = 0; y < 4; y++)
			{
				print(a, y, words);
				cout << "  ";
			}
		cout << endl;
	}
}
//cmtloadarray
//cmtprint
//cmtcoldisplay
//colnumdisplay
//cmtrownumdisplay
void loadarray(int arr[][2])
{
	fstream file;
	file.open("arrayvalue.txt");
	for (int x = 0; x < 224; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			file >> arr[x][y];
		}
	}
	file.close();
}
void print(int chkchr[][2], int a, int x, char puz[][16])
{
	fstream file;
	file.open("bgcolor.txt");
	int val, m, c;
	file >> val;
	file.close();
	if (val == 1)
	{
		m = 4;
		c = 15;
	}
	else if (val == 2)
	{
		m = 20;
		c = 31;
	}
	else if (val == 3)
	{
		m = 36;
		c = 47;
	}
	else if (val == 4)
	{
		m = 84;
		c = 95;
	}

	for (int row = 0; row < 224; row++)
	{
		if (a == chkchr[row][0] && x == chkchr[row][1])
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m);
			break;
		}
	}
	cout << puz[a][x];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void print(int a, int b, string words[][4])
{
	fstream file;
	file.open("bgcolor.txt");
	int val, m, c;
	file >> val;
	file.close();
	if (val == 1)
	{
		m = 4;
		c = 15;
	}
	else if (val == 2)
	{
		m = 20;
		c = 31;
	}
	else if (val == 3)
	{
		m = 36;
		c = 47;
	}
	else if (val == 4)
	{
		m = 84;
		c = 95;
	}


	file.open("arraykey.txt");
	int arr[88][2];

	for (int x = 0; x < 88; x++)
		for (int y = 0; y < 2; y++)
			file >> arr[x][y];
	file.close();

	for (int x = 0; x < 88; x++)
	{
		if (arr[x][0] == a && arr[x][1] == b)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m);
			break;
		}
	}
	cout << words[a][b];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void coldisplay()
{
	fstream file;
	file.open("bgcolor.txt");
	int val, x, y;
	file >> val;
	file.close();

	if (val == 1)
	{
		x = 6;
		y = 15;
	}
	else if (val == 2)
	{
		x = 22
			; y = 31;
	}
	else if (val == 3)
	{
		x = 37;
		y = 47;
	}
	else if (val == 4)
	{
		x = 86;
		y = 95;
	}



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	halfcenter();
	cout << "                C" << endl;
	halfcenter();
	cout << "                O" << endl;
	halfcenter();
	cout << "                L" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);

}
void colnumdisplay()
{
	fstream file;
	file.open("bgcolor.txt");
	int val, x, y;
	file >> val;
	file.close();

	if (val == 1)
	{
		x = 6;
		y = 15;
	}
	else if (val == 2)
	{
		x = 22
			; y = 31;
	}
	else if (val == 3)
	{
		x = 37;
		y = 47;
	}
	else if (val == 4)
	{
		x = 86;
		y = 95;
	}


	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	cout << "    ";
	halfcenter();
	for (int x = 0, z = 1; x < 16; x++)
		if (x > 9)
			cout << z << " ";
		else
			cout << "  ";
	halfcenter();
	cout << "PRESS -1 TO RETURN TO LOBBY";

	cout << endl;
	halfcenter();
	cout << "    ";
	for (int x = 0, z = 0; x < 16; x++)
	{
		cout << z++ << " ";
		if (z == 10)
			z = 0;
	}
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);

}
void rownumdisplay(int a)
{
	fstream file;
	file.open("bgcolor.txt");
	int val, x, y;
	file >> val;
	file.close();

	if (val == 1)
	{
		x = 6;
		y = 15;
	}
	else if (val == 2)
	{
		x = 22
			; y = 31;
	}
	else if (val == 3)
	{
		x = 37;
		y = 47;
	}
	else if (val == 4)
	{
		x = 86;
		y = 95;
	}




	if (a == 7)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
		cout << "                ROWS";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);
	}
	if (a != 7)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
		halfcenter();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	cout << setw(3) << a << " ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), y);

}


//cmtinputchecking
void inputchecking(int a, int b, int c, int d)
{
	if (a == c && b < d)
		rowstring(a, b, c, d);
	else if (a < c&&b == d)
		colstring(a, b, c, d);
	else if ((a == b && c == d || (c - a) == (d - b)) && a < c)
		digstring(a, b, c, d);
	else if (a == c && b > d)
		rowstringinv(a, b, c, d);
	else if (a > c&&b == d)
		colstringinv(a, b, c, d);
	else if ((a == b && c == d || (a - c) == (b - d)) && a > c)
		digstringinv(a, b, c, d);
	else if (a + b == c + d && a < c)
		antidigstring(a, b, c, d);
	else if ((a + b == c + d) && a > c)
		antidigstringinv(a, b, c, d);
	else
	{
		system("cls");
		cout << endl;
		center();
		cout << "INVALID ENTERY";
		Sleep(1000);
	}
}


//cmtrowstring
void rowstring(int a, int b, int c, int d)
{
	char puz[14][16];
	string words[11][4];
	loadsavedfile(puz, words);

	char chr[15];
	int bc = b;

	for (int x = 0; bc <= d; bc++, x++)
	{
		chr[x] = puz[a][bc];
		chr[x + 1] = '\0';
	}


	string str;
	char chrstr[20];

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			str = words[x][y];
			strtochr(chrstr, str);
			if (strcmp(chr, chrstr) == 0)
			{
				savedatavalue(a, b, c, d);
				savedatakey(x, y);
				beep();
				break;
			}
			if (x == 10 && y == 3)
			{
				system("cls");
				cout << endl;
				center();
				cout << "NO MATCH FOUND";
				Sleep(1000);
			}
		}
		if (strcmp(chr, chrstr) == 0)
			break;
	}
}
void colstring(int a, int b, int c, int d)
{


	char puz[14][16];
	string words[11][4];
	loadsavedfile(puz, words);

	char chr[15];
	int ac = a;

	for (int x = 0; ac <= c; ac++, x++)
	{
		chr[x] = puz[ac][b];
		chr[x + 1] = '\0';
	}


	string str;
	char chrstr[20];

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			str = words[x][y];
			strtochr(chrstr, str);
			if (strcmp(chr, chrstr) == 0)
			{
				savedatavalue(a, b, c, d);
				savedatakey(x, y);
				beep();
				break;
			}
			if (x == 10 && y == 3)
			{
				system("cls");
				cout << endl;
				center();
				cout << "NO MATCH FOUND";
				Sleep(1000);
			}
		}
		if (strcmp(chr, chrstr) == 0)
			break;
	}

}
void digstring(int a, int b, int c, int d)
{
	char puz[14][16];
	string words[11][4];
	loadsavedfile(puz, words);

	char chr[15];
	int ac = a;
	int bc = b;

	for (int x = 0; ac <= c; ac++, bc++, x++)
	{
		chr[x] = puz[ac][bc];
		chr[x + 1] = '\0';
	}



	string str;
	char chrstr[20];

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			str = words[x][y];
			strtochr(chrstr, str);
			if (strcmp(chr, chrstr) == 0)
			{
				savedatavalue(a, b, c, d);
				savedatakey(x, y);
				beep();
				break;
			}
			if (x == 10 && y == 3)
			{
				system("cls");
				cout << endl;
				center();
				cout << "NO MATCH FOUND";
				Sleep(1000);
			}
		}
		if (strcmp(chr, chrstr) == 0)
			break;
	}
}
void rowstringinv(int a, int b, int c, int d)
{
	char puz[14][16];
	string words[11][4];
	loadsavedfile(puz, words);

	char chr[15];
	int bc = b;

	for (int x = 0; bc >= d; bc--, x++)
	{
		chr[x] = puz[a][bc];
		chr[x + 1] = '\0';
	}



	string str;
	char chrstr[20];

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			str = words[x][y];
			strtochr(chrstr, str);
			if (strcmp(chr, chrstr) == 0)
			{
				savedatavalue(a, b, c, d);
				savedatakey(x, y);
				beep();
				break;
			}
			if (x == 10 && y == 3)
			{
				system("cls");
				cout << endl;
				center();
				cout << "NO MATCH FOUND";
				Sleep(1000);
			}
		}
		if (strcmp(chr, chrstr) == 0)
			break;
	}


}
void colstringinv(int a, int b, int c, int d)
{
	char puz[14][16];
	string words[11][4];
	loadsavedfile(puz, words);

	char chr[15];
	int ac = a;

	for (int x = 0; ac >= c; ac--, x++)
	{
		chr[x] = puz[ac][b];
		chr[x + 1] = '\0';
	}



	string str;
	char chrstr[20];

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			str = words[x][y];
			strtochr(chrstr, str);
			if (strcmp(chr, chrstr) == 0)
			{
				savedatavalue(a, b, c, d);
				savedatakey(x, y);
				beep();
				break;
			}
			if (x == 10 && y == 3)
			{
				system("cls");
				cout << endl;
				center();
				cout << "NO MATCH FOUND";
				Sleep(1000);
			}
		}
		if (strcmp(chr, chrstr) == 0)
			break;
	}

}
void digstringinv(int a, int b, int c, int d)
{
	char puz[14][16];
	string words[11][4];
	loadsavedfile(puz, words);


	char chr[15];
	int ac = a;
	int bc = b;

	for (int x = 0; ac >= c; ac--, bc--, x++)
	{
		chr[x] = puz[ac][bc];
		chr[x + 1] = '\0';
	}



	string str;
	char chrstr[20];

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			str = words[x][y];
			strtochr(chrstr, str);
			if (strcmp(chr, chrstr) == 0)
			{
				savedatavalue(a, b, c, d);
				savedatakey(x, y);
				beep();
				break;
			}
			if (x == 10 && y == 3)
			{
				system("cls");
				cout << endl;
				center();
				cout << "NO MATCH FOUND";
				Sleep(1000);
			}
		}
		if (strcmp(chr, chrstr) == 0)
			break;
	}
}
void antidigstring(int a, int b, int c, int d)
{
	char puz[14][16];
	string words[11][4];
	loadsavedfile(puz, words);


	char chr[15];
	int ac = a;
	int bc = b;

	for (int x = 0; ac <= c; ac++, bc--, x++)
	{
		chr[x] = puz[ac][bc];
		chr[x + 1] = '\0';
	}



	string str;
	char chrstr[20];

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			str = words[x][y];
			strtochr(chrstr, str);
			if (strcmp(chr, chrstr) == 0)
			{
				savedatavalue(a, b, c, d);
				savedatakey(x, y);
				beep();
				break;
			}
			if (x == 10 && y == 3)
			{
				system("cls");
				cout << endl;
				center();
				cout << "NO MATCH FOUND";
				Sleep(1000);
			}
		}
		if (strcmp(chr, chrstr) == 0)
			break;
	}
}
void antidigstringinv(int a, int b, int c, int d)
{
	char puz[14][16];
	string words[11][4];
	loadsavedfile(puz, words);


	char chr[15];
	int ac = a;
	int bc = b;

	for (int x = 0; ac >= c; ac--, bc++, x++)
	{
		chr[x] = puz[ac][bc];
		chr[x + 1] = '\0';
	}



	string str;
	char chrstr[20];

	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			str = words[x][y];
			strtochr(chrstr, str);
			if (strcmp(chr, chrstr) == 0)
			{
				savedatavalue(a, b, c, d);
				savedatakey(x, y);
				beep();
				break;
			}
			if (x == 10 && y == 3)
			{
				system("cls");
				cout << endl;
				center();
				cout << "NO MATCH FOUND";
				Sleep(1000);
			}
		}
		if (strcmp(chr, chrstr) == 0)
			break;
	}
}





//cmtsavedata
void strtochr(char chrstr[], string str)
{
	for (int x = 0; str[x] != '\0'; x++)
	{
		chrstr[x] = str[x];
		chrstr[x + 1] = '\0';
	}
}
void savedatakey(int a, int b)
{
	int arr[88][2];
	fstream file;
	file.open("arraykey.txt");

	for (int x = 0; x < 88; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			file >> arr[x][y];
		}
	}
	file.close();

	for (int x = 0; x < 88; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			if (arr[x][0] == -1 && arr[x][0] != a && arr[x][1] != b)
			{
				arr[x][0] = a;
				arr[x][1] = b;
				break;
			}
		}
		if (arr[x][0] == a)
			break;
	}

	file.open("arraykey.txt");
	for (int x = 0; x < 88; x++)
		for (int y = 0; y < 2; y++)
			file << arr[x][y] << " ";
	file.close();

}
void savedatavalue(int a, int b, int c, int d)
{
	int arr[224][2];
	loadarray(arr);

	if (a > c || b > d)
	{
		int temp;
		temp = c;
		c = a;
		a = temp;
		temp = d;
		d = b;
		b = temp;
	}

	if (a < c&&b < d)
	{
		c++;
		d++;
	}
	if (a == c)
		d++;
	if (b == d)
		c++;
	if (a<c&&b>d)
		c++;
	if (a > c&&b < d)
		d++;



	for (; a < c || b < d;)
	{
		for (int row = 0; row < 224; row++)
		{
			if (arr[row][0] == a && arr[row][1] == b)
				break;
			if ((arr[row][0] == -1))
			{
				arr[row][0] = a;
				arr[row][1] = b;
				break;
			}
		}
		if (a < c)
			a++;
		if (b < d)
			b++;
		if (b > d)
			b--;
		if (a > c)
			a--;
	}


	fstream file;
	file.open("arrayvalue.txt");
	for (int x = 0; x < 224; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			file << arr[x][y];
			file << " ";
		}
	}
	file.close();

}




//cmtquick
void quick()
{
	newgame();
	clearsavedmaze();
	clearsavedkey();
	char lvl = getlevel();
	if (lvl == '1')
		easymode();
	else if (lvl == '2')
		mediummode();
	else if (lvl == '3')
		hardmode();
}


//cmtnewgame
//cmtclear
void newgame()
{
	fstream file;
	file.open("arrayvalue.txt");
	for (int x = 0; x < 448; x++)
		file << -1 << " ";
	file.close();
	file.open("arraykey.txt");
	for (int x = 0; x < 176; x++)
		file << -1 << " ";
	file.close();
}
void clearsavedmaze()
{
	fstream file;
	file.open("savedmaze.txt", ios::out | ios::trunc);
	file.close();
}
void clearsavedkey()
{
	fstream file;
	file.open("savedkey.txt", ios::out | ios::trunc);
	file.close();
}
void clear(int arr[][2])
{
	for (int x = 0; x < 224; x++)
	{
		for (int y = 0; y < 2; y++)
			arr[x][y] = -1;
	}
}

//cmtgetlevel
char getlevel()
{
	fstream file;
	char chr;
	file.open("level.txt");
	file.get(chr);
	file.close();
	return chr;
}
//cmtmode
void easymode()
{
	char puz[14][16];
	string words[11][4];

	newload();
	loadsavedfile(puz, words);
	playgame(puz, words);

}
void mediummode()
{
	char puz[14][16];
	string words[11][4];

	newload();
	loadsavedfile(puz, words);
	playgame(puz, words);

}
void hardmode()
{
	char puz[14][16];
	string words[11][4];

	newload();
	loadsavedfile(puz, words);
	playgame(puz, words);

}
//cmtnewload
void newload()
{
	char lvl = getlevel();
	fstream file;
	fstream file2;
	file2.open("savedmaze.txt");

	if (lvl == '1')
		file.open("easy1.txt");
	else if (lvl == '2')
		file.open("easy2.txt");
	else if (lvl == '3')
		file.open("easy3.txt");

	string str;
	while (!file.eof())
	{
		getline(file, str);
		file2 << str;
	}
	file.close();
	file2.close();

	file2.open("savedkey.txt");

	if (lvl == '1')
		file.open("easy1code.txt");
	else if (lvl == '2')
		file.open("easy2code.txt");
	else if (lvl == '3')
		file.open("easy3code.txt");

	while (!file.eof())
	{
		getline(file, str);
		file2 << str;
	}
	file.close();
	file2.close();
}










void time()
{

}
void survival()
{

}









//cmtfunctions-5,6,7,8
//cmtbesttime
void besttime()
{
	system("cls");
	string str;
	fstream file;
	file.open("besttime.txt");
	getline(file, str);
	file.close();
	cout << endl;
	center();
	cout << "BEST TIME" << endl;
	cout << "\n\n\n\n\n";
	center();
	cout << "BEST TIME   :" << str << endl;
	cout << endl;
	center();
	cout << "Back to lobby in 3 seconds";
	Sleep(3000);
}
//cmtnewbesttime
void newbesttime(string val)
{
	fstream file;
	file.open("besttime.txt");
	file << val;
	file.close();
}

//cmthighscore
void highscore()
{
	system("cls");
	string str;
	fstream file;
	file.open("highscore.txt");
	getline(file, str);
	file.close();
	cout << endl;
	center();
	cout << "HIGH SCORE" << endl;
	cout << "\n\n\n\n\n";
	center();
	cout << "HIGH SCORE   :" << str << "minutes" << endl;
	cout << endl;
	center();
	cout << "Back to lobby in 3 seconds";
	Sleep(3000);
}
//cmtnewhighscore
void newhighscore(int val)
{
	fstream file;
	file.open("highscore.txt");
	file << val;
	file.close();
}








//cmtinstructions
void instruction()
{
	system("cls");
	fstream file;
	char chr;
	file.open("instructions.txt");
	cout << endl;
	center();
	cout << "INSTRUCTIONS";
	cout << "\n\n\n\n\n";
	center();
	while ((chr = file.get()) != EOF)
	{
		Sleep(100);
		cout << chr;
		if (chr == '\n')
			center();
	}
	cout << endl;
	center();
	cout << "Back to lobby in 5 seconds";
	Sleep(5000);
}
//cmtsettings
void setting()
{
	int opt;
	for (; true;)
	{
		system("cls");
		cout << endl;
		center();
		cout << "SETTING";
		cout << "\n\n\n\n\n";
		center();
		cout << "1 LEVEL" << endl;
		center();
		cout << "2 BACKGROUND" << endl;
		center();
		cout << "3 SOUND" << endl;
		center();
		cout << "4 LOBBY" << endl;
		center();
		cout << "PRESS THE OPTION   :";
		cin >> opt;
		beep();
		if (opt == 1)
			level();
		else if (opt == 2)
			bgcolor();
		else if (opt == 3)
			sound();
		else if (opt == 4)
			break;
		else
		{
			system("cls");
			cout << "\n";
			center();
			cout << "INVALID ENTRY";
			Sleep(600);
		}
	}
}
//cmtsettingfunctions
//cmtlevel
void level()
{
	fstream file;
	int opt;
	char chr;


	for (; true;)
	{
		file.open("level.txt", ios::in);
		file.get(chr);
		file.close();



		system("cls");
		cout << endl;
		center();
		cout << "LEVEL" << endl;
		cout << "\n\n\n\n\n";
		center();
		cout << "CURRENT LEVEL " << chr << endl;
		center();
		cout << "1 EASY" << endl;
		center();
		cout << "2 MEDIUM" << endl;
		center();
		cout << "3 HARD" << endl;
		center();
		cout << "4 LOBBY" << endl;
		center();
		cout << "PRESS THE OPTION  :";
		cin >> opt;
		if (opt == 1)
		{
			file.open("level.txt", ios::out | ios::trunc);
			file << "1";
			file.close();
		}
		else if (opt == 2)
		{
			file.open("level.txt", ios::out | ios::trunc);
			file << "2";
			file.close();
		}
		else if (opt == 3)
		{
			file.open("level.txt", ios::out | ios::trunc);
			file << "3";
			file.close();
		}
		else if (opt == 4)
			break;
		else
		{
			system("cls");
			cout << endl;
			center();
			cout << "INVALID ENTRY";
			Sleep(600);

		}
	}
}
//cmtbgcolor
void bgcolor()
{
	fstream file;
	int opt;
	char chr;


	for (; true;)
	{
		file.open("bgcolor.txt", ios::in);
		file.get(chr);
		file.close();
		changebgcolor(chr);



		system("cls");
		cout << endl;
		center();
		cout << "BACKGROUND" << endl;
		cout << "\n\n\n\n\n";
		center();
		cout << "BACKGROUND IS " << chr << endl;
		center();
		cout << "1 BLACK" << endl;
		center();
		cout << "2 BLUE" << endl;
		center();
		cout << "3 GREEN" << endl;
		center();
		cout << "4 PURPLE" << endl;
		center();
		cout << "5 LOBBY" << endl;
		center();
		cout << "PRESS THE OPTION  :";
		cin >> opt;
		if (opt == 1)
		{
			file.open("bgcolor.txt", ios::out | ios::trunc);
			file << "1";
			file.close();
		}
		else if (opt == 2)
		{
			file.open("bgcolor.txt", ios::out | ios::trunc);
			file << "2";
			file.close();
		}
		else if (opt == 3)
		{
			file.open("bgcolor.txt", ios::out | ios::trunc);
			file << "3";
			file.close();
		}
		else if (opt == 4)
		{
			file.open("bgcolor.txt", ios::out | ios::trunc);
			file << "4";
			file.close();
		}
		else if (opt == 5)
			break;
		else
		{
			system("cls");
			cout << endl;
			center();
			cout << "INVALID ENTRY";
			Sleep(600);

		}
	}

}
//cmtchangebgcolor
void changebgcolor(char chr)
{
	if (chr == '1')
		system("color 0F");
	else if (chr == '2')
		system("color 1F");
	else if (chr == '3')
		system("color 2F");
	else if (chr == '4')
		system("color 5F");
}
//cmtsound
void sound()
{
	fstream file;
	int opt;
	char chr;


	for (; true;)
	{
		beep();
		file.open("sound.txt", ios::in);
		file.get(chr);
		file.close();



		system("cls");
		cout << endl;
		center();
		cout << "SOUND" << endl;
		cout << "\n\n\n\n\n";
		center();
		cout << "SOUND IS " << chr << endl;
		center();
		cout << "1 OFF" << endl;
		center();
		cout << "2 ON" << endl;
		center();
		cout << "3 LOBBY" << endl;
		center();
		cout << "PRESS THE OPTION  :";
		cin >> opt;
		if (opt == 1)
		{
			file.open("sound.txt", ios::out | ios::trunc);
			file << "1";
			file.close();
		}
		else if (opt == 2)
		{
			file.open("sound.txt", ios::out | ios::trunc);
			file << "2";
			file.close();
		}
		else if (opt == 3)
			break;
		else
		{
			system("cls");
			cout << endl;
			center();
			cout << "INVALID ENTRY";
			Sleep(600);

		}
	}

}
//cmtbeep
void beep()
{
	fstream file;
	file.open("sound.txt");
	int val;
	file >> val;
	file.close();

	if (val == 2)
		cout << "\a";
}



