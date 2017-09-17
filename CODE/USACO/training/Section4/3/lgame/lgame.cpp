/*
ID:cqz15311
LANG:C++
PROG:lgame
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int score[26],n;
void f(char a,int b){
	score[a-'a'] = b;
}
void init(){
	f('q',7);f('w',6);f('e',1);f('r',2);f('t',2);f('y',5);f('u',4);f('i',1);f('o',3);f('p',5);
	f('a',2);f('s',1);f('d',4);f('f',6);f('g',5);f('h',5);f('j',7);f('k',6);f('l',3);
	f('z',7);f('x',7);f('c',4);f('v',6);f('b',5);f('n',2);f('m',5);
}
char a[40005][20];

int flag[26];
bool check1(char s[]){
	int Flag[26];
	memset(Flag,0,sizeof(Flag));
	for (int i=0;s[i];i++){
		Flag[s[i]-'a']++;
	}
	for (int i=0;i<26;i++){
		if (Flag[i] > flag[i]) return false;
	} 
	return true;
}

bool check2(char s[],char t[]){
	int Flag[26];
	memset(Flag,0,sizeof(Flag));
	for (int i=0;s[i];i++){
		Flag[s[i]-'a']++;
	}
	for (int i=0;t[i];i++){
		Flag[t[i]-'a']++;
	}
	for (int i=0;i<26;i++){
		if (Flag[i] > flag[i]) return false;
	} 
	return true;
}

int Score(char s[]){
	int Ans = 0;
	for (int i=0;s[i];i++){
		Ans = Ans + score[s[i] - 'a'];
	}
	return Ans;
}

void solve(){
	int Ans = 0;
	int ans[40005][2];
	int Num = 0;
	memset(ans,0,sizeof(ans));
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (check2(a[i],a[j])){
				int x = Score(a[i]) + Score(a[j]);
				if (x > Ans){
					Ans = x;
					Num = 0;
					ans[++Num][0] = i;
					ans[Num][1] = j;
				} else
				if (x == Ans){
					ans[++Num][0] = i;
					ans[Num][1] = j;
				}
			}
		}
	}

	for (int i=0;i<n;i++){
//		printf("%d\n",i);
		if (check1(a[i])){
			int x = Score(a[i]);
//			printf("%s %d\n",a[i],x);
			if (x > Ans){
				Ans = x;
				Num = 0;
				ans[++Num][0] = i;
				ans[Num][1] = -1;
			} else
			if (x == Ans){
				ans[++Num][0] = i;
				ans[Num][1] = -1;
			}
		}
	}
	//考虑单独一个的 
	printf("%d\n",Ans);
//	printf("%d\n",Num);
	for (int i=1;i<=Num;i++){
		printf("%s",a[ans[i][0]]);
		if (ans[i][1] != -1){
			printf(" %s\n",a[ans[i][1]]);
		} else puts("");
	}
}

int main(){
	init();
	freopen("lgame.in","r",stdin);
	char s[20];
	scanf("%s",&s);
	memset(flag,0,sizeof(flag));
	for(int i=0;s[i];i++){
		flag[s[i] - 'a']++;
//		printf("%c %d\n",s[i],flag[s[i]-'a']);
	}
	fclose(stdin);
	freopen("lgame.dict","r",stdin);
	n = 0;
	while (scanf("%s",&a[n]) && a[n][0]!='.'){
		for (int i=0;a[n][i];i++){
			if (!flag[a[n][i] - 'a']){
				n--;
				break; 
			}
		}
		n++;
	}
	freopen("lgame.out","w",stdout);
	solve();
	fclose(stdout);
	return 0;
}
/*
40000^2似乎要超？是不是？？
是的。那么如何处理呢？
注意到：
	One line with a string of lowercase letters (from `a' to `z'). The string consists of at least 3 and at most 7 letters in arbitrary order.
也就是给定的串最多只有7个字符，那么。
我们可以把读入的dict文件里面，含有a所不含有的直接踢掉！。
如何处理呢？？对读入的字符串的每一位打标记。
（当然，可以把包含地多了的也踢掉，但是并
没有必要，代码会复杂很多） 
在结果的单词或词组构所成的字母中，每个字母出现的频数不大于输入的字符串中每个字母的频数。也就是例如输入是 aaa，字典中有单词 a,aa,aaa,aaaa，其中a,aa,aaa都是符合条件的解，但只有aaa才是要输出的最优解。
可能要字典序？？？？，但是好像要先输出词组，然后输出单词就可以过了。 
其实还有另外一种枚举思路
枚举每一个位置，然后用Map搞一搞。代码可能简单很多。 

prmgroa
profile
program
prom
rag
ram
rom
.
*/
