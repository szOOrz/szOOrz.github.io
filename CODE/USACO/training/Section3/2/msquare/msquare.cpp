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








����

�ڳɹ��ط�����ħ��֮��³�ȿ��������������Ķ�ά�汾������ħ�塣����һ����8����С��ͬ�ĸ��ӵ�ħ�壺
1  2  3  4  
8  7  6  5  
����֪��ħ���ÿһ��������һ����ɫ����8����ɫ��ǰ8������������ʾ����������ɫ����������ʾһ��ħ��״̬���涨��ħ������Ͻǿ�ʼ����˳ʱ�뷽������ȡ������������һ����ɫ���С�������ͼ��ħ��״̬�����������У�1��2��3��4��5��6��7��8������ʾ�����ǻ���״̬��
�����ṩ���ֻ����������ֱ��ô�д��ĸ��A������B������C������ʾ������ͨ����Щ�����ı�ħ���״̬����
��A���������������У�  
��B���������ұߵ�һ�в�������ߣ� 
��C����ħ�������ĸ���˳ʱ����ת�� 
�����ǶԻ���״̬���в�����ʾ����
 A:  8  7  6  5  
     1  2  3  4  
 B:  4  1  2  3  
     5  8  7  6  
 C:  1  7  2  4  
     8  6  3  5
����ÿ�ֿ��ܵ�״̬�������ֻ�������������ʹ�á�
��Ҫ��̼��������ٵĻ���������ɻ���״̬��Ŀ��״̬��ת������������������С�
[�༭]��ʽ

PROGRAM NAME: msquare
INPUT FORMAT:
(file msquare.in)
ֻ��һ�У�����8���������ÿո�ֿ�����Щ�����ڷ�Χ 1����8 ֮�䣩�����У���ʾĿ��״̬��
OUTPUT FORMAT:
(file msquare.out)
Line 1: ����һ����������ʾ��̲������еĳ��ȡ�
Line 2: ���ֵ�����������ֵĲ������У����ַ�����ʾ�������һ���⣬ÿ�����60���ַ���
[�༭] SAMPLE INPUT

2 6 8 4 5 7 3 1 
[�༭] SAMPLE OUTPUT
7 
BCABCCB
*/
