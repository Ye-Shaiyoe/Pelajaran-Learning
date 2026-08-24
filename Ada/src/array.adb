with Ada.Text_IO; use Ada.Text_IO;

procedure Main is
   type Nilai_Arrayku is array (1 .. 5) of Integer;

   Angka : Nilai_Arrayku := (10, 20, 30, 40, 50);

begin
   Put_Line ("Elemen ke-3: " & Integer'Image (Angka (3)));

   Put_Line ("Semua isi array:");
   for I in Angka'Range loop
      Put_Line ("Indeks" & Integer'Image (I) & " = " & Integer'Image (Angka (I)));
   end loop;
end Main;