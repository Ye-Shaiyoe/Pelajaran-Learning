//! # Modul Level 4: Koleksi Data, String & Error Handling

pub mod collections;
pub mod strings_detail;
pub mod error_handling;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("  📦 LEVEL 4: KOLEKSI DATA & ERROR HANDLING                 ");
    println!("############################################################\n");

    collections::jalankan_demo();
    strings_detail::jalankan_demo();
    error_handling::jalankan_demo();
}
