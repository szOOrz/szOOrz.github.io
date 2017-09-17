/*
ID:cqz15311 
TASK:contact
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int time[20][5000];
int a,b,n;
char s[200005];
int cnt;
int toB(int be,int len){
    int ans=0;
    for(int i=0;i<len;i++)
        ans=ans*2+(s[be+i]=='1');
    return ans;
}
struct node{
    int time,v,len;
}e[100000];
bool cmp(node a,node b){
    return a.time>b.time||a.time==b.time&&(a.len<b.len||a.len==b.len&&a.v<b.v);
}
void toS(int v,int len){
    char s[20]="";
    for(int i=len-1;i>=0;i--){
        s[i]=v%2+'0';
        v/=2;
    }
    printf("%s",s);
}
int main(){
    freopen("contact.in","r",stdin);
    freopen("contact.out","w",stdout);
    scanf("%d%d%d",&a,&b,&n);
    while(~scanf("%s",s+strlen(s)));
    int l=strlen(s);
    for(int i=0;i<l-a+1;i++)
        for(int j=a;j<=b&&i+j<=l;j++)
            time[j][toB(i,j)]++;//长度j的值为toB的子串出现次数++

    for(int i=a;i<=b;i++)
        for(int j=0;j<1<<i;j++)
            if(time[i][j])e[cnt++]=(node){time[i][j],j,i};//出现次数不为0的子串放入e中
    sort(e,e+cnt,cmp);//按出现次数排序
    int num;
    for(int i=0,j=0;i<cnt;i++){
        if(!i||e[i].time!=e[i-1].time){//如果和上一个子串次数不同
            j++;
            if(j>n)break;//只输出前n大的。
            printf("%d\n",e[i].time);
            num=0;
        }
        toS(e[i].v,e[i].len);
        num++;
        if(e[i].time==e[i+1].time && num%6)
            printf(" ");
        else//下一个子串和当前子串的出现次数不同或者是第6个了，就要换行
            puts("");
    }
    return 0;
}
