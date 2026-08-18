//! # Level 8.2: Channels (Message Passing Concurrency)
//!
//! Konsep yang dipelajari:
//! 1. Filosofi: "Do not communicate by sharing memory; instead, share memory by communicating."
//! 2. MPSC Channel: Multi-Producer, Single-Consumer (`mpsc::channel`)
//! 3. Mengirim data (`tx.send()`) dan Menerima data (`rx.recv()` / iterasi)

use std::sync::mpsc;
use std::thread;
use std::time::Duration;

pub fn jalankan_demo() {
    println!("=== 8.2 MPSC CHANNELS (MESSAGE PASSING) ===");

    let (tx, rx) = mpsc::channel();

    // Membuat Producer 1
    let tx1 = tx.clone();
    thread::spawn(move || {
        let pesan = vec!["Halo", "dari", "Worker 1"];
        for p in pesan {
            tx1.send(String::from(p)).unwrap();
            thread::sleep(Duration::from_millis(30));
        }
    });

    // Membuat Producer 2
    thread::spawn(move || {
        let pesan = vec!["Data", "dari", "Worker 2"];
        for p in pesan {
            tx.send(String::from(p)).unwrap();
            thread::sleep(Duration::from_millis(20));
        }
    });

    // Consumer menerima pesan dari kedua producer
    println!("Main thread mendengarkan channel:");
    for pesan_masuk in rx {
        println!("   -> Menerima: \"{pesan_masuk}\"");
    }
    println!("Channel ditutup otomatis setelah semua sender selesai.");
    println!();
}
