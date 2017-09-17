---
title: USACO5.1.2
date: 2017-08-14 12:49:06
tags:
 - USACO
 - hash
---

# Starry Night

给定H*W的一幅图，让你给图中的一些极大联通快（8联通）编号，已知如果两个联通快经过旋转，对称等可以相同，说明两个联通快是同一个编号的。

<!--more-->

原题：——大家仔细理解一下样例

**Starry Night**
**IOI 98**

High up in the night sky, the shining stars appear in clusters of various shapes. A **cluster** is a non-empty group of neighbouring stars, adjacent in horizontal, vertical or diagonal direction. A cluster cannot be a part of a larger cluster.

Clusters may be similar. Two clusters are **similar** if they have the same shape and number of stars, irrespective of their orientation. In general, the number of possible orientations for a cluster is eight, as Figure 1 exemplifies.

![Figure 1. Eight similar clusters](http://train.usaco.org/usaco/probs/starry-1.gif) 
*Figure 1. Eight similar clusters*

The night sky is represented by a sky map, which is a two-dimensional matrix of 0's and 1's. A cell contains the digit 1 if it has a star, and the digit 0 otherwise.

Given a sky map, mark all the clusters with lower case letters. Similar clusters must be marked with the same letter; non-similar clusters must be marked with different letters.

You mark a cluster with a lower case letter by replacing every 1 in the cluster by that lower case letter.

### PROGRAM NAME: starry

### INPUT FORMAT

The first two lines contain, respectively, the width **W** and the height **H** of a sky map. The sky map is given in the following **H** lines, of **W** characters each.

### SAMPLE INPUT (file starry.in)

```
23
15
10001000000000010000000
01111100011111000101101
01000000010001000111111
00000000010101000101111
00000111010001000000000
00001001011111000000000
10000001000000000000000
00101000000111110010000
00001000000100010011111
00000001110101010100010
00000100110100010000000
00010001110111110000000
00100001110000000100000
00001000100001000100101
00000001110001000111000

```

In this case, the sky map has width 23 and height 15. Just to make it clearer, notice that this input file corresponds to the following picture of the sky.

![Figure 2. Picture of thesky](http://train.usaco.org/usaco/probs/starry-2.gif)
*Figure 2. Picture of the sky*

### OUTPUT FORMAT

The output file contains the same map as the input file, except that the clusters are marked as described in Task.

There will generally be more than one way to label the clusters with letters. Your program should choose the labeling such that if the entire output file is read as a string, this string will be minimal in the lexicographical ordering.

### SAMPLE OUTPUT (file starry.out)

```java
a000a0000000000b0000000
0aaaaa000ccccc000d0dd0d
0a0000000c000c000dddddd
000000000c0b0c000d0dddd
00000eee0c000c000000000
0000e00e0ccccc000000000
b000000e000000000000000
00b0f000000ccccc00a0000
0000f000000c000c00aaaaa
0000000ddd0c0b0c0a000a0
00000b00dd0c000c0000000
000g000ddd0ccccc0000000
00g0000ddd0000000e00000
0000b000d0000f000e00e0b
0000000ddd000f000eee000
```

This is one possible result for the sample input above. Notice that this output file corresponds to the following picture.

![img](http://train.usaco.org/usaco/probs/starry-3.gif)
*Figure 3. Picture with the clusters marked*

### Constraints

0 <= 

W

 (width of the sky map) <= 100

0 <= 

H

 (height of the sky map) <= 100

0 <= Number of clusters <= 500

0 <= Number of non-similar clusters <= 26 (a..z)

1 <= Number of stars per cluster <= 160



# **做法**

显然，我们可以求出每一个联通快——通过floodfill。那么问题就是哪些联通快是同构的。

容易想到**哈希**，如果两个联通块完全相同，我们可以通过最左上角的坐标和一些来进行Hash。

那么如果要满足旋转，对称怎么办。

> 大家想一下，怎么样的一个Hash可以满足？









可能还有别的做法，但是我写此文时只想到这个。

考虑旋转对称之后，对于联通块的某一个对应的格子，它的周围8个是类似的。

可以考虑把每一个联通快的每一个是1的根据8*8范围内的1来进行Hash——可以累加或者怎么样的。

当然，可以多取几个模数来保证正确性。——反例总是有的。

发现，W*H<=10000，所以是不会超时的。

下面给出我的哈希函数

```cpp
const int P[5][5] = 
{{659 ,2017,4049,2017,659 },
 {2017,3169,3359,3169,2017},
 {4049,3359,1   ,3359,4049},
 {2017,3169,3359,3169,2017},
 {659 ,2017,4049,2017,659 }};
int Val(int x,int y){
	int ans = 0;
	for (int i=-2;i<=2;i++){
		for (int j=-2;j<=2;j++){
			if ((x + i < 0) || (x + i >= H) || (y + j < 0) || (y + j >= W))continue;
			if (Ans[x+i][y+j] == -1){
				ans = ans + P[i+2][j+2];
			}
		}
	}
	return ans;
}

```

取一些大素数！这样可以让正确率增大许多。

Executing...
   Test 1: TEST OK [0.000 secs, 4332 KB]
   Test 2: TEST OK [0.000 secs, 4332 KB]
   Test 3: TEST OK [0.000 secs, 4332 KB]
   Test 4: TEST OK [0.000 secs, 4332 KB]
   Test 5: TEST OK [0.000 secs, 4332 KB]

All tests OK.

事实上很快。

```cpp
/*
ID:cqz15311
LANG:C++
PROG:starry 
*/
#include<bits/stdc++.h>
const int maxn = 105;
using namespace std;
const int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
const int dy[8] = {-1, 0, 1,-1,1,-1,0,1}; 
struct Q{
	int x,y;
	Q(int _x = 0,int _y = 0){
		x = _x;
		y = _y;
	}
}q[maxn*maxn];
char a[maxn][maxn];
bool vis[maxn][maxn];
int Ans[maxn][maxn];
int front,rear;
int W,H;
void floodfill(int sx,int sy){
	int x,y,_x,_y;
//	puts("");
	front = rear = 0;
	q[rear++] = Q(sx,sy);
	Ans[sx][sy] = -1;
	while (front < rear){
		x = q[front] . x;
		y = q[front] . y;
		front++;
		for (int d=0;d<8;d++){
			_x = x + dx[d];
			_y = y + dy[d];
			if ((_x < 0) || (_y < 0) || (_x >= H) || (_y >= W) || (a[_x][_y] == 0) || Ans[_x][_y] == -1) continue;
			Ans[_x][_y] = -1;
			q[rear++] = Q(_x,_y);
		}
	}
}

const int P[5][5] = 
{{659 ,2017,4049,2017,659 },
 {2017,3169,3359,3169,2017},
 {4049,3359,1   ,3359,4049},
 {2017,3169,3359,3169,2017},
 {659 ,2017,4049,2017,659 }};
int Val(int x,int y){
	int ans = 0;
	for (int i=-2;i<=2;i++){
		for (int j=-2;j<=2;j++){
			if ((x + i < 0) || (x + i >= H) || (y + j < 0) || (y + j >= W))continue;
			if (Ans[x+i][y+j] == -1){
				ans = ans + P[i+2][j+2];
			}
		}
	}
	return ans;
}
int get_hash(int sx,int sy){
	int x,y,_x,_y;
	int rec = 0;
	front = rear = 0;
	q[rear++] = Q(sx,sy);
	vis[sx][sy] = true;
	while (front < rear){
		x = q[front] . x;
		y = q[front] . y;
		rec = rec + Val(x,y);
		front++;
		for (int d=0;d<8;d++){
			_x = x + dx[d];
			_y = y + dy[d];
			if ((_x < 0) || (_y < 0) || (_x >= H) || (_y >= W)) continue;
			if (Ans[_x][_y] == -1 && !vis[_x][_y]){
				vis[_x][_y] = true;
				q[rear++] = Q(_x,_y);
			}
		}
	}
	return rec;
}
void Filled(int sx,int sy,int Addval){
	int x,y,_x,_y;
	front = rear = 0;
	Ans[sx][sy] = Addval;
	q[rear++] = Q(sx,sy);
	while (front < rear){
		x = q[front] . x;
		y = q[front] . y;
		front++;
		for (int d=0;d<8;d++){
			_x = x + dx[d];
			_y = y + dy[d];
			if ((_x < 0) || (_y < 0) || (_x >= H) || (_y >= W) || Ans[_x][_y] != -1) continue;
			Ans[_x][_y] = Addval;
			q[rear++] = Q(_x,_y);
		}
	}	
}
int Hash[28];
int find(int x){
	for (int i=1;i<=Hash[0];i++){
		if (x == Hash[i]) return i + 'a' - 1;
	}
	Hash[++Hash[0]] = x;
	return Hash[0] + 'a' - 1;
}

int main(){
	freopen("starry.in","r",stdin);
	freopen("starry.out","w",stdout);
	scanf("%d%d",&W,&H);
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			a[i][j] = getchar();
			while ((a[i][j] != '0') && (a[i][j]!='1')) a[i][j] = getchar();
			a[i][j] -= '0';
		}
	}
	memset(Hash,0,sizeof(Hash));
	memset(vis,false,sizeof(vis));
	memset(Ans,0,sizeof(Ans));
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if (Ans[i][j] != 0 || a[i][j] == 0) continue;
			floodfill(i,j); //把当前联通块全部求出来，标记为-1
			int Tmp = find(get_hash(i,j)); 
			Filled(i,j,Tmp);
		}
	}
	
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if (Ans[i][j] == 0) putchar('0'); else
							    printf("%c",Ans[i][j]);
		}
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
```

