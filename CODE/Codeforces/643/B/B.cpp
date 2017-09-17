#include<bits/stdc++.h> 
using namespace std;
int n,k,a,b,c,d;
int main(){
	scanf("%d%d",&n,&k);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (a == c && b == d || a == d && b == c){
		if (n-1 > k){
			puts("-1");
			return 0;
		}
		printf("%d ",a);
		for (int i=1;i<=n;i++)
			if (i!=a && i!=b && i!=c && i!=d)
				printf("%d ",i);
		printf("%d ",b);
		puts("");
		if (a == c) printf("%d ",c); else printf("%d ",d);
		if (a == c){
			for (int i=1;i<=n;i++)
				if (i!=a && i!=b && i!=c && i!=d)
					printf("%d ",i);
		} else{
			for (int i=n;i>=1;i--)
				if (i!=a && i!=b && i!=c && i!=d)
					printf("%d ",i);
		}
		if (a == c) printf("%d ",d); else printf("%d ",c);
		return 0;
	}
	if (a == c || a == d || b == c || b == d){
		//一个公用
		if (n > k){
			puts("-1");
			return 0;
		}
		if (a == c){
			printf("%d ",a);
				for (int i=1;i<=n;i++)
					if (i!=a && i!=b && i!=c && i!=d)
						printf("%d ",i);			
			printf("%d %d\n",d,b);
			
			printf("%d ",a);
				for (int i=1;i<=n;i++)
					if (i!=a && i!=b && i!=c && i!=d)
						printf("%d ",i);			
			printf("%d %d\n",b,d);
		} else
		if (a == d){
			printf("%d %d",a);
			for (int i=1;i<=n;i++)
				if (i!=a && i!=b && i!=c && i!=d)
					printf("%d ",i);
			printf("%d %d\n",c,b);
			printf("%d %d",c,b);
			for (int i=n;i>=1;i--)
				if (i!=a && i!=b && i!=c && i!=d)
					printf("%d ",i);
			printf("%d\n",d);
		} else
		if (b == c){
			printf("%d %d",a,d);
			for (int i=1;i<=n;i++)
				if (i!=a && i!=b && i!=c && i!=d) printf("%d ",i);			
			printf("%d\n",b);
			
			printf("%d ",c);
			for (int i=n;i>=1;i--)
				if (i!=a && i!=b && i!=c && i!=d) printf("%d ",i);			
			printf("%d\n",a,d);
		} else{
			printf("%d %d",a,c);
			for (int i=1;i<=n;i++)
				if (i!=a && i!=b && i!=c && i!=d)
					printf("%d ",i);
			printf("%d\n",b);
			printf("%d %d",c,a);
			for (int i=1;i<=n;i++)
				if (i!=a && i!=b && i!=c && i!=d)
					printf("%d ",i);
			printf("%d\n",b);
		}
	} else{
		if (n + 1 > k || n<=4){
			puts("-1");
			return 0;
		}
		printf("%d %d ",a,c);
		for (int i=1;i<=n;i++)
			if (i!=a && i!=b && i!=c && i!=d) printf("%d ",i);			
		printf("%d %d\n",d,b);
		printf("%d %d ",c,a);
		for (int i=1;i<=n;i++)
			if (i!=a && i!=b && i!=c && i!=d) printf("%d ",i);			
		printf("%d %d\n",b,d);
	}
	return 0;
}
