var
 k,n:longint;
 s,t,r,i,j,m:longint;
 ans:longint;
 f:boolean;
begin
 readln(n,k);
 for i:=1 to k do
 begin
  readln(s,t,r);
  m:=n;
  f:=true;
  ans:=0;
	while m>s*t do
		begin
			m:=m-s*t;
			ans:=ans+t+r;
		end;
	for j:=1 to t do
		begin
			if m<=0 then
			begin
				writeln(ans);f:=false;break;
			end;
			m:=m-s;
			ans:=ans+1;
		end;
	if f then writeln(ans);
 end;
end.
