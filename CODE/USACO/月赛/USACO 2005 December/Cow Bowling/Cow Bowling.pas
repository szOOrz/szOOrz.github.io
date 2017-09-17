var
	a,dp:array[0..1000,0..1000] of longint;
	n,i,j:longint;
begin
	readln(n);
	for i:=0 to n-1 do
		for j:=0 to i do
			read(a[i,j]);
	fillchar(dp,sizeof(dp),0);
        for i:=0 to n-1 do dp[n-1,i]:=a[n-1,i];
	for i:=n-2 downto 0 do
	begin
		for j:=0 to i do
		if (dp[i+1,j]>dp[i+1,j+1]) then
				dp[i,j]:=dp[i+1,j]+a[i,j]
			else
				dp[i,j]:=dp[i+1,j+1]+a[i,j];
	end;
	writeln(dp[0,0]);
end.
