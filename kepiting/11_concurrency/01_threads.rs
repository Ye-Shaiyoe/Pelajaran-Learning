use std::thread;
use std::time::Duration;

fn main() {
    println!("=== 1. MEMBUAT THREAD BARU DENGAN thread::spawn ===");

    let handle = thread::spawn(|| {
        for i in 1..=5 {
            println!("  [Spawned Thread] Langkah ke-{i}");
            thread::sleep(Duration::from_millis(50));
        }
        "Hasil komputasi dari background thread"
    });

    for i in 1..=3 {
        println!("[Main Thread] Sedang bekerja ke-{i}");
        thread::sleep(Duration::from_millis(60));
    }

    let hasil_thread = handle.join().unwrap();
    println!("Background thread selesai! Return: '{hasil_thread}'");

    println!("\n=== 2. MEMINDAHKAN DATA KE THREAD DENGAN 'move' ===");
    let list_pekerjaan = vec!["Analisis Data", "Generate PDF", "Kirim Email"];

    let handle2 = thread::spawn(move || {
        println!("Thread kedua memproses pekerjaan:");
        for job in &list_pekerjaan {
            println!("  -> Menjalankan: {job}");
        }
    });

    handle2.join().unwrap();
}
