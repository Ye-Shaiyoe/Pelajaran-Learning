//! # Level 2.1: Ownership (Kepemilikan Memori di Rust)
//!
//! Konsep yang dipelajari:
//! 1. 3 Aturan Emas Ownership
//! 2. Stack vs Heap
//! 3. Move Semantics (Tipe data Heap seperti `String`)
//! 4. Copy Trait (Tipe data Stack seperti `i32`, `bool`)
//! 5. Clone (Deep Copy)

pub fn jalankan_demo() {
    println!("=== 2.1 ATURAN OWNERSHIP & MOVE SEMANTICS ===");

    // 1. Copy Semantics (Stack Only)
    // Tipe data dengan ukuran pasti di Stack mengimplementasikan trait `Copy`
    let a = 42;
    let b = a; // Nilai `a` disalin (bit-level copy)
    println!("Copy: a = {a}, b = {b} (keduanya valid)");

    // 2. Move Semantics (Heap Allocated)
    // String dialokasikan di Heap.
    let s1 = String::from("Halo Rust");
    let s2 = s1; // OWNERSHIP BERPINDAH (MOVE) dari s1 ke s2!
    // println!("{}", s1); // COMPILE ERROR: value borrowed here after move!
    println!("Move: s2 = \"{s2}\" (s1 sudah tidak valid/invalidated)");

    // 3. Clone (Deep Copy di Heap)
    let s3 = s2.clone(); // Mengalokasikan memori baru di heap dan menyalin isinya
    println!("Clone: s2 = \"{s2}\", s3 = \"{s3}\" (keduanya valid)");

    // 4. Ownership saat Passing ke Fungsi
    let teks = String::from("Kepemilikan ditransfer");
    ambil_ownership(teks);
    // println!("{}", teks); // ERROR: teks sudah di-move ke dalam fungsi!

    let teks_kembali = ambil_dan_kembalikan(String::from("Nilai dikembalikan"));
    println!("Ownership kembali ke pemanggil: \"{teks_kembali}\"");
    println!();
}

fn ambil_ownership(s: String) {
    println!("   [ambil_ownership] Menerima \"{s}\". Di akhir fungsi ini, memori s akan di-DROP!");
}

fn ambil_dan_kembalikan(s: String) -> String {
    println!("   [ambil_dan_kembalikan] Menerima \"{s}\" dan mengembalikannya.");
    s
}
