
var
 n:qword;
 a,sum,dp:array[0..15000] of qword;
 i,j:longint;
procedure qsort(l,r:longint);
 var ql,qr,x:longint;
 begin
  x:=a[l];
  ql:=l;qr:=r;
  while ql<qr do
   begin
    while (a[qr]>=x)and(ql<qr) do qr:=qr-1;  if ql<qr then a[ql]:=a[qr];
    while (a[ql]<=x)and(ql<qr) do ql:=ql+1;  if ql<qr then a[qr]:=a[ql];
   end;
  a[ql]:=x;
  ql:=ql-1;qr:=qr+1;
  if l<ql then qsort(l,ql);
  if qr<r then qsort(qr,r);
 end;

begin
	readln(n);
	for i:=1 to n do readln(a[i]);
	qsort(1,n);
	dp[1]:=0;
	sum[1]:=a[1];
	for i:=2 to n do
	begin
	 dp[i]:=dp[i-1]+(i-1)*a[i]-sum[i-1];
	 sum[i]:=sum[i-1]+a[i];
	end;
	writeln(dp[n]*2);
end.
