program main;
var a: integer;

function func(p, q: integer): integer;
begin
  p := p - 1;
  func := p;
end;

begin
  func(a);
  func(1, 2);
  func(1, 2, 3);
end.