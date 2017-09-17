var
 n,s,k:longint;
 a:array[0..400,0..400] of longint;
 i,j,now:longint;
begin
 readln(n,s);
 i:=1;j:=1;now:=s;
 fillchar(a,sizeof(a),0);
 for k:=0 to n*n-1 do
 begin
  a[i,j]:=now;
  now:=now+1;
  if now=10 then now:=1;
  if (i=j) then
	begin
	 j:=j+1;
	 i:=1;
	end
	   else
	begin
	 i:=i+1;
	end;
 end;
 for i:=1 to n do
 begin
  if a[i,1]=0 then write(' ') else write(a[i,1]);
  for j:=2 to n do
   if a[i,j]=0 then write('  ') else write(' ',a[i,j]);
  writeln;
 end;
end.
