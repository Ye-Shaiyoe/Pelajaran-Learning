//! # Level 9.1: Lifetime Syntax & Borrow Checker
//!
//! Konsep yang dipelajari:
//! 1. Mengapa Lifetime dibutuhkan oleh Borrow Checker
//! 2. Sintaks Generic Lifetime Parameters (`'a`)
//! 3. Fungsi yang mengembalikan reference dari dua input

/// Fungsi ini menjamin bahwa reference yang dikembalikan akan valid
/// selama kedua parameter `x` dan `y` sama-sama masih valid (irisan lifetime 'a)
pub fn teks_terpanjang<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

pub fn jalankan_demo() {
    println!("=== 9.1 LIFETIME ANNOTATIONS ('a) PADA FUNGSI ===");

    let str1 = String::from("Rustacean Sejati");
    let hasil;
    {
        let str2 = String::from("C++ Dev");
        hasil = teks_terpanjang(&str1, &str2);
        println!("Teks terpanjang dalam scope: \"{hasil}\"");
    }

    let a = "Pendek";
    let b = "Sangat Panjang Sekali";
    println!("Hasil terpanjang: \"{}\"", teks_terpanjang(a, b));
    println!();
}
