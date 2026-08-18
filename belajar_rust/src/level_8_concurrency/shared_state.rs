//! # Level 8.3: Shared-State Concurrency (`Arc<Mutex<T>>` & `RwLock<T>`)
//!
//! Konsep yang dipelajari:
//! 1. Mutex (Mutual Exclusion) untuk perlindungan data race
//! 2. `Arc<Mutex<T>>` pola standar multi-thread mutable state
//! 3. `RwLock<T>` (Banyak Reader, Satu Writer)

use std::sync::{Arc, Mutex, RwLock};
use std::thread;

pub fn jalankan_demo() {
    println!("=== 8.3 SHARED STATE (ARC<MUTEX<T>> & RWLOCK<T>) ===");

    // 1. Mutex Counter antar 5 Thread
    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];

    for _ in 0..5 {
        let counter_clone = Arc::clone(&counter);
        let handle = thread::spawn(move || {
            let mut num = counter_clone.lock().unwrap(); // Mengunci Mutex
            *num += 1;
        }); // Lock dilepaskan otomatis saat `num` keluar scope
        handles.push(handle);
    }

    for h in handles {
        h.join().unwrap();
    }
    println!("Hasil akhir Mutex Counter (5 threads): {}", *counter.lock().unwrap());

    // 2. RwLock (Read-Heavy workload)
    let konfigurasi = Arc::new(RwLock::new(String::from("v1.0.0")));

    // Baca bersamaan
    {
        let r1 = konfigurasi.read().unwrap();
        let r2 = konfigurasi.read().unwrap();
        println!("Membaca RwLock secara paralel: r1='{}', r2='{}'", *r1, *r2);
    }

    // Tulis secara eksklusif
    {
        let mut w = konfigurasi.write().unwrap();
        *w = String::from("v2.0.0");
        println!("Menulis ke RwLock: Versi baru='{}'", *w);
    }
    println!();
}
