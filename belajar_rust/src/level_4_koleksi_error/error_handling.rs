//! # Level 4.3: Error Handling (panic! vs Result<T, E> & Operator ?)
//!
//! Konsep yang dipelajari:
//! 1. Unrecoverable Errors (`panic!`)
//! 2. Recoverable Errors (`Result<T, E>`)
//! 3. Operator `?` untuk propagasi error ringkas
//! 4. Membuat Custom Error Enum dengan std::fmt::Display & std::error::Error

use std::fmt;

#[derive(Debug)]
pub enum KalkulasiError {
    BagiDenganNol,
    AkarNegatif,
}

impl fmt::Display for KalkulasiError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            KalkulasiError::BagiDenganNol => write!(f, "Kesalahan Matematika: Tidak bisa membagi dengan 0"),
            KalkulasiError::AkarNegatif => write!(f, "Kesalahan Matematika: Tidak bisa menghitung akar bilangan negatif"),
        }
    }
}

impl std::error::Error for KalkulasiError {}

pub fn bagi(a: f64, b: f64) -> Result<f64, KalkulasiError> {
    if b == 0.0 {
        Err(KalkulasiError::BagiDenganNol)
    } else {
        Ok(a / b)
    }
}

pub fn akar_kuadrat(x: f64) -> Result<f64, KalkulasiError> {
    if x < 0.0 {
        Err(KalkulasiError::AkarNegatif)
    } else {
        Ok(x.sqrt())
    }
}

/// Fungsi yang menggunakan operator '?' untuk merangkai operasi berisiko error
pub fn operasi_kompleks(a: f64, b: f64) -> Result<f64, KalkulasiError> {
    let hasil_bagi = bagi(a, b)?; // Jika error, langsung return Err dan keluar dari fungsi!
    let hasil_akar = akar_kuadrat(hasil_bagi)?;
    Ok(hasil_akar)
}

pub fn jalankan_demo() {
    println!("=== 4.3 ERROR HANDLING (RESULT<T, E> & OPERATOR ?) ===");

    // 1. Kasus Sukses
    match operasi_kompleks(100.0, 4.0) {
        Ok(val) => println!("sqrt(100 / 4) = {val}"),
        Err(e) => println!("Terjadi error: {e}"),
    }

    // 2. Kasus Pembagian Nol
    match operasi_kompleks(10.0, 0.0) {
        Ok(val) => println!("Hasil: {val}"),
        Err(e) => println!("Berhasil menangkap error pembagian: {e}"),
    }

    // 3. Kasus Akar Bilangan Negatif
    match operasi_kompleks(-16.0, 1.0) {
        Ok(val) => println!("Hasil: {val}"),
        Err(e) => println!("Berhasil menangkap error akar negatif: {e}"),
    }
    println!();
}
