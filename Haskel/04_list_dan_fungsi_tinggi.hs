angka :: [Int]
angka = [1, 2, 3, 4, 5, 6]

-- List comprehension membuat list baru dari list yang sudah ada.
kuadratGenap :: [Int]
kuadratGenap = [n * n | n <- angka, even n]

main :: IO ()
main = do
  putStrLn ("Semua angka: " ++ show angka)
  putStrLn ("Angka dikali dua: " ++ show (map (* 2) angka))
  putStrLn ("Angka genap: " ++ show (filter even angka))
  putStrLn ("Kuadrat angka genap: " ++ show kuadratGenap)
  putStrLn ("Jumlah semua angka: " ++ show (foldr (+) 0 angka))
