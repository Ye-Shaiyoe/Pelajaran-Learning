//! # Modul Level 7: Smart Pointers & Alokasi Memori Heap

pub mod box_pointer;
pub mod rc_arc;
pub mod refcell_cell;
pub mod memory_leak_weak;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("  📍 LEVEL 7: SMART POINTERS & HEAP ALLOCATION              ");
    println!("############################################################\n");

    box_pointer::jalankan_demo();
    rc_arc::jalankan_demo();
    refcell_cell::jalankan_demo();
    memory_leak_weak::jalankan_demo();
}
