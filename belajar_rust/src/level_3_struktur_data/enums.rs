//! # Level 3.2: Enums & Option
//!
//! Konsep yang dipelajari:
//! 1. Enum varian sederhana
//! 2. Enum varian dengan data terlampir (String, Tuple, Struct-like)
//! 3. `Option<T>` (Solusi Rust menggantikan `null`)
//! 4. Method di dalam Enum

#[derive(Debug)]
pub enum PesanJaringan {
    Keluar,
    PindahPosisi { x: i32, y: i32 },
    KirimTeks(String),
    UbahWarna(u8, u8, u8),
}

impl PesanJaringan {
    pub fn proses(&self) {
        match self {
            PesanJaringan::Keluar => println!("   [Jaringan] Perintah Keluar diterima."),
            PesanJaringan::PindahPosisi { x, y } => {
                println!("   [Jaringan] Karakter pindah ke koordinat ({x}, {y})");
            }
            PesanJaringan::KirimTeks(pesan) => {
                println!("   [Jaringan] Pesan Chat: \"{pesan}\"");
            }
            PesanJaringan::UbahWarna(r, g, b) => {
                println!("   [Jaringan] Ubah warna avatar ke RGB({r}, {g}, {b})");
            }
        }
    }
}

pub fn jalankan_demo() {
    println!("=== 3.2 ENUMS & OPTION<T> ===");

    // 1. Berbagai Varian Enum dengan Data
    let pesan1 = PesanJaringan::KirimTeks(String::from("Halo semua!"));
    let pesan2 = PesanJaringan::PindahPosisi { x: 100, y: 250 };
    let pesan3 = PesanJaringan::UbahWarna(255, 128, 0);

    pesan1.proses();
    pesan2.proses();
    pesan3.proses();

    // 2. Option<T> (Some(T) vs None)
    let angka_ada: Option<i32> = Some(42);
    let angka_kosong: Option<i32> = None;

    periksa_option(angka_ada);
    periksa_option(angka_kosong);

    // 3. Menggunakan method bawaan Option (unwrap_or, map, and_then)
    let nilai_default = angka_kosong.unwrap_or(0);
    println!("Nilai fallback unwrap_or: {nilai_default}");

    let hasil_kali = angka_ada.map(|x| x * 2);
    println!("Hasil map Option Some(42) * 2: {:?}", hasil_kali);
    println!();
}

fn periksa_option(opsi: Option<i32>) {
    match opsi {
        Some(val) => println!("   Option berisi nilai: {val}"),
        None => println!("   Option KOSONG (None)"),
    }
}
