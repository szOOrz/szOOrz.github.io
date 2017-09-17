#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
bool flag[255],temp;
char s[200];
char t[200];
int n,cnt;
int main()
{
	memset(flag,true,sizeof(flag));
	flag['A']=false;flag['E']=false;flag['I']=false;flag['O']=false;flag['U']=false;
	flag[' ']=false;
	memset(t,0,sizeof(t));
	gets(s);cnt=0;
	temp=false;
	for (int i=0;i<strlen(s);i++)
	{
		if ((s[i]==' ') && temp)
		{
			 t[cnt++]=' ';
			 temp=false;
		}
		else
		if (flag[s[i]])
		{
			temp=true;
			t[cnt++]=s[i];
			flag[s[i]]=false;
		}
	}
	while (t[cnt-1]==' ') cnt--;
	cnt--;
	while (t[cnt-1]==' ')cnt--;
	t[cnt]='.';
	for (int i=0;i<cnt;i++) printf("%c",t[i]);
	printf(".");
	return 0;
}
