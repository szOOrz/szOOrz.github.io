/*
长度为n的环，第i个数字为ai。 
从起点s出发，走一个格子的花费为1，输出当前数字的花费为0，
输出n个数的非递减序列的最小花费是多少，并打印方案。
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
	对于每一组，只有2种可能：
	要么是饶了一个圆圈（正着或者倒着） 
	要么是先往左走，然后往右边走
	或者先往右走，然后往左走 
	考虑把圆圈倍长。
	先得到每个点作为起始点的最小花费 
	那么左半部分只能往右边走。
	右半部分只能往左边走。
	还有一种是往左走到某个点，然后往右走。
	得到每个点作为最左边的价值。
	那么往右走必然只会到达它原先的位置的前面那个位置。
	类似的预处理得到。 
*/
