var
 height,x,y,tree_max,tree_min:array[-500..200050] of longint;
 i,a,b,n,q:longint;

function max(a,b:longint):longint;
begin
 if a>b then exit(a) else exit(b);
end;

function min(a,b:longint):longint;
begin
 if a<b then exit(a) else exit(b);
end;


function maketree_max(i,left,right:longint):longint;
var
 mid:longint;
begin
 x[i]:=left;
 y[i]:=right;//����ÿ��tree�ķ�Χ

 if (left=right) then
	begin
		tree_max[i]:=height[left];
		exit(tree_max[i]);
	end;
 mid:=(left+right) div 2;
 tree_max[i]:=max(maketree_max(i*2,left,mid),maketree_max(i*2+1,mid+1,right));
 exit(tree_max[i]);
end;


function maketree_min(i,left,right:longint):longint;
var
 mid:longint;
begin
 if (left=right) then
	begin
		tree_min[i]:=height[left];
		exit(tree_min[i]);
	end;
 mid:=(left+right) div 2;
 tree_min[i]:=min(maketree_min(i*2,left,mid),maketree_min(i*2+1,mid+1,right));
 exit(tree_min[i]);
end;

function find_max(i,left,right:longint):longint;
var li,ri,midi,ans:longint;
begin
 li:=x[i];
 ri:=y[i];
 midi:=(li+ri) div 2;
 if (li=left) and (ri=right) then
	begin
	 exit(tree_max[i]);
	end;
 ans:=-maxlongint;
 if (left<=midi) then ans:=max(ans,find_max(i*2,left,min(right,midi)));
 if (right>midi) then ans:=max(ans,find_max(i*2+1,max(left,midi+1),right));
 exit(ans);
end;

function find_min(i,left,right:longint):longint;
var li,ri,midi,ans:longint;
begin
 li:=x[i];
 ri:=y[i];
 midi:=(li+ri) div 2;
 if (li=left) and (ri=right) then exit(tree_min[i]);
 ans:=maxlongint;
 if (left<=midi) then ans:=min(ans,find_min(i*2,left,min(right,midi)));
 if (right>midi) then ans:=min(ans,find_min(i*2+1,max(left,midi+1),right));
 exit(ans);
end;


begin
 readln(n,q);
 for i:=1 to n do
  readln(height[i]);
 maketree_max(1,1,n);
 maketree_min(1,1,n);//make tree;
 for i:=1 to q do
 begin
  readln(a,b);
  writeln(find_max(1,a,b)-find_min(1,a,b));
 end;


end.
