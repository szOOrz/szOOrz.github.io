#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
/*
���ȣ��������һ����ʵ�����Ǽ����������У��������ֳ�a���֣���������ÿһ���֣�������1~k�����ĩβ��Щ���������Ǿ���ȥ������ô������Ϊa�����ж��ǿ��еġ�����˵1��2��������k-1��k 3��4������k-1��k�� 1,2��3,4����k-1��kֻ�ܷ�Ϊ2���֣�һ������ǰ��1~k���ڶ�������3~2�����һ���֣���Ȼ�Ƕ���ģ�������a ��ô���2���Ǵ𰸡����ڱ��⣬���ǵ������ǣ�һ��һ�������������1~k�������ˣ�tot��һ��Ȼ�������¶�����һֱ����������������tot+1 
*/
int n,k,tot,temp,x;
bool flag[10005];
int main()
{
	scanf("%d%d",&n,&k);
	temp=k;
	memset(flag,true,sizeof(flag));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (flag[x])
		{
			temp--;
			flag[x]=false;
			if (temp==0)
			{
				temp=k;
				tot++;
				memset(flag,true,sizeof(flag));
			}
		}
	}
	printf("%d",tot+1);
}
