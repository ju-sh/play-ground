with Ada.Text_IO;
use Ada.Text_IO;

procedure Hello is begin
  Put_Line ("Hello world!");
end Hello;

 -- ✓
-- gnatmake hello.adb
-- ./hello

-- This was not needed:
-- ✗ gcc -c hello.adb
