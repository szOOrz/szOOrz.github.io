{
ID: cqz15311
PROG: gift1
LANG: PASCAL
}
var
 name:array[0..15] of string;
 ans:array[0..15] of longint;
 temp,temp2:longint;
 s:string;
 np,money,t:longint;
 i,j,k:longint;
begin
 assign(input,'gift1.in');
 assign(output,'gift1.out');
 reset(input);
 rewrite(output);
 readln(np);
 for i:=1 to np do readln(name[i]);
 fillchar(ans,0,sizeof(ans));
 for i:=1 to np do
 begin
  readln(s);
  temp:=-1;
  for j:=1 to np do if name[j]=s then temp:=j;

  readln(money,t);
  if t=0 then continue;
  temp2:=money div t;

  for j:=1 to t do
   begin
    readln(s);
    for k:=1 to np do
	if s=name[k] then
	 begin
	   dec(ans[temp],temp2);
	   inc(ans[k]   ,temp2);
	   break;
	 end;

   end;

 end;
 for i:=1 to np do writeln(name[i],' ',ans[i]);
 close(input);
 close(output);
end.
