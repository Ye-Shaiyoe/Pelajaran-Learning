fn main() {
    println!("=== 1. STRING SLICE (&str) ===");
    let kalimat = String::from("Pemrograman Rust Mantap");

    let kata_pertama: &str = &kalimat[0..11];
    let kata_kedua: &str = &kalimat[12..16];
    let kata_ketiga: &str = &kalimat[17..];

    println!("Kalimat Asli : {kalimat}");
    println!("Slice 1      : {kata_pertama}");
    println!("Slice 2      : {kata_kedua}");
    println!("Slice 3      : {kata_ketiga}");

    let literal: &str = "Ini adalah static slice";
    println!("Literal      : {literal}");

    println!("\n=== 2. ARRAY SLICE (&[T]) ===");
    let daftar_angka = [10, 20, 30, 40, 50, 60, 70];

    let sebagian_angka: &[i32] = &daftar_angka[1..5];
    println!("Array asli  : {:?}", daftar_angka);
    println!("Slice array : {:?}", sebagian_angka);

    println!("\n=== 3. FUNGSI MENGAMBIL SLICE ===");
    let kata_ditemukan = cari_kata_pertama(&kalimat);
    println!("Kata pertama yang ditemukan: '{kata_ditemukan}'");
}

fn cari_kata_pertama(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }

    &s[..]
}
