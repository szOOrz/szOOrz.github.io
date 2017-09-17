#include<bits/stdc++.h>
using namespace std;
const int maxm = 43;
const int SG[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};
int N, K,Num;
bitset<1000007> vis;
int main(){
    scanf("%d", &N);
    K = 0;Num = 0;
    for (int i = 2; i * i <= N; i++)
        if (!vis[i]){
            int num = 0;
            for (long long j = i; j <= N; j *= i, num++){
            	Num++;
				if (j*j<=N) vis[j] = 1;
            }
            K ^= SG[num];
        }
    printf("%s\n", (K ^ ((N-Num) & 1)) ? "Vasya" : "Petya");
    return 0;
}
