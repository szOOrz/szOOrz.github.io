#include<iostream> 
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int oo=200000000;
struct Nod{
	int son[1555],father,height,son_num,num_tree,first;
}; 
Nod nod[1555];
int n,p;
int root,queue[2005],front,rear;//用于bfs求深度 
int dp[1555][1555];
int find[1555];
void add(int x,int y)
{
	nod[x].son_num++;
	nod[x].son[nod[x].son_num]=y;
	nod[y].father=x;
}
int get_root()
{
	for (int i=1;i<=n;i++) if (nod[i].father==i) return i;
	return -1;
}
void push(int x){
	queue[rear]=x;
	rear++;
}
void pop(){
	front++;
}
/*
void pt()
{
	printf("  ");
	for (int i=0;i<=p;i++) printf("%16d",i);printf("\n");
	for (int i=1;i<=n;i++) 
	{
		printf("%d ",nod[i].first);
		for (int j=0;j<=p;j++) printf("%16d",dp[i][j]);
		printf("\n");
	}	
	printf("\n\n");
}
*/
void get_height(int root){
	front=0;
	rear=1;
	queue[0]=root;
	nod[root].height=1;
	while (front<rear)
	{
		int x=queue[front];
		for (int i=1;i<=nod[x].son_num;i++)
		{
			nod[nod[x].son[i]].height=nod[x].height+1;
			push(nod[x].son[i]);
		}
		pop();
	}
}//BFS求深度 

void get_num_tree()
{
	for (int i=1;i<=n;i++)
	{
		nod[i].num_tree=1;
		for (int j=1;j<=nod[i].son_num;j++) nod[i].num_tree+=nod[find[nod[i].son[j]]].num_tree;
	}
}

bool cmp(Nod x,Nod y){
	return x.height>y.height;
}
void get_find()
{
	for (int i=1;i<=n;i++)	find[nod[i].first]=i;
}
int min(int x,int y){if (x<y) return x;else return y;}
void slove()
{
	//dp[i,j]表示第i个节点，如果子树节点个数为j，最小需要分割几次。 
	for (int x=1;x<=n;x++)//枚举每个节点 
	{
		if (nod[x].son_num==0) 
		{
			for (int i=0;i<=p;i++) dp[x][i]=oo;
			dp[x][1]=0;
			continue;
		}
		
		for (int i=0;i<=p;i++) dp[x][i]=oo;
		dp[x][0]=0;
		
		int temp[1055];
		
		for (int s=1;s<=nod[x].son_num;s++)	//值得一提的是，假设一棵n个节点的树中有k0个叶节点，k1个有一个儿子的结点……ki个有i个儿子的结点，那么k0*0+k1*1+……+ki*i……=n-1，因此，枚举子节点和枚举所有节点，加起来的时间复杂度还是线性的。 
		{
			int y=find[nod[x].son[s]];//子节点
			for (int i=0;i<=p;i++) temp[i]=dp[x][i];
			//要么是子树y砍掉了，即：
			for (int i=0;i<=p;i++) temp[i]=temp[i]+1;

			for (int i=0;i<=nod[x].num_tree;i++)//防止影响 
			{
				for (int j=1;j<=nod[y].num_tree;j++)
					temp[i+j]=min(temp[i+j],dp[x][i]+dp[y][j]);//要么是子树y没砍掉，那么状态转移方程式dp[x][i+1]=min(dp[x][i-t]（原先前面子树的）+dp[y][t]) 
			}
			
			for (int i=0;i<=nod[x].num_tree;i++) dp[x][i]=temp[i];
//			dp[x][0]=oo;
//			dp[x]
		}
		for (int i=nod[x].num_tree-1;i>=0;i--) dp[x][i+1]=dp[x][i];
		dp[x][0]=oo;
	}

}
int main()
{
//	freopen("text.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&p);
	memset(nod,0,sizeof(nod));
	for (int i=1;i<=n;i++) nod[i].father=i;
	for (int i=1;i<=n;i++) nod[i].first=i;
	int x,y;
	for (int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	root=get_root();
	get_height(root); 
	std::sort(nod+1,nod+1+n,cmp);//按照深度从大到小排序 
	get_find();//因为排序之后，那些孩子节点都变过了。 
	get_num_tree();
	/*
	for (int i=1;i<=n;i++)
	{
		printf("nod[%d]的深度是%d，父亲是%d，有%d个孩子，子节点个数为%d\n",i,nod[i].height,nod[i].father,nod[i].son_num,nod[i].num_tree);
	}
	*/
	slove();//DP部分 
	//pt();
	for (int i=1;i<=n-1;i++)
		for (int j=1;j<=p;j++)
			dp[i][j]++;
	//pt();
	int ans=oo;
	for (int i=1;i<=n;i++)
		ans=min(ans,dp[i][p]);
	printf("%d",ans);
	return 0;
}
