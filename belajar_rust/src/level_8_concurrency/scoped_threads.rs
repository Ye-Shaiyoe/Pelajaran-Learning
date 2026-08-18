//! # Level 8.4: Scoped Threads (Modern Rust 1.63+)
//!
//! Konsep yang dipelajari:
//! 1. Keterbatasan `thread::spawn` yang memerlukan `'static` data
//! 2. `thread::scope` yang menjamin semua thread selesai sebelum keluar dari scope
//! 3. Meminjam data lokal stack (`&T` / `&mut T`) langsung di dalam thread tanpa `Arc`!

use std::thread;

pub fn jalankan_demo() {
    println!("=== 8.4 SCOPED THREADS (MEMINJAM DATA STACK TANPA ARC) ===");

    let mut angka = vec![1, 2, 3];
    let nama = "Rust Modern";

    // `thread::scope` memungkinkan thread meminjam `nama` dan memodifikasi `angka`
    // tanpa perlu Arc atau Mutex karena Rust menjamin thread selesai sebelum fungsi berakhir!
    thread::scope(|s| {
        // Thread 1 membaca `nama`
        s.spawn(|| {
            println!("   [Scoped Thread 1] Membaca &str lokal: {nama}");
        });

        // Thread 2 membaca `angka`
        s.spawn(|| {
            println!("   [Scoped Thread 2] Membaca Vector stack: {:?}", &angka);
        });
    });

    // Modifikasi setelah scoped thread selesai:
    angka.push(4);
    println!("Vector setelah scoped threads selesai: {:?}", angka);
    println!();
}
