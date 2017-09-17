{
ID: cqz15311
PROG: ride
LANG: PASCAL
}
var
 s1,s2:string;
 x1,x2,i:longint;

function val(c:char):longint;
begin
 exit (ord(c)-ord('A')+1);
end;

begin
 assign(input,'ride.in');
 assign(output,'ride.out');
 reset(input);
 rewrite(output);
 readln(s1);
 readln(s2);
 x1:=1;
 for i:=1 to length(s1) do
   x1:=x1*val(s1[i]) mod 47;
 x2:=1;
 for i:=1 to length(s2) do
   x2:=x2*val(s2[i]) mod 47;
 if x1=x2 then writeln('GO') else writeln('STAY');
 close(input);
 close(output);
end.
