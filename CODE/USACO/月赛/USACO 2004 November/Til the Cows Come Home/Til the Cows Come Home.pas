type type_edge=record
	u,v,dist,next:longint;
     end;
     type_point=record
        last_edge:longint;
     end;
const
 maxn=1505;
 maxm=15005;
var
 point:array[0..maxn] of type_point;
 edge:array[0..maxm] of type_edge;
 ans:array[0..maxn] of longint;
 i,n,m,s,t,y:longint;

procedure init;
var i:longint;
    x,y,z:longint;
begin
 readln(m,n);
 for i:=1 to n do
 begin
  point[i].last_edge:=-1;
 end;

 for i:=1 to m do
 begin
  readln(x,y,z);
  edge[i*2-1].u:=x;
  edge[i*2-1].v:=y;
  edge[i*2-1].dist:=z;
  edge[i*2-1].next:=point[x].last_edge;
  point[x].last_edge:=i*2-1;
 
  edge[i*2].u:=y;
  edge[i*2].v:=x;
  edge[i*2].dist:=z;
  edge[i*2].next:=point[y].last_edge;
  point[y].last_edge:=i*2;
 end;

 s:=1;
 t:=n;
end;

procedure spfa(s:longint);
var
 queue:array[0..maxn*maxn] of longint;
 flag:array[0..maxn] of boolean;
 i,x,y,xx,yy,dd:longint;
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
  y:=point[queue[front]].last_edge;
  readln;
  while y<>-1 do
  begin
   xx:=edge[y].u;//当前点
   yy:=edge[y].v;
   dd:=edge[y].dist;
   if ans[yy]>ans[xx]+dd then
   begin
     ans[yy]:=ans[xx]+dd;
     if flag[yy] then 
      begin 
	     queue[rear]:=yy;
	     rear:=rear+1;
	     flag[yy]:=false;
      end;
   end;
   y:=edge[y].next;
  end;
  front:=front+1;
  flag[xx]:=true;
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
