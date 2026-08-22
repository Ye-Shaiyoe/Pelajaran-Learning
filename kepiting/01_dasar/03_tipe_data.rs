
fn main() {
    println!("=== 1. TIPE DATA SKALAR ===");

    let min_i8: i8 = -128;
    let max_u8: u8 = 255;
    let uang_i64: i64 = 10_000_000;
    let index_usize: usize = 0;

    println!("i8: {min_i8}, u8: {max_u8}, i64: Rp{uang_i64}, usize: {index_usize}");

    let pi: f64 = 3.141592653589793;
    let gravitasi: f32 = 9.81;
    println!("Pi (f64): {pi}, Gravitasi (f32): {gravitasi}");

    let is_rust_fast: bool = true;
    let is_boring: bool = false;
    println!("Rust cepat? {is_rust_fast}, Membosankan? {is_boring}");

    let huruf: char = 'A';
    let emoji: char = '🦀';
    let japanese: char = '本';
    println!("Huruf: {huruf}, Emoji: {emoji}, Kanji: {japanese}");

    println!("\n=== 2. TIPE DATA MAJEMUK (COMPOUND) ===");

    let user: (&str, u32, bool) = ("Andi", 28, true);

    println!("User - Nama: {}, Umur: {}, Aktif: {}", user.0, user.1, user.2);

    let (nama, umur, aktif) = user;
    println!("Destructuring -> Nama: {nama}, Umur: {umur}, Status: {aktif}");

    let angka: [i32; 5] = [10, 20, 30, 40, 50];

    let nol_semua = [0; 4];

    println!("Array angka: {:?}", angka);
    println!("Elemen pertama: {}", angka[0]);
    println!("Jumlah elemen array: {}", angka.len());
    println!("Array nol: {:?}", nol_semua);
}
