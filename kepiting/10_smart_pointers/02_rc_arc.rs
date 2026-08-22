use std::rc::Rc;
use std::sync::Arc;
use std::thread;

fn main() {
    println!("=== 1. Rc<T> DI SINGLE THREAD ===");

    let data_bersama = Rc::new(String::from("Konfigurasi Aplikasi Global"));
    println!("Strong count awal: {}", Rc::strong_count(&data_bersama));

    {

        let ref_modul_a = Rc::clone(&data_bersama);
        println!("Strong count setelah Modul A clone: {}", Rc::strong_count(&data_bersama));
        println!("Modul A membaca: {ref_modul_a}");

        {
            let ref_modul_b = Rc::clone(&data_bersama);
            println!("Strong count setelah Modul B clone: {}", Rc::strong_count(&data_bersama));
            println!("Modul B membaca: {ref_modul_b}");
        }

        println!("Strong count setelah Modul B selesai: {}", Rc::strong_count(&data_bersama));
    }

    println!("Strong count akhir di scope main: {}", Rc::strong_count(&data_bersama));

    println!("\n=== 2. Arc<T> DI MULTI THREAD ===");
    let pesan_thread = Arc::new(String::from("Data dibagikan antar thread"));
    let mut handlers = vec![];

    for i in 1..=3 {
        let pesan_clone = Arc::clone(&pesan_thread);
        let handle = thread::spawn(move || {
            println!("  [Thread {}] Membaca Arc: '{}' (Current count: {})",
                i, pesan_clone, Arc::strong_count(&pesan_clone));
        });
        handlers.push(handle);
    }

    for h in handlers {
        h.join().unwrap();
    }
    println!("Semua thread selesai. Strong count Arc: {}", Arc::strong_count(&pesan_thread));
}
