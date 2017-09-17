{
ID:cqz15311
PROG:transform
LANG:PASCAL
}
var
 a,b,c,d:array[0..15,0..15] of char;
 n:longint;
 i,j:longint;
procedure check(x:longint);
var flag:boolean;
begin
	flag:=true;
	for i:=1 to n do 
		for j:=1 to n do 
		begin
			if c[i,j]<>b[i,j] then flag:=false;
		end;
	if flag then
	begin
		writeln(x);
		close(input);
		close(output);
		halt;
	end;
end;

procedure c1;
begin 
	for i:=1 to n do 
		for j:=1 to n do 
			c[i,j]:=a[n+1-j,i];
	check(1);
end;
procedure c2;
begin 
	for i:=1 to n do 
		for j:=1 to n do 
			c[i,j]:=a[n-i+1,n-j+1];
	check(2);
end;
procedure c3;
begin 
	for i:=1 to n do 
		for j:=1 to n do 
			c[i,j]:=a[j,n-i+1];
	check(3);
end;

procedure c4;
begin 
	for i:=1 to n do 
		for j:=1 to n do 
			c[i,j]:=a[i,n+1-j];

	check(4);
end;

procedure c5;
begin 
	for i:=1 to n do 
		for j:=1 to n do 
			d[i,j]:=a[i,n+1-j];
	for i:=1 to n do 
		for j:=1 to n do 
			c[i,j]:=d[n+1-j,i];
	check(5);
	for i:=1 to n do 
		for j:=1 to n do 
			c[i,j]:=d[n-i+1,n-j+1];
	check(5);
	for i:=1 to n do 
		for j:=1 to n do 
			c[i,j]:=d[j,n-i+1];	
	check(5);
end;

procedure c6;
begin 
	for i:=1 to n do 
		for j:=1 to n do 
			c[i,j]:=a[i,j];
	check(6);
end;

begin 
	assign(input,'transform.in');
	assign(output,'transform.out');
	reset(input);
	rewrite(output);
	readln(n);
	for i:=1 to n do 
	begin 
		for j:=1 to n do read(a[i,j]);
		readln;
	end;
	for i:=1 to n do 
	begin 
		for j:=1 to n do read(b[i,j]);
		readln;
	end;
	c1;c2;c3;c4;c5;c6;
	writeln(7);
	close(input);
	close(output);
end.