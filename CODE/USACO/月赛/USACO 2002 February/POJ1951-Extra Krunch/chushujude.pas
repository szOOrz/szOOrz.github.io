var
 n,x,i:longint;
begin
 assign(output,'shuju.out');
 rewrite(output);
 randomize;
 n:=random(100)+100;
 for i:=1 to n do
 begin
  x:=random(30)+1;
  if (x<=26) then write(chr(x+ord('A')-1)) else
  if (x=27) then write(' ') else if (x=28) then write(',') else if (x=29) then write('?') else if (x=30) then write('.');
 end;
 close(output);
end.
