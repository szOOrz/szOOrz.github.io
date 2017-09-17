
const
 maxn=1008;
var
 dist:array[0..maxn,0..maxn] of longint;
 ans:array[0..maxn] of longint;
 i,n,m,s,t,y:longint;


function min(a,b:longint):longint;
begin
 if a>b then exit(b) else exit(a);
end;


procedure init;
var i,j:longint;
    x,y,z:longint;
begin
 readln(m,n);
 for i:=1 to n do
  for j:=1 to n do
    dist[i,j]:=99999999;

 for i:=1 to m do
 begin
  readln(x,y,z);
  dist[x,y]:=min(dist[x,y],z);
 end;

 s:=1;
 t:=n;
end;

procedure spfa(s:longint);
var
 queue:array[0..maxn*maxn] of longint;
 flag:array[0..maxn] of boolean;
 i,j,x,y,xx,yy,dd:longint;
 front,rear:longint;
begin
 for i:=1 to n do ans[i]:=99999999;
 fillchar(flag,sizeof(flag),true);//保存每个点遍历了多少次
 queue[0]:=s;
 flag[s]:=false;
 ans[s]:=0;
 front:=0;rear:=1;
 while front<rear do
 begin
  i:=queue[front];
  for j:=1 to n do
  if ans[i]+dist[i,j]<ans[j] then
   begin
    ans[j]:=ans[i]+dist[i,j];
    if flag[j] then
    begin
     queue[rear]:=j;
     rear:=rear+1;
     flag[j]:=false;
    end;
   end;
  front:=front+1;
  flag[i]:=true;
 end;
end;
procedure print;
begin
 writeln(ans[t]);
end;


begin
 init;
 spfa(s);
 print;
end.
