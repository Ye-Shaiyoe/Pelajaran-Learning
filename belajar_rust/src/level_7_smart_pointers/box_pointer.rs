//! # Level 7.1: `Box<T>` (Alokasi Heap & Tipe Rekursif)
//!
//! Konsep yang dipelajari:
//! 1. Apa itu `Box<T>` (Pointer tunggal yang menunjuk ke data di Heap)
//! 2. Mengatasi Tipe Rekursif (Struktur data berukuran tak terhingga jika di-inline)
//! 3. Contoh Implementasi Singly-Linked List sederhana (Cons List)

#[derive(Debug)]
pub enum List<T> {
    Cons(T, Box<List<T>>),
    Nil,
}

pub fn jalankan_demo() {
    println!("=== 7.1 BOX<T> (HEAP POINTER & RECURSIVE DATA STRUCTURES) ===");

    // 1. Alokasi nilai sederhana di heap
    let angka_heap = Box::new(42);
    println!("Nilai di Heap via Box: {angka_heap} (Dereferencing: {})", *angka_heap);

    // 2. Recursive Cons List: 1 -> 2 -> 3 -> Nil
    let daftar = List::Cons(
        1,
        Box::new(List::Cons(
            2,
            Box::new(List::Cons(3, Box::new(List::Nil))),
        )),
    );

    println!("Linked List dibuat dengan Box: {:?}", daftar);
    println!();
}
