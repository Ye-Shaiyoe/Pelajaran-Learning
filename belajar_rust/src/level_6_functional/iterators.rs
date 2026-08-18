//! # Level 6.2: Iterators & Functional Data Pipeline
//!
//! Konsep yang dipelajari:
//! 1. Tiga jenis iterasi: `.iter()`, `.iter_mut()`, `.into_iter()`
//! 2. Iterator Adapters (Lazy): `map`, `filter`, `take`, `zip`
//! 3. Consuming Adapters: `collect`, `sum`, `fold`
//! 4. Performa Zero-Cost: Loop vs Iterator

pub fn jalankan_demo() {
    println!("=== 6.2 ITERATORS & DATA PIPELINES ===");

    let angka = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

    // 1. Pipeline Fungsional:
    // Ambil angka genap -> kalikan 10 -> jumlahkan semuanya
    let total_genap_kali_10: i32 = angka
        .iter()
        .filter(|&&x| x % 2 == 0) // Memfilter genap
        .map(|&x| x * 10)         // Mengalikan 10
        .sum();                   // Menjumlahkan

    println!("Data awal: {:?}", angka);
    println!("Total genap * 10: {total_genap_kali_10}");

    // 2. Mengumpulkan hasil ke Koleksi baru via .collect()
    let kuadrat: Vec<i32> = (1..=5).map(|x| x * x).collect();
    println!("Hasil 1..=5 di-map x*x: {:?}", kuadrat);

    // 3. .fold() (Mirip reduce di JavaScript / Python)
    let gabungan_string = ["Rust", "is", "Blazingly", "Fast"]
        .iter()
        .fold(String::new(), |mut acc, &kata| {
            if !acc.is_empty() {
                acc.push(' ');
            }
            acc.push_str(kata);
            acc
        });
    println!("Hasil fold kalimat: \"{gabungan_string}\"");
    println!();
}
