program main;
var
  a: real;
  b: integer;
  c: char;

begin
  a := 1.5;
  b := a;
  b := 1.5;
  a := a < b;
  a := a + b;
  a := a * b;
  a := a < c;
  a := a + c;
  a := a * c;
  write(b);
end.
