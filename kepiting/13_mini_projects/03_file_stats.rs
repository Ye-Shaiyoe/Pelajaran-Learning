use std::collections::HashMap;

#[derive(Debug)]
struct LaporanStatistik {
    total_baris: usize,
    total_kata: usize,
    total_karakter: usize,
    rata_rata_panjang_kata: f64,
    top_5_kata: Vec<(String, usize)>,
}

fn analisis_teks(konten: &str) -> LaporanStatistik {
    let baris: Vec<&str> = konten.lines().collect();
    let total_baris = baris.len();

    let mut total_karakter = 0;
    let mut frekuensi_kata: HashMap<String, usize> = HashMap::new();
    let mut total_panjang_kata = 0;
    let mut total_kata = 0;

    for line in baris {
        total_karakter += line.chars().count();

        for raw_word in line.split_whitespace() {
            let kata_bersih: String = raw_word
                .chars()
                .filter(|c| c.is_alphanumeric())
                .collect::<String>()
                .to_lowercase();

            if !kata_bersih.is_empty() {
                total_kata += 1;
                total_panjang_kata += kata_bersih.chars().count();
                *frekuensi_kata.entry(kata_bersih).or_insert(0) += 1;
            }
        }
    }

    let rata_rata = if total_kata > 0 {
        total_panjang_kata as f64 / total_kata as f64
    } else {
        0.0
    };

    let mut daftar_kata: Vec<(String, usize)> = frekuensi_kata.into_iter().collect();
    daftar_kata.sort_by(|a, b| b.1.cmp(&a.1));

    let top_5 = daftar_kata.into_iter().take(5).collect();

    LaporanStatistik {
        total_baris,
        total_kata,
        total_karakter,
        rata_rata_panjang_kata: rata_rata,
        top_5_kata: top_5,
    }
}

fn main() {
    let contoh_dokumen = "\
Rust adalah bahasa pemrograman sistem yang berfokus pada kecepatan, keamanan memori, dan konkurensi.
Rust menjamin keamanan memori tanpa garbage collector.
Dengan Rust, Anda dapat membangun perangkat lunak handal dan berkinerja tinggi.
Mari belajar Rust bersama Ferris si kepiting!";

    println!("=== DOKUMEN INPUT ===");
    println!("{}\n", contoh_dokumen);

    let laporan = analisis_teks(contoh_dokumen);

    println!("=== HASIL ANALISIS STATISTIK ===");
    println!("Total Baris               : {}", laporan.total_baris);
    println!("Total Kata                : {}", laporan.total_kata);
    println!("Total Karakter            : {}", laporan.total_karakter);
    println!("Rata-rata Panjang Kata    : {:.2} huruf/kata", laporan.rata_rata_panjang_kata);
    println!("\nTop 5 Kata Paling Sering Muncul:");
    for (ranking, (kata, jumlah)) in laporan.top_5_kata.iter().enumerate() {
        println!("  {}. '{:<12}' -> {} kali", ranking + 1, kata, jumlah);
    }
}
