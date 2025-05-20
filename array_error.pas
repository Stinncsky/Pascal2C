program main;
var
    a: array[0..9, 0..9, 100..200] of integer;
begin
    write(a[100, -5]);
    write(a[0, 0, 100.5]);
end.