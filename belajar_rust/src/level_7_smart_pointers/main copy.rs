// ============================================================================
// 🦀 MASTER MODUL PEMBELAJARAN BAHASA PEMROGRAMAN RUST (DARI 0 SAMPAI MAHIR) 🦀
// ============================================================================

pub mod level_1_dasar;
pub mod level_2_memori;
pub mod level_3_struktur_data;
pub mod level_4_koleksi_error;
pub mod level_5_oop_traits;
pub mod level_6_functional;
pub mod level_7_smart_pointers;
pub mod level_8_concurrency;
pub mod level_9_lifetimes_advanced;
pub mod level_10_expert_rust;
pub mod level_11_proyek_nyata;

use std::env;
use std::io::{self, Write};

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() > 1 {
        // Mode Argumen Langsung: `cargo run -- 1` atau `cargo run -- all`
        match args[1].as_str() {
            "all" | "semua" => jalankan_semua_level(),
            "1" => level_1_dasar::pelajari_semua(),
            "2" => level_2_memori::pelajari_semua(),
            "3" => level_3_struktur_data::pelajari_semua(),
            "4" => level_4_koleksi_error::pelajari_semua(),
            "5" => level_5_oop_traits::pelajari_semua(),
            "6" => level_6_functional::pelajari_semua(),
            "7" => level_7_smart_pointers::pelajari_semua(),
            "8" => level_8_concurrency::pelajari_semua(),
            "9" => level_9_lifetimes_advanced::pelajari_semua(),
            "10" => level_10_expert_rust::pelajari_semua(),
            "11" => level_11_proyek_nyata::pelajari_semua(),
            other => {
                println!("⚠️ Pilihan '{other}' tidak dikenali. Gunakan angka 1-11 atau 'all'.");
            }
        }
        return;
    }

    // Mode Menu Interaktif
    menu_interaktif();
}

fn menu_interaktif() {
    loop {
        println!("\n╔══════════════════════════════════════════════════════════════╗");
        println!("║   🦀 KURIKULUM LENGKAP BELAJAR RUST: DARI 0 SAMPAI MAHIR     ║");
        println!("╠══════════════════════════════════════════════════════════════╣");
        println!("║  [1]  Level 1 : Sintaks Dasar, Variabel & Control Flow      ║");
        println!("║  [2]  Level 2 : Ownership, Borrowing & Slices               ║");
        println!("║  [3]  Level 3 : Struct, Enum & Pattern Matching             ║");
        println!("║  [4]  Level 4 : Koleksi Data, Strings & Error Handling      ║");
        println!("║  [5]  Level 5 : Generics, Traits & Polimorfisme (OOP)       ║");
        println!("║  [6]  Level 6 : Functional Programming (Closures/Iterators) ║");
        println!("║  [7]  Level 7 : Smart Pointers (Box, Rc, Arc, RefCell)      ║");
        println!("║  [8]  Level 8 : Concurrency & Multithreading (Threads/MPSC) ║");
        println!("║  [9]  Level 9 : Advanced Lifetimes & Elision Rules          ║");
        println!("║  [10] Level 10: Expert Rust (Macros, Unsafe & Patterns)     ║");
        println!("║  [11] Level 11: Proyek Mini Nyata (Todo, Grep, Cache Engine)║");
        println!("║  [A]  Jalankan SEMUA Level Sekaligus                        ║");
        println!("║  [0/Q] Keluar                                               ║");
        println!("╚══════════════════════════════════════════════════════════════╝");
        print!("👉 Pilih level yang ingin dipelajari [0-11/A]: ");
        io::stdout().flush().unwrap();

        let mut input = String::new();
        if io::stdin().read_line(&mut input).is_err() {
            println!("Gagal membaca input.");
            break;
        }

        let pilihan = input.trim().to_uppercase();
        println!();

        match pilihan.as_str() {
            "1" => level_1_dasar::pelajari_semua(),
            "2" => level_2_memori::pelajari_semua(),
            "3" => level_3_struktur_data::pelajari_semua(),
            "4" => level_4_koleksi_error::pelajari_semua(),
            "5" => level_5_oop_traits::pelajari_semua(),
            "6" => level_6_functional::pelajari_semua(),
            "7" => level_7_smart_pointers::pelajari_semua(),
            "8" => level_8_concurrency::pelajari_semua(),
            "9" => level_9_lifetimes_advanced::pelajari_semua(),
            "10" => level_10_expert_rust::pelajari_semua(),
            "11" => level_11_proyek_nyata::pelajari_semua(),
            "A" | "ALL" => jalankan_semua_level(),
            "0" | "Q" | "EXIT" => {
                println!("👋 Selamat belajar dan berlatih Rust! Sampai jumpa.");
                break;
            }
            _ => println!("⚠️ Pilihan tidak valid, silakan masukkan nomor 1-11 atau A."),
        }
    }
}

fn jalankan_semua_level() {
    level_1_dasar::pelajari_semua();
    level_2_memori::pelajari_semua();
    level_3_struktur_data::pelajari_semua();
    level_4_koleksi_error::pelajari_semua();
    level_5_oop_traits::pelajari_semua();
    level_6_functional::pelajari_semua();
    level_7_smart_pointers::pelajari_semua();
    level_8_concurrency::pelajari_semua();
    level_9_lifetimes_advanced::pelajari_semua();
    level_10_expert_rust::pelajari_semua();
    level_11_proyek_nyata::pelajari_semua();

    println!("============================================================");
    println!("🎉 SELAMAT! Anda telah menjalankan seluruh modul pembelajaran Rust.");
    println!("============================================================");
}
