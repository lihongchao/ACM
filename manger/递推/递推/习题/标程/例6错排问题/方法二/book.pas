var n,i:integer;
    f:array[1..20]of int64;
    ch:char;
begin
  assign(input,'book.in');
  reset(input);
  assign(output,'book.out');
  rewrite(output);
  readln(n);
  f[1]:=0;
  for i:=2 to n do
    if odd(i) then f[i]:=i*f[i-1]-1
    else  f[i]:=i*f[i-1]+1;
  writeln(f[n]);
  close(input);
  close(output);
end.
