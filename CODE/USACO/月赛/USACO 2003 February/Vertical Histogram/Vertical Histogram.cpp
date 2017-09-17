#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
int en[3000];
int number[300];
int maxnum;
int cnt;
char ch;
int main()
{
	
	cnt=0;
	while (true )
	{
		 scanf("%c",&ch);	
		 if (ch=='\n') cnt++;
	else if ((ch>='A') and (ch <= 'Z')) number[ch]++;
		 if (cnt == 4) break; 
	}
	//init;
	for (int i=0;i<=2000;i++) en[i]==0;
	maxnum=0;
	for (int i='A';i<='Z';i++)	
	{
		for (int j=1;j<=number[i];j++) en[j]=i;
		
		if (number[i]>maxnum) maxnum=number[i];
	}
	for (int i=maxnum;i>0;i--)
	{
		if (number['A']>=i) printf("*"); else printf(" ");
		for (int j='B';j<=en[i];j++)
		{
			if (number[j]>=i) printf(" *"); else printf("  ");
		} 
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
} 
