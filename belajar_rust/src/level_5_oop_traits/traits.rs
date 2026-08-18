//! # Level 5.2: Traits (Interface & Perilaku Bersama)
//!
//! Konsep yang dipelajari:
//! 1. Mendefinisikan Trait
//! 2. Default Implementation dalam Trait
//! 3. Trait Bounds (`impl Trait`, `T: Trait`, dan `where` clause)
//! 4. Implementasi Trait Standar (`Display`, `Clone`, `PartialEq`)

pub trait Ringkasan {
    // Method signature yang harus diimplementasikan
    fn penulis(&self) -> String;

    // Default implementation (bisa di-override jika perlu)
    fn format_ringkasan(&self) -> String {
        format!("(Diringkas oleh: {})", self.penulis())
    }
}

pub struct ArtikelBerita {
    pub judul: String,
    pub lokasi: String,
    pub penulis: String,
}

impl Ringkasan for ArtikelBerita {
    fn penulis(&self) -> String {
        self.penulis.clone()
    }

    fn format_ringkasan(&self) -> String {
        format!("BREAKING: {} - {} (Oleh: {})", self.judul, self.lokasi, self.penulis)
    }
}

pub struct Tweet {
    pub username: String,
    pub isi: String,
}

impl Ringkasan for Tweet {
    fn penulis(&self) -> String {
        format!("@{}", self.username)
    }
}

// Fungsi dengan Trait Bound: Hanya menerima tipe yang mengimplementasikan Ringkasan
pub fn publikasikan<T: Ringkasan>(item: &T) {
    println!("   [PUBLIKASI]: {}", item.format_ringkasan());
}

pub fn jalankan_demo() {
    println!("=== 5.2 TRAITS & DEFAULT IMPLEMENTATIONS ===");

    let artikel = ArtikelBerita {
        judul: String::from("Rust 2026 Dirilis"),
        lokasi: String::from("Bandung"),
        penulis: String::from("Akrom"),
    };

    let tweet = Tweet {
        username: String::from("rust_id"),
        isi: String::from("Belajar Rust seru banget!"),
    };

    publikasikan(&artikel);
    publikasikan(&tweet);
    println!();
}



