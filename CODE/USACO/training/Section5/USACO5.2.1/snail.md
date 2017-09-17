---
title: USACO5.2.1
date: 2017-08-14 17:20:40
tags:
 - USACO
 - 搜索
---

# 题意

有一个N*N的方格(N<=120)，上面有B（B<=200）个障碍，你从(1,1)出发，一开始可以向右或下走，一直碰到障碍，然后选择转90度再走，走到障碍，一直走，直到走的过程中经过了原来走过的格子。问最多能走过过多少格子

<!--more-->

# 原题

**Snail Trails**
**All Ireland Contest**

Sally Snail likes to stroll on a N x N square grid (1 <n <= 120). She always starts in the upper left corner of the grid. The grid has empty squares (denoted below by ‘.') and a number (B) of barriers (denoted below by `#'). Here is a depiction of a grid including a demonstration of the grid labelling algorithm:

```
          A B C D E F G H
        1 S . . . . . # .
        2 . . . . # . . .
        3 . . . . . . . .
        4 . . . . . . . .
        5 . . . . . # . .
        6 # . . . . . . .
        7 . . . . . . . .
        8 . . . . . . . .
```

Sally travels vertically (up or down) or horizontally (left or right). Sally can travel either down or right from her starting location, which is always A1.

Sally travels as long as she can in her chosen direction. She stops and turns 90 degrees whenever she encounters the edge of the board or one of the barriers. She can not leave the grid or enter a space with a barrier. Additionally, Sally can not re-cross any square she has already traversed. She stops her traversal altogether any time she can no longer make a move.

Here is one sample traversal on the sample grid above:

```
          A B C D E F G H
        1 S---------+ # .
        2 . . . . # | . .
        3 . . . . . | . .
        4 . . . . . +---+
        5 . . . . . # . |
        6 # . . . . . . |
        7 +-----------+ |
        8 +-------------+
```

Sally traversed right, down, right, down, left, up, and right. She could not continue since she encountered a square already visited. Things might have gone differently if she had chosen to turn back toward our left when she encountered the barrier at F5.

Your task is to determine and print the largest possible number of squares that Sally can visit if she chooses her turns wisely. Be sure to count square A1 as one of the visited squares.

### PROGRAM NAME: snail

### INPUT FORMAT

The first line of the input has N, the dimension of the square, and B, the number of barriers (1 <= B <= 200). The subsequent B lines contain the locations of the barriers. The sample input file below describes the sample grid above. The sample output file below is supposed to describe the traversal shown above. Note that when N > 26 then the input file can not specify barriers to the right of column Z.

### SAMPLE INPUT (file snail.in)

```
8 4
E2
A6
G1
F5
```

### OUTPUT FORMAT

The output file should consist of exactly one line, the largest possible number of squares that Sally can visit.

### SAMPLE OUTPUT (file snail.out)

```
33
```

Using this traversal:

```
          A B C D E F G H
        1 S . . . . . # .
        2 | . . . # . . .
        3 | . . . +-----+
        4 | . . . | . . |
        5 +-------+ # . |
        6 # . . . . . . |
        7 +------------ |
        8 +-------------+
```

# 做法

这题的做法的本质就是一个DFS的搜索。

走还是转。

然后弄一个数组保存哪些格子走过了。

输入比较繁琐。

```cpp
/*
ID:cqz15311
LANG:C++
PROG:snail
*/
#include<bits/stdc++.h>
const int maxn = 125;
using namespace std;
const int dx[4] = {-1, 0,0,1};
const int dy[4] = { 0,-1,1,0};
#define UP 0
#define LEFT 1
#define RIGHT 2
#define DOWN 3
bool vis[maxn][maxn];
bool f[maxn][maxn];
char s[5];
int n,B,Ans;
int getnum(){
	int a = 0;
	for (int i=1;s[i];i++) a = a*10+s[i]-48;
	return a;
}
void PT(){
	for (int i=0;i<=n+1;i++){
		for (int j=0;j<=n+1;j++){
			if (vis[i][j]) putchar('V'); else
			if (f[i][j]) putchar('#'); else putchar('.');
		}
		puts("");
	}
	puts("");
}
void dfs(int x,int y,int fx,int cnt){
	int _x,_y;
//	printf("X = %d %d %d\n",x,y,fx);
	if (f[x][y] || vis[x][y]) return;
	if (cnt > Ans) Ans = cnt;
	vis[x][y] = true;
//	printf("%d %d\n",x,y);
//	PT();
	_x = x + dx[fx];
	_y = y + dy[fx];
	if (f[_x][_y]){
		for (int d=0;d<4;d++)
			dfs(x + dx[d ],y+dy[d ],d ,cnt+1);
	}//前面是障碍 
	else 
			dfs(x + dx[fx],y+dy[fx],fx,cnt+1);
	vis[x][y] = false;
}
int main(){
	freopen("snail.in","r",stdin);
	freopen("snail.out","w",stdout);
	scanf("%d%d",&n,&B);
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++) f[0][i] = f[n+1][i] = 1;
	for (int i=1;i<=n;i++) f[i][0] = f[i][n+1] = 1;
	for (int i=1;i<=B;i++){
		scanf("%s",&s);
		f[getnum()][s[0] - 'A' + 1] = 1;
	}
	Ans = 0;
	memset(vis,false,sizeof(vis));
	dfs(1,1,RIGHT,1);
	dfs(1,1,DOWN,1);
	printf("%d\n",Ans);
	fclose(stdin);
	fclose(stdout);
}
```

速度还是很快的


Executing...
   Test 1: TEST OK [0.014 secs, 4208 KB]
   Test 2: TEST OK [0.014 secs, 4208 KB]
   Test 3: TEST OK [0.014 secs, 4208 KB]
   Test 4: TEST OK [0.014 secs, 4208 KB]
   Test 5: TEST OK [0.014 secs, 4208 KB]
   Test 6: TEST OK [0.014 secs, 4208 KB]
   Test 7: TEST OK [0.014 secs, 4208 KB]
   Test 8: TEST OK [0.014 secs, 4208 KB]
   Test 9: TEST OK [0.014 secs, 4208 KB]
   Test 10: TEST OK [0.014 secs, 4208 KB]
   Test 11: TEST OK [0.014 secs, 4208 KB]
   Test 12: TEST OK [0.112 secs, 4208 KB]

All tests OK.
YOUR PROGRAM ('snail') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
