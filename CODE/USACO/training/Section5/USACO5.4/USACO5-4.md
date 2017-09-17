---
title: USACO5.4
date: 2017-08-18 16:43:25
tags:
 - USACO
 - DP
 - 网络流
---

[TOC]

<!--more-->

# USACO5.4.1

### 题意

给定一个图，问一条从起点到终点，再从终点到起点，除了起点和终点外，不能经过重复节点的路劲，这条路劲最长有多长。（节点<=100)

而且，是东西方向的，所以不存在类似1-->3-->2-->4的，只有1-->2-->3-->4的。

### 原题

USACO5.4.1-**Canada Tour**

**Canada Tour**

You have won a contest sponsored by an airline. The prize is a ticket to travel around Canada, beginning in the most western point served by this airline, then traveling only from west to east until you reach the most eastern point served, and then coming back only from east to west until you reach the starting city. No city may be visited more than once, except for the starting city, which must be visited exactly twice (at the beginning and the end of the trip). You are not allowed to use any other airline or any other means of transportation.

Given a list of cities served by the airline and a list of direct flights between pairs of cities, find an itinerary which visits as many cities as possible and satisfies the above conditions beginning with the first city and visiting the last city on the list and returning to the first city.

PROGRAM NAME: tour

INPUT FORMAT

| Line 1:             | The number N of cities served by the airline and the number V of direct flights that will be listed. N will be a positive integer not larger than 100. V is any positive integer. |
| ------------------- | ---------------------------------------- |
| Lines 2..N+1:       | Each line contains a name of a city served by the airline. The names are ordered from west to east in the input file. There are no two cities in the same meridian. The name of each city is a string of, at most, 15 digits and/or characters of the Latin alphabet; there are no spaces in the name of a city. |
| Lines N+2..N+2+V-1: | Each line contains two names of cities (taken from the supplied list), separated by a single blank space. This pair is connected by a direct, two-way airline flight. |

SAMPLE INPUT (file tour.in)

8 9	
Vancouver		
Yellowknife	
Edmonton
Calgary
Winnipeg
Toronto	
Montreal
Halifax	
Vancouver Edmonton
Vancouver Calgary	
Calgary Winnipeg
Winnipeg Toronto
Toronto Halifax
Montreal Halifax
Edmonton Montreal
Edmonton Yellowknife
Edmonton Calgary

OUTPUT FORMAT

| Line 1: | The number M of different cities visited in the optimal itinerary. Output 1 if no itinerary is possible. |
| ------- | ---------------------------------------- |
|         |                                          |

SAMPLE OUTPUT (file tour.out)

7



Namely: Vancouver, Edmonton, Montreal, Halifax, Toronto, Winnipeg, Calgary, and Vancouver (but that's not a different city). 

### 做法

这是一个无向图——至于字符串可以用Map来解决。

那么不能经过重复节点的，要到终点的2条路。

考虑用$f[i,j]$表示2条路劲，其中一条到了i，第二条到了j最多经过的城市

考虑对于一个城市k
$$
f[i,j] = max(f[i,k] + 1，f[k,j]+1);
$$
如果j到k右边，那么左边的是可行的，如果k到j有边，那么k到j是有边的

这样是不会重复的。

可以用归纳法解决，如果f[i,k]或者f[k,j]没有重复，那么加上只有一个城市到了j，所以也是不会有重复的。

把f函数改改

可以得到这些：

​	1、$f[i,j] = f[j,i]$

因此只要考虑把第二个k改变即可。

$f[i,j] = max(f[i,k] + 1)$

**百度到的做法Orz**

相当于（除了1和n）每个点内部有容量为1，费用为1的边，外部是容量为1费用为0的边。跑最大费用最大流$Orz$

好了，不管下面的做法。

给出DP代码



```cpp
/*
ID:cqz15311
LANG:C++
PROG:tour
*/
#include<bits/stdc++.h> 
using namespace std;
string a,b;
map<string,int> Name; 
const int inf = 0x3fffffff;
bool g[105][105];
int f[105][105],n,m,ans;
char s[105],t[105];
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> s;
		Name[s] = i;
	}
	memset(g,false,sizeof(g));
	for (int i=1;i<=m;i++){
		cin >> s >> t;
		g[Name[s]][Name[t]] = true;
		g[Name[t]][Name[s]] = true;
	}
	f[1][1] = 1;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			f[i][j] = -inf;
			for (int k=1;k<j;k++)
				if (g[k][j] && f[i][k]>0 && f[i][k]>f[i][j])
					f[i][j] = f[i][k];
			f[j][i] = ++f[i][j];
//			printf("%d %d:%d\n",i,j,f[i][j]);
		}
	}
	ans = 1;
	for (int i=1;i<=n;i++)
		if (g[i][n] && f[i][n] > ans) ans = f[i][n];
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4236 KB]
   Test 2: TEST OK [0.000 secs, 4236 KB]
   Test 3: TEST OK [0.000 secs, 4236 KB]
   Test 4: TEST OK [0.000 secs, 4236 KB]
   Test 5: TEST OK [0.000 secs, 4236 KB]
   Test 6: TEST OK [0.000 secs, 4236 KB]
   Test 7: TEST OK [0.000 secs, 4236 KB]
   Test 8: TEST OK [0.000 secs, 4236 KB]
   Test 9: TEST OK [0.000 secs, 4236 KB]
   Test 10: TEST OK [0.000 secs, 4236 KB]
   Test 11: TEST OK [0.000 secs, 4236 KB]

All tests OK.
YOUR PROGRAM ('tour') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
*/
```

# USACO5.4.2

### 题意

图像识别：给定_,a,b,……z的完整图像，然后给出一个破损的图像

每个完整字符长 20 行。

输入文件包含一个或多个可能损坏的字符图案。一个字符图案可能以这些方式被损坏。

- 最多有一行可能被复制了（就接在原来那一行的下面）
- 最多有一行可能丢失了
- 有些“0”可能被改成“1”
- 有些“1”可能被改成“0”

不会有任何一个字符图案既多余了一行**并且**又丢失了一行。在测试数据的任何一个字符图案中，“0”和“1”的被改变率不超过 30%。

### 原题

USACO5.4.2-**Character Recognition**

给出输入问题http://train.usaco.org/usaco/font.in

### 做法

​	一脸懵逼Orz

​	第一次接触到类似的题目Orz

​	可不可以枚举每一个答案

​	然后枚举是哪一行删除，哪一行复制，然后计算匹配率QAQ

​	这样的话

​	复杂度是$O(27*27*27*20*20)$……好像不会超

​	可是怎么根据匹配率搞？

​	说真的我只会暴力模拟

​	事实上我题目都错了：不会有任何一个字符图案既多余了一行**并且**又丢失了一行QAQ

​	吓得我感觉百度。

​	下面复述一下百度到的结果。++DP

​	说真的，看了好几天还没懂QAQ。

> ​	 设$b[i]$表示给定图从第$i$行开始匹配所能得到的最小差距
>
> ​	$c[i,j]$表示给定图从第$i$行开始连续匹配$j$行所能得到的最小差距
>
> ​	$dif[i,j,k]$表示第$i$个字符图的第j行与给定图的第k行的差距
>
> ​	$b[i]:=min(b[i+19]+c[i,19],b[i+20]+c[i,20],b[i+21]+c[i,21])$
>
> ​	j=19：枚举字母。设表示字符图前行匹配的差距，表示后行匹配的差距，则$c[i,j]:=min(pre[k]+tail[19-k]).$
>
> ​	j=20：直接枚举字符，统计即可。
>
> ​	j=21：与j=19相仿。
>
> ​	对于其中涉及到的统计问题，可以从dif[i,j,k]直接获得，避免了很多重复计算

​	应该不会有这么坑的题再出现了吧。

# USACO5.4.3

### 题意

给定一个无向图，问字典序最小的最小点割集。

### 原题

USACO5.4.3 - **Telecowmunication**

SAMPLE INPUT (file telecow.in)

```
3 2 1 2
1 3
2 3
```

SAMPLE OUTPUT (file telecow.out)

```
1
3
```

### 做法

考虑把每个点拆成2份，中间连一条边，权值为1.

当然，1号点和n号点权值无穷大

对于外面的边，权值为无穷大。

然后跑最小割（SAP）。

