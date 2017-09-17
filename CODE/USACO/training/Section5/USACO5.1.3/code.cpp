/*
ID:cqz15311
LANG:C++
PROG:theme
*/
#include<bits/stdc++.h>
const int Mod = (1e6+7);
const int bit1 = 17;
const int bit2 = 23;
//��λ17����ڰ˸�����ˣ��ھŸ���WA��
//��ʵ���Զ��ع�ϣ����ȡ����ģ����
//��Ū��2��bit���ܹ�USACO���������ˡ�����ʵ��û���ȡģ��������ĸ��� 
//��ʵ�����17��3֮���������һ����WA�ģ�����͸����֣���ʵ����Ǹ�ģ��
//��������Һþã�����˵���׻���Hash����Ŀ�����١�
//����˵����ǰ��hash����Ŀ��������hash�ġ�
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
		f1[i] = rec1;	//ע����Len-1����Len��������N�� 
		f2[i] = rec2;
	}
	bool flag = false;
	for (int i=Len;i<=n;i++){
		if (Hash1[f1[i]] == -1) Hash1[f1[i]] = i;
		if (Hash2[f2[i]] == -1) Hash2[f2[i]] = i;
		if ((Hash1[f1[i]] < i - Len/*+1*/) && (Hash2[f2[i]] < i - Len)) flag = true;
				/*���ܼ�һ����Ϊ��ֹ������һ������ǰ����ǰ���һ��*/
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
	}//a0û��
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
