// 测试样例 00-17
program main;
const
  ca = 1;
  cb = 'a';
var 
  a, input: integer;
  b: array [0..9, 2..9] of integer;
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

begin
  a := defn;
  write(ifWhile()); // 需完善函数类型部分后测试
  a := func(a);
  foo;
  tmp := -1;
  a := a * tmp;
  write(a div 1);

  read(input);
  input := input + input * a - tmp;
  input := tmp * (a + input);
  write(input - (1+1));
end.
