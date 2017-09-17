/*
有两条分别为红色，蓝色的线。如图波浪形排列。
在n处位置相交，求两条线能否解开。
n<=1e5

如果两处相交的位置是同一种颜色在上，那么一定可以解开。
然后可以将这两个位置删除。
过程用栈维护即可。
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100009;
char str[maxn], s[maxn];
int top;

int main(){
	scanf("%s", &str);
	for (int i=0; str[i]; i++)
		if (top && s[top] == str[i]) top--;
		else s[++top] = str[i];
	puts(top ? "No" : "Yes");
	return 0;
}