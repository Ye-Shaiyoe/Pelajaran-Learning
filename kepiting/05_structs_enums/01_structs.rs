#[derive(Debug)]
struct Mahasiswa {
    nama: String,
    jurusan: String,
    nim: u32,
    ipk: f32,
    aktif: bool,
}

impl Mahasiswa {

    fn baru(nama: &str, jurusan: &str, nim: u32, ipk: f32) -> Self {
        Self {
            nama: nama.to_string(),
            jurusan: jurusan.to_string(),
            nim,
            ipk,
            aktif: true,
        }
    }

    fn cetak_profil(&self) {
        println!("--- Profil Mahasiswa ---");
        println!("Nama    : {}", self.nama);
        println!("Jurusan : {}", self.jurusan);
        println!("NIM     : {}", self.nim);
        println!("IPK     : {:.2}", self.ipk);
        println!("Status  : {}", if self.aktif { "Aktif" } else { "Cuti" });
    }

    fn update_ipk(&mut self, ipk_baru: f32) {
        self.ipk = ipk_baru;
    }
}

#[derive(Debug)]
struct WarnaRgb(u8, u8, u8);

#[derive(Debug)]
struct Titik2D(f64, f64);

#[derive(Debug)]
struct LoggerSistem;

fn main() {
    println!("=== 1. MEMBUAT & MENGGUNAKAN STRUCT ===");
    let mut mhs1 = Mahasiswa::baru("Budi Santoso", "Informatika", 2026001, 3.75);

    mhs1.cetak_profil();

    println!("\nUpdate IPK Mahasiswa:");
    mhs1.update_ipk(3.90);
    mhs1.cetak_profil();

    println!("\n=== 2. TUPLE STRUCTS ===");
    let merah = WarnaRgb(255, 0, 0);
    let koordinat = Titik2D(12.5, -45.0);

    println!("Warna RGB: Merah={}, Hijau={}, Biru={}", merah.0, merah.1, merah.2);
    println!("Titik 2D : ({}, {})", koordinat.0, koordinat.1);

    println!("\n=== 3. STRUCT UPDATE SYNTAX ===");

    let mhs2 = Mahasiswa {
        nama: String::from("Siti Rahma"),
        nim: 2026002,
        ..mhs1
    };
    println!("Data Mahasiswa 2: {:?}", mhs2);

    println!("\n=== 4. UNIT-LIKE STRUCT ===");
    let _logger = LoggerSistem;
    println!("Unit-like struct berhasil dibuat: {:?}", _logger);
}
