#[derive(Debug, Clone, PartialEq)]
enum Prioritas {
    Rendah,
    Sedang,
    Tinggi,
}

impl Prioritas {
    fn label(&self) -> &str {
        match self {
            Prioritas::Rendah => "🟢 Rendah",
            Prioritas::Sedang => "🟡 Sedang",
            Prioritas::Tinggi => "🔴 Tinggi",
        }
    }
}

#[derive(Debug, Clone)]
struct Tugas {
    id: usize,
    deskripsi: String,
    selesai: bool,
    prioritas: Prioritas,
}

struct TodoApp {
    daftar_tugas: Vec<Tugas>,
    counter_id: usize,
}

impl TodoApp {
    fn baru() -> Self {
        Self {
            daftar_tugas: Vec::new(),
            counter_id: 1,
        }
    }

    fn tambah_tugas(&mut self, deskripsi: &str, prioritas: Prioritas) {
        let tugas = Tugas {
            id: self.counter_id,
            deskripsi: deskripsi.to_string(),
            selesai: false,
            prioritas,
        };
        self.daftar_tugas.push(tugas);
        println!("  [+] Berhasil menambahkan tugas #{}: '{}'", self.counter_id, deskripsi);
        self.counter_id += 1;
    }

    fn tandai_selesai(&mut self, id: usize) -> Result<(), String> {
        for tugas in &mut self.daftar_tugas {
            if tugas.id == id {
                tugas.selesai = true;
                return Ok(());
            }
        }
        Err(format!("Tugas dengan ID #{} tidak ditemukan!", id))
    }

    fn hapus_tugas(&mut self, id: usize) -> Result<(), String> {
        let index = self
            .daftar_tugas
            .iter()
            .position(|t| t.id == id)
            .ok_or_else(|| format!("Tugas dengan ID #{} tidak ditemukan!", id))?;

        let terhapus = self.daftar_tugas.remove(index);
        println!("  [-] Menghapus tugas #{}: '{}'", terhapus.id, terhapus.deskripsi);
        Ok(())
    }

    fn tampilkan_tugas(&self) {
        println!("\n========================================================");
        println!("                 DAFTAR TUGAS ANDA                      ");
        println!("========================================================");
        if self.daftar_tugas.is_empty() {
            println!("  (Tidak ada tugas, saatnya bersantai! 🌴)");
        } else {
            for t in &self.daftar_tugas {
                let status_icon = if t.selesai { "[✓]" } else { "[ ]" };
                println!(
                    "  {} #{:<2} | {:<25} | {}",
                    status_icon,
                    t.id,
                    t.deskripsi,
                    t.prioritas.label()
                );
            }
        }
        println!("========================================================\n");
    }
}

fn main() {
    println!("=== SIMULASI APLIKASI TODO CLI ===");
    let mut app = TodoApp::baru();

    app.tambah_tugas("Belajar Dasar Rust", Prioritas::Tinggi);
    app.tambah_tugas("Pahami Ownership & Borrowing", Prioritas::Tinggi);
    app.tambah_tugas("Olahraga Sore 30 Menit", Prioritas::Sedang);
    app.tambah_tugas("Beli Kopi Arabika", Prioritas::Rendah);

    app.tampilkan_tugas();

    println!("Menandai tugas #1 dan #2 sebagai SELESAI...");
    let _ = app.tandai_selesai(1);
    let _ = app.tandai_selesai(2);

    println!("Menghapus tugas #4...");
    let _ = app.hapus_tugas(4);

    app.tampilkan_tugas();
}
