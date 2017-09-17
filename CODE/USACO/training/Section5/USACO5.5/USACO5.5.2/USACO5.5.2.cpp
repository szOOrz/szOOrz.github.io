/*
ID:cqz15311
LANG:C++
PROG:hidden
*/
#include<bits/stdc++.h>
using namespace std;
char s[100500];
int work(int n){
	int i=0,j=1,k;
	while (i<n && j<n){
		for (k=0;k<n && s[(i+k)%n] == s[(j+k)%n];k++);
		/*比较，找到第一个不相等的*/
		if (s[(i+k)%n] > s[(j+k)%n]) i=i+k+1; else j=j+k+1;
		/*
		注意到，s[i]~s[i+k-1]这一段中不会有比s[j]更好的了。 
		首先
		s[i]~s[i+k-1]和s[j]~s[j+k-1]这一段是相同的 
		假设s[i+1]~s[i+k]中的某一个的是最小表示法的开头 
		设为s[i+t]
		那么容易发现，如果s[j+k]<s[i+k]，那么说明
		s[j+t]比s[i+t]更优，所以s[i+t]不可能成为最小表示法的开头 
		同理，如果s[j+k]>s[i+k]，那么s[j]~s[j+k]都不可能是最小表示法的开头
		*/ 
		if (i == j) i=j+1;
	}
	/*必然有一个i或者一个j是n了——也可能2个都是，那么返回它们中的小的那个就是最小表示法的开头*/ 
	return min(i,j);
}
int main(){
	freopen("hidden.in","r",stdin);
	freopen("hidden.out","w",stdout);
	scanf("%*d");
	for (int i=0;~scanf("%s",s+i);i+=72);//读入 
	printf("%d\n",work(strlen(s)));//处理 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
