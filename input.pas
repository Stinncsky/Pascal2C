// 测试样例 00-27 (28 'not') 29-43 (45 Syntax) (56 EXIT) (57 函数传入多参数) (58 While)
program main;
const
  ca = 1;
  cb = 'a';
var 
  a, input: integer;
  f: real;
  b : array [1..10] of integer;
  bx: array [1..9, 2..9] of integer;
  tmp: integer;

function func(p: integer): integer;
begin
  p := p - 1;
  func := p;
end;

function defn: integer;
begin
  defn := 4;
end;

procedure foo;
begin
  write(15)
end;

function ifWhile: integer;
var a,b: integer;
begin
  a := 0;
  b := 1;
  if (a = 5) then
  begin
    for b := 1 to 3 do
    begin
    end;
    b := b + 25;
    ifWhile := b;
  end
  else
    for a := 0 to 4 do
      b := b * 2;
  ifWhile := b;
end;

procedure opPriority;
var a,b,c,d,e: integer; flag: boolean;
begin
  a := 1;
  b := 0;
  c := 1;
  d := 2;
  e := 4;
  flag := false;
  tmp := ((d mod 2 + 67) + -(a - b) - -((c + 2) mod 2)) * ((d * 1 div 2) + (a - b) - -(c + 3) mod 2);
  if ((a * b / c = e + d) and (a * (a + b) + c <= d + e) or (a - (b * c) = d - a / c) or false) then
  begin
    flag := true;
  end;
  if (flag) then
    write(1);
end;

function bubblesort:integer;
var i,j,n,tmp:integer; arr:array [0..9] of integer;
begin
  for i := 0 to n - 2 do
  begin
    for j := 0 to (n - 2 - i) do
    begin
      if arr[j] > arr[j + 1] then
      begin
        tmp := arr[j + 1];
        arr[j + 1] := arr[j];
        arr[j] := tmp;
      end;
    end;
  end;
  bubblesort := 0;
end;

procedure selectsort;
var i,j,min,tmp,n: integer; arr: array [0..9] of integer;
begin
  for i := 0 to n - 2 do
  begin
    min := i;
    for j := i + 1 to n - 1 do
    begin
      if arr[min] > arr[j] then
        min := j;
    end;
    if min <> i then
    begin
      tmp := arr[min];
      arr[min] := arr[i];
      arr[i] := tmp;
    end;
  end;
end;

procedure nullfunc;
begin
end;

procedure recursion(n: integer);
begin
  if n = 0 then
    write(0)
  else
  begin
    write(n);
    recursion(n - 1);
  end;
end;

procedure call(a, b, c, d, e: integer);
begin
  write(a, b, c, d, e);
end;

function funcall(a, b, c, d, e: integer): real;
begin
  funcall := a + b + c + d + e;
end;

function varfunc(a: integer; var b: integer): integer;
begin
  a := a + 1;
  b := b + 1;
  varfunc := a;
end;

procedure varproc(var a: integer; b: integer);
begin
  a := a + 1;
  b := b + 1;
end;

begin
  write(cb);
  a := defn;
  write(ifWhile());
  a := func(a);
  foo;
  tmp := -1;
  a := a * tmp;
  write(a div 1);

  read(input);
  input := input + input * a - tmp;
  input := tmp * (a + input);
  write(input - (1+1));

  b[1] := 1;
  a := b[1];
  write(a + (-5));

  bx[1, 2] := 1;
  write(bx[1, 2] + 1);

  tmp := not a; //Bool为!，Int为~，尚未实现

  tmp := - - -1;
  tmp := a + +a - -4;

  if 1=1 then ;
  opPriority;
  call(a, b[1], bx[1, 2], tmp, input);
  varproc(a, a);
  tmp := varfunc(a, a);

  f := funcall(a, b[1], bx[1, 2], tmp, input);
  write(f);
end.
