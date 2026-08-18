//! # Level 5.4: Associated Types vs Generic Traits
//!
//! Konsep yang dipelajari:
//! 1. Apa itu Associated Types (`type Item;`)
//! 2. Kapan menggunakan Associated Types vs Generics
//! 3. Contoh nyata: Iterator & Graph traversal pattern

pub trait IteratorSederhana {
    type Item; // Associated Type

    fn berikut(&mut self) -> Option<Self::Item>;
}

pub struct PenghitungMundur {
    angka: u32,
}

impl PenghitungMundur {
    pub fn mulai_dari(n: u32) -> Self {
        Self { angka: n }
    }
}

impl IteratorSederhana for PenghitungMundur {
    type Item = u32;

    fn berikut(&mut self) -> Option<Self::Item> {
        if self.angka == 0 {
            None
        } else {
            let hasil = self.angka;
            self.angka -= 1;
            Some(hasil)
        }
    }
}

pub fn jalankan_demo() {
    println!("=== 5.4 ASSOCIATED TYPES DALAM TRAIT ===");

    let mut counter = PenghitungMundur::mulai_dari(3);
    print!("Mundur dengan Iterator kustom: ");
    while let Some(val) = counter.berikut() {
        print!("{val} ");
    }
    println!("(Selesai)");
    println!();
}
