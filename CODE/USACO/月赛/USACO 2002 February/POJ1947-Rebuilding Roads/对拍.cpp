#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int i;
	for(i=1;i<=1000;i++)
	{
		printf("Case %03d : ",i);
		system("rand");
		system("a");
		system("b");
		if(system("fc a.out b.out >NULL")==0)printf("AC\n");
		else
		{
			printf("WA!!!\n");
			return 0;
		}
	}
	return 0;
}
