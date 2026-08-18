//! # Level 1.3: Control Flow (Percabangan & Perulangan)
//!
//! Konsep yang dipelajari:
//! 1. `if` - `else if` - `else`
//! 2. `if` sebagai ekspresi (ternary operator ala Rust)
//! 3. `loop` tanpa henti dengan `break value`
//! 4. `while` loop
//! 5. `for in` loop dan Range (`..` dan `..=`)
//! 6. Loop label (`'label: loop`)

pub fn jalankan_demo() {
    println!("=== 1.3 CONTROL FLOW (PERCABANGAN & PERULANGAN) ===");

    // 1. `if` sebagai ekspresi
    let nilai = 82;
    let predikat = if nilai >= 85 {
        "A"
    } else if nilai >= 75 {
        "B"
    } else {
        "C"
    };
    println!("Nilai: {nilai}, Predikat: {predikat}");

    // 2. `loop` mengembalikan nilai via `break`
    let mut hitungan = 0;
    let hasil_loop = loop {
        hitungan += 1;
        if hitungan == 5 {
            break hitungan * 10; // Mengembalikan 50
        }
    };
    println!("Hasil dari loop break: {hasil_loop}");

    // 3. `while` loop
    let mut sisa_waktu = 3;
    print!("Hitung mundur: ");
    while sisa_waktu > 0 {
        print!("{sisa_waktu}... ");
        sisa_waktu -= 1;
    }
    println!("Selesai!");

    // 4. `for in` dengan Range
    print!("For in 1..=5: ");
    for angka in 1..=5 {
        print!("{angka} ");
    }
    println!();

    // 5. Loop label untuk keluar dari nested loop
    let mut total_iterasi = 0;
    'outer: for i in 1..=3 {
        for j in 1..=3 {
            total_iterasi += 1;
            if i == 2 && j == 2 {
                println!("Keluar dari 'outer loop saat i={i}, j={j}");
                break 'outer;
            }
        }
    }
    println!("Total iterasi sebelum break 'outer: {total_iterasi}");
    println!();
}
