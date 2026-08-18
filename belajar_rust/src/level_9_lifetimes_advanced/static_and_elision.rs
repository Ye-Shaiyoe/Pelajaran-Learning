//! # Level 9.3: `'static` Lifetime & Aturan Lifetime Elision
//!
//! Konsep yang dipelajari:
//! 1. Apa itu `'static` (Reference yang hidup selama program berjalan)
//! 2. String Literal selalu memiliki lifetime `'static`
//! 3. 3 Aturan Lifetime Elision (Mengapa seringkali kita tidak perlu menulis anotasi `'a` secara manual)

// Contoh fungsi tanpa anotasi eksplisit karena memenuhi aturan Lifetime Elision #1 & #2
pub fn ambil_kata_pertama(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    s
}

pub fn jalankan_demo() {
    println!("=== 9.3 'STATIC LIFETIME & ELISION RULES ===");

    // 1. Literal string otomatis bertipe &'static str
    let teks_abadi: &'static str = "Saya tersimpan langsung di binary biner program!";
    println!("Teks static: \"{teks_abadi}\"");

    // 2. Lifetime Elision (Rust menyimpulkan lifetime secara otomatis di balik layar)
    let kalimat = "Belajar Rust dari nol sampai mahir";
    let kata1 = ambil_kata_pertama(kalimat);
    println!("Kata pertama (via elision): \"{kata1}\"");
    println!();
}
