var
 a:array[0..20000] of longint ;
 ans,x,n,s,i,j:longint;

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]<x do
            inc(i);
           while x<a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;

function find(k:longint):longint;//找出不大于k的最后的一个数
var
 left,right,mid:longint;
begin
 left:=1;
 right:=n;
 while left<right do
 begin
  mid:=(left+right+1) div 2;
  if a[mid]<=k then left:=mid else right:=mid-1;
 end;
 exit(left);
end;
begin
 ans:=0;
 readln(n,s);
 for i:=1 to n do readln(a[i]);
 sort(1,n);
 for i:=1 to n do
 begin
  x:=find(s-a[i]);
  if x>i then ans:=ans+x-i;
 end;
 writeln(ans);
end.
