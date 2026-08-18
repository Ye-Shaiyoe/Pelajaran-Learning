//! # Modul Level 2: Manajemen Memori & Ownership
//!
//! Inti kekuatan sistem keamanan Rust tanpa Garbage Collector.

pub mod ownership;
pub mod borrowing;
pub mod slices;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("  🧠 LEVEL 2: MANAJEMEN MEMORI, OWNERSHIP & BORROWING       ");
    println!("############################################################\n");

    ownership::jalankan_demo();
    borrowing::jalankan_demo();
    slices::jalankan_demo();
}
