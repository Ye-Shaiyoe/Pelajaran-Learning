//! # Level 9.2: Lifetimes pada Struct & Method
//!
//! Konsep yang dipelajari:
//! 1. Menyimpan reference di dalam field struct (`&'a str`)
//! 2. Menjamin instance struct tidak boleh hidup lebih lama dari data yang dipinjamnya
//! 3. Lifetime annotations pada blok `impl<'a>`

#[derive(Debug)]
pub struct KutipanPenting<'a> {
    pub isi: &'a str,
    pub penulis: &'a str,
}

impl<'a> KutipanPenting<'a> {
    pub fn cetak(&self) {
        println!("   \"{}\" - {}", self.isi, self.penulis);
    }

    pub fn umumkan_dan_kembalikan(&self, pengantar: &str) -> &'a str {
        println!("   [Pengumuman]: {pengantar}");
        self.isi // Mengembalikan reference dengan lifetime 'a
    }
}

pub fn jalankan_demo() {
    println!("=== 9.2 LIFETIMES DALAM STRUCT ===");

    let sumber_teks = String::from("Kesalahan terbesar adalah tidak pernah mencoba.");
    let nama_penulis = "Albert Einstein";

    let kutipan = KutipanPenting {
        isi: &sumber_teks[0..],
        penulis: nama_penulis,
    };

    kutipan.cetak();
    let kembali = kutipan.umumkan_dan_kembalikan("Kata Mutiara Hari Ini");
    println!("Nilai yang dikembalikan: \"{kembali}\"");
    println!();
}
