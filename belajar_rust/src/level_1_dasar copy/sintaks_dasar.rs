//! # Level 1.1: Sintaks Dasar, Variabel, Mutabilitas & Tipe Data
//!
//! Konsep yang dipelajari:
//! 1. Immutability by default (`let`)
//! 2. Mutabilitas (`let mut`)
//! 3. Konstanta (`const`)
//! 4. Shadowing
//! 5. Tipe Data Skalar (Integer, Float, Bool, Char)
//! 6. Tipe Data Majemuk (Tuple & Array)

const MAX_POINTS: u32 = 100_000;

pub fn jalankan_demo() {
    println!("=== 1.1 SINTAKS DASAR & TIPE DATA ===");

    // 1. Immutable vs Mutable
    let x = 5;
    println!("Nilai x (immutable): {x}");
    // x = 6; // ERROR! Tidak bisa diubah karena immutable secara default

    let mut y = 10;
    println!("Nilai y awal (mutable): {y}");
    y = 20;
    println!("Nilai y setelah diubah: {y}");

    // 2. Konstanta
    println!("Nilai konstanta MAX_POINTS: {MAX_POINTS}");

    // 3. Shadowing
    // Shadowing memungkinkan mendeklarasikan ulang variabel dengan nama yang sama,
    // bahkan bisa mengubah tipe datanya!
    let spasi = "   ";
    let spasi = spasi.len(); // Menimpa `spasi` dari &str menjadi usize
    println!("Panjang spasi (hasil shadowing): {spasi}");

    // 4. Tipe Data Skalar
    let integer_bertanda: i32 = -123;
    let integer_positif: u64 = 456_789;
    let pecahan: f64 = 3.1415926535;
    let boolean: bool = true;
    let karakter: char = '🦀'; // Karakter Rust adalah Unicode 4-byte (bisa emoji)

    println!("Tipe Skalar -> i32: {integer_bertanda}, u64: {integer_positif}, f64: {pecahan}, bool: {boolean}, char: {karakter}");

    // 5. Tipe Data Majemuk
    // A. Tuple (kumpulan nilai dengan tipe data bisa berbeda)
    let identitas: (&str, u8, bool) = ("Budi", 25, true);
    let (nama, umur, status_aktif) = identitas; // Destructuring
    println!("Tuple Destructuring -> Nama: {nama}, Umur: {umur}, Aktif: {status_aktif}");
    println!("Akses tuple dengan indeks -> identitas.0: {}", identitas.0);

    // B. Array (kumpulan nilai dengan tipe sama dan panjang tetap di Stack)
    let bulan = ["Januari", "Februari", "Maret", "April"];
    let deret_nol: [i32; 5] = [0; 5]; // Array berisi lima angka 0: [0, 0, 0, 0, 0]
    println!("Array -> Bulan pertama: {}, Panjang array deret_nol: {}", bulan[0], deret_nol.len());
    println!();
}
