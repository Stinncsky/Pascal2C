program main;
var a: integer;

function func(p, q: integer): integer;
begin
  p := p - 1;
  func := p;
end;

function typeerr(p: real; q: integer): integer;
begin
  p := p - 1.0;
  typeerr := p;
end;

function f(var x: integer): integer;
begin
  f := x;
end;

begin
  func(a);
  func(1, 2);
  func(1, 2, 3);

  typeerr(1, 2);
  typeerr(a, 1.0);

  f(1);
  f(a + 2);
end.