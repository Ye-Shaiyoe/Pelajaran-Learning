-- Haskell menggunakan binding yang nilainya tidak diubah setelah dibuat.
main :: IO ()
main = do
  let nama = "Ayu"
      umur = 18 :: Int
      tinggi = 1.62 :: Double
      sedangBelajar = True

  putStrLn ("Nama: " ++ nama)
  putStrLn ("Umur: " ++ show umur ++ " tahun")
  putStrLn ("Tinggi: " ++ show tinggi ++ " meter")
  putStrLn ("Sedang belajar? " ++ show sedangBelajar)

  putStrLn ("Tahun depan umur " ++ nama ++ " adalah " ++ show (umur + 1))
