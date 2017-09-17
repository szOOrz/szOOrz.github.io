---
title: USACO4.4.3
date: 2017-08-12 18:25:32
tags: USACO
---

# Frame up

题意：

有一些框架，大小在H*W以内，依次放入这些框架在一个格子内，得到一副图，给你这幅图，问放框架的顺序。

保证矩形的每条边都有一部分是可见的。

<!--more-->

**原题**

Consider the following five picture frames shown on an 9 x 8 array:

```
........   ........   ........   ........   .CCC....
EEEEEE..   ........   ........   ..BBBB..   .C.C....
E....E..   DDDDDD..   ........   ..B..B..   .C.C....
E....E..   D....D..   ........   ..B..B..   .CCC....
E....E..   D....D..   ....AAAA   ..B..B..   ........
E....E..   D....D..   ....A..A   ..BBBB..   ........
E....E..   DDDDDD..   ....A..A   ........   ........
E....E..   ........   ....AAAA   ........   ........
EEEEEE..   ........   ........   ........   ........
```

   1          2           3          4          5
Now place all five picture frames on top of one another starting with 1 at the bottom and ending up with 5 on top. If any part of a frame covers another frame, it hides that part of the frame below. Viewing the stack of five frames we see the following.

           .CCC...
           ECBCBB..
           DCBCDB..
           DCCC.B..
           D.B.ABAA
           D.BBBB.A
           DDDDAD.A
           E...AAAA
           EEEEEE..
Given a picture like this, determine the order of the frames stacked from bottom to top.

Here are the rules for this challenge:

The width of the frame is always exactly 1 character and the sides are never shorter than 3 characters.
It is possible to see at least one part of each of the four sides of a frame. A corner is part of two sides.
The frames will be lettered with capital letters, and no two frames will be assigned the same letter.
PROGRAM NAME: frameup

**INPUT FORMAT**

Line 1:	Two space-separated integers: the height H (3 <= H <=30) and the width W (3 <= W <= 30).
Line 2..H+1:	H lines, each with a string W characters wide.
SAMPLE INPUT (file frameup.in)



```
9 8
.CCC....
ECBCBB..
DCBCDB..
DCCC.B..
D.B.ABAA
D.BBBB.A
DDDDAD.A
E...AAAA
EEEEEE..
```

**OUTPUT FORMAT**

Print the letters of the frames in the order they were stacked from bottom to top. If there are multiple possibilities for an ordering, list all such possibilities -- in alphabetical order -- on successive lines. There will always be at least one legal ordering.

**SAMPLE OUTPUT (file frameup.out)**

EDABC

**做法**:

注意到题目保证

​	矩形的每条边都有一部分是可见的。

​	而且N<=26（不然无法保存）

而且矩形的每一条边的长度为1，我们可以很显然地得到一个矩形的范围。

（通过枚举每一个N，然后得到其最左在什么地方出现，最上在什么地方出现，最右在什么地方出现，最下在什么地方出现）

那么如果在这个矩形边上的可见的，说明那个编号的矩形是当前矩形之后才摁上去的。

从而可以考虑到**拓扑排序**,怎么做呢？设当前处理到的矩形为i,编号为j的矩形在i的边上，而且是可见的，那么相当于从i到j有一条又向边。

通过一次拓扑排序，就可以得到结果了。

 注意，该题中的字母可能不连续。



具体实现：

```cpp
/*
ID:cqz15311
LANG:C++
PROG:frameup
*/
#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int from,to,nxt;
}edge[31*31*31*31];
//邻接矩阵就行了，我是不是太浪费了 
int first[255];
int H,W,In[255],nume,Len;
char a[31][31];
bool find(char x){
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if (a[i][j] == x) return true;
		}
	}
	return false;
}
void add_edge(int a,int b){
//	printf("%c-->%c\n",a,b);
//	if (b == 'E') printf("ADDing%c\n",a);
	edge[nume] . from = a;
	edge[nume] . to = b;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
	In[b]++;
}


int cnt;
bool vis[255];
char ans[255];
bool found[255];
void dfs(int x){
	if (x == Len+1){
		for (int i=1;i<=Len;i++) putchar(ans[i]);
		puts("");
		return ;
	}
	for (int i='A';i<='Z';i++){
		if (found[i] && !vis[i] && In[i] == 0){
			vis[i] = true;
			ans[x] = i;
			for (int e=first[i];e!=-1;e=edge[e].nxt) In[edge[e].to]--;
			dfs(x+1);
			for (int e=first[i];e!=-1;e=edge[e].nxt) In[edge[e].to]++;
			vis[i] =false;
			ans[x] = -1;
		}
	}
	//一位一位按照字典序枚举，得到一个解就输出，是满足字典序的。 
}

int main(){
	freopen("frameup.in","r",stdin);
	freopen("frameup.out","w",stdout);
	scanf("%d%d",&H,&W);
	for (int i=0;i<H;i++){
		scanf("%s",&a[i]);
	}
	nume = 0;
	Len = 0;
	memset(found,false,sizeof(found));
	memset(first,-1,sizeof(first));
	for (int c='A';c<='Z';c++){
		if (find(c)){//可能不连续，所以要判断c是否存在 
			found[c] = true;
			Len++;
			int L,R,U,D;
			L = W;
			R = -1;
			U = H;
			D = -1;
			for (int i=0;i<H;i++)
				for (int j=0;j<W;j++)
					if (a[i][j] == c)
						L = min(L,j),R = max(R,j),U = min(U,i),D = max(D,i);
			for (int i=L;i<=R;i++){
				if (a[U][i] != '.' && a[U][i] != c)	add_edge(c,a[U][i]);
				if (a[D][i] != '.' && a[D][i] != c) add_edge(c,a[D][i]);
			}
			for (int i=U;i<=D;i++){
				if (a[i][L] != '.' && a[i][L] != c)	add_edge(c,a[i][L]);
				if (a[i][R] != '.' && a[i][R] != c)	add_edge(c,a[i][R]);
			}
			//注意不能自己向自己连边 
		}
	}
	memset(vis,false,sizeof(vis));
	dfs(1);	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
```

呼&把第四章刷完了。