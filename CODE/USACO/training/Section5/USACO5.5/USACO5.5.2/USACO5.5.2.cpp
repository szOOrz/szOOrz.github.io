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
		/*�Ƚϣ��ҵ���һ������ȵ�*/
		if (s[(i+k)%n] > s[(j+k)%n]) i=i+k+1; else j=j+k+1;
		/*
		ע�⵽��s[i]~s[i+k-1]��һ���в����б�s[j]���õ��ˡ� 
		����
		s[i]~s[i+k-1]��s[j]~s[j+k-1]��һ������ͬ�� 
		����s[i+1]~s[i+k]�е�ĳһ��������С��ʾ���Ŀ�ͷ 
		��Ϊs[i+t]
		��ô���׷��֣����s[j+k]<s[i+k]����ô˵��
		s[j+t]��s[i+t]���ţ�����s[i+t]�����ܳ�Ϊ��С��ʾ���Ŀ�ͷ 
		ͬ�����s[j+k]>s[i+k]����ôs[j]~s[j+k]������������С��ʾ���Ŀ�ͷ
		*/ 
		if (i == j) i=j+1;
	}
	/*��Ȼ��һ��i����һ��j��n�ˡ���Ҳ����2�����ǣ���ô���������е�С���Ǹ�������С��ʾ���Ŀ�ͷ*/ 
	return min(i,j);
}
int main(){
	freopen("hidden.in","r",stdin);
	freopen("hidden.out","w",stdout);
	scanf("%*d");
	for (int i=0;~scanf("%s",s+i);i+=72);//���� 
	printf("%d\n",work(strlen(s)));//���� 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
