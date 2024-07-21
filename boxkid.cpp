#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

int ROW = 7, i, target[4][2] = {{4, 2}, {4, 3}, {5, 2}, {5, 3}};    //target position (y, x)

void refresh(string s[])
{
    COORD point;
    point.X = point.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);   //cursor to top

	for (i = 0; i < 4; i++) {                           //display * covered by player
		if (s[target[i][0]][target[i][1]] == ' ')
			s[target[i][0]][target[i][1]] = '*';
	}
    cout << "\n    Use W, A, S, D, to control. Press R to restart\n\n";
    for (i = 0; i < ROW; i++)
		cout << "    " << s[i] << "\n";
}

int main()
{
	restart:
	string s[ROW] = {"##########",
					 "##     ###",
					 "##o###   #",
					 "# & o  o #",
					 "# **# o ##",
					 "##**#   ##",
					 "##########"};
    int y = 3, x = 2, success = 0;   //the number of boxes in the correct position
	char k;
	system("cls");
	cout << "\e[?25l";  			//hide cursor
	refresh(s);
	
	while (success < 4) {
		k = getch();
		if (k == 'w' || k == 'W') {     		//up
			if (s[y - 1][x] == ' ') {
				s[y - 1][x] = '&';
				s[y--][x] = ' ';
			}
			else if (s[y - 1][x] == 'o' && s[y - 2][x] == ' ') {
    			s[y - 2][x] = 'o';
				s[y - 1][x] = '&';
				s[y--][x] = ' ';
			}
			else if (s[y - 1][x] == 'o' && s[y - 2][x] == '*') {
				success++;
				s[y - 2][x] = '@';
				s[y - 1][x] = '&';
				s[y--][x] = ' ';
			}
			else if (s[y - 1][x] == '@' && s[y - 2][x] == '*') {
				s[y - 2][x] = '@';
				s[y - 1][x] = '&';
				s[y--][x] = ' ';
			}
			refresh(s);
		}
		else if (k == 'a' || k =='A') {     		//left
			if (s[y][x - 1] == ' ') {
				s[y][x - 1] = '&';
				s[y][x--] = ' ';
			}
			else if (s[y][x - 1] == 'o' && s[y][x - 2] == ' ') {
    			s[y][x - 2] = 'o';
				s[y][x - 1] = '&';
				s[y][x--] = ' ';
			}
			else if (s[y][x - 1] == 'o' && s[y][x - 2] == '*') {
				success++;
				s[y][x - 2] = '@';
				s[y][x - 1] = '&';
				s[y][x--] = ' ';
			}
			else if (s[y][x - 1] == '@' && s[y][x - 2] == '*') {
				s[y][x - 2] = '@';
				s[y][x - 1] = '&';
				s[y][x--] = ' ';
			}
			refresh(s);
		}
		else if (k == 's' || k == 'S') {     		//down
			if (s[y + 1][x] == ' ') {
				s[y + 1][x] = '&';
				s[y++][x] = ' ';
			}
			else if (s[y + 1][x] == 'o' && s[y + 2][x] == ' ') {
    			s[y + 2][x] = 'o';
				s[y + 1][x] = '&';
				s[y++][x] = ' ';
			}
			else if (s[y + 1][x] == 'o' && s[y + 2][x] == '*') {
				success++;
				s[y + 2][x] = '@';
				s[y + 1][x] = '&';
				s[y++][x] = ' ';
			}
			else if (s[y + 1][x] == '@' && s[y + 2][x] == '*') {
				s[y + 2][x] = '@';
				s[y + 1][x] = '&';
				s[y++][x] = ' ';
			}
			refresh(s);
		}
		else if (k == 'd' || k == 'D') {     		//right
			if (s[y][x + 1] == ' ') {
				s[y][x + 1] = '&';
				s[y][x++] = ' ';
			}
			else if (s[y][x + 1] == 'o' && s[y][x + 2] == ' ') {
    			s[y][x + 2] = 'o';
				s[y][x + 1] = '&';
				s[y][x++] = ' ';
			}
			else if (s[y][x + 1] == 'o' && s[y][x + 2] == '*') {
				success++;
				s[y][x + 2] = '@';
				s[y][x + 1] = '&';
				s[y][x++] = ' ';
			}
			else if (s[y][x + 1] == '@' && s[y][x + 2] == '*') {
				s[y][x + 2] = '@';
				s[y][x + 1] = '&';
				s[y][x++] = ' ';
			}
			refresh(s);
		}
		else if (k == 'r' || k == 'R')
			goto restart;
	}
	cout << "\a\n\n     You win!\n\n\n\n";
	system("pause");
	return 0;
}
