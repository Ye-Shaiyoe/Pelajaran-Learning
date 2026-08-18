//! # Modul Level 11: Proyek Mini & Kasus Nyata

pub mod todo_cli;
pub mod file_searcher;
pub mod cache_engine;

pub fn pelajari_semua() {
    println!("############################################################");
    println!("  🛠️ LEVEL 11: PROYEK MINI & KASUS PENGGUNAAN NYATA          ");
    println!("############################################################\n");

    todo_cli::jalankan_demo();
    file_searcher::jalankan_demo();
    cache_engine::jalankan_demo();
}
