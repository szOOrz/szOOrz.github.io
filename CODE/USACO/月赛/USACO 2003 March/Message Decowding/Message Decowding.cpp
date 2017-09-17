#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

int n,ans;
char ch;
int cnt;
int password[200];
char s[2000];

int main()
{
 //   freopen("Message Decowding.in","r",stdin);
 //   freopen("Message Decowding.out","w",stdout);
	cnt='a'; 
	while (true)
	{
		ch=getchar();
		if (ch == '\n') break;
		password[cnt] = ch;
		cnt++;
		
	} 
	
	gets(s);
	for (int i=0;i<strlen(s);i++) 
	{
		 ch=s[i];
		 if (ch == ' ') printf(" ");
	else {
			int big=0;
			if ((ch>='A') and (ch <='Z')) big=1;
			printf("%c",big*('A'-'a')+password[ch-big*('A'-'a')]);
		 }
	}
	return 0;
}
