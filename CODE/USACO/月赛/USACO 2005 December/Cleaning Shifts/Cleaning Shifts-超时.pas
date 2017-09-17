var
	n,m,e:longint;
	T1,T2,S:array[0..10000] of longint;
	f:array[0..10000] of longint;
	i,j:longint;
	ans:longint;
	k,a:longint;

function min(a,b:longint):longint;
begin
 if a>b then exit(b) else exit(a);
end;

procedure sort(first,last:longint);
var i,j,x,t:longint;
begin
 i:=first; j:=last; x:=T1[(i+j) shr 1];
 repeat
  while T1[i]<x do inc(i);
  while T1[j]>x do dec(j);
  if i<=j then
   begin
    t:=T1[i]; T1[i]:=T1[j]; T1[j]:=t;
    t:=T2[i]; T2[i]:=T2[j]; T2[j]:=t;
    t:=S[i];  S[i]:=S[j]; S[j]:=t;
    inc(i); dec(j);
   end;
 until i>=j;
 if i<last then sort(i,last);
 if j>first then sort(first,j);
end;



begin
	readln(n,m,e);
	for i:=1 to n do
		readln(T1[i],T2[i],S[i]);
	sort(1,n);
	k:=1;
	fillchar(f,sizeof(f),100);

	 for i:=1 to n do
	  begin
	   if T1[i]=m then f[i]:=S[i];
	   if T1[i]>m then break;
	  end;

	 for i:=1 to n do
	  for j:=i+1 to n do
	   if T2[i]>=T1[j]-1 then f[j]:=min(f[j],f[i]+S[j]);

	ans:=maxlongint;
	for i:=1 to n do
		if t2[i]=e then ans:=min(ans,f[i]);
	if ans>=1584300900 then writeln(-1) else writeln(ans);
end.
