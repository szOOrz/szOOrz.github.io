var
 a,b,c:array[0..50050] of longint;
 i,n,k,ee,max:longint;

    procedure sort(l,r: longint);
      var
         i,j,x,y: longint;
      begin
         i:=l;
         j:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i]>x do
            inc(i);
           while x>a[j] do
            dec(j);
           if not(i>j) then
             begin
                y:=a[i];
                a[i]:=a[j];
                a[j]:=y;
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                y:=c[i];
                c[i]:=c[j];
                c[j]:=y;
                inc(i);
                j:=j-1;
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;


begin
 readln(n,k);
 for i:=1 to n do readln(a[i],b[i]);
 for i:=1 to n do c[i]:=i;
 sort(1,n);
 max:=-maxlongint;
 ee:=0;
 for i:=1 to k do
  if b[i]>max then begin max:=b[i];ee:=i;end;
 writeln(c[ee]);
end.
