var
 n,i,j,k:longint;
 f:array[0..8001] of longint;
begin
 readln(n);
 f[1]:=0;
 for i:=2 to n do
  readln(f[i]);
 for i:=1 to n do f[i]:=f[i]+1;
 for i:=1 to n do
  for j:=1 to i-1 do 
   if f[j]>=f[i] then f[j]:=f[j]+1;
 for i:=1 to n do writeln(f[i]);
end.
