# Belajar Haskell untuk Pemula

Materi disusun dari contoh kecil menuju satu program tutorial yang lebih lengkap.
Setiap file `.hs` dapat dijalankan secara terpisah.

## Urutan belajar

1. `01_hello_world.hs` - fungsi `main`, fungsi sederhana, dan output.
2. `02_variabel_dan_tipe.hs` - binding `let`, tipe dasar, dan anotasi tipe.
3. `03_fungsi_dan_kondisi.hs` - fungsi bertipe, guards, `if`, dan rekursi.
4. `04_list_dan_fungsi_tinggi.hs` - list, list comprehension, `map`, `filter`, dan `foldr`.
5. `Belajar_Haskell_Lengkap.hs` - tutorial besar dengan fungsi, tipe data, list,
   `Maybe`, `Either`, dan input interaktif.

## Menjalankan

Pasang GHC (Glasgow Haskell Compiler), lalu jalankan file tanpa membuat executable:

```bash
runghc 01_hello_world.hs
runghc 02_variabel_dan_tipe.hs
runghc 03_fungsi_dan_kondisi.hs
runghc 04_list_dan_fungsi_tinggi.hs
runghc Belajar_Haskell_Lengkap.hs
```

Atau kompilasi satu file dengan GHC:

```bash
ghc 01_hello_world.hs -o hello
./hello
```

Tutorial besar meminta nama dan nilai saat dijalankan. Nilai harus berupa bilangan
bulat antara 0 dan 100.
