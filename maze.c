/*  3/30 : Add font size enlarge function  
    4/2 : Back to original font size in the end(for command line user) */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

//enlarge font size
int GetFontSize(HANDLE windowHandle, COORD *size)
    {
    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }
    *size = font.dwFontSize;
    return 1;
    }

int SetFontSize(HANDLE windowHandle, COORD size)
    {
    CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX) };
    if (!GetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }
    font.dwFontSize = size;
    if (!SetCurrentConsoleFontEx(windowHandle, 0, &font))
        {
        return 0;
        }
    return 1;
    } 


//cursor moving function
void gotoxy(int x,int y)            
{
    COORD point;
    point.X = x; point.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}


int main(void)
{
    //enlarge font size
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size;
    if (GetFontSize(h, &size))
        {
        size.X += (SHORT)(size.X * .5);//Grow by 50%
        size.Y += (SHORT)(size.Y * .5);
        SetFontSize(h, size);
        }
    
    int x=1,y=6,i,j;
	char k;
	char s[16][31]={"     #########################",	//0
					"     #o #   #       ##       #",
					"     #  # # # ##### #  ##### #",
					"     #    #   #        #   # #",	
					"     ## ####### ##### ## # # #",
					"     #    #     #   #    # # #",	//5
					"     # #### ##### # ###### # #",
					"     #    # #     #      # # #",
					"     #### # #### ####### ### #",	
					"     #      #    #     #     #",	
					"     ##  ##### ####### ### ###",	//10
					"     #  # #         #        #",
					"     # ## # ################ #",
					"     #    #                # #",	
					"     ############## ##########",	
					"               end point      "};	//15
	system("cls");
    printf("\e[?25l");  //hide cursor
	Sleep(500);
	printf("\n\n\n\n\n          loading...\n\n");
	Sleep(1000);
	system("cls");
	Sleep(800);
	printf("\n\n\n\n\n          Maze Game\n\n\n\n");
	Sleep(400);
	for(i=10;i<=40;i++)
	{
		gotoxy(0,0);	//refresh the screen
		printf("\n\n\n\n\n");
		for(j=1;j<=i;j++)
			printf(" ");
		printf("Maze Game\n\n");
		Sleep(20);
	}
	Sleep(150);
	for(i=40;i>=10;i--)
	{
		gotoxy(0,0);	//refresh the screen
		printf("\n\n\n\n\n");
		for(j=1;j<=i;j++)
			printf(" ");
		printf("Maze Game          \n\n");
		Sleep(20);
	}
	Sleep(400);
	system("cls");
	printf("\n      use W A S D to control\n\n");
	for(i=0;i<=16;i++)
		puts(s[i]);

	while(x!=14||y!=19)     //escape main loop when reach endpoint(14,19) 
	{
		k=getch();
		if (k=='w')
		{
			if (s[x-1][y]!='#')
			{
				s[x][y]=' ';
				x--;
				s[x][y]='o';
				gotoxy(0,0);	//refresh the screen
				printf("\n      use W A S D to control\n\n");
				for(i=0;i<=16;i++)
					puts(s[i]);
			}
		}
		if (k=='a')
		{
			if (s[x][y-1]!='#')
			{
				s[x][y]=' ';
				y--;
				s[x][y]='o';
				gotoxy(0,0);	//refresh the screen		
				printf("\n      use W A S D to control\n\n");			
				for(i=0;i<=16;i++)
					puts(s[i]);
			}
		}
		if (k=='s')
		{
			if (s[x+1][y]!='#')
			{
				s[x][y]=' ';
				x++;
				s[x][y]='o';
				gotoxy(0,0);	//refresh the screen
				printf("\n      use W A S D to control\n\n");
				for(i=0;i<=16;i++)
					puts(s[i]);
			}
		}
		if (k=='d')
		{
			if (s[x][y+1]!='#')
			{
				s[x][y]=' ';
				y++;
				s[x][y]='o';
				gotoxy(0,0);	//refresh the screen
				printf("\n      use W A S D to control\n\n");
				for(i=0;i<=16;i++)
					puts(s[i]);
			}
		}
	}
	printf("\a\n     Congratulations !\n\n");
	Sleep(500);
	printf("     You win !\n\n");
	system("pause");

	if (GetFontSize(h, &size))    //back to original font size
        {
        size.X -= (SHORT)(size.X * .35);
        size.Y -= (SHORT)(size.Y * .35);
        SetFontSize(h, size);
        }
	return 0;	
}
