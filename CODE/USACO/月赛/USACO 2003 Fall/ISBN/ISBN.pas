var
 a:array[0..9] of longint;
 s,i,k,qm,ans:longint;
 ch:char;

begin
 fillchar(a,sizeof(a),0);
 for i:=10 downto 1 do
 begin
  read(ch);
     if ch='X' then qm:=qm+10*i
else if ch='?' then k:=i
else qm:=qm+(ord(ch)-48)*i;
 end;
 qm:=11-(qm mod 11);
 if qm=11 then qm:=0;
 ans:=-1;
 for i:=0 to 9 do
 begin
  if ((i*k)) mod 11=qm then
	begin
		ans:=i;
		break;
	end;
  end;
 if (k=1) and (qm=10) and (ans=-1) then ans:=10;
 if ans=10 then writeln('X') else writeln(ans);
end.
