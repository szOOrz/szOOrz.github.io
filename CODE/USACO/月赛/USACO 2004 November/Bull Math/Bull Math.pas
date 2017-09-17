var
s1,s2:ansistring;
a,b,c:array[1..1001]of integer;
i,j,p:integer;
begin
readln(s1);
readln(s2);

for i:=1 to length(s1) do a[i]:=ord(s1[length(s1)-i+1])-48;
for i:=1 to length(s2) do b[i]:=ord(s2[length(s2)-i+1])-48;
for i:=1 to length(s1) do
for j:=1 to length(s2) do
begin
inc(c[i+j-1],a[i]*b[j]);
inc(c[i+j],c[i+j-1] div 10);
c[i+j-1]:=c[i+j-1] mod 10;
end;
for i:=length(s1)+length(s2) downto 1 do if c[i]<>0 then begin p:=i;break; end;
for i:=p downto 1 do write(c[i]);
end.