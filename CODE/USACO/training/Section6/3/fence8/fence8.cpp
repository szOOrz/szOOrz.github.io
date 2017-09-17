/*
ID:cqz15311
LANG:C++
PROB:fence8
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 55;
const int maxm = 1025;
int n,m,V[maxn],r[maxm],All,Sum[maxm];
bool Judge(int i,int waste,int last){
	if (waste < 0) return false;
	if (i == -1) return true;
	int limit = n-1;
	if (last != -1 && r[i] == r[i+1]) limit = last;
	for (int j=limit;j>=0;j--){
		if (V[j] >= r[i]){
			V[j]-=r[i];
			int tmp = Judge(i-1,waste - V[j]*(V[j]<r[0]),j);
			V[j]+=r[i];
			if (tmp) return true;
		}
	}
	return false;
}
void init(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&V[i]);
	}
	sort(V,V+n);
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		scanf("%d",&r[i]);
		if (r[i] > V[n-1]) i--,m--;//���������󱳰����� 
	}
	sort(r,r+m);
	for (int i=0;i<n;i++){
		if (V[i] < r[0]){
			for (int j=0;j<n-1;j++) V[j] = V[j+1];
			i--,n--;
		}
	}
	All = 0;
	for (int i=0;i<n;i++) All += V[i];
	Sum[0] = r[0];
	for (int i=1;i<m;i++) Sum[i] = Sum[i-1] + r[i];
}
int Ans;
int main(){
	freopen("fence8.in","r",stdin);
	freopen("fence8.out","w",stdout);
	init();
	Ans = 0;
	int L = 1,R = m;
	while (L <= R){
		int Mid = (L + R) >> 1;
		if (Judge(Mid - 1,All - Sum[Mid-1],-1)){//���Է���Mid�� 
			Ans = Mid;
			L = Mid + 1;
		} else{
			R = Mid - 1;
		}
	}
	printf("%d\n",Ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*������ԭ����Ϊall��ǰK��ľͷ�ܺ�Ϊsum����ôall-sum������һ���и�������ܡ��˷ѡ��������Ŀ������һ����ʣ�µ�ԭ���ϣ���������С��Ŀ��ľͷ��ҪС����������Ϊ�����á��ģ����õ�Ҳ�����˷ѵģ����˷�>all-sum����ֱ�ӷ���false*/

