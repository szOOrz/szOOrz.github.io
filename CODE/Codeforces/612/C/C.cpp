#include<cstdio> 
#include<cstring>
#include<cstdlib>

using namespace std;
char s[1000555],Stack[1000555];
int top,Ans;
int main(){
	fgets(s,1000005,stdin);
	top = 0;
	Ans = 0;
	for (int i=0;s[i]!='\n';i++){
//		printf("%c %d\n",s[i],top);
		if (s[i] == '{') Stack[++top] = '{'; else
		if (s[i] == '[') Stack[++top] = '['; else
		if (s[i] == '<') Stack[++top] = '<'; else
		if (s[i] == '(') Stack[++top] = '('; else{
//			printf("%d\n",top);
			if (top == 0){
				puts("Impossible");
				return 0;
			}
			
			if (s[i] == '}'){
				if (Stack[top] != '{') Ans++;
			} else
			if (s[i] == ']'){
				if (Stack[top] != '[') Ans++;
			} else 
			if (s[i] == ')'){
				if (Stack[top] != '(') Ans++;
			} else
			if (s[i] == '>'){
				if (Stack[top] != '<') Ans++;
			}
			top--;
		} 
	}
	if (top > 0){
		puts("Impossible");
		return 0;
		
	}
	printf("%d\n",Ans);
}
