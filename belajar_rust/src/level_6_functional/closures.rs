//! # Level 6.1: Closures (Anonymous Functions & Environment Capturing)
//!
//! Konsep yang dipelajari:
//! 1. Sintaks Closure (`|x| x + 1`)
//! 2. Tiga Trait Closure: `Fn`, `FnMut`, `FnOnce`
//! 3. Kata Kunci `move` pada Closure (Transfer ownership environment)

pub fn jalankan_demo() {
    println!("=== 6.1 CLOSURES (ANONYMOUS FUNCTIONS) ===");

    // 1. Sintaks dasar closure
    let tambah_satu = |x: i32| x + 1;
    println!("tambah_satu(10) = {}", tambah_satu(10));

    // 2. Closure meminjam variabel dari luar (Fn - Immutable Borrow)
    let teks = String::from("Rust");
    let cetak_teks = || println!("   Closure membaca: {teks}");
    cetak_teks();

    // 3. Closure memodifikasi variabel luar (FnMut - Mutable Borrow)
    let mut total = 0;
    let mut akumulasi = |angka: i32| {
        total += angka;
    };
    akumulasi(10);
    akumulasi(25);
    println!("Total setelah akumulasi via FnMut: {total}");

    // 4. Closure dengan `move` (FnOnce - Mengambil ownership)
    let data_heap = vec![1, 2, 3];
    let konsumsi = move || {
        println!("   Closure memindahkan data heap: {:?}", data_heap);
        // data_heap keluar dari scope di sini dan di-drop
    };
    konsumsi();
    // println!("{:?}", data_heap); // ERROR: data_heap sudah di-move ke closure!
    println!();
}
