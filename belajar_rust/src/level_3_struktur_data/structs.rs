//! # Level 3.1: Structs & Methods (Struktur Data Kustom)
//!
//! Konsep yang dipelajari:
//! 1. Classic Struct dengan field bernama
//! 2. Tuple Struct
//! 3. Unit-like Struct
//! 4. Implementasi Method (`&self`, `&mut self`)
//! 5. Associated Functions (Constructor pattern `Self::new`)

#[derive(Debug, Clone)]
pub struct Pengguna {
    pub username: String,
    pub email: String,
    pub jumlah_login: u64,
    pub aktif: bool,
}

impl Pengguna {
    /// Associated function / Constructor (tidak ada parameter self)
    pub fn baru(username: &str, email: &str) -> Self {
        Self {
            username: String::from(username),
            email: String::from(email),
            jumlah_login: 1,
            aktif: true,
        }
    }

    /// Method dengan peminjaman immutable (&self)
    pub fn perkenalkan(&self) {
        println!("   [Pengguna] Halo, saya @{} ({})", self.username, self.email);
    }

    /// Method dengan peminjaman mutable (&mut self)
    pub fn catat_login(&mut self) {
        self.jumlah_login += 1;
        println!("   [Pengguna] {} login. Total login: {}", self.username, self.jumlah_login);
    }
}

// Tuple Struct (tanpa nama field, hanya urutan tipe data)
#[derive(Debug)]
pub struct Warna(pub u8, pub u8, pub u8); // RGB

// Unit-like Struct (tanpa field sama sekali, berguna untuk state / trait marker)
#[derive(Debug)]
pub struct MarkerLogger;

pub fn jalankan_demo() {
    println!("=== 3.1 STRUCTS & IMPLEMENTASI METHOD ===");

    // 1. Membuat struct via constructor
    let mut user1 = Pengguna::baru("akrom_dev", "akrom@example.com");
    user1.perkenalkan();
    user1.catat_login();

    // 2. Struct Update Syntax
    let user2 = Pengguna {
        username: String::from("budi_rust"),
        email: String::from("budi@example.com"),
        ..user1.clone() // Mengambil field lain dari user1
    };
    println!("User 2 dibuat via struct update syntax: {:?}", user2);

    // 3. Tuple Struct
    let hitam = Warna(0, 0, 0);
    println!("Tuple Struct Warna RGB: ({}, {}, {})", hitam.0, hitam.1, hitam.2);

    // 4. Unit Struct
    let _marker = MarkerLogger;
    println!("Unit Struct siap digunakan!");
    println!();
}
