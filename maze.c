#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
void gotoxy(int x,int y)			//cursor moving function
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}
int main(void)
{
	int x=1,y=1,i,j;
	char k;
	char s[16][26]={"#########################",	//0
					"#o #   #       ##       #",
					"#  # # # ##### #  ##### #",
					"#    #   #        #   # #",	
					"## ####### ##### ## # # #",
					"#    #     #   #    # # #",	//5
					"# #### ##### # ###### # #",
					"#    # #     #      # # #",
					"#### # #### ####### ### #",	
					"#      #    #     #     #",	
					"##  ##### ####### ### ###",	//10
					"#  # #         #        #",
					"# ## # ################ #",
					"#    #                # #",	
					"############## ##########",	
					"          end point      "};	//15
	system("cls");		
	Sleep(500);
	printf("\n\n     loading...\n\n");
	Sleep(1000);
	system("cls");
	printf("\n\n  Maze Game\n\n");
	Sleep(400);
	for(i=2;i<=30;i++)
	{
		gotoxy(0,0);	//refresh the screen
		printf("\n\n");
		for(j=1;j<=i;j++)
			printf(" ");
		printf("Maze Game\n\n");
		Sleep(20);
	}
	Sleep(150);
	for(i=30;i>=2;i--)
	{
		gotoxy(0,0);	//refresh the screen
		printf("\n\n");
		for(j=1;j<=i;j++)
			printf(" ");
		printf("Maze Game          \n\n");
		Sleep(20);
	}
	Sleep(400);
	system("cls");
	printf("\n use W A S D to control\n\n");
	for(i=0;i<=16;i++)
		puts(s[i]);

	while(x!=14||y!=14)		//escape the loop when reach endpoint(14,14) 
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
				printf("\n use W A S D to control\n\n");
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
				printf("\n use W A S D to control\n\n");			
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
				printf("\n use W A S D to control\n\n");
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
				printf("\n use W A S D to control\n\n");
				for(i=0;i<=16;i++)
					puts(s[i]);
			}
		}
	}
	printf("\a\n     Congratulations !");
	Sleep(500);
	printf("\n\n     You win !");
	printf("\n\n");
	system("pause");
	return 0;	
}
