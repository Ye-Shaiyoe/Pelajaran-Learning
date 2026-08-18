//! # Level 3.3: Advanced Pattern Matching
//!
//! Konsep yang dipelajari:
//! 1. `match` dengan exhaustiveness checking
//! 2. Match Guards (`if` condition dalam arm)
//! 3. `if let` syntax (shorthand untuk 1 varian)
//! 4. `while let` syntax (loop selama pola cocok)
//! 5. Binding pattern dengan `@` operator

pub fn jalankan_demo() {
    println!("=== 3.3 PATTERN MATCHING ADVANCED ===");

    // 1. Match dengan Range dan Guard
    let usia = 19;
    let kategori = match usia {
        0..=12 => "Anak-anak",
        13..=17 => "Remaja",
        18..=59 if usia == 18 || usia == 19 => "Dewasa Pemula (Guard Aktif)",
        18..=59 => "Dewasa",
        _ => "Lansia",
    };
    println!("Usia {usia} tahun masuk kategori: {kategori}");

    // 2. `if let` (Shorthand yang sangat populer di Rust)
    let koin: Option<&str> = Some("Emas Murni");
    if let Some(nama_koin) = koin {
        println!("Koin ditemukan via 'if let': {nama_koin}");
    }

    // 3. `while let` (Menghabiskan isi stack/vector)
    let mut antrean = vec!["Task 1", "Task 2", "Task 3"];
    print!("Memproses antrean dengan while let: ");
    while let Some(tugas) = antrean.pop() {
        print!("[{tugas}] ");
    }
    println!();

    // 4. Operator @ (Binding value sambil mencocokkan range)
    let pesan_id = 7;
    match pesan_id {
        id @ 1..=5 => println!("Pesan prioritas tinggi dengan ID: {id}"),
        id @ 6..=10 => println!("Pesan prioritas sedang dengan ID: {id}"),
        _ => println!("Pesan umum."),
    }
    println!();
}
