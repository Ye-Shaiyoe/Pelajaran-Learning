//! # Level 11.1: Mini Proyek - Task / Todo Engine
//!
//! Menggabungkan: Struct, Vec, Enum, Method, Error Handling, Pattern Matching

#[derive(Debug, Clone, PartialEq)]
pub enum Prioritas {
    Rendah,
    Sedang,
    Tinggi,
}

#[derive(Debug, Clone)]
pub struct Task {
    pub id: u32,
    pub deskripsi: String,
    pub selesai: bool,
    pub prioritas: Prioritas,
}

pub struct TodoApp {
    tasks: Vec<Task>,
    counter_id: u32,
}

impl TodoApp {
    pub fn new() -> Self {
        Self {
            tasks: Vec::new(),
            counter_id: 1,
        }
    }

    pub fn tambah_tugas(&mut self, deskripsi: &str, prioritas: Prioritas) -> u32 {
        let id = self.counter_id;
        self.counter_id += 1;
        self.tasks.push(Task {
            id,
            deskripsi: String::from(deskripsi),
            selesai: false,
            prioritas,
        });
        id
    }

    pub fn selesaikan_tugas(&mut self, id: u32) -> Result<(), String> {
        if let Some(t) = self.tasks.iter_mut().find(|t| t.id == id) {
            t.selesai = true;
            Ok(())
        } else {
            Err(format!("Tugas dengan ID {id} tidak ditemukan!"))
        }
    }

    pub fn cetak_daftar(&self) {
        println!("   📋 [DAFTAR TUGAS TODO APP]");
        if self.tasks.is_empty() {
            println!("      (Tidak ada tugas)");
            return;
        }

        for t in &self.tasks {
            let status_ikon = if t.selesai { "✅" } else { "⏳" };
            let p_ikon = match t.prioritas {
                Prioritas::Tinggi => "🔥 [HIGH]",
                Prioritas::Sedang => "⚡ [MED]",
                Prioritas::Rendah => "🌱 [LOW]",
            };
            println!("      {status_ikon} ID #{:<2} {:<9} | {}", t.id, p_ikon, t.deskripsi);
        }
    }
}

pub fn jalankan_demo() {
    println!("=== 11.1 PROYEK MINI: TODO ENGINE ===");

    let mut app = TodoApp::new();

    let id1 = app.tambah_tugas("Pelajari Ownership Rust", Prioritas::Tinggi);
    let id2 = app.tambah_tugas("Beli Kopi Arabica", Prioritas::Rendah);
    let _id3 = app.tambah_tugas("Bangun Aplikasi Web dengan Rust", Prioritas::Sedang);

    app.cetak_daftar();

    println!("\n   -> Menyelesaikan tugas ID #{id1}...");
    app.selesaikan_tugas(id1).unwrap();

    println!("   -> Menyelesaikan tugas ID #{id2}...");
    app.selesaikan_tugas(id2).unwrap();

    println!();
    app.cetak_daftar();
    println!();
}
