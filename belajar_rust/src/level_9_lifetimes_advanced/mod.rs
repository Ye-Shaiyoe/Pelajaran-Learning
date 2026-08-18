//! # Modul Level 9: Lifetimes & Borrow Checker Tingkat Lanjut

pub mod lifetimes_syntax;
pub mod struct_lifetimes;
pub mod static_and_elision;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("  ⏳ LEVEL 9: ADVANCED LIFETIMES & BORROW CHECKER           ");
    println!("############################################################\n");

    lifetimes_syntax::jalankan_demo();
    struct_lifetimes::jalankan_demo();
    static_and_elision::jalankan_demo();
}
