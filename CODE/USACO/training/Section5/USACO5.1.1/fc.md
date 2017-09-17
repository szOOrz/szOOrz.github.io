---
title: USACO5.1.1
date: 2017-08-14 09:17:49
tags:
 - USACO
 - 计算几何
---

**Fencing the Cows**

给你一些点，问包围这些点的最小花费是多少。

<!--more-->

本题的实质是求一个凸包

> 为什么是凸包？

很显然地发现，如果存在A->B->C，其中B是凹的，那么不如A->C来得赚。

> 凸包是什么？请大家自行Baidu Or Google

下面给出凸包的求法：

首先明确什么是叉积

对于点A，点B，它们的叉积就是

|A| * |B| * sin(α)①

其中|A|表示A的长度，α表示A到B的夹角

我们可以通过α的正负来判断A和B相对于原点的位置（顺时针or逆时针）

然而，叉积还有另外一个公式

A.x * B.y - A.y * B.x②

```cpp
double Cross(Point a,Point b,Point c){//这里以c为源点 
	return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}
```

这个证明不给出，主要是通过单位向量之间的转换得到。

那么我们可以通过公式②的正负性得到点之间的位置。

凸包因为是凸多边形，对于相邻的3个点A，B，C（按照逆时针排序）

必然满足相对于A来说，C在B的顺时针方向。

而且我们还知道，凸包的顶点一定是给定的点中的。

因此可以整理出下面的算法框架

$选择最左的，如果相同选择最下面的——这个点一定是凸包中的点

——好处很多，下面有提到

```cpp
	int k = 0;
	for (int i=1;i<n;i++){
		if ((P[i].x < P[k].x) || (fabs(P[i].x-P[k].x)<eps) && (P[i].y < P[k].y)){
			k = i;
		}
	}
	tmp = P[k];P[k] = P[0];P[0] = tmp;
```

$把其它的点与这个点之间，按照极角排序

```cpp
bool cmp(Point a,Point b){
	return Cross(a,b,p[0]) > 0;
	//大于0表示a在b的顺时针方向，所以a应该排在b的前面 
}
```

$逆时针一个点一个点考虑，要满足上面提到的性质——用一个栈维护

```cpp
	top = 0;
	Stack[top] . x = P[0].x;
	Stack[top] . y = P[0].y;
	top++;
	for (int i=1;i<n;i++){
		while ((top >= 2) && (Cross(P[i],Stack[top-1],Stack[top-2]) > 0)) top--;
		Stack[top] . x = P[i].x;
		Stack[top] . y = P[i].y;
		top++;
	}
```

$直到考虑完所有点结束（不用重新考虑0号点)

> 大家可以考虑一下为什么不用重新考虑

上面的性质可以用一个栈来维护。

那么凸包的周长就是所有凸包上的点之间的距离和

```cpp
	double Ans = 0;
	for (int i=1;i<top;i++){
		Ans = Ans + dis(Stack[i-1],Stack[i]);
	}
	Ans = Ans + dis(Stack[top-1],Stack[0]);
	printf("%.2lf\n",Ans);
```



做法虽然有点繁琐，但代码很好理解

```cpp
/*
ID:cqz15311
LANG:C++
PROG:fc
*/
#include<bits/stdc++.h>
const double eps = 1e-8;
using namespace std;
struct Point{
	double x,y;
}tmp,P[10005],Stack[10005];
int n; 
double Cross(Point a,Point b,Point c){//这里以c为源点 
	return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
bool cmp(Point a,Point b){
	return Cross(a,b,P[0]) > 0;
	//大于0表示a在b的顺时针方向，所以a应该排在b的前面 
}
void init(){
	freopen("fc.in","r",stdin);
	freopen("fc.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%lf%lf",&P[i].x,&P[i].y);
	}
	int k = 0;
	for (int i=1;i<n;i++){
		if ((P[i].x < P[k].x) || (fabs(P[i].x-P[k].x)<eps) && (P[i].y < P[k].y)){
			k = i;
		}
	}
	tmp = P[k];P[k] = P[0];P[0] = tmp;
	sort(P+1,P+n,cmp);
}
int top;
void solve(){
	top = 0;
	Stack[top] . x = P[0].x;
	Stack[top] . y = P[0].y;
	top++;
	for (int i=1;i<n;i++){
		while ((top >= 2) && (Cross(P[i],Stack[top-1],Stack[top-2]) > 0)) top--;
		Stack[top] . x = P[i].x;
		Stack[top] . y = P[i].y;
		top++;
	}
}
double dis(Point a,Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Write(){
	double Ans = 0;
	for (int i=1;i<top;i++){
		Ans = Ans + dis(Stack[i-1],Stack[i]);
	}
	Ans = Ans + dis(Stack[top-1],Stack[0]);
	printf("%.2lf\n",Ans);
	fclose(stdin);
	fclose(stdout);
}
int main(){
	init();
	solve();
	Write();
	return 0;
}
```

