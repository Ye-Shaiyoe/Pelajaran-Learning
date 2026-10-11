-- Fungsi biasa memiliki tipe yang ditulis dari input ke output.
luasPersegi :: Double -> Double
luasPersegi sisi = sisi * sisi

-- Guards cocok untuk beberapa kondisi yang berurutan.
kategoriUmur :: Int -> String
kategoriUmur umur
  | umur < 0 = "Umur tidak valid"
  | umur < 13 = "Anak-anak"
  | umur < 18 = "Remaja"
  | otherwise = "Dewasa"

-- Contoh rekursi: kasus dasar menghentikan pemanggilan berulang.
jumlahSampai :: Int -> Int
jumlahSampai n
  | n <= 0 = 0
  | otherwise = n + jumlahSampai (n - 1)

main :: IO ()
main = do
  putStrLn ("Luas persegi dengan sisi 4: " ++ show (luasPersegi 4))
  putStrLn ("Kategori umur 15: " ++ kategoriUmur 15)
  putStrLn ("Jumlah bilangan 1 sampai 5: " ++ show (jumlahSampai 5))

  let angka = 7
  putStrLn
    (if even angka then "Angka genap" else "Angka ganjil")
