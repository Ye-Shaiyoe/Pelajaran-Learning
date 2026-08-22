#[derive(Debug)]
enum DaftarList {
    Cons(i32, Box<DaftarList>),
    Nil,
}

use DaftarList::{Cons, Nil};

fn main() {
    println!("=== 1. DASAR ALOKASI HEAP DENGAN BOX ===");
    let angka_heap = Box::new(12345);
    println!("Nilai di dalam heap: {angka_heap}");
    println!("Dereferencing manual: {}", *angka_heap);

    println!("\n=== 2. LINKED LIST REKURSIF MENGGUNAKAN BOX ===");

    let list = Cons(1, Box::new(Cons(2, Box::new(Cons(3, Box::new(Nil))))));

    println!("Struktur Linked List: {:?}", list);

    let mut total_elemen = 0;
    let mut current = &list;

    while let Cons(val, next) = current {
        total_elemen += 1;
        println!("  Elemen ke-{}: {}", total_elemen, val);
        current = next;
    }
    println!("Total panjang list: {total_elemen}");
}
