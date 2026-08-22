trait Ringkasan {

    fn ambil_penulis(&self) -> String;

    fn format_ringkasan(&self) -> String {
        format!("(Baca selengkapnya dari {}...)", self.ambil_penulis())
    }
}

struct ArtikelBerita {
    judul: String,
    penulis: String,
    isi: String,
}

impl Ringkasan for ArtikelBerita {
    fn ambil_penulis(&self) -> String {
        self.penulis.clone()
    }

    fn format_ringkasan(&self) -> String {
        format!("'{}' oleh {} - Kutipan: \"{}\"", self.judul, self.penulis, self.isi)
    }
}

struct Tweet {
    username: String,
    konten: String,
    retweet: bool,
}

impl Ringkasan for Tweet {
    fn ambil_penulis(&self) -> String {
        let rt_label = if self.retweet { " [RT]" } else { "" };
        format!("@{}{}: \"{}\"", self.username, rt_label, self.konten)
    }

}

fn terbitkan_publikasi(item: &impl Ringkasan) {
    println!("[PUBLIKASI BARU] {}", item.format_ringkasan());
}

fn bandingkan_dan_cetak<T, U>(item1: &T, item2: &U)
where
    T: Ringkasan,
    U: Ringkasan,
{
    println!("1: {}", item1.format_ringkasan());
    println!("2: {}", item2.format_ringkasan());
}

fn main() {
    println!("=== IMPLEMENTASI TRAITS DI RUST ===");

    let artikel = ArtikelBerita {
        judul: String::from("Rust Meraih Peringkat Bahasa Paling Dicintai"),
        penulis: String::from("Budi Rustacean"),
        isi: String::from("Survey StackOverflow menunjukkan komunitas Rust sangat antusias..."),
    };

    let tweet = Tweet {
        username: String::from("ferris_crab"),
        konten: String::from("Hari ini belajar Traits di Rust, asyik banget! 🦀"),
        retweet: false,
    };

    println!("--- Artikel (Custom Implementation) ---");
    terbitkan_publikasi(&artikel);

    println!("\n--- Tweet (Menggunakan Default Method) ---");
    terbitkan_publikasi(&tweet);

    println!("\n--- Membandingkan Dua Item Berbeda dengan Trait Bounds ---");
    bandingkan_dan_cetak(&artikel, &tweet);
}
