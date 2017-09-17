#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cmath>
struct GJD{
	static bit = 10;
	static wid = 1;
    int val[2000],len;
    bool operator < (const GJD &x) const{
        if (len < x.len) return true;
        if (len > x.len) return false;
        for (int i=len;i>=1;i--){
            if (val[i] < x.val[i]) return true;
            if (val[i] > x.val[i]) return false;
        }
        return false;//等于 
    }
    
    GJD operator + (const GJD &x) const{
        GJD c;
        memset(c.val,0,sizeof(c.val));
        if (len < x.len) c.len = x.len; else
                         c.len = len;
        for (int i=1;i<=c.len;i++){
            c.val[i] += val[i] + x.val[i];
            c.val[i+1] += c.val[i] / 10;
            c.val[i] %= 10;
        }
        while (c.val[c.len+1] > 0){
            c.len++;
            c.val[c.len+1] += c.val[c.len] / 10;
            c.val[c.len] %= 10;
        }
        return c;
    }
    GJD operator * (const int &x) const{
        GJD c;
        memset(c.val,0,sizeof(c.val));
        c.len = len;
        for (int i=1;i<=c.len;i++){
            c.val[i] = val[i] * x;
        }
        for (int i=1;i<=c.len;i++){
            c.val[i+1] += c.val[i] / 10;
            c.val[i] %= 10;
        }
        while (c.val[c.len+1] > 0){
            c.len++;
            c.val[c.len+1] += c.val[c.len] / 10;
            c.val[c.len] %= 10;
        }
        return c;
    }
    
    GJD operator * (const GJD &x) const{
        GJD c;
        memset(c.val,0,sizeof(c.val));
        for (int i=1;i<=len;i++){
            for (int j=1;j<=x.len;j++){
                c.val[i+j-1] += val[i] * x.val[j];
            }
        }
        c.len = len + x.len - 1;
        for (int i=1;i<=c.len;i++){
            c.val[i+1] += c.val[i] / 10;
            c.val[i] %= 10;
        }
        while (c.val[c.len+1] > 0){
            c.len++;
            c.val[c.len+1] += c.val[c.len] / 10;
            c.val[c.len] %= 10;
        }
        return c;
    }
    
    GJD operator / (const int &x) const{
        GJD a;
        a.len = len;
        for (int i=1;i<=len;i++) a.val[i] = val[i];
        GJD c;
        memset(c.val,0,sizeof(c.val));
        c.len = a.len;
        for (int i=c.len;i>=1;i--){
            c.val[i] = a.val[i] / x;
            a.val[i-1] += (a.val[i] % x) * 10;
        }
        while (c.val[c.len] == 0) c.len--;
        return c;
    }
    GJD operator = (const int &x){
    	if (x == 0){
    		len = 1;
    		val[1] = 0;
    		return *this;
    	}
        len = 0;
        int tmp = x;
        while (tmp){
            val[++len] = tmp % 10;
            tmp/=10;
        }
        return *this;
    }
    
    void write(){
//        printf("%d\n",len);
        printf("%d",val[len]);
        for (int i=len-1;i>=1;i--){
            //if (val[i] < 100) …… 
            printf("%d",val[i]);
        }
        puts("");
    }
};
GJD one;

typedef long long LL;
int a[10500],b[10500];
GJD dfs(int l1,int r1,int l2,int r2){
//	printf("(%d,%d):(%d,%d)\n",l1,r1,l2,r2); 
	if (l1 == r1) return one;
	//能保证a[l1] = b[r2] 
	if (a[l1+1] == b[r2-1]) return dfs(l1+1,r1,l2,r2-1) * 2LL;//只有一个子树 	
	l1++;r2--;
	int i = l2;
	while (b[i]!=a[l1]) i++;
	return dfs(l1,l1+(i-l2+1)-1,l2,i) * dfs(l1+(i-l2+1),r1,i+1,r2);
}
int n;
int main(){
	one = 1;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	GJD Ans = dfs(1,n,1,n);
	Ans.write();
}
