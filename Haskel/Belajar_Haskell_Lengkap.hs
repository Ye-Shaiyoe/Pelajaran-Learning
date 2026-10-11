-- Tutorial pemula Haskell dalam satu file.
-- Jalankan dengan: runghc Belajar_Haskell_Lengkap.hs

-- 1. Fungsi dan anotasi tipe
sapa :: String -> String
sapa nama = "Halo, " ++ nama ++ "!"

kalikan :: Int -> Int -> Int
kalikan a b = a * b

-- 2. Guards dan pattern matching
nilaiHuruf :: Int -> String
nilaiHuruf nilai
  | nilai < 0 || nilai > 100 = "Nilai harus berada di antara 0 dan 100."
  | nilai >= 90 = "A"
  | nilai >= 80 = "B"
  | nilai >= 70 = "C"
  | nilai >= 60 = "D"
  | otherwise = "E"

namaHari :: Int -> String
namaHari nomor =
  case nomor of
    1 -> "Senin"
    2 -> "Selasa"
    3 -> "Rabu"
    4 -> "Kamis"
    5 -> "Jumat"
    6 -> "Sabtu"
    7 -> "Minggu"
    _ -> "Nomor hari tidak valid"

-- 3. Rekursi dan hasil yang mungkin tidak tersedia
faktorial :: Integer -> Maybe Integer
faktorial n
  | n < 0 = Nothing
  | n == 0 = Just 1
  | otherwise = fmap (n *) (faktorial (n - 1))

-- 4. Fungsi untuk mengolah list
jumlahList :: [Int] -> Int
jumlahList = foldr (+) 0

angkaContoh :: [Int]
angkaContoh = [1 .. 10]

angkaGenap :: [Int]
angkaGenap = filter even angkaContoh

kuadrat :: [Int]
kuadrat = map (\angka -> angka * angka) angkaContoh

-- 5. Tipe data buatan sendiri
data Buku = Buku
  { judulBuku :: String
  , penulisBuku :: String
  , tahunTerbit :: Int
  }
  deriving (Show)

bukuContoh :: Buku
bukuContoh =
  Buku
    { judulBuku = "Belajar Pemrograman"
    , penulisBuku = "Dina"
    , tahunTerbit = 2024
    }

-- 6. Either untuk mengembalikan pesan error atau hasil yang benar
bacaBilangan :: String -> Either String Int
bacaBilangan teks =
  case reads teks of
    [(angka, "")] -> Right angka
    _ -> Left "Input bukan bilangan bulat."

cekNilai :: Int -> Either String String
cekNilai nilai
  | nilai < 0 || nilai > 100 = Left "Nilai harus berada di antara 0 dan 100."
  | otherwise = Right ("Nilai huruf: " ++ nilaiHuruf nilai)

tampilkanHasilNilai :: String -> IO ()
tampilkanHasilNilai teks =
  case bacaBilangan teks of
    Left pesan -> putStrLn pesan
    Right nilai ->
      case cekNilai nilai of
        Left pesan -> putStrLn pesan
        Right hasil -> putStrLn hasil

-- 7. Efek input dan output berada di dalam tipe IO.
main :: IO ()
main = do
  putStrLn "=== Belajar Haskell ==="
  putStrLn (sapa "Teman")

  putStrLn "\nFungsi dan kondisi"
  putStrLn ("6 dikali 7 = " ++ show (kalikan 6 7))
  putStrLn ("Nilai 85 mendapat: " ++ nilaiHuruf 85)
  putStrLn ("Nomor hari 3 adalah: " ++ namaHari 3)

  putStrLn "\nRekursi dan Maybe"
  putStrLn ("Faktorial 5: " ++ show (faktorial 5))
  putStrLn ("Faktorial -1: " ++ show (faktorial (-1)))

  putStrLn "\nList dan fungsi tingkat tinggi"
  putStrLn ("Daftar angka: " ++ show angkaContoh)
  putStrLn ("Angka genap: " ++ show angkaGenap)
  putStrLn ("Kuadrat angka: " ++ show kuadrat)
  putStrLn ("Jumlah angka: " ++ show (jumlahList angkaContoh))

  putStrLn "\nTipe data"
  putStrLn ("Contoh buku: " ++ show bukuContoh)
  putStrLn ("Judul buku: " ++ judulBuku bukuContoh)

  putStrLn "\nCoba input sendiri"
  putStrLn "Masukkan nama:"
  nama <- getLine
  putStrLn (sapa nama)
  putStrLn "Masukkan nilai (0-100):"
  teksNilai <- getLine
  tampilkanHasilNilai teksNilai
