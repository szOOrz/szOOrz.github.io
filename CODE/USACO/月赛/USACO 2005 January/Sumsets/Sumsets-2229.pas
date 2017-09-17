var
 n,i:longint;
 f:array[0..1000000] of qword;
begin
 readln(n);
 f[1]:=1;
 for i:=2 to n do
 if odd(i) then f[i]:=f[i-1] mod 1000000000
	   else f[i]:=(f[i-1]+f[i shr 1]) mod 1000000000;
 writeln(f[n]);
end.
