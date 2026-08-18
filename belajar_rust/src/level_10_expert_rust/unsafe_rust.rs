//! # Level 10.2: Unsafe Rust & Raw Pointers
//!
//! Konsep yang dipelajari:
//! 1. 5 Kekuatan Super Unsafe Rust:
//!    - Dereferencing Raw Pointers (`*const T`, `*mut T`)
//!    - Memanggil fungsi unsafe
//!    - Mengakses mutable static variable
//!    - Mengimplementasikan unsafe trait
//!    - Mengakses union fields
//! 2. Konsep FFI (Foreign Function Interface) dengan pustaka bahasa C (contoh `abs`)

extern "C" {
    // Memanggil fungsi pustaka standar C `abs`
    fn abs(input: i32) -> i32;
}

pub fn jalankan_demo() {
    println!("=== 10.2 UNSAFE RUST & RAW POINTERS ===");

    let mut nilai = 42;

    // 1. Membuat Raw Pointer (Aman dilakukan di Safe Rust)
    let r1: *const i32 = &nilai;
    let r2: *mut i32 = &mut nilai;

    // 2. Dereferencing Raw Pointer (HARUS di dalam blok `unsafe`)
    unsafe {
        println!("Membaca raw pointer r1: {}", *r1);
        *r2 = 99; // Mengubah data lewat raw pointer
        println!("Nilai setelah diubah lewat raw pointer r2: {}", *r2);
    }
    println!("Nilai di Safe Rust sekarang: {nilai}");

    // 3. FFI (Foreign Function Interface) memanggil C
    unsafe {
        let hasil_c = abs(-55);
        println!("Hasil memanggil C 'abs(-55)': {hasil_c}");
    }
    println!();
}
