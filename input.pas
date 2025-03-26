// 测试样例 00-27
program main;
const
  ca = 1;
  cb = 'a';
var 
  a, input: integer;
  b : array [1..10] of integer;
  bx: array [0..9, 2..9] of integer;
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
  if ((a * b / c = e + d) and (a * (a + b) + c <= d + e) or (a - (b * c) = d - a / c) or false) then
  begin
    flag := true;
  end;
  if (flag) then
    write(1);
end;

begin
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

  bx[0, 2] := 1;
  write(bx[0, 2] + 1); //现在这个顺序反了

  tmp := not a; //Bool为!，Int为~，尚未实现

  tmp := - - -1;
  tmp := a + +a;

  opPriority;
end.
