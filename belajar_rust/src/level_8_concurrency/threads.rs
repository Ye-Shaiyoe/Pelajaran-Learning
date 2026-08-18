//! # Level 8.1: Threads & Fearless Concurrency Dasar
//!
//! Konsep yang dipelajari:
//! 1. Membuat thread baru dengan `std::thread::spawn`
//! 2. Menunggu thread selesai dengan `.join()`
//! 3. Mentransfer data ke thread dengan closure `move`

use std::thread;
use std::time::Duration;

pub fn jalankan_demo() {
    println!("=== 8.1 BASIC THREADS & JOIN HANDLES ===");

    // 1. Thread Sederhana
    let handle = thread::spawn(|| {
        for i in 1..=3 {
            println!("   [Background Thread] Langkah {i}");
            thread::sleep(Duration::from_millis(20));
        }
        "Hasil Perhitungan Thread Selesai"
    });

    for i in 1..=2 {
        println!("   [Main Thread] Langkah {i}");
        thread::sleep(Duration::from_millis(25));
    }

    // Menunggu thread latar belakang dan mengambil nilai kembaliannya
    let hasil = handle.join().unwrap();
    println!("Main thread menerima: \"{hasil}\"");

    // 2. Closure `move` pada Thread
    let data = vec![100, 200, 300];
    let thread_move = thread::spawn(move || {
        println!("   [Thread Move] Data yang dipindahkan: {:?}", data);
    });

    thread_move.join().unwrap();
    println!();
}
