var
 flag:array['A'..'Z'] of boolean;
 s:string;
 i:longint;
begin
 readln(s);
 fillchar(flag,sizeof(flag),false);
 flag['A']:=true;
 flag['E']:=true;
 flag['I']:=true;
 flag['O']:=true;
 flag['U']:=true;
 i:=1;
 while (i<=length(s)) do
 begin
  if not ((s[i]>='A') and (s[i]<='Z')) then
  begin
	inc(i);
	continue;
  end;

  if (flag[s[i]]) then
	begin delete(s,i,1);continue;end;
  flag[s[i]]:=true;
  i:=i+1;
 end;

 while (s[1]=' ') do delete(s,1,1);
 while (s[length(s)]=' ') do delete(s,length(s),1);
 i:=1;
 while (i<length(s)) do
 begin
   while (s[i]=' ') and (s[i+1]=' ') do delete(s,i,1);
   inc(i);

 end;
 i:=1;
while (i<length(s)) do
 begin

  if (((s[i]=' ') and (s[i+1]='.'))
  or ((s[i]=' ') and (s[i+1]=','))
  or ((s[i]=' ') and (s[i+1]='?')))  then delete(s,i,1);
   i:=i+1;
 end;
 write(s);
end.
