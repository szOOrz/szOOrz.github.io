#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1000005;
int n,a[maxn],sum[maxn];
int main(){
	scanf("%d",&n);
	sum[0] = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]+=a[i];
	}
	if (sum[n] & 1) puts("First"); else{
		bool flag = false;
		for (int i=1;i<=n;i++) if (sum[i] & 1) flag = true;
		if (flag) puts("First"); else puts("Second");
	}
	return 0;
}
/*
������һ����������ȫ��ȡ�������
������һ����ż����ֻ��Ҫȡ��һ�ξ�Ӯ�ˡ�
���ǿ��ܲ���ȡ����һС�Σ�ʹ����һ�ε���ֵ����������
���ǵõ�ǰ׺�ͣ��������ǰ׺�Ͷ���ż������ôSecond������First 
*/
