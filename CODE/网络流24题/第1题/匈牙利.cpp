#include<bits/stdc++.h>  
const int maxv = 505;
int nl,nr,m,ans;  
int Map[maxv][maxv],link[maxv],Ans[maxv];  
bool vis[maxv];  
using namespace std;  
bool Hungary(int u){  
    for (int v=1;v<=nr;v++){  
        if (!vis[v] && Map[u][v]){  
            vis[v] = true;  
            if (link[v] == -1 || Hungary(link[v])){  
                link[v] = u;  
                return true;  
            }  
        }  
    }  
    return false;  
}  
int c,x;  
int main(){  
    memset(Map,false,sizeof(Map));  
    scanf("%d%d%d",&nl,&nr,&m);  
    for (int i=1;i<=m;i++){
    	int a,b;
    	scanf("%d%d",&a,&b);
    	Map[a][b] = true;
    }
    ans = 0;  
    memset(link,-1,sizeof(link));  
    for (int k=1;k<=nl;k++){  
        memset(vis,false,sizeof(vis));  
        if (Hungary(k)) ans++;  
    }  
    printf("%d\n",ans);
    memset(Ans,0,sizeof(Ans));
    for (int i=1;i<=nr;i++){
    	Ans[link[i]] = i;
    }
    for (int i=1;i<=nl;i++){
    	printf("%d ",Ans[i]);
    }
	return 0; 
}
