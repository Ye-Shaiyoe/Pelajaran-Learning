//! # Level 1.2: Fungsi, Parameter, & Return Value
//!
//! Konsep yang dipelajari:
//! 1. Deklarasi fungsi (`fn`)
//! 2. Parameter dengan tipe eksplisit
//! 3. Statements vs Expressions
//! 4. Implicit Return (tanpa tanda titik koma)
//! 5. Explicit Return (`return`)

/// Fungsi dengan parameter dan return value eksplisit
pub fn tambah(a: i32, b: i32) -> i32 {
    // Di Rust, baris terakhir tanpa ';' adalah EKSPRESI yang mengembalikan nilai
    a + b
}

/// Fungsi dengan early return
pub fn cek_kelulusan(nilai: u32) -> &'static str {
    if nilai >= 75 {
        return "Lulus dengan Baik";
    }
    "Perlu Perbaikan"
}

/// Fungsi yang mendemonstrasikan blok ekspresi
pub fn hitung_lingkaran(radius: f64) -> (f64, f64) {
    let pi = std::f64::consts::PI;

    // Blok kode di Rust adalah ekspresi yang menghasilkan nilai
    let luas = {
        let r_kuadrat = radius * radius;
        pi * r_kuadrat // Mengembalikan nilai ke variabel `luas`
    };

    let keliling = 2.0 * pi * radius;

    (luas, keliling) // Mengembalikan tuple
}

pub fn jalankan_demo() {
    println!("=== 1.2 FUNGSI & RETURN VALUE ===");

    let hasil_tambah = tambah(15, 35);
    println!("Hasil tambah(15, 35) = {hasil_tambah}");

    let status = cek_kelulusan(88);
    println!("Status nilai 88: {status}");

    let (luas, keliling) = hitung_lingkaran(7.0);
    println!("Lingkaran r=7 -> Luas: {luas:.2}, Keliling: {keliling:.2}");
    println!();
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_tambah() {
        assert_eq!(tambah(10, 20), 30);
    }

    #[test]
    fn test_kelulusan() {
        assert_eq!(cek_kelulusan(80), "Lulus dengan Baik");
        assert_eq!(cek_kelulusan(60), "Perlu Perbaikan");
    }
}
