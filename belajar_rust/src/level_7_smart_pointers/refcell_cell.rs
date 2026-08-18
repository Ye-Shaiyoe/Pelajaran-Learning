//! # Level 7.3: `RefCell<T>` & Interior Mutability Pattern
//!
//! Konsep yang dipelajari:
//! 1. Interior Mutability (Mengubah data meskipun variabelnya immutable)
//! 2. Compile-time Borrow Check vs Runtime Borrow Check (`.borrow()`, `.borrow_mut()`)
//! 3. Kombinasi maut: `Rc<RefCell<T>>` (Multiple Ownership + Mutabilitas)

use std::cell::RefCell;
use std::rc::Rc;

pub fn jalankan_demo() {
    println!("=== 7.3 REFCELL<T> & INTERIOR MUTABILITY ===");

    // 1. RefCell dasar
    let data_terkunci = RefCell::new(100);

    {
        let mut pinjaman_ubah = data_terkunci.borrow_mut();
        *pinjaman_ubah += 50;
    } // pinjaman_ubah keluar dari scope di sini!

    println!("Nilai RefCell setelah diubah: {}", *data_terkunci.borrow());

    // 2. Rc<RefCell<T>>: Memungkinkan banyak pemilik mengubah data yang sama!
    let daftar_bersama = Rc::new(RefCell::new(vec!["Item A"]));

    let client1 = Rc::clone(&daftar_bersama);
    let client2 = Rc::clone(&daftar_bersama);

    client1.borrow_mut().push("Item B (ditambah Client 1)");
    client2.borrow_mut().push("Item C (ditambah Client 2)");

    println!("Isi akhir Rc<RefCell<Vec>>: {:?}", daftar_bersama.borrow());
    println!();
}
