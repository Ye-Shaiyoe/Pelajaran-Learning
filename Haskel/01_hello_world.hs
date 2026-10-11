-- Contoh pertama: program Haskell selalu dimulai dari fungsi main.
main :: IO ()
main = do
  putStrLn "Halo, Haskell!"
  putStrLn (sapa "Teman")

sapa :: String -> String
sapa nama = "Selamat belajar, " ++ nama ++ "!"
