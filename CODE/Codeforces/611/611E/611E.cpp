#include<bits/stdc++.h> 
using namespace std;
set<int,vector<int>,greater<int> > s;
set<int,vector<int>,greater<int> >::iterator iter1,iter2;
int main(){
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		s.insert(x);
	}
	if (a+b+c < *s.begin()){
		puts("-1");
		return 0;
	}
	Ans = 0;
	while (s.begin()!=s.end()){
		iter1 = s.end() - 1;
		x = *u;
		if (x > b+c){
			Ans = Ans + 1;
			s.erase(x);
		} //ֻ����a+b+c�� 
		else
		if (x > a+c){
			Ans = Ans + 1;
			s.erase(x);
			iter2 = s.begin();
			if (*iter2 <= a){
				s.erase(iter2);
			}
		} //����a+b+c����b+c��ѡ��b+cȥ�� 
		else
		if (c > x && a+b > x)
		{
			
		}
		else
		if (c > x){
			
		}
	}
}
