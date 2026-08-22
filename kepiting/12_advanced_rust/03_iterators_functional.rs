fn main() {
    let angka = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    println!("Data Awal: {:?}", angka);

    println!("\n=== 1. FILTER DAN MAP ===");

    let genap_kali_sepuluh: Vec<i32> = angka
        .iter()
        .filter(|&&x| x % 2 == 0)
        .map(|&x| x * 10)
        .collect();

    println!("Genap x 10: {:?}", genap_kali_sepuluh);

    println!("\n=== 2. AGREGASI DENGAN FOLD / SUM / PRODUCT ===");
    let total_sum: i32 = angka.iter().sum();
    let total_produk: i32 = angka.iter().take(5).product();

    let jumlah_kuadrat = angka.iter().fold(0, |acc, &x| acc + (x * x));

    println!("Total Sum (1..10)      : {total_sum}");
    println!("Total Produk (1..5)    : {total_produk}");
    println!("Total Jumlah Kuadrat   : {jumlah_kuadrat}");

    println!("\n=== 3. ZIP DAN ENUMERATE ===");
    let nama_siswa = vec!["Ali", "Budi", "Citra"];
    let nilai_siswa = vec![95, 88, 92];

    let daftar_pasangan: Vec<(&&str, &i32)> = nama_siswa.iter().zip(nilai_siswa.iter()).collect();
    println!("Daftar Siswa & Nilai:");
    for (ranking, (nama, nilai)) in daftar_pasangan.iter().enumerate() {
        println!("  Juara {}: {} dengan nilai {}", ranking + 1, nama, nilai);
    }

    println!("\n=== 4. CUSTOM ITERATOR MENGGUNAKAN TRAIT Iterator ===");

    struct DeretFibonacci {
        sekarang: u32,
        selanjutnya: u32,
    }

    impl DeretFibonacci {
        fn baru() -> Self {
            Self { sekarang: 0, selanjutnya: 1 }
        }
    }

    impl Iterator for DeretFibonacci {
        type Item = u32;

        fn next(&mut self) -> Option<Self::Item> {
            let nilai_saat_ini = self.sekarang;
            let nilai_baru = self.sekarang + self.selanjutnya;
            self.sekarang = self.selanjutnya;
            self.selanjutnya = nilai_baru;

            Some(nilai_saat_ini)
        }
    }

    let fibo_10_pertama: Vec<u32> = DeretFibonacci::baru().take(10).collect();
    println!("10 Bilangan Fibonacci Pertama: {:?}", fibo_10_pertama);
}
