//! # Level 11.2: Mini Proyek - Mini-Grep (Pencari Kata dalam Teks / File)
//!
//! Menggabungkan: String Slices, Iterators, Closures, Result Handling, Lifetimes

pub struct HasilPencarian<'a> {
    pub nomor_baris: usize,
    pub konten_baris: &'a str,
}

pub fn cari_kata<'a>(query: &str, konten: &'a str, case_sensitive: bool) -> Vec<HasilPencarian<'a>> {
    let query_lower = query.to_lowercase();

    konten
        .lines()
        .enumerate()
        .filter_map(|(idx, baris)| {
            let cocok = if case_sensitive {
                baris.contains(query)
            } else {
                baris.to_lowercase().contains(&query_lower)
            };

            if cocok {
                Some(HasilPencarian {
                    nomor_baris: idx + 1,
                    konten_baris: baris,
                })
            } else {
                None
            }
        })
        .collect()
}

pub fn jalankan_demo() {
    println!("=== 11.2 PROYEK MINI: MINI-GREP SEARCH ENGINE ===");

    let dokumen_sampel = "\
Rust adalah bahasa pemrograman sistem yang cepat dan aman.
Kelebihan utama Rust adalah manajemen memori tanpa Garbage Collector.
Dengan Rust, Anda mendapatkan keamanan memori di tingkat kompilasi.
Semoga perjalanan belajar RUST Anda menyenangkan!";

    let kata_kunci = "rust";

    println!("Mencari kata: \"{kata_kunci}\" (Case-Insensitive)...");
    let hasil = cari_kata(kata_kunci, dokumen_sampel, false);

    println!("Ditemukan {} baris yang cocok:", hasil.len());
    for item in hasil {
        println!("   [Baris {:<2}] {}", item.nomor_baris, item.konten_baris);
    }
    println!();
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_cari_kata_case_insensitive() {
        let konten = "Halo Rust\nBelajar rustacean\nPython";
        let hasil = cari_kata("rust", konten, false);
        assert_eq!(hasil.len(), 2);
        assert_eq!(hasil[0].nomor_baris, 1);
        assert_eq!(hasil[1].nomor_baris, 2);
    }
}
