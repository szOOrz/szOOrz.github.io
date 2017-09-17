/*
ID:cqz15311
LANG:C++
PROG:heritage
*/ 
#include<cstdio>
#include<cstring>
char first[26];
char middle[26];
void dfs(int L1,int R1,int L2,int R2){
	if (L1 > R1) return ;
	if (L2 > R2) return ;
	if (L1 == R1){
		printf("%c",first[L1]);
		return;
	}
	/*
	处理 
	*/
	char root = middle[L2];
	int location;
	for (int i=L1;i<=R1;i++){
		if (root == first[i]){
			location = i;
			break;
		}
	}
	dfs(L1,location-1,L2+1,L2+location-L1);
	dfs(location+1,R1,L2+location-L1+1,R2);
	printf("%c",middle[L2]);
}
int main(){
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	scanf("%s%s",&first,&middle);
	int Len = strlen(first);
	dfs(0,Len-1,0,Len-1);
	puts("");
	//又忘记了，这里一定要回车。 
	fclose(stdin);
	fclose(stdout);
	return 0;

}
/*
01234567
ABEDFCHG
CBADEFGH
*/
