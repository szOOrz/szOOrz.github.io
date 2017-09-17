---
title: USACO4.4.2
date: 2017-08-11 20:44:20
tags: 
 - USACO
 - 网络流
---

# Pollutant Control

题意：给定一张图，每条边有流量，求一个图的最小割，并且求出字典序最小一组最小割（在满足的情况下，边越少越好）。

<!-- more -->

下面给出原题：

USACO4.4.2

**Pollutant Control**

**Hal Burch**

It's your first day in Quality Control at Merry Milk Makers, and already there's been a catastrophe: a shipment of bad milk has been sent out. Unfortunately, you didn't discover this until the milk was already into your delivery system on its way to stores. You know which grocer that milk was destined for, but there may be multiple ways for the milk to get to that store.

The delivery system is made up of a several warehouses, with trucks running from warehouse to warehouse moving milk. While the milk will be found quickly, it is important that it does not make it to the grocer, so you must shut down enough trucks to ensure that it is impossible for the milk to get to the grocer in question. Every route costs a certain amount to shut down. Find the minimum amount that must be spent to ensure the milk does not reach its destination, along with a set of trucks to shut down that achieves this goal at that cost.

PROGRAM NAME: milk6

INPUT FORMAT

  Line 1:     	Two space separated integers, N and M. N (2 <= N <= 32) is the number of warehouses that Merry Milk Makers has, and M (0 <= M <= 1000) is the number of trucks routes run. Warehouse 1 is actually the productional facility, while warehouse N is the grocer to which which the bad milk was destined.
  Line 2..M+1:	Truck routes: three space-separated integers, Si, Ei, and Ci. Si and Ei (1 <= Si,Ei <= N) correspond to the pickup warehouse and dropoff warehouse for the truck route. Ci (0 <= Ci <= 2,000,000) is the cost of shutting down the truck route.

SAMPLE INPUT (file milk6.in)

```cpp
4 5
1 3 100
3 2 50
2 4 60
1 2 40
2 3 80
```

OUTPUT FORMAT

The first line of the output should be two integers, C and T. C is the minimum amount which must be spent in order to ensure the our milk never reaches its destination. T is the minimum number of truck routes that you plan to shut down in order to achive this goal. The next T lines sould contain a sorted list of the indexes of the truck routes that you suggest shutting down. If there are multiple sets of truck routes that achieve the goal at minimum cost, choose one that shuts down the minimum number of routes. If there are still multiple sets, choose the one whose initial routes have the smallest index.

SAMPLE OUTPUT (file milk6.out)

```cpp
60 1
3
```





<!-- more -->

分析和做法：

这题只需要最大流就可以：注意到边不超过1000个，我们可以把每条边的边权改成原来的边权*1001再加上1，那么跑一编最小割，可以得到用的边最少的。因为在边权相同的情况下，1选的越少越好。

那么答案就是最小割 / 1001。

那么如何求出字典序最小的一组最小割呢？

显然，因为要字典序最小，我们不能用普通的BFS之类的。

考虑枚举每一条边，如果删去这条边后整个图的最小割变小了，而且变小的正好等于这条边的边权，说明这条边是最小割的一部分，然后真的把这条边从原来的网络中删去。

这里有一些注意点：

1、后面都是每行输出一个答案，不是一行里面

2、要开long long，不然会爆

3、答案的maxv和maxe不要搞错。

```cpp
/*
ID:cqz15311
LANG:C++
PROG:milk6 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL oo = 1LL<<50;
const int maxv = 35;
const int maxe = 2005;
struct Edge{
	int from,to,nxt;
	LL cap,flow;
};
struct G{
	int nume;
	int first[maxv],cur[maxv],path[maxv],num[maxv+2],n;
	int dist[maxv];
	Edge edge[maxe * 2];
	LL Max_flow;
	
	void init(int n){
		this -> n = n;
		nume = 0;
		memset(first,-1,sizeof(first));
	}
	void add_edge(int a,int b,int c){
		edge[nume] . from = a;
		edge[nume] . to   = b;
		edge[nume] . cap  = c;
		edge[nume] . flow = 0;
		edge[nume] . nxt  = first[a];
		first[a] = nume++;
		edge[nume] . from = b;
		edge[nume] . to   = a;
		edge[nume] . cap  = 0;
		edge[nume] . flow = 0;
		edge[nume] . nxt  = first[b];
		first[b] = nume++;
	}
	void Reset(){
		for (int i=0;i<nume;i++) edge[i] . flow = 0;
	}
	LL sap(int s,int t){
		Reset();
		Max_flow = 0;
		memset(num,0,sizeof(num));
		num[0] = n;
		memset(dist,0,sizeof(dist));
		for (int i=1;i<=n;i++) cur[i] = first[i];
		int u = s;
		while (dist[s] < n){
//			printf("%d\n",u);
			if (u == t){
				LL Min_flow = oo,break_point;
				//Augment
				for (int v=t;v!=s;v=edge[path[v]].from){
					if (edge[path[v]] . cap - edge[path[v]] . flow < Min_flow){
						Min_flow = edge[path[v]] . cap - edge[path[v]] . flow;
						break_point = edge[path[v]] . from;
					}
				}
				Max_flow += Min_flow;
				for (int v=t;v!=s;v=edge[path[v]].from){
					edge[path[v]] . flow += Min_flow;
					edge[path[v]^1] .flow -= Min_flow;
				}
				u = break_point;
			} else{
				bool found = false;
				for (int &e = cur[u];e!=-1;e=edge[e].nxt){
					if ((edge[e].cap > edge[e].flow) && (dist[edge[e].to] + 1 == dist[u])){
						path[edge[e].to] = e;
						u = edge[e].to;
						found = true;
						break;
					}
				}
				if (!found){
					int tmp = n+1;
					for (int e=first[u];e!=-1;e=edge[e].nxt){
						if (edge[e].cap > edge[e].flow){
							tmp = min(tmp,dist[edge[e].to] + 1);
						}
					}
					if (--num[dist[u]] == 0) return Max_flow;
					dist[u] = tmp;
					num[tmp]++;
					cur[u] = first[u];
					if (u != s) u = edge[path[u]] . from;
				}
			}
		}
		return Max_flow;
	}
}G;
int ans[maxe+1];
int a[maxe],b[maxe];
LL c[maxe];
int main(){
	freopen("milk6.in","r",stdin);
	freopen("milk6.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	G.init(n);
	for (int i=0;i<m;i++){
		scanf("%d%d%lld",&a[i],&b[i],&c[i]);
		c[i] = c[i] * 1001 + 1;
		G.add_edge(a[i],b[i],c[i]);
	}
	LL Max_flow = G.sap(1,n);
	printf("%lld ",Max_flow / 1001);
	memset(ans,0,sizeof(ans));
	for (int i=0;i<m;i++){
		G.edge[i*2] . cap = 0;
		LL tmp = G.sap(1,n);
		if (Max_flow - tmp == c[i]){
			ans[++ans[0]] = i+1;
			Max_flow -= c[i];
		} else
			G.edge[i*2] . cap = c[i];
	}
	printf("%d\n",ans[0]);
	if (ans[0] != 0){
		printf("%d\n",ans[1]);
		for (int i=2;i<=ans[0];i++){
			printf("%d\n",ans[i]);
		}
	} 
	fclose(stdin);
	fclose(stdout);
}
/*

Executing...
   Test 1: TEST OK [0.000 secs, 4328 KB]
   Test 2: TEST OK [0.000 secs, 4328 KB]
   Test 3: TEST OK [0.000 secs, 4328 KB]
   Test 4: TEST OK [0.000 secs, 4328 KB]
   Test 5: TEST OK [0.056 secs, 4328 KB]
   Test 6: TEST OK [0.000 secs, 4328 KB]
   Test 7: TEST OK [0.000 secs, 4328 KB]
   Test 8: TEST OK [0.000 secs, 4328 KB]
   Test 9: TEST OK [0.014 secs, 4328 KB]
   Test 10: TEST OK [0.154 secs, 4328 KB]
   Test 11: TEST OK [0.000 secs, 4328 KB]
   Test 12: TEST OK [0.000 secs, 4328 KB]
All tests OK.

*/
```

