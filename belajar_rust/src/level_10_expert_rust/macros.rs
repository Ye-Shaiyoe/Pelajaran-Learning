//! # Level 10.1: Declarative Macros (`macro_rules!`)
//!
//! Konsep yang dipelajari:
//! 1. Apa itu Macro (Metaprogramming / Code that writes code)
//! 2. Declarative Macro Syntax (`macro_rules!`)
//! 3. Matching pola arguments (`$x:expr`, `$($val:expr),*`)
//! 4. Membuat macro kustom mirip `vec!`

/// Macro untuk membuat HashMap dengan mudah mirip sintaks JSON/Dict
#[macro_export]
macro_rules! buat_map {
    ( $( $key:expr => $val:expr ),* $(,)? ) => {
        {
            let mut map = std::collections::HashMap::new();
            $(
                map.insert($key, $val);
            )*
            map
        }
    };
}

/// Macro untuk menghitung waktu eksekusi fungsi secara instan
#[macro_export]
macro_rules! ukur_waktu {
    ($label:expr, $blok:block) => {{
        let mulai = std::time::Instant::now();
        let hasil = $blok;
        let durasi = mulai.elapsed();
        println!("   ⏱️ [Benchmark] {}: {:?}", $label, durasi);
        hasil
    }};
}

pub fn jalankan_demo() {
    println!("=== 10.1 DECLARATIVE MACROS (macro_rules!) ===");

    // 1. Menggunakan macro `buat_map!`
    let kamus = buat_map!(
        "id" => "Indonesia",
        "en" => "Inggris",
        "jp" => "Jepang",
    );
    println!("HashMap dibuat via macro: {:?}", kamus);

    // 2. Menggunakan macro `ukur_waktu!`
    let total: u64 = ukur_waktu!("Penjumlahan 1 Juta Angka", {
        (1..=1_000_000).sum()
    });
    println!("Hasil kalkulasi: {total}");
    println!();
}
