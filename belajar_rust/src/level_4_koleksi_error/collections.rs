//! # Level 4.1: Koleksi Data Standar Rust (Collections)
//!
//! Konsep yang dipelajari:
//! 1. `Vec<T>` (Dynamic Array di Heap)
//! 2. `HashMap<K, V>` (Key-Value Store)
//! 3. `HashSet<T>` (Kumpulan data unik)
//! 4. `VecDeque<T>` (Double-ended queue / antrean dua arah)

use std::collections::{HashMap, HashSet, VecDeque};

pub fn jalankan_demo() {
    println!("=== 4.1 KOLEKSI DATA (VEC, HASHMAP, HASHSET, VECDEQUE) ===");

    // 1. Vector (Vec<T>)
    let mut angka = vec![10, 20, 30];
    angka.push(40);
    angka.push(50);
    println!("Vector awal: {:?}", angka);

    // Mengakses dengan get() aman dari Out of Bounds panic
    match angka.get(3) {
        Some(val) => println!("Elemen indeks 3: {val}"),
        None => println!("Indeks di luar batas!"),
    }

    // 2. HashMap (Key-Value)
    let mut nilai_siswa: HashMap<String, u32> = HashMap::new();
    nilai_siswa.insert(String::from("Akrom"), 98);
    nilai_siswa.insert(String::from("Budi"), 85);

    // entry API: masukkan nilai 90 hanya jika belum ada
    nilai_siswa.entry(String::from("Citra")).or_insert(90);
    nilai_siswa.entry(String::from("Akrom")).or_insert(100); // Tidak akan menimpa

    println!("Isi HashMap Siswa: {:?}", nilai_siswa);

    // 3. HashSet (Data Unik)
    let mut tag_artikel: HashSet<&str> = HashSet::new();
    tag_artikel.insert("rust");
    tag_artikel.insert("programming");
    tag_artikel.insert("rust"); // Duplikat otomatis diabaikan
    println!("HashSet Tag (Unik): {:?}", tag_artikel);

    // 4. VecDeque (Antrean / Queue)
    let mut antrean: VecDeque<&str> = VecDeque::new();
    antrean.push_back("Pelanggan A");
    antrean.push_back("Pelanggan B");
    antrean.push_front("VIP C"); // Masuk dari depan
    println!("VecDeque Queue: {:?}", antrean);
    println!("Melayani: {:?}", antrean.pop_front());
    println!();
}
