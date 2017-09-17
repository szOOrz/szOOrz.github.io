var
 i,j,k,n,ans:longint;
 a:array[0..1001,0..1001] of longint ;
 flag:array[0..1001] of boolean;
 pay:array[0..1001] of longint;
begin
 while not eof do
 begin 
 readln(n);
 for i:=1 to n do
  begin
  for j:=1 to n do
   read(a[i,j]);
   readln;
  end;
 ans:=0;
 fillchar(flag,sizeof(flag),false);
 flag[1]:=true;
 for i:=1 to n do pay[i]:=a[1,i];
 pay[0]:=maxlongint;
 for i:=1 to n-1 do
 begin
  k:=0;
  for j:=1 to n do
   if (flag[j]=false) and (pay[j]<pay[k]) then k:=j;//找到最小的
  ans:=ans+pay[k];
  flag[k]:=true;
  for j:=1 to n do
   if (flag[j]=false) and (pay[j]>a[k,j]) then pay[j]:=a[k,j];
 end;
 writeln(ans);
 end;
end.
