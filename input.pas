// 测试样例 00-17
program main;
const
  ca = 1;
  cb = 'a';
var 
  a: integer;
  b: array [0..9, 0..9] of integer;
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

begin
  a := defn;
  a := func(a);
  tmp := -1;
  a := a * tmp;
  write(a div 1);
end.
