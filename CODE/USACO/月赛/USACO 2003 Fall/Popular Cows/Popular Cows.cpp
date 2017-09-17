#include <cstdio>
#include <cstring>
#include <iostream> 
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
struct E
{
	int from,to,next;
}; 
E edge[50050];
int point[10050];
bool s[10050],found;//�Ƿ���ջ�� 
int cnt,n,m,h,shed[10050],x,y,n_after,number_chudu[10050],k,ans; 
int DFN[10050],Low[10050],top,which[10050];
inline void add_edge(int x,int y)
{
	edge[cnt].from=x;
	edge[cnt].to  =y;
	edge[cnt].next=point[x];
	point[x]=cnt;
	cnt++;
}
inline void Tarjan(int i)
{
	int j;
	DFN[i]=Low[i]=h++;
	s[i]=true;//�Ƿ���ջ�� 
	shed[++top]=i;//��ջ 
	int e=point[i];
	while (e!=-1)
	{
		j=edge[e].to;
		if (DFN[j]==-1)	//û�б����� 
		{
			Tarjan(j);
			Low[i]=min(Low[i],Low[j]);
		}
		else
		if (s[j]) Low[i]=min(Low[i],DFN[j]);
		e=edge[e].next;
	}
	if (DFN[i]==Low[i])
	{
		while (shed[top]!=i)
		{
			s[shed[top]]=false;
			which[shed[top]]=cnt;
			top--;
		}
		s[shed[top]]=false;
		which[shed[top]]=cnt;
		top--;
		//������Ǹ��� 
		cnt++;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	cnt=0;
	for (int i=1;i<=n;i++)
	{
		point[i]=-1;
		DFN[i]=-1;
	}
		
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		add_edge(x,y);
	}
	memset(s,false,sizeof(s));
	h=0;
	cnt=0;
	for (int i=1;i<=n;i++)
		if (DFN[i]==-1) Tarjan(i);//���û�б����� 
		//ǿ��ͨ������ 
//	for (int i=1;i<=n;i++)	printf("%d ",which[i]);
//	printf("\n");
	n_after=cnt;
	memset(number_chudu,0,sizeof(number_chudu));
	for (int i=0;i<m;i++)
	{
		if (which[edge[i].from]!=which[edge[i].to])
			number_chudu[which[edge[i].from]]++;
	}
		
//	for (int i=0;i<n_after;i++) printf("%d ",number_chudu[i]);
//	printf("\n");
	found=true;
	k=-1;
	for (int i=0;i<n_after;i++)
		if (number_chudu[i]==0)
		{
			if (k!=-1) found=false;
			k=i;
		}
	ans=0;
	if (found)
		for (int i=1;i<=n;i++) if (which[i]==k) ans++;
	printf("%d",ans);
	return 0;
}
