//! # Level 5.1: Generics (Pemrograman Generik & Monomorphization)
//!
//! Konsep yang dipelajari:
//! 1. Generic Functions (`fn terbesar<T: PartialOrd>(...)`)
//! 2. Generic Structs (`struct Titik<T>`)
//! 3. Monomorphization (Zero-cost abstraction di waktu kompilasi)

#[derive(Debug)]
pub struct Titik<T> {
    pub x: T,
    pub y: T,
}

impl<T> Titik<T> {
    pub fn new(x: T, y: T) -> Self {
        Self { x, y }
    }
}

// Implementasi khusus hanya jika T adalah f64
impl Titik<f64> {
    pub fn jarak_dari_pusat(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

/// Fungsi generik untuk mencari elemen terbesar dari slice
pub fn cari_terbesar<T: PartialOrd + Copy>(list: &[T]) -> Option<T> {
    if list.is_empty() {
        return None;
    }
    let mut terbesar = list[0];
    for &item in list.iter().skip(1) {
        if item > terbesar {
            terbesar = item;
        }
    }
    Some(terbesar)
}

pub fn jalankan_demo() {
    println!("=== 5.1 GENERICS & ZERO-COST ABSTRACTIONS ===");

    // 1. Generic Struct dengan tipe berbeda
    let titik_int = Titik::new(5, 10);
    let titik_float = Titik::new(3.0, 4.0);

    println!("Titik Integer: {:?}", titik_int);
    println!("Titik Float: {:?}, Jarak dari pusat: {}", titik_float, titik_float.jarak_dari_pusat());

    // 2. Generic Function
    let deret_angka = [12, 45, 89, 23, 7];
    let deret_huruf = ['a', 'z', 'm', 'k'];

    println!("Angka terbesar: {:?}", cari_terbesar(&deret_angka));
    println!("Huruf terbesar: {:?}", cari_terbesar(&deret_huruf));
    println!();
}
