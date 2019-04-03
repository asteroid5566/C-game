/*  3/30 : Add font size enlarge function
    4/2 : Back to original font size in the end(for command line user) */

#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>

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


void gotoxy(int x,int y)			//cursor moving function for screen refresh
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
    system("cls");
    printf("\e[?25l");      //hide cursor
    printf("\n\n\n\n      Do not hit the ball !");
    Sleep(1500);
    
    start:
	system("cls");
	int i,j,m,n,t,s=0,x=2,y=3;
	char k;
	char map[5][36]={"###################################",		//0
			         "#                                 #",
			         "#  @                              #",		//2
			         "#                                 #",
			         "###################################"};	//4
	srand(time(NULL));
	printf("\n\n    use w, s to control\n\n");
	for(i=0;i<=4;i++)
		puts(map[i]);
	printf("\n    score: %d\n\n",s/10);
	
	while(1)
	{
		while(!kbhit())
		{
			for(i=1;i<=3;i++)
			{	
				for(j=1;j<=35;j++)
				{
					if(map[i][j]=='O')
					{
						if(map[i][j-1]=='@')
						{
							gotoxy(0,0);
							map[x][y]=' ';
							printf("\n\n    use w, s to control\n\n");
							for(i=0;i<=4;i++)
								puts(map[i]);
							printf("\n    score: %d\n\n",s/10);
							goto lose;
						}
						map[i][j]=' ';
						if(map[i][j-1]==' ')
							map[i][j-1]='O';
					}
				}
			}
			
			for(i=1;i<=3;i++)		//generate ball
			{
				t=rand()%10+1;
				for(j=30;j<=33;j++)
				{
					if(map[i][j]==' ')
						t++;
					if(t>13)
					{
						int flag=0;
						for(m=1;m<=3;m++)
						{
							for(n=30;n<=33;n++)
							{
								if(map[m][n]=='O')
									flag++;
							}
						}
						if(flag<1)
							map[i][j]='O';
					}
				}		
			}
			
			gotoxy(0,0);
			printf("\n\n    use w, s to control\n\n");
			for(i=0;i<=4;i++)
				puts(map[i]);
			printf("\n    score: %d\n\n",s/10);
			
			if(s>900)			//speed level
				Sleep(25);
			else if(s>800)
				Sleep(30);
			else if(s>700)
				Sleep(35);
			else if(s>600)
				Sleep(40);
			else if(s>500)
				Sleep(45);
			else if(s>400)
				Sleep(50);
			else if(s>300)
				Sleep(55);
			else if(s>200)
				Sleep(60);
			else if(s>100)
				Sleep(65);
			else 	
				Sleep(70);
			s+=1;
		}

		k=getch();
		if (k=='w')
		{
			if (map[x-1][y]!='#')
			{
				if(map[x-1][y]=='O')
				{
					map[x][y]=' ';
					gotoxy(0,0);	//refresh the screen
					printf("\n\n    use w, s to control\n\n");
					for(i=0;i<=4;i++)
						puts(map[i]);
					printf("\n    score: %d\n\n",s/10);
					goto lose;
				}
				map[x][y]=' ';
				x--;
				map[x][y]='@';
				gotoxy(0,0);		//refresh the screen
				printf("\n\n    use w, s to control\n\n");
				for(i=0;i<=4;i++)
					puts(map[i]);
				printf("\n    score: %d\n\n",s/10);
			}
		}
		if (k=='s')
		{
			if (map[x+1][y]!='#')
			{
				if(map[x+1][y]=='O')
				{
					map[x][y]=' ';
					gotoxy(0,0);	//refresh the screen
					printf("\n\n    use w, s to control\n\n");
					for(i=0;i<=4;i++)
						puts(map[i]);
					printf("\n    score: %d\n\n",s/10);
					goto lose;
				}
				map[x][y]=' ';
				x++;
				map[x][y]='@';
				gotoxy(0,0);		//refresh the screen
				printf("\n\n    use w, s to control\n\n");
				for(i=0;i<=4;i++)
					puts(map[i]);
				printf("\n    score: %d\n\n",s/10);
			}
		}
	}
	lose:
	printf("\n\n    Bang!\n\n\n");
	Sleep(500);
	printf("    Play again?  y/n");
	do{
		k=getch();
		if(k=='y')
			goto start;
	}while(k!='y'&&k!='n');
	
	if (GetFontSize(h, &size))    //back to original font size
        {
        size.X -= (SHORT)(size.X * .35);
        size.Y -= (SHORT)(size.Y * .35);
        SetFontSize(h, size);
        }
	return 0;
}
