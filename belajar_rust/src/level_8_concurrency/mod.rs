//! # Modul Level 8: Concurrency & Multithreading (Fearless Concurrency)

pub mod threads;
pub mod channels;
pub mod shared_state;
pub mod scoped_threads;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("  🧵 LEVEL 8: CONCURRENCY & MULTITHREADING                  ");
    println!("############################################################\n");

    threads::jalankan_demo();
    channels::jalankan_demo();
    shared_state::jalankan_demo();
    scoped_threads::jalankan_demo();
}
