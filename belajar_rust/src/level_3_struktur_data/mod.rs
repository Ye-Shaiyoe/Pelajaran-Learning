//! # Modul Level 3: Tipe Data Kustom (Struct, Enum, Pattern Matching)

pub mod structs;
pub mod enums;
pub mod pattern_matching;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("  🧱 LEVEL 3: STRUCT, ENUM & PATTERN MATCHING               ");
    println!("############################################################\n");

    structs::jalankan_demo();
    enums::jalankan_demo();
    pattern_matching::jalankan_demo();
}
