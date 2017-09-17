var
 father,pre,number:array[0..30020] of longint;
 i,j:longint;
 s:string;
 n,x,y:longint;
function getfather(x:longint):longint;
var
 t:longint;
begin
 if father[x]=x then exit(x);
 t:=father[x];
 father[x]:=getfather(father[x]);
 pre[x]:=pre[x]+pre[t];
 exit(father[x]);
end;
procedure move(x,y:longint);
var
 xx,yy:longint;
begin
 xx:=getfather(x);
 yy:=getfather(y);
 if (xx=yy) then exit;
 father[yy]:=xx;
 pre[yy]:=number[xx];
 number[xx]:=number[xx]+number[yy];
 number[yy]:=0;
end;

procedure print(x:longint);
var xx:longint;
begin
             xx:=getfather(x);
 writeln(number[xx]-pre[x]-1);
end;

begin
 readln(n);
 for i:=1 to 30000 do
  begin
   father[i]:=i;
   pre[i]:=0;
   number[i]:=1;
  end;
 for i:=1 to n do
 begin
  readln(s);
  if (s[1]='M') then
  begin
   delete(s,1,2);
   val(copy(s,1,pos(' ',s)-1),x);
   val(copy(s,pos(' ',s)+1,length(s)),y);
   move(x,y);
  end		else
  if (s[1]='C') then
  begin
   delete(s,1,2);
   val(copy(s,1,length(s)),x);
   print(x);
  end;
//  for j:=1 to 10 do write(pre[j],' ');writeln;
//  for j:=1 to 10 do write(number[j],' ');writeln;
//  for j:=1 to 10 do write(father[j],' ');writeln;
 end;
end.
