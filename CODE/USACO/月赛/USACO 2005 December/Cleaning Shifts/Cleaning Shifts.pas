var
 n,m,e,i,j,s:longint;
 l,r,p,f:array[0..10000] of longint;
procedure sort(first,last:longint);
var i,j,x,t:longint;
begin
 i:=first; j:=last; x:=l[(i+j) div 2];
 repeat
  while l[i]<x do inc(i);
  while l[j]>x do dec(j);
  if i<=j then
   begin
    t:=l[i]; l[i]:=l[j]; l[j]:=t;
    t:=r[i]; r[i]:=r[j]; r[j]:=t;
    t:=p[i]; p[i]:=p[j]; p[j]:=t;
    inc(i); dec(j);
   end;
 until i>=j;
 if i<last then sort(i,last);
 if j>first then sort(first,j);
end;
function min(a,b:longint):longint;
begin
 if a>b then exit(b) else exit(a);
end;
begin
 readln(n,m,e);
 for i:=1 to n do readln(l[i],r[i],p[i]);
 sort(1,n);
 fillchar(f,sizeof(f),100);
 for i:=1 to n do
  begin
   if l[i]=m then f[i]:=p[i];
   if l[i]>m then break;
  end;
 for i:=1 to n do
  for j:=i+1 to n do
   if r[i]>=l[j]-1 then f[j]:=min(f[j],f[i]+p[j]);
 s:=maxlongint;
 for i:=1 to n do
  if r[i]>=e then s:=min(s,f[i]);
 if s=1684300900 then write(-1) else write(s);
end.