//! # Level 4.2: String vs &str & UTF-8 Encoding Mendalam
//!
//! Konsep yang dipelajari:
//! 1. Perbedaan mendasar `String` (Heap) vs `&str` (Slice/Borrowed)
//! 2. UTF-8 Multi-byte (Kenapa Rust melarang indexing langsung `s[0]`)
//! 3. Iterasi Bytes vs Chars
//! 4. Format & String Building

pub fn jalankan_demo() {
    println!("=== 4.2 PEMBAHASAN STRING & UTF-8 ===");

    // 1. String Concatenation & Format Macro
    let s1 = String::from("Halo");
    let s2 = String::from("Dunia");
    let gabungan = format!("{s1}, {}! Selamat pagi.", s2);
    println!("Hasil format!: \"{gabungan}\"");

    // 2. UTF-8 & Karakter Khusus
    // Bahasa Rust menggunakan UTF-8 penuh. Setiap karakter bisa berukuran 1 hingga 4 byte!
    let teks_internasional = "Halo 🦀 Привет 日本語";
    println!("Teks: \"{teks_internasional}\"");
    println!("Ukuran dalam byte: {} bytes", teks_internasional.len());
    println!("Jumlah karakter/glyph: {} chars", teks_internasional.chars().count());

    // 3. Kenapa tidak bisa `teks[0]`?
    // Karena karakter seperti '🦀' berukuran 4 bytes! Jika di-index langsung bisa merusak batas byte UTF-8.
    print!("Iterasi Chars 5 karakter pertama: ");
    for c in teks_internasional.chars().take(7) {
        print!("'{c}' ");
    }
    println!();

    // 4. Manipulasi String
    let draft = String::from("  bahasa rust itu cepat dan aman  ");
    let dibersihkan = draft.trim().to_uppercase();
    println!("Hasil trim & uppercase: \"{dibersihkan}\"");
    println!();
}
