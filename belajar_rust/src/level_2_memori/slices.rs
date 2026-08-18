//! # Level 2.3: Slices (Potongan Data Tanpa Alokasi Baru)
//!
//! Konsep yang dipelajari:
//! 1. String Slice (`&str`)
//! 2. Array Slice (`&[T]`)
//! 3. Kenapa `&str` lebih fleksibel sebagai parameter fungsi daripada `&String`

pub fn jalankan_demo() {
    println!("=== 2.3 SLICES (&str & &[T]) ===");

    // 1. String Slice
    let kalimat = String::from("Rust Sangat Keren");
    let kata1: &str = &kalimat[0..4];  // "Rust"
    let kata2: &str = &kalimat[5..11]; // "Sangat"
    let kata3: &str = &kalimat[12..];  // "Keren"
    println!("Kalimat: \"{kalimat}\"");
    println!("Potongan kata: [1]=\"{kata1}\", [2]=\"{kata2}\", [3]=\"{kata3}\"");

    // 2. Fungsi yang menerima &str (Dapat menerima String maupun literal str)
    let nama_string = String::from("Akrom");
    let nama_literal = "Budi";

    cetak_salam(&nama_string);  // Rust otomatis mengonversi &String menjadi &str (Deref Coercion)
    cetak_salam(nama_literal);

    // 3. Array Slice
    let angka = [10, 20, 30, 40, 50, 60];
    let potongan_angka: &[i32] = &angka[1..4]; // Mengambil elemen indeks 1, 2, 3 -> [20, 30, 40]
    println!("Array asli: {:?}, Potongan slice: {:?}", angka, potongan_angka);
    println!();
}

fn cetak_salam(nama: &str) {
    println!("   Halo, {nama}!");
}
