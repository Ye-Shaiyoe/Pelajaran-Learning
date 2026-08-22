use std::sync::mpsc;
use std::thread;
use std::time::Duration;

fn main() {
    println!("=== 1. KOMUNIKASI SATU PENGIRIM KE SATU PENERIMA ===");

    let (tx, rx) = mpsc::channel();

    thread::spawn(move || {
        let pesan = String::from("Halo dari Producer!");
        thread::sleep(Duration::from_millis(100));

        tx.send(pesan).unwrap();
    });

    let pesan_diterima = rx.recv().unwrap();
    println!("Main thread menerima: '{pesan_diterima}'");

    println!("\n=== 2. MULTIPLE PRODUCERS (BANYAK PENGIRIM PESAN) ===");
    let (tx_multi, rx_multi) = mpsc::channel();

    let tx1 = tx_multi.clone();
    thread::spawn(move || {
        let daftar = vec!["Pesan 1A", "Pesan 1B", "Pesan 1C"];
        for item in daftar {
            tx1.send(format!("[Worker 1] {}", item)).unwrap();
            thread::sleep(Duration::from_millis(50));
        }
    });

    thread::spawn(move || {
        let daftar = vec!["Pesan 2A", "Pesan 2B", "Pesan 2C"];
        for item in daftar {
            tx_multi.send(format!("[Worker 2] {}", item)).unwrap();
            thread::sleep(Duration::from_millis(50));
        }
    });

    println!("Menerima seluruh pesan dari semua Worker:");
    for pesan in rx_multi {
        println!("  -> {pesan}");
    }
}
