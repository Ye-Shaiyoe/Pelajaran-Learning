#[derive(Debug)]
struct KutipanPenting<'a> {
    bagian_teks: &'a str,
    halaman: u32,
}

impl<'a> KutipanPenting<'a> {

    fn cetak_info(&self) {
        println!("Halaman {}: \"{}\"", self.halaman, self.bagian_teks);
    }

    fn ambil_teks(&self) -> &str {
        self.bagian_teks
    }
}

fn main() {
    let novel = String::from("Panggil aku Ishmael. Beberapa tahun yang lalu...");

    let kalimat_pertama = novel.split('.').next().expect("Tidak ada kalimat");

    let kutipan = KutipanPenting {
        bagian_teks: kalimat_pertama,
        halaman: 1,
    };

    kutipan.cetak_info();
    println!("Teks yang diekstrak: {}", kutipan.ambil_teks());
}
