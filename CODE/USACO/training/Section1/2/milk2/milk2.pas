{
ID: cqz15311
PROG: milk2
LANG: PASCAL
}
var
	x,y,minx,maxy:longint;
	f:array[-55..1000500] of integer;
	k,n,i,ans1,ans2,tot1,tot2:longint;
function min(x,y:longint):longint;
begin
	if (x<y) then exit(x) else exit(y);
end;
function max(x,y:longint):longint;
begin
	if (x>y) then exit(x) else exit(y);
end;

begin
	assign(input,'milk2.in');
	reset(input);
	assign(output,'milk2.out');
	rewrite(output);
	readln(n);
	fillchar(f,sizeof(f),0);
	minx:=1000050;
	maxy:=-5;
	for i:=1 to n do
	begin
		readln(x,y);
		minx:=min(minx,x);
		maxy:=max(maxy,y);
		f[x]:=f[x]+1;
		f[y]:=f[y]-1;
	end;
	k:=0;
	ans1:=0;
	ans2:=0;
	tot1:=0;
	tot2:=0;
	for i:=minx to maxy do
	begin
		k:=k+f[i];
		if (k<>0) then
		begin
			ans2:=max(ans2,tot2);
			tot2:=0;
			tot1:=tot1+1;//ÓÐÈË¼·ÄÌ
		end;
		if (k= 0) then
		begin
			ans1:=max(ans1,tot1);
			tot1:=0;
			tot2:=tot2+1;//¼ä¸ô
		end;
	end;
        ans1:=max(ans1,tot1);
	writeln(ans1,' ',ans2);
	close(input);
	close(output);
end.
