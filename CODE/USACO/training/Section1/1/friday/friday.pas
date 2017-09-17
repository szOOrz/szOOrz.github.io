{
ID: cqz15311
PROG: friday
LANG: PASCAL
}
var
 a:array[0..6]of integer;
 i,j,n,k:integer;
function f(i,j:integer):integer;
begin
 case j of
  1,3,5,7,8,10,12:f:=31;
  4,6,9,11:f:=30;
  2:if(i mod 400=0)or(i mod 100<>0)and(i mod 4=0) then f:=29 else f:=28
 end
end;

begin
	assign(input,'friday.in');
	assign(output,'friday.out');
	reset(input);
	rewrite(output);
	readln(n);
	k:=6;
	for i:=1900 to 1900+n-1 do
	for j:=1 to 12 do
	begin
		inc(a[k]);
		k:=(k+f(i,j))mod 7
	end;
	write(a[6]);
	for i:=0 to 5 do write(' ',a[i]);
	writeln;
	close(input);
	close(output);
end.

