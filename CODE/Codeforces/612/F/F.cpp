/*
����Ϊn�Ļ�����i������Ϊai�� 
�����s��������һ�����ӵĻ���Ϊ1�������ǰ���ֵĻ���Ϊ0��
���n�����ķǵݼ����е���С�����Ƕ��٣�����ӡ������
*/
#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct W{
	int a,loca;
	bool operator <(const W &x) const{
		return a < x.a || a == x.a && loca < x.loca;
	}
};
int main(){
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++){
		scanf("%d",&w[i].a);
		w[i].loca = i;
	}
	sort(a+1,a+1+n);
	int j;
	for (int i=1;i<=n;i=j){
		j = i;
		while (w[i].a == w[j].a) j++;
		
		for (int k=i;k<=j;k++){
			if (i == 1) 
		}
	}
}


/*
	����ÿһ�飬ֻ��2�ֿ��ܣ�
	Ҫô������һ��ԲȦ�����Ż��ߵ��ţ� 
	Ҫô���������ߣ�Ȼ�����ұ���
	�����������ߣ�Ȼ�������� 
	���ǰ�ԲȦ������
	�ȵõ�ÿ������Ϊ��ʼ�����С���� 
	��ô��벿��ֻ�����ұ��ߡ�
	�Ұ벿��ֻ��������ߡ�
	����һ���������ߵ�ĳ���㣬Ȼ�������ߡ�
	�õ�ÿ������Ϊ����ߵļ�ֵ��
	��ô�����߱�Ȼֻ�ᵽ����ԭ�ȵ�λ�õ�ǰ���Ǹ�λ�á�
	���Ƶ�Ԥ����õ��� 
*/
