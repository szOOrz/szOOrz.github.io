{
ID:cqz15311
PROG:namenum
LANG:PASCAL
}
Const
a:array['A'..'Z']of char=('2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0');

var
 num,name:array[0..5000]of string;
 p:string;
 i,n:longint;
 find:boolean;
	
begin
 assign(input,'dict.txt');
 reset(input);
 n:=0;
 while not eof do
 begin
  n:=n+1;
  readln(name[n]);
  for i:=1 to length(name[n]) do
  begin  
   num[n]:=num[n]+a[name[n][i]];
  end;
 end;
 close(input);
 assign(input,'namenum.in');
 assign(output,'namenum.out');
 reset(input);
 rewrite(output);
 readln(p);
 find:=false;
 for i:=1 to n do 
 begin 
  if num[i]=p then 
  begin 
   writeln(name[i]);
   find:=true;
  end;
 end;
 if not find then writeln('NONE');
 close(input);
 close(output);
end.