{
ID: cqz15311
PROG: beads
LANG: PASCAL
}
var
 bl,rl,br,rr:array[0..1000] of longint;
 ch:array[0..1000] of char;
 n,i,ans:longint;

function max(x,y:longint):longint;
begin
 if (x>y) then exit(x) else exit(y);
end;

begin
 assign(input,'beads.in');
 assign(output,'beads.out');
 reset(input);
 rewrite(output);
 readln(n);
 for i:=1 to n do read(ch[i]);
 for i:=n+1 to 2*n do ch[i]:=ch[i-n];

 bl[0]:=0;
 rl[0]:=0;
 for i:=1 to 2*n do
 begin
  if ch[i]='r' then
  begin
   rl[i]:=rl[i-1]+1;
   bl[i]:=0;
  end;
  if ch[i]='b' then
  begin
   rl[i]:=0;
   bl[i]:=bl[i-1]+1;
  end;
  if ch[i]='w' then
  begin
   rl[i]:=rl[i-1]+1;
   bl[i]:=bl[i-1]+1;
  end;
 end;

 br[2*n+1]:=0;
 rr[2*n+1]:=0;
 for i:=2*n downto 1 do
 begin
  if ch[i]='r' then
  begin
   rr[i]:=rr[i+1]+1;
   br[i]:=0;
  end;
  if ch[i]='b' then
  begin
   rr[i]:=0;
   br[i]:=br[i+1]+1;
  end;
  if ch[i]='w' then
  begin
   rr[i]:=rr[i+1]+1;
   br[i]:=br[i+1]+1;
  end;
 end;

 for i:=1 to 2*n-1 do
  ans:=max(ans,max(rl[i],bl[i])+max(rr[i+1],br[i+1]));
 if (ans>n) then ans:=n;
 writeln(ans);
 close(input);
 close(output);
end.
