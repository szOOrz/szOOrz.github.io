---
title: USACO5.3
date: 2017-08-17 12:41:43
tags:
 - USACO
---

[TOC]

<!--more-->

# USACO5.3.2

### window

你刚刚接手一项窗体界面工程。窗体界面还算简单，而且幸运的是，你不必显示实际的窗体。有 5 种基本操作：

1. 创建一个新窗体
2. 将窗体置顶
3. 将窗体置底
4. 删除一个窗体
5. 输出窗体可见部分的百分比（就是，不被其它窗体覆盖的部分）。

<!--more-->

### 原题

USACO5.3.2-Window

### 做法

这题采用模拟大法

如何模拟

我们可以用一个链表存储QAQ。

保存底窗体，顶窗体。

同时保存前面的那个窗体，后面的那个窗体。

支持这些操作。

1、Remove

删除其中一个窗体

```cpp
void remove(int x){
	if (x == -1) return;
	if (x != tail) pre[nxt[x]] = pre[x];
	if (x != head) nxt[pre[x]] = nxt[x];
	if (x == tail) tail = pre[x];
	if (x == head) head = nxt[x];
}
```

2、Addhead

在头加上一个窗体（用于置底操作）

```cpp
void Addhead(int x){
	pre[x] = -1;
	nxt[x] = head;
	if (head!=-1) pre[head] = x;
	head = x;
	if (tail==-1) tail = x;
}
```

3、Addtail

在尾部加上一个窗体（用于置顶操作）

```cpp
void Addtail(int x){
	nxt[x] = -1;
	pre[x] = tail;
	if (tail!=-1) nxt[tail] = x;
	tail = x;
	if (head==-1) head = x;
}
```

★顺着next指针寻找，利用漂浮法，矩阵切割，从而得到可以见到的面积。

```cpp
int dfs(int l,int r,int u,int d,int n){
	while ((n != -1) && ((l >= R[n]) || (r <= L[n]) || (u >= D[n]) || (d <= U[n]))) n = nxt[n];
	if (n == -1) return (r-l) * (d-u);
	int rec = 0;
	if (l < L[n]){
		rec += dfs(l,L[n],u,d,nxt[n]);
		l = L[n];
	}
	if (r > R[n]){
		rec += dfs(R[n],r,u,d,nxt[n]);
		r = R[n];
	}
	if (u < U[n]){
		rec += dfs(l,r,u,U[n],nxt[n]);
		u = U[n];
	}
	if (d > D[n]){
		rec += dfs(l,r,D[n],d,nxt[n]);
		d = D[n];
	}
	return rec;
}
```

----

# USACO5.3.3

### 题意

给定一个有向图，然后在一些点上立flag，这些flag可以通过有向边传递

1、问使得所有点都被弄上flag最少要立多少flag

2、问最少加多少边使得这个图强连通

<!--more-->

### 原题

USACO5.3.3-schlnet

### 做法

**很显然的做法**

先**强连通分量**缩点，缩完点后，求有多少个没有入度，那么就是结果1

第二问显然就是没有出度的分量和没有入度的分量之中取一个较大的。

注意只有一个强连通分量的特判QAQ

> 1A

----

# USACO5.3.4

### 题意

一个N* N的矩阵中有T个点有树，(xi,yi)有一棵树，然后在N*N的范围内，问最大的没有树的正方形的边长是多少。(N<=1000,T<=10000)

### 原题

**USACO5.3.4-bigbrn**

**Big Barn**
A Special Treat
Farmer John wants to place a big square barn on his square farm. He hates to cut down trees on his farm and wants to find a location for his barn that enables him to build it only on land that is already clear of trees. For our purposes, his land is divided into N x N parcels. The input contains a list of parcels that contain trees. Your job is to determine and report the largest possible square barn that can be placed on his land without having to clear away trees. The barn sides must be parallel to the horizontal or vertical axis.

**EXAMPLE**

Consider the following grid of Farmer John's land where `.' represents a parcel with no trees and `#' represents a parcel with trees:

```
      1 2 3 4 5 6 7 8
    1 . . . . . . . .
    2 . # . . . # . .
    3 . . . . . . . .
    4 . . . . . . . .
    5 . . . . . . . .
    6 . . # . . . . .
    7 . . . . . . . .
    8 . . . . . . . .
```

The largest barn is 5 x 5 and can be placed in either of two locations in the lower right part of the grid.

PROGRAM NAME: bigbrn

INPUT FORMAT

Line 1:	Two integers: N (1 <= N <= 1000), the number of parcels on a side, and T (1 <= T <= 10,000) the number of parcels with trees
Lines 2..T+1:	Two integers (1 <= each integer <= N), the row and column of a tree parcel
SAMPLE INPUT (file bigbrn.in)

8 3
2 2
2 6
6 3
OUTPUT FORMAT

The output file should consist of exactly one line, the maximum side length of John's barn.

SAMPLE OUTPUT (file bigbrn.out)

5

### 做法

**考虑枚举每一个点作为右下角的点，然后看能往左上角扩展多少。**

**考虑用f[i,j]表示第i行，第j列的答案**

**如果(i,j)是'#'，那么f[i,j] = 0**

**否则**

**f[i,j] = min( f[i,j-1],f[i-1,j],f[i-1,j-1]) + 1**

**为什么是这样的呢？**

**首先f[i-1,j-1]是比较好理解的**

**假设f[i-1,j-1] = x**

**那么还需要横着和竖着的两条都是x得到。**

**那么好理解了吧QAQ**
