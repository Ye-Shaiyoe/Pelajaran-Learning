//! # Modul Level 5: OOP & Polimorfisme (Generics, Traits, Dynamic Dispatch)

pub mod generics;
pub mod traits;
pub mod trait_objects;
pub mod associated_types;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("  🎭 LEVEL 5: GENERICS, TRAITS & POLIMORFISME               ");
    println!("############################################################\n");

    generics::jalankan_demo();
    traits::jalankan_demo();
    trait_objects::jalankan_demo();
    associated_types::jalankan_demo();
}
