/*
ID:cqz15311
PROG:prefix
LANG:C++
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using std::max;
char s[205000],x[205][21];
int num,ans,dp[205000],dlen[205000];
bool found;
void init()
{
	num=0;
	while (~scanf("%s",&x[num]))
	{
		if (x[num][0]=='.') break;
		dlen[num]=strlen(x[num]);
		num++;
	}
	int m=0;
	char ch;
	while (~scanf("%c",&ch))
	{
		if ((ch!='\n') && (ch!=' ')) s[m++]=ch;
	};
//	puts(s);
}
int work()
{
	memset(dp,0,sizeof(dp));
	ans=0;
	dp[0]=1;
	for (int i=0;s[i];i++)
	{
		if (dp[i]==1)
		{
			ans=max(ans,i);
		}
		else continue;
		for (int t=0;t<num;t++)
		{
			found=true;
			for (int k=0;k<dlen[t];k++) 
			{
				if (s[i+k]!=x[t][k]) 
				{
					found=false;
					break;
				}
			}
			if (found) dp[i+dlen[t]]=1;
		}
	}
	if (dp[strlen(s)]==1) ans=strlen(s);
	//这句很重要，因为上述可能会忘记这句话。 
	return ans;
}
int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	init(); 
	int temp=work();
	printf("%d\n",temp);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
AH AS AZ BW CD CK CN CU CZ DB DH EC ED EN FJ GA GK GM GS GT 
HA HN HZ IN IR JB JD JM JZ KG KI LO LQ LU LW LY MJ MT MV ND 
NM NS OB OI OK OM PG PO PQ PZ QE QP RG RK RN RP RQ RR RS RU 
SA SF SJ SN TK TR TU TY UA UO US UW UX VH VL VO WF WH WL WS 
WZ XU XW XY YA YI YN YT ZF ZH ZJ ZL ZR ZX 
        .
ASCDCKCUEDFJGKGMHAIRJMKILQLWLYMJMTMVNSOIOKOMPOPQQPRGRNRPSJTU 
TYWSWZXWYIYTAHAZBWCDCNCUDHECENGAGMGSGTHAHNKGLQLULWNMOBOIOKOM 
PGPOPQPZRGRKRNRPRRSATRTUUWVLVOWFWLWSXUXYYAYIYNYTZFZJZRZXBWCK 
CUFJGAGSHAHNIRJBJMKILQLUNDNMNSOKOMPQQERGRQRRRSSASFSJSNTUTYUA 
UOUWVLWHXUXWXYYAYTZFZJZLZRZXASBWCDCNDBECEDFJGSHAHNHZINJMKGKI 
LQMJNMNSOKOMPQQPRRRSSFSJSNTRTUTYUAUWUXVLVOWLWSWZXYYNYTZFZHZR 
ZXAHASAZCDCKCNDBECENGMGSHAHZIRJDKGKILOLYOBOKPGPQQPRRSNTRTYUO 
USUXVHVLVOWFWLWSXYYNZJZXZZAHAZBWCDCKCNDB 
*/
