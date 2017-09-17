---
title: USACO4.4.1
date: 2017-08-11 21:04:04
tags: 
 - USACO
---

# Shuttle Puzzle

题意：给定n，当n=3的时候，表示从WWW_BBB到BBB_WWW的最少操作步数。每次可以将某一个W或者B移动到空格位置，但是距离得小于等于2。

n<=12

<!--more-->

这题搜索似乎要超时。

下面给出原题：

USACO4.4.1

**Shuttle Puzzle**
**Traditional**
The Shuttle Puzzle of size 3 consists of 3 white marbles, 3 black marbles, and a strip of wood with 7 holes. The marbles of the same color are placed in the holes at the opposite ends of the strip, leaving the center hole empty.

INITIAL STATE: WWW_BBB 
GOAL STATE: BBB_WWW
To solve the shuttle puzzle, use only two types of moves. Move 1 marble 1 space (into the empty hole) or jump 1 marble over 1 marble of the opposite color (into the empty hole). You may not back up, and you may not jump over 2 marbles.

A Shuttle Puzzle of size N consists of N white marbles and N black marbles and 2N+1 holes.

Here's one solution for the problem of size 3 showing the initial, intermediate, and end states:

WWW BBB
WW WBBB
WWBW BB
WWBWB B
WWB BWB
W BWBWB
 WBWBWB
BW WBWB
BWBW WB
BWBWBW 
BWBWB W
BWB BWW
B BWBWW
BB WBWW
BBBW WW
BBB WWW
Write a program that will solve the SHUTTLE PUZZLE for any size N (1 <= N <= 12) in the minimum number of moves and display the successive moves, 20 per line.

PROGRAM NAME: shuttle

**INPUT FORMAT**

A single line with the integer N.
**SAMPLE INPUT (file shuttle.in)**

3
**OUTPUT FORMAT**

The list of moves expressed as space-separated integers, 20 per line (except possibly the last line). Number the marbles/holes from the left, starting with one.

Output the solution that would appear first among the set of minimal solutions sorted numerically (first by the first number, using the second number for ties, and so on).

**SAMPLE OUTPUT (file shuttle.out)**

3 5 6 4 2 1 3 5 7 6 4 2 3 5 4



一下仅表示-对于Nocow内容，我的理解-

3
3 5 6 4 2 1 3 5 7 6 4 2 3 5 4
4
4 6 7 5 3 2 4 6 8 9 7 5 3 1 2 4 6 8 7 5 3 4 6 5
5
5 7 8 6 4 3 5 7 9 10 8 6 4 2 1 3 5 7 9 11 10 8 6 4 2 3 5 7 9 8 6 4 5 7 6
6
6 8 9 7 5 4 6 8 10 11 9 7 5 3 2 4 6 8 10 12 13 11 9 7 5 3 1 2 4 6 8 10 12 11 9 7 5 3 4 6 8 10 9 7 5 6 8 7

**进行神奇的分析**

把空格的位置也算上

3：4|35|642|1357|642|35|4

4：5|46|753|2468|97531|2468|753|46|5

……聪明的你发现规律了吗？

是的，这是一个对称的等差数列。

要证明？？http://train.usaco.org/usacoanal2?a=lNUFVam4bZA&S=shuttle

```cpp
/*
ID:cqz15311
LANG:C++
PROG:shuttle
*/
#include<bits/stdc++.h> 
using namespace std;
int n,now,len,cnt;
int main(){
	freopen("shuttle.in","r",stdin);
	freopen("shuttle.out","w",stdout);
	scanf("%d",&n);
	now = n+1;
	cnt = 0;
	for (int i=1;i<=2*n+1;i++){
		if (i <= n+1){
			len = i;
		} else 
			len = 2 * (n+1) - i;
		if (i & 1){
			for (int j=1;j<=len;j++){
				if (i!=1){
					cnt++;
					printf("%d",now);
					if ((i == 2*n+1) && (j == len)) puts(""); else
					if (cnt % 20 == 0) puts(""); else
					putchar(' ');
				}
				now = now - 2;
			}
			now+=2;
			if (i <= n)now--; else now++;
		} else{
			for (int j=1;j<=len;j++){
					cnt++;
					printf("%d",now);
					if (cnt % 20 == 0) puts(""); else
					putchar(' ');
					now = now + 2;
			}
			now-=2;
			if (i <= n)now++; else now--;
		}
	}
	//puts("");这个不能有！害得我没有1A 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4176 KB]
   Test 2: TEST OK [0.000 secs, 4176 KB]
   Test 3: TEST OK [0.000 secs, 4176 KB]
   Test 4: TEST OK [0.000 secs, 4176 KB]
   Test 5: TEST OK [0.000 secs, 4176 KB]
   Test 6: TEST OK [0.000 secs, 4176 KB]
   Test 7: TEST OK [0.000 secs, 4176 KB]
   Test 8: TEST OK [0.000 secs, 4176 KB]
   Test 9: TEST OK [0.000 secs, 4176 KB]
   Test 10: TEST OK [0.000 secs, 4176 KB]

All tests OK.
Your program ('shuttle') produced all correct answers!  This is your
submission #2 for this problem.  Congratulations!
*/ 
```

