---
title: USACO5.1.3
date: 2017-08-14 15:10:03
tags:
 - USACO
 - hash
 - 差分
---

# Musical Themes

**题意**

​	给定一个长度为N（N<=5000)的数字串(0~88)，问最长的一个子串，使得除了这个子串外，还有一个与该子串重合位置的另一个长度相同子串的对应位置都是该子串的对应位置增加

<!--more-->

# 原题

**Brian Dean**

A musical melody is represented as a sequence of N (1 <= N <= 5000) notes that are integers in the range 1..88, each representing a key on the piano. It is unfortunate but true that this representation of melodies ignores the notion of musical timing; but, this programming task is about notes and not timings.

Many composers structure their music around a repeating "theme", which, being a subsequence of an entire melody, is a sequence of integers in our representation. A subsequence of a melody is a theme if it:

- is at least five notes long
- appears (potentially transposed -- see below) again somewhere else in the piece of music
- is disjoint from (i.e., non-overlapping with) at least one of its other appearance(s)

Transposed means that a constant positive or negative value is added to every note value in the theme subsequence.

Given a melody, compute the length (number of notes) of the longest theme.

One second time limit for this problem's solutions!

### PROGRAM NAME: theme

### INPUT FORMAT

The first line of the input file contains the integer N. Each subsequent line (except potentially the last) contains 20 integers representing the sequence of notes. The last line contains the remainder of the notes, potentially fewer than 20.

### SAMPLE INPUT (file theme.in)

```
30
25 27 30 34 39 45 52 60 69 79 69 60 52 45 39 34 30 26 22 18
82 78 74 70 66 67 64 60 65 80

```

### OUTPUT FORMAT

The output file should contain a single line with a single integer that represents the length of the longest theme. If there are no themes, output 0.

### SAMPLE OUTPUT (file theme.out)

```
5

```

[The five-long theme is the last five notes of the first line and the first five notes of the second] 

<!--more-->

# 做法

做法很多。

下面给出我的做法。



第一想法是**哈希**。

从而想到了二分答案。

加入现在知道了长度D，只是问存不存在2个长度为D的串可能。

那么存不存在呢？

如果简单的哈希，难的就是因为有可能转调

经过思考，查询一些题解，找到了一个好的方法

——转自nocow——

-----------------

​	这个题考虑到相同的旋律之间的差是常数，可以把读入的序列变换一下。就是每个元素与其前一个元素做差。例如原序列 {3,5,7,3,4,4,6,8,4}，做差后是{2,2,-4,1,0,2,2,-4}。这样就可以在变换后的序列中直接查找最长的重复序列即可。上述例子中是2,2,-4，长度为3，对应原序列中3,5,7,3，长度为4。

----------

上述转化后我们就可以通过寻找最长重复串来做到。

**做法1**

​	可以通过上述转化后，以每一个为截开的位置，跑KMP。(N^2)

**做法2**

​	还是我刚才那个想法，每次二分后O(N)扫描，得到这个点以及这个点一直到前面总D个长度的哈希值——如果哈希值相同，很大可能是和前面的重复的，然后D+1就是最终的答案。(N log N)

​	我后来写这种做法遇到了好多坑——建议大家多练习一下hash的题目，特别是应该多取几个模数，当然我取了2个bit。具体的细节很繁琐，可以看一下代码。

​	虽然速度比较快，但是我不推荐这种做法，更简单的做法往下看

```cpp
/*
ID:cqz15311
LANG:C++
PROG:theme
*/
#include<bits/stdc++.h>
const int Mod = (1e6+7);
//好像1e7就超空间了.
const int bit1 = 17;
const int bit2 = 23;
//但位17好像第八个点过了，第九个点WA了
//其实可以多重哈希，多取几个模数。
//我弄了2个bit就能过USACO所有数据了——其实最好还是取模数，代码改改少 
//其实如果是17，3之类的我试了一下是WA的，懒惰就改数字，其实最好是改模数
//这题坑了我好久，但是说到底还是Hash的题目做得少。
//或者说，以前做hash的题目都不卡单hash的。
const int maxn = 5005;
using namespace std;
typedef long long LL;
int Hash1[Mod],Hash2[Mod];
LL f1[maxn],f2[maxn],a[maxn];
LL Pow1[maxn],Pow2[maxn];
int n,L,R,Mid;
bool check(int Len){
	LL rec1 = 0,rec2 = 0;
	for (int i=1;i<=Len;i++) rec1 = (rec1 * bit1 + a[i]) % Mod,rec2 = (rec2 * bit2 + a[i]) % Mod;
	f1[Len] = rec1;
	f2[Len] = rec2;
	for (int i=Len+1;i<=n;i++){
		rec1 = (((rec1 - Pow1[Len-1] * a[i - Len]) % Mod + Mod) % Mod * bit1 + a[i]) % Mod;
		rec2 = (((rec2 - Pow2[Len-1] * a[i - Len]) % Mod + Mod) % Mod * bit2 + a[i]) % Mod;
		f1[i] = rec1;	//注意是Len-1不是Len——卡了N久 
		f2[i] = rec2;
	}
	bool flag = false;
	for (int i=Len;i<=n;i++){
		if (Hash1[f1[i]] == -1) Hash1[f1[i]] = i;
		if (Hash2[f2[i]] == -1) Hash2[f2[i]] = i;
		if ((Hash1[f1[i]] < i - Len/*+1*/) && (Hash2[f2[i]] < i - Len)) flag = true;
				/*不能加一，因为差分过的最后一个等于前面最前面的一个*/
	}
	for (int i=Len;i<=n;i++){
		Hash1[f1[i]] = -1;
		Hash2[f2[i]] = -1;
	}
	if (flag) return true; else return false;
}

int main(){
	freopen("theme.in","r",stdin);
	freopen("theme.out","w",stdout);
	Pow1[0] = 1,Pow2[0] = 1;
	memset(Hash1,-1,sizeof(Hash1));
	memset(Hash2,-1,sizeof(Hash2));
	for (int i=1;i<=5000;i++)Pow1[i] = Pow1[i-1] * bit1 % Mod;
	for (int i=1;i<=5000;i++)Pow2[i] = Pow2[i-1] * bit2 % Mod;
	scanf("%d",&n);
	a[0] = 0;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=n-1;i>=1;i--){
		a[i] = a[i] - a[i-1];
		a[i] = (a[i] % Mod + Mod) % Mod;
	}//a0没用
	n--;
	L = 1;
	R = n;
	while (L < R){
		Mid = (L + R + 1) >> 1;
		if (check(Mid)){
			L = Mid;
		} else 
			R = Mid - 1;
	}
	if (L+1 < 5)  puts("0"); else printf("%d\n",L + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
```



**算法3**

考虑用DP[i,j]表示左边匹配到i，右边匹配到j的最大匹配数。——直接跑，都不用转化……

--------

Let theme(i,j) be the length of the longest theme which occurs starting at both note i and j. Note that if note[i+1]-note[i] == note[j+1]-note[j], than theme(i,j) = 1+theme(i+1,j+1). Otherwise, theme(i,j) = 1. Thus, we order the search in such a way that theme(i,j) is tested immediately after theme(i+1,j+1), keeping track of the length of the current theme, as well as the length of the longest theme found so far.

------

http://train.usaco.org/usacoanal2?a=2ocZH3qaoaJ&S=theme

```cpp
#include <fstream.h>

int     n;
int     note[5000];

int 
main () {
    ifstream filein ("theme.in");
    filein >> n;
    for (int i = 0; i < n; ++i) 
	filein >> note[i];
    filein.close ();

    int     longest = 1;

    for (int i = 1; i < n; ++i) {
	int     length = 1;
	for (int j = n - i - 1 - 1; j >= 0; --j) {
	    if (note[j] - note[j + 1] == note[j + i] - note[j + i + 1]) {
		++length;
		if (length > i) 
		    length = i;
		if (longest < length)
		    longest = length;
	    }
	    else {
		length = 1;
	    }
	}
    }

    ofstream fileout ("theme.out");
    fileout << ((longest >= 5) ? longest : 0) << endl;
    fileout.close ();

    exit (0);
}
```



**算法4+**

​	一些我听说过的名词：好像也只是听说过——————后缀数组。后缀自动机。……
