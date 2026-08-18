//! # Level 5.3: Trait Objects & Dynamic Dispatch (`dyn Trait`)
//!
//! Konsep yang dipelajari:
//! 1. Static Dispatch (Generics, di-inline saat compile-time)
//! 2. Dynamic Dispatch (`Box<dyn Trait>`, runtime vtable lookup)
//! 3. Polimorfisme sejati seperti OOP (Heterogeneous collection)

pub trait GambarBentuk {
    fn gambar(&self);
    fn luas(&self) -> f64;
}

pub struct Persegi {
    pub sisi: f64,
}

impl GambarBentuk for Persegi {
    fn gambar(&self) {
        println!("   Menggambar Persegi (sisi = {})", self.sisi);
    }
    fn luas(&self) -> f64 {
        self.sisi * self.sisi
    }
}

pub struct Lingkaran {
    pub radius: f64,
}

impl GambarBentuk for Lingkaran {
    fn gambar(&self) {
        println!("   Menggambar Lingkaran (radius = {})", self.radius);
    }
    fn luas(&self) -> f64 {
        std::f64::consts::PI * self.radius * self.radius
    }
}

pub fn jalankan_demo() {
    println!("=== 5.3 DYNAMIC DISPATCH & TRAIT OBJECTS (dyn Trait) ===");

    // Vector berisi berbagai bentuk berbeda menggunakan Trait Object `Box<dyn GambarBentuk>`
    let daftar_bentuk: Vec<Box<dyn GambarBentuk>> = vec![
        Box::new(Persegi { sisi: 10.0 }),
        Box::new(Lingkaran { radius: 5.0 }),
        Box::new(Persegi { sisi: 4.0 }),
    ];

    let mut total_luas = 0.0;
    for bentuk in &daftar_bentuk {
        bentuk.gambar();
        let l = bentuk.luas();
        println!("   -> Luas: {l:.2}");
        total_luas += l;
    }

    println!("Total Luas Seluruh Bentuk Polimorfik: {total_luas:.2}");
    println!();
}
