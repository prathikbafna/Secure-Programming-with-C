#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

//Global Declaration of Variables
//int flag=0,fptr,*ptr,rno,year,maxrollno,cnt=0,false1=0;  
//DCL04-C Do not use more than one variable per declaration. 

int* ptr;
int rno;
int year;
int maxrollno;



int num1;
char branch[6],br1[6];


//fn to check valid PRN
int isSpecial(char prn[15])
{
	FILE* fp;
	char sprn[15];
	fp = fopen("blank.txt", "r");
	while (feof(fp) == 0)
	{
		fgets(sprn, 99, fp);
		sprn[14] = '\0';
		//if(!strcmp(sprn,prn))  EXP20-C explicitly check if condition.
		if (strcmp(sprn, prn) == 0)
			return 1;
	}
	fclose(fp);
	return 0;
}

int isAuthentic(char prn[15])
{
	int i = 0;
	int j = 0;
	int no = 0;
	int yr = 0;
	char br[6];
	char d;   //DCL04-C No more than 1 var per declaration.
	while (i < 4)
	{
		d = prn[i];
		yr = (yr * 10) + (d - 48);
		i++;
	}
	if (yr != year)
	{
		printf("\n  Invalid PRN(Incorrect Year)");
		return 0;
	}
	num1 = yr;
	while (i < 9)
	{
		br[j] = prn[i];
		j++;
		i++;
	}
	br[j] = '\0';
	strcpy(br1, br);
	//if(strcmp(br,branch))
	if (strcmp(br, branch) != 0)  //EXP20-C explicitly check if condition.
	{
		printf("\n  Invalid PRN(Incorrect Branch)");
		return 0;
	}
	while (i < 14)
	{
		d = prn[i];
		no = (no * 10) + (d - 48);
		i++;
	}
	if (no > maxrollno || no < 0)
	{
		printf("\n  Invalid PRN(Incorrect Number)");
		return 0;
	}
	rno = no;
	return 1;
}

