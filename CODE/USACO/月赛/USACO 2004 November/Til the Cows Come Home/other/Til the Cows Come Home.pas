
const
 maxn=1008;
var
 dist:array[0..maxn,0..maxn] of longint;
 ans:array[0..maxn] of longint;
 i,j,n,m,s,t,y:longint;
 f:array[0..maxn] of boolean;

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
  dist[y,x]:=min(dist[y,x],z);
 end;
 s:=1;
 t:=n;
end;

procedure dijkstra(s,t:longint);
var
 k,mm:longint;
begin
 for i:=1 to n do ans[i]:=20000000;
 fillchar(f,sizeof(f),true);
 ans[s]:=0;
 for i:=1 to n do 
 begin 
  mm:=maxlongint;
  k:=-1;
  for j:=1 to n do 
   if (f[j] and (mm>ans[j])) then 
		begin
			mm:=ans[j];
			k:=j; 
 		end;
 f[k]:=false;
  for j:=1 to n do 
   if f[j] then ans[j]:=min(ans[j],ans[k]+dist[k,j]);
  
 end;
 writeln(ans[t]);

end;

begin
 init;
 dijkstra(s,t);
end.
