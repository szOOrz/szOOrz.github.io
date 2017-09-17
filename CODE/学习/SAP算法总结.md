---
title: SAP算法总结
date: 2017-08-09 20:56:24
tags:
---

ISAP算法，一种最大流的优秀算法。

<!-- more -->

概念1：增广路，不解释

概念2：当前弧
​	对于一个点，必然存在当前要处理的弧，一开始，最早的当前弧是它的第一条弧，然后如果下一次他要到下一条边处理，它的当前弧变成下一条边。

具体实现：

·一开始，先跑一发BFS，得到每一个点到汇点的最短距离，这里用最短距离为n+1表示与汇点不联通。

·在满足源点到汇点联通的情况下（dist[s] != n+1)，每一个节点从那个节点的当前弧开始跑增广路，跑增广路的时候，保存其当前弧，以及整条增广路的路劲。

·如果到了节点t，那么从节点t开始，一直到s（也就是遍历整条增广路）得到可以增广的量最少的，同时记录这条边的开始那个节点），记为Min_flow和break_point。

![img](/img/1.png)

·对整条增广路上的所有路劲减去Min_flow，并同时从break_point开始继续增广。

·如果当前节点找不到一个后继节点使得dist[u] +1 = dist[nxt]，那么让dist[u]变成它后继节点的dist的最小值+1，如果没有，或者后继节点都到不了t，那么变为n+1。同时，原先那个层次的点的个数-1，当前这个层次的点的个数+1。这个点的当前弧从第一条弧重新开始（如果原先那个层次没有点，说明有断层，直接return即可）

·一直找，直到出现断层。

<!-- more -->



```cpp
#include<bits/stdc++.h> 
using namespace std;
#define maxv 205
#define maxe 205
struct Edge{
	int from,to,cap,flow,nxt;
	//表示从from到to有一条容量为cap，当前流量为flow的边（数组模拟链表的下一个是nxt） 
}edge[maxe * 2];
//总共有maxe条边，还有maxe条反向边 
int nume,first[maxv];//边的数量和某个点开始最早的边 
int dist[maxv];//当前点到汇点的dist 
int n,m,path[maxv],cur[maxv];
//节点个数，边的个数，增广路以及当前弧 

void init(){
	nume = 0;
	memset(first,-1,sizeof(first));
}//预处理 

void add_edge(int a,int b,int c){
	edge[nume] . from = a;
	edge[nume] . to   = b;
	edge[nume] . cap  = c;
	edge[nume] . flow = 0;
	edge[nume] . nxt  = first[a];
	first[a] = nume++;
	//正边 
	edge[nume] . from = b;
	edge[nume] . to   = a;
	edge[nume] . cap  = 0;
	edge[nume] . flow = 0;
	edge[nume] . nxt  = first[b];
	first[b] = nume++;
	//反向边 
}

const int oo = 1<<20;
int ISAP(int s,int t){
	int u,v,break_point;
	int num[maxv];
	for (int i=1;i<=n;i++) cur[i] = first[i];
	int Ans = 0;
//	bfs(t);//反向BFS，可以不要。 
	memset(num,0,sizeof(num)); 
	for (int i=1;i<=n;i++) num[dist[i]] ++;//预处理得到每个层次的数量
	u = s;//从源点开始 
	while (dist[s] < n){
		if (u == t){//找到一条增广路 
			v = u;
			int Min_flow = oo; 
			while (v!=s){
				int e = path[v];
				if (edge[e].cap - edge[e].flow < Min_flow){
					Min_flow = edge[e].cap - edge[e].flow;
					break_point = edge[e] . from;
				}
				v = edge[e] . from;
			}//遍历整个增广路，找到Min_flow和break_point 
			
			Ans = Ans + Min_flow;//增加答案 
			v = u; 
			while (v!=s){
				edge[path[v]] . flow += Min_flow;
				edge[path[v] ^ 1] . flow -= Min_flow;
				v = edge[path[v]] . from; 
			}//改变整条增广路上的flow。 
			u = break_point;//回到端点 
		}//end of (u = t) 
		else{
			bool found = false;
			for (int e = cur[u];e!=-1;e=edge[e].nxt){
				v = edge[e].to;
				if ((dist[v] == dist[u] - 1) && (edge[e].cap > edge[e].flow)){
					//找到一条可以走的路（满足是下一个，并且容量大于流量） 
					path[v] = e;
					cur[u] = e;
					u = v;
					found = true;
					break;
				}
			}
			if (!found){//Retreat
				int tmp = n+1; 
				for (int e=first[u];e!=-1;e=edge[e].nxt)
					if (edge[e].cap > edge[e].flow){
						v = edge[e].to; 
						tmp = min(tmp,dist[v] + 1);
					}//得到其子节点的所有dist中最小的+1
					 
				num[dist[u]]--;//原来层次的点数-1 
				if ((num[dist[u]]) == 0) return Ans;//断点优化，也叫做GAP优化 
				dist[u] = tmp;//更新层次 
				num[tmp] = num[tmp] + 1;//新的层次的点数增加 
				cur[u] = first[u];//当前弧从头开始 
				if (u != s) u = edge[path[u]].from;//前面的点也要改过 
			}
		}
	}
	return Ans;//返回结果 
}

int main(){
	init();
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
	}
	printf("%d\n",ISAP(1,n));
}
```

