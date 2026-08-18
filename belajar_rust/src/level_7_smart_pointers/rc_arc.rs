//! # Level 7.2: `Rc<T>` & `Arc<T>` (Reference Counting Pointers)
//!
//! Konsep yang dipelajari:
//! 1. `Rc<T>` (Reference Counted) untuk Single-threaded Multiple Ownership
//! 2. Mengapa `.clone()` pada `Rc` murah (Hanya menaikkan counter integer)
//! 3. `Arc<T>` (Atomic Reference Counted) untuk Multi-threaded Shared Ownership

use std::rc::Rc;
use std::sync::Arc;
use std::thread;

pub fn jalankan_demo() {
    println!("=== 7.2 RC<T> & ARC<T> (SHARED OWNERSHIP) ===");

    // 1. Rc<T> di Single-thread
    let data_bersama = Rc::new(String::from("Konfigurasi Aplikasi"));
    println!("Rc Count Awal: {}", Rc::strong_count(&data_bersama));

    let pemegang1 = Rc::clone(&data_bersama);
    let pemegang2 = Rc::clone(&data_bersama);
    println!("Rc Count setelah di-clone 2x: {}", Rc::strong_count(&data_bersama));

    drop(pemegang1);
    println!("Rc Count setelah pemegang1 di-drop: {}", Rc::strong_count(&data_bersama));
    println!("Data tetap ada: \"{pemegang2}\"");

    // 2. Arc<T> untuk Multi-thread
    let data_thread = Arc::new(vec![10, 20, 30]);
    let mut handles = vec![];

    for id in 1..=3 {
        let clone_data = Arc::clone(&data_thread);
        let handle = thread::spawn(move || {
            println!("   [Thread {id}] Membaca Arc Data: {:?}", clone_data);
        });
        handles.push(handle);
    }

    for h in handles {
        h.join().unwrap();
    }
    println!("Semua thread selesai membaca Arc!");
    println!();
}
