use std::collections::HashMap;

fn main() {
    println!("=== 1. INISIALISASI & INSERT DATA ===");
    let mut skor_tim: HashMap<String, i32> = HashMap::new();

    skor_tim.insert(String::from("Garuda"), 85);
    skor_tim.insert(String::from("Rajawali"), 92);
    skor_tim.insert(String::from("Elang"), 78);

    println!("Data Tim: {:?}", skor_tim);

    println!("\n=== 2. MENGAMBIL NILAI DENGAN .get() ===");
    let nama_tim = String::from("Rajawali");
    match skor_tim.get(&nama_tim) {
        Some(&skor) => println!("Skor tim {nama_tim}: {skor}"),
        None => println!("Tim {nama_tim} tidak ditemukan"),
    }

    println!("\n=== 3. ENTRY API: INSERT JIKA BELUM ADA (or_insert) ===");

    skor_tim.entry(String::from("Kancil")).or_insert(50);
    skor_tim.entry(String::from("Garuda")).or_insert(100);

    println!("Setelah entry API: {:?}", skor_tim);

    println!("\n=== 4. APLIKASI PRAKTIS: PENGHITUNG FREKUENSI KATA ===");
    let teks = "rust adalah bahasa yang cepat dan rust adalah bahasa yang aman";
    let mut frekuensi_kata: HashMap<&str, u32> = HashMap::new();

    for kata in teks.split_whitespace() {
        let count = frekuensi_kata.entry(kata).or_insert(0);
        *count += 1;
    }

    println!("Frekuensi kemunculan setiap kata dalam kalimat:");
    for (kata, jumlah) in &frekuensi_kata {
        println!("  - '{kata}' muncul sebanyak {jumlah} kali");
    }
}
