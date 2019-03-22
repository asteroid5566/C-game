#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int main(void)
{
	int x=1,y=1,i,j;
	char k;
	char s[16][26]={"#########################",	//0
					"#o #    #      ##       #",
					"#  # #  # #### #  ##### #",
					"#    #    #  #    #   # #",	
					"## ########  ### ## # # #",
					"#    #         #    # # #",	//5
					"# #### # ##### ###### # #",
					"#    # #     #      # # #",
					"#### # ##### ###### ### #",	
					"#      #          #     #",	
					"##  ##### ####### #######",	//10
					"#  # #         #        #",
					"# ## # ################ #",
					"#    #                # #",	
					"############## ##########",	
					"          end point      "};	//15
	system("cls");		
	Sleep(1000);
	printf("\n\n     loading...\n\n");
	Sleep(1000);
	system("cls");
	printf("\n\nMaze Game\n\n");
	Sleep(200);
	for(i=2;i<=30;i++)
	{
		system("cls");
		printf("\n\n");
		for(j=1;j<=i;j++)
			printf(" ");
		printf("Maze Game\n\n");
		Sleep(20);
	}
	for(i=30;i>=2;i--)
	{
		system("cls");
		printf("\n\n");
		for(j=1;j<=i;j++)
			printf(" ");
		printf("Maze Game\n\n");
		Sleep(20);
	}
	Sleep(300);
	system("cls");
	//Sleep(500);
	printf("\n use w,a,s,d to control\n\n");
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
				system("cls");
				printf("\n use w,a,s,d to control\n\n");
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
				system("cls");		
				printf("\n use w,a,s,d to control\n\n");			
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
				system("cls");
				printf("\n use w,a,s,d to control\n\n");
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
				system("cls");
				printf("\n use w,a,s,d to control\n\n");
				for(i=0;i<=16;i++)
					puts(s[i]);
			}
		}
	}
	printf("\a\n\n     you win!!");
	Sleep(500);
	printf("\n\n     you win!!");
	Sleep(500);
	printf("\n\n     you win!!");
	printf("\n\n");
	system("pause");
	return 0;	
}
