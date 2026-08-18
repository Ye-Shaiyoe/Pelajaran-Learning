//! # Modul Level 1: Dasar Sintaks Rust
//!
//! Mencakup sintaks dasar variabel, tipe data skalar/majemuk, fungsi, dan control flow.

pub mod sintaks_dasar;
pub mod fungsi;
pub mod control_flow;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("       📘 LEVEL 1: DASAR SINTAKS & TIPE DATA RUST          ");
    println!("############################################################\n");

    sintaks_dasar::jalankan_demo();
    fungsi::jalankan_demo();
    control_flow::jalankan_demo();
}
