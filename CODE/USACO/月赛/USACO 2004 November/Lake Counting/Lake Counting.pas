const dx:array[0..7] of integer=(-1,-1,-1, 0, 0, 1, 1, 1);
const dy:array[0..7] of integer=(-1, 0, 1,-1, 1,-1, 0, 1);
var

ans,n,m:longint;
ch:array[0..1000,0..1000] of char;
flag:array[0..1000,0..1000] of boolean;
i,j:longint;
procedure dfs(i,j:longint);
var
 xx,yy,k:longint;
begin
 for k:=0 to 7 do
  begin
   xx:=i+dx[k];
   yy:=j+dy[k];
   if  (xx>=0) and (xx<n) and (yy>=0) and (yy<m)  then
   begin
    if (ch[xx,yy]='W') and (flag[xx,yy]) then
	begin
		flag[xx,yy]:=false;
		dfs(xx,yy);
	end;
   end;
  end;
end;

begin
 readln(n,m);
 for i:=0 to n-1 do
  begin
   for j:=0 to m-1 do
     read(ch[i,j]);
     readln;
  end;
 fillchar(flag,sizeof(flag),true);
 for i:=0 to n-1 do
  for j:=0 to m-1 do
   if (flag[i,j]) and (ch[i,j]='W') then
	begin
                flag[i,j]:=false;
		dfs(i,j);
		ans:=ans+1;
	end;
 writeln(ans);
end.
