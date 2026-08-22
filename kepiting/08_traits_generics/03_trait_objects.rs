trait KomponenUI {
    fn gambar(&self);
}

struct Tombol {
    label: String,
    lebar: u32,
    tinggi: u32,
}

impl KomponenUI for Tombol {
    fn gambar(&self) {
        println!("[BUTTON] Menggambar tombol '{}' ukuran {}x{}", self.label, self.lebar, self.tinggi);
    }
}

struct InputTeks {
    placeholder: String,
}

impl KomponenUI for InputTeks {
    fn gambar(&self) {
        println!("[INPUT] Menggambar form teks dengan placeholder: '{}'", self.placeholder);
    }
}

struct Layar {

    komponen: Vec<Box<dyn KomponenUI>>,
}

impl Layar {
    fn render_semua(&self) {
        println!("=== MEMULAI RENDER SCREEN ===");
        for item in &self.komponen {
            item.gambar();
        }
        println!("=== RENDER SELESAI ===\n");
    }
}

fn main() {
    let tombol_simpan = Box::new(Tombol {
        label: String::from("Simpan Perubahan"),
        lebar: 120,
        tinggi: 40,
    });

    let tombol_batal = Box::new(Tombol {
        label: String::from("Batal"),
        lebar: 80,
        tinggi: 40,
    });

    let input_nama = Box::new(InputTeks {
        placeholder: String::from("Masukkan nama lengkap Anda..."),
    });

    let layar = Layar {
        komponen: vec![input_nama, tombol_simpan, tombol_batal],
    };

    layar.render_semua();
}
