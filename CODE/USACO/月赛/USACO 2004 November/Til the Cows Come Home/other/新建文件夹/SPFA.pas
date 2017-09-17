type type_edge=record
	u,v,dist,next:longint;
     end;
     type_point=record
        last_edge:longint;
     end;
const
 maxn=1000;
 maxm=1000000;
var
 point:array[0..maxn] of type_point;
 edge:array[0..maxm] of type_edge;
 ans:array[0..maxn] of longint;
 i,n,m,s,t,y:longint;
procedure error;
begin
 writeln('ERROR');
 readln;
 halt;
end;
procedure init;
var i,j:longint;
    x,y,z,k:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  point[i].last_edge:=-1;
 end;

 for i:=1 to n do 
  for j:=1 to n do 
  begin
   x:=i;
   y:=j;
   read(z); 
   k:=i*n-n+j;
  edge[k].u:=x;
  edge[k].v:=y;
  edge[k].dist:=z;
  edge[k].next:=point[x].last_edge;
  point[x].last_edge:=k;
  end;

 s:=1;
 t:=n;
end;

procedure spfa(s:longint);
var
 queue:array[0..maxn*maxn] of longint;
 flag:array[0..maxn] of longint;
 i,x,y,xx,yy,dd:longint;
 front,rear:longint;
begin
 for i:=1 to n do ans[i]:=99999999;
 fillchar(flag,sizeof(flag),0);//保存每个点遍历了多少次
 queue[0]:=s;
 flag[s]:=1;
 ans[s]:=0;
 front:=0;rear:=1;
 while front<rear do
 begin
  y:=point[queue[front]].last_edge;
  while y<>-1 do
  begin
   xx:=edge[y].u;//当前点
   yy:=edge[y].v;
   dd:=edge[y].dist;
   if ans[yy]>ans[xx]+dd then
   begin
     ans[yy]:=ans[xx]+dd;
     flag[yy]:=flag[yy]+1;
     if flag[yy]>=n then error;
     queue[rear]:=yy;
     rear:=rear+1;
   end;
   y:=edge[y].next;
  end;
  front:=front+1;
 end;
end;
procedure print;
begin
 writeln(ans[t]);
end;


begin
 init;
 readln(m);
 for i:=1 to m do 
 begin
 readln(s,t); 
 spfa(s);
 print;
 end;
end.
