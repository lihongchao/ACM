var n,m,i,j,k,x:integer;
    f:array[0..200,0..200,0..200]of int64;
begin
  assign(input,'divide3.in');
  reset(input);
  assign(output,'divide3.out');
  rewrite(output);
  readln(n,m);
  for k:=1 to n do
    for i:=k to n do f[i,1,k]:=1;
  for j:=2 to m do begin
    for k:=1 to n div j do begin
      for i:=j*k to n do begin
        for x:=k to i div j do f[i,j,k]:=f[i,j,k]+f[i-x,j-1,x];
      end;
    end;
  end;
  writeln(f[n,m,1]);
  close(input);
  close(output);
end.
