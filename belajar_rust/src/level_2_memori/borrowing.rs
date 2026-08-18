//! # Level 2.2: References & Borrowing (Peminjaman Data)
//!
//! Konsep yang dipelajari:
//! 1. Immutable Reference (`&T`)
//! 2. Mutable Reference (`&mut T`)
//! 3. Aturan Borrowing:
//!    - Boleh banyak `&T` sekaligus (Read-only)
//!    - ATAU HANYA SATU `&mut T` dalam satu waktu (Read-write)
//! 4. Pencegahan Data Race & Dangling References

pub fn jalankan_demo() {
    println!("=== 2.2 BORROWING & REFERENCES ===");

    // 1. Immutable Borrowing (&T)
    let s1 = String::from("Rustacean");
    let panjang = hitung_panjang(&s1); // Meminjam s1 tanpa memindahkan ownership
    println!("String \"{s1}\" memiliki panjang {panjang} karakter (s1 tetap valid)");

    // 2. Mutable Borrowing (&mut T)
    let mut pesan = String::from("Selamat");
    tambahkan_kata(&mut pesan);
    println!("Pesan setelah modifikasi via &mut: \"{pesan}\"");

    // 3. Aturan Referensi: Multiple Immutable Boleh
    let mut data = String::from("Data Rahasia");
    let r1 = &data;
    let r2 = &data;
    println!("Multiple read: r1 = \"{r1}\", r2 = \"{r2}\"");
    // Scope r1 dan r2 berakhir di sini (Non-Lexical Lifetimes - NLL)

    // 4. Setelah read selesai, baru boleh mutable borrow:
    let r3 = &mut data;
    r3.push_str(" (Terbaca)");
    println!("Single write: r3 = \"{r3}\"");
    println!();
}

fn hitung_panjang(s: &String) -> usize {
    s.len()
} // s keluar dari scope, tapi data String tidak di-drop karena hanya meminjam!

fn tambahkan_kata(s: &mut String) {
    s.push_str(" Belajar Rust!");
}
