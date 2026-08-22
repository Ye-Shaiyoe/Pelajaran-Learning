fn main() {
    println!("=== 1. IMMUTABLE REFERENCE (&T) ===");
    let s1 = String::from("Rustacean Sejati");

    let panjang = hitung_panjang(&s1);

    println!("String: '{s1}', Panjang: {panjang} karakter");

    let r1 = &s1;
    let r2 = &s1;
    println!("Membaca bersamaan -> r1: '{r1}', r2: '{r2}'");

    println!("\n=== 2. MUTABLE REFERENCE (&mut T) ===");
    let mut pesan = String::from("Halo");

    tambahkan_kata(&mut pesan);
    println!("Pesan setelah dimodifikasi: '{pesan}'");

    println!("\n=== 3. ATURAN ALIASING XOR MUTABILITY ===");
    let mut data = String::from("Data Sensitif");

    let ref_baca = &data;
    println!("Membaca: {ref_baca}");

    let ref_tulis = &mut data;
    ref_tulis.push_str(" (Telah Diverifikasi)");
    println!("Hasil perubahan: {ref_tulis}");
}

fn hitung_panjang(s: &String) -> usize {
    s.len()
}

fn tambahkan_kata(s: &mut String) {
    s.push_str(", Dunia Rust 🦀!");
}
