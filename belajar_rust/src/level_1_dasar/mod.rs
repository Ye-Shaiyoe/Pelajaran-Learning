// # Level 1: Dasar-Dasar Pemrograman Rust
// Syntax dasar variabel

pub mod syntax_dasar;
pub mod tipe_data;
pub mod function;

pub fn demo_pembelajaran() {
    println!("-----");
    println!("Level 1 Dasar Pemrograman Rust");
    println!("-----");

    syntax_dasar::jalankan_demo();
    println!();
    
    tipe_data::jalankan_demo();
    println!();

    function::jalankan_demo();
    println!();
}