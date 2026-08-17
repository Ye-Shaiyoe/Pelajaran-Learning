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
    println!("=== 1.1 SINTAKS DASAR & VARIABEL ===");

    // 1. Immutability by default
    let x = 5;
    println!("Nilai x: {x}");
    // x = 6; // Compile error: cannot assign twice to immutable variable

    // 2. Mutabilitas
    let mut y = 10;
    y = 15;
    println!("Nilai y (mutable): {y}");

    // 3. Konstanta (harus dengan tipe eksplisit, nama pakai SCREAMING_SNAKE_CASE)
    println!("Nilai Konstanta: {MAX_POINTS}");

    // 4. Shadowing
    let x = x + 1;
    {
        let x = x * 2;
        println!("Nilai x di dalam scope baru: {x}"); // 12
    }
    println!("Nilai x di luar scope: {x}"); // 6

    // 5. Tipe Data Skalar
    // Integer
    let i8_val: i8 = -128;
    let u32_val: u32 = 4_294_967_295;

    // Float
    let f64_val: f64 = 3.141592653589793;

    // Boolean
    let is_active: bool = true;

    // Char
    let grade: char = 'A';
    let emoji: char = '🚀';

    // 6. Tipe Data Majemuk
    // Tuple
    let user_profile: (String, u32, bool) = ("Budi".to_string(), 25, true);
    let (nama, umur, status) = user_profile;
    println!("Profile User: Nama={nama}, Umur={umur}, Aktif={status}");

    // Array (ukuran harus diketahui saat compile, elemen harus tipe sama)
    let scores: [i32; 5] = [85, 92, 78, 95, 88];
    let first_score = scores[0];
    println!("First Score: {first_score}");

    println!(); // Baris kosong
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_const() {
        assert_eq!(MAX_POINTS, 100_000);
    }

    #[test]
    fn test_shadowing() {
        let x = 5;
        let x = x + 1;
        assert_eq!(x, 6);
    }
}
