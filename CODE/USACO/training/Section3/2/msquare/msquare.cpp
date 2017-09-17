/*
ID:cqz15311
LANG:C++
PROG:msquare
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define REP(i,s,t) for (int i=s;i<t;i++) 
using namespace std;
const int maxq = 40395;
struct V{
	int val[8];
	void debug(){
		printf("%d%d%d%d\n",val[0],val[1],val[2],val[3]);
		printf("%d%d%d%d\n",val[7],val[6],val[5],val[4]);
		puts("");
	}
}u,v,from,to;
struct T{
	V val;
	int step,from;
	char choice;
}q[maxq];
int front,rear,_v;
const int fac[8]={1,1,2,6,24,120,720,5040};

int Cantor(V a){
	int num = 0;
	for (int i=0;i<8;i++){
		int tmp = 0;
		for (int j=i+1;j<8;j++){
			if (a.val[j] < a.val[i]) tmp++;
		}
		num += tmp * fac[7-i];
	}
	return num;
}
void swap(int &a,int &b){int t = a;a = b;b = t;}

V A(V a){
	V c;
	c.val[0]=a.val[7];
	c.val[1]=a.val[6];
	c.val[2]=a.val[5];
	c.val[3]=a.val[4];
	c.val[4]=a.val[3];
	c.val[5]=a.val[2];
	c.val[6]=a.val[1];
	c.val[7]=a.val[0];
	return c;
}


V B(V a){
	V c;
	c.val[0]=a.val[3];
	c.val[1]=a.val[0];
	c.val[2]=a.val[1];
	c.val[3]=a.val[2];
	c.val[4]=a.val[5];
	c.val[5]=a.val[6];
	c.val[6]=a.val[7];
	c.val[7]=a.val[4];
	return c;
}
V C(V a){
	V c;
	c.val[0]=a.val[0];
	c.val[1]=a.val[6];
	c.val[2]=a.val[1];
	c.val[3]=a.val[3];
	c.val[4]=a.val[4];
	c.val[5]=a.val[2];
	c.val[6]=a.val[5];
	c.val[7]=a.val[7];
	return c;
}

void write(int x){
//	printf("(%d %d %c)\n",q[x].from,q[x].step,q[x].choice);
	if (q[x].from == -1)return ;
	write(q[x].from);
//	q[x].val.debug();
	printf("%c",q[x].choice);
}

int ans[50000];
int main(){
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	memset(ans,-1,sizeof(ans));
	for (int i=0;i<8;i++) from.val[i] = i+1;
	for (int i=0;i<8;i++){
		scanf("%d",&to.val[i]);
	}
	front = rear = 0;
	
	q[rear].val  = from;
	q[rear].from = -1;
	q[rear].choice = -1;
	q[rear].step = 0;
	ans[Cantor(from)] = 0;
	rear++;
	while (front < rear){
		u = q[front].val;
//		u.debug();
		int S = q[front].step;
		//A
		v = A(u);
		_v = Cantor(v);
		if (ans[_v] == -1){
			q[rear] . val = v;
			q[rear] . step = S+1;
			q[rear] . choice = 'A';
			q[rear] . from = front;
			ans[_v] = rear;
			rear++;
		}
		
		//B
		v = B(u);
		_v = Cantor(v);
		if (ans[_v] == -1){
			q[rear] . val = v;
			q[rear] . step = S+1;
			q[rear] . choice = 'B';
			q[rear] . from = front;
			ans[_v] = rear;
			rear++;
		}
		
		//C
		v = C(u);
		_v = Cantor(v);
		if (ans[_v] == -1){
			q[rear] . val = v;
			q[rear] . step = S+1;
			q[rear] . choice = 'C';
			q[rear] . from = front;
			ans[_v] = rear;
			rear++;
		}	
		front ++;
		if (ans[Cantor(to)]!=-1) break;
	}
	printf("%d\n",q[ans[Cantor(to)]].step);
	write(ans[Cantor(to)]);
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1 2 3 4 5 6 7 8
1 2 3 4 5 6 8 7
1 2 3 4 5 7 6 8
1 2 3 4 5 7 8 6
1 2 3 4 5 8 6 7
1 2 3 4 5 8 7 6
8 7 6 5 4 3 2 1

8 2 7 5
1 3 6 4

8765
1234

4123
5876

1724
8635

1234
5678
------
8765
1234
------

-----
read:
2 6 8 4 5 7 3 1 
write:
7
BCABCCB
*/


/*


Magic Squares
IOI'96
Following the success of the magic cube, Mr. Rubik invented its planar version, called magic squares. This is a sheet composed of 8 equal-sized squares:

1	2	3	4
8	7	6	5
In this task we consider the version where each square has a different color. Colors are denoted by the first 8 positive integers. A sheet configuration is given by the sequence of colors obtained by reading the colors of the squares starting at the upper left corner and going in clockwise direction. For instance, the configuration of Figure 3 is given by the sequence (1,2,3,4,5,6,7,8). This configuration is the initial configuration.

Three basic transformations, identified by the letters `A', `B' and `C', can be applied to a sheet:

'A': exchange the top and bottom row,
'B': single right circular shifting of the rectangle,
'C': single clockwise rotation of the middle four squares.
Below is a demonstration of applying the transformations to the initial squares given above:

A:	
8	7	6	5
1	2	3	4
B:	
4	1	2	3
5	8	7	6
C:	
1	7	2	4
8	6	3	5
All possible configurations are available using the three basic transformations.

You are to write a program that computes a minimal sequence of basic transformations that transforms the initial configuration above to a specific target configuration.

PROGRAM NAME: msquare

INPUT FORMAT

A single line with eight space-separated integers (a permutation of (1..8)) that are the target configuration.

SAMPLE INPUT (file msquare.in)

2 6 8 4 5 7 3 1 
OUTPUT FORMAT

Line 1:	A single integer that is the length of the shortest transformation sequence.
Line 2:	The lexically earliest string of transformations expressed as a string of characters, 60 per line except possibly the last line.
SAMPLE OUTPUT (file msquare.out)

7
BCABCCB








描述

在成功地发明了魔方之后，鲁比克先生发明了它的二维版本，称作魔板。这是一张有8个大小相同的格子的魔板：
1  2  3  4  
8  7  6  5  
我们知道魔板的每一个方格都有一种颜色。这8种颜色用前8个正整数来表示。可以用颜色的序列来表示一种魔板状态，规定从魔板的左上角开始，沿顺时针方向依次取出整数，构成一个颜色序列。对于上图的魔板状态，我们用序列（1，2，3，4，5，6，7，8）来表示。这是基本状态。
这里提供三种基本操作，分别用大写字母“A”，“B”，“C”来表示（可以通过这些操作改变魔板的状态）：
“A”：交换上下两行；  
“B”：将最右边的一列插入最左边； 
“C”：魔板中央四格作顺时针旋转。 
下面是对基本状态进行操作的示范：
 A:  8  7  6  5  
     1  2  3  4  
 B:  4  1  2  3  
     5  8  7  6  
 C:  1  7  2  4  
     8  6  3  5
对于每种可能的状态，这三种基本操作都可以使用。
你要编程计算用最少的基本操作完成基本状态到目标状态的转换，输出基本操作序列。
[编辑]格式

PROGRAM NAME: msquare
INPUT FORMAT:
(file msquare.in)
只有一行，包括8个整数，用空格分开（这些整数在范围 1——8 之间）不换行，表示目标状态。
OUTPUT FORMAT:
(file msquare.out)
Line 1: 包括一个整数，表示最短操作序列的长度。
Line 2: 在字典序中最早出现的操作序列，用字符串表示，除最后一行外，每行输出60个字符。
[编辑] SAMPLE INPUT

2 6 8 4 5 7 3 1 
[编辑] SAMPLE OUTPUT
7 
BCABCCB
*/
