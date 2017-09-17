var
 ch:string;
 f:array['A'..'Z']of boolean;
 i,len:longint;
function fh(ch:char):boolean;
  begin
	if ch='.' then exit(true);
	if ch=',' then exit(true);
	if ch='?' then exit(true);
	exit(false);
  end;
begin
 readln(ch);
 fillchar(f,sizeof(f),false);
 f['A']:=true;
 f['E']:=true;
 f['I']:=true;
 f['O']:=true;
 f['U']:=true;
 i:=1;
 while i<=length(ch) do
 begin
	if not (('A'<=ch[i])and(ch[i]<='Z')) then
	begin
		inc(i);
		continue;
	end;
	if (f[ch[i]]) then 
	begin
		delete(ch,i,1);
		continue;
	end;
       f[ch[i]]:=true;
	inc(i);
 end;
 while ch[1]=' ' do delete(ch,1,1);
 while ch[length(ch)]=' ' do 
	delete(ch,length(ch),1);
 i:=1;
 while i<length(ch) do 
 begin
	while (ch[i]=' ')and(ch[i+1]=' ') do 
		delete(ch,i+1,1);
	inc(i);
 end;
 i:=1;
 while i<length(ch) do
 begin
	if (ch[i]=' ')and(fh(ch[i+1])) then
		delete(ch,i,1);
	inc(i);
 end;
 write(ch);
end.