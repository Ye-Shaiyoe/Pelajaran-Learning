use std::sync::{Arc, Mutex};
use std::thread;

fn main() {
    println!("=== 1. DASAR PENGGUNAAN MUTEX DI SINGLE THREAD ===");
    let m = Mutex::new(10);
    {

        let mut num = m.lock().unwrap();
        *num += 5;
    }

    println!("Nilai Mutex setelah lock dilepas: {:?}", m);

    println!("\n=== 2. MENGHITUNG BERSAMA DI 10 THREAD PARALEL ===");

    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];

    for id in 1..=10 {
        let counter_clone = Arc::clone(&counter);
        let handle = thread::spawn(move || {

            let mut num = counter_clone.lock().unwrap();
            *num += 1;
            println!("  [Thread {:02}] Mengubah counter menjadi: {}", id, *num);
        });
        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap();
    }

    println!("\nNilai akhir counter yang dihitung bersama: {}", *counter.lock().unwrap());
    assert_eq!(*counter.lock().unwrap(), 10);
}
