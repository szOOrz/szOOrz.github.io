#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
int m,h,a;
int read(){
	int a = 0;
	char c = getchar();
	while (!(c>='0' && c<='9')) c = getchar();
	while (c>='0' && c<='9'){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}
void next_time(){
	m++;
	if (m == 60){
		m = 0;
		h++;
		if (h == 24){
			h = 0;
		}
	}
}
int main(){
	h = read();
	m = read();
	a = read();
	while (a--){
		next_time();
	}
	if (h < 10) putchar('0');
	printf("%d:",h);
	if (m < 10) putchar('0');
	printf("%d\n",m);
	return 0;
}
