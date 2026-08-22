fn main() {
    println!("=== 1. MEMBUAT DAN MENGUBAH STRING ===");
    let mut salam = String::from("Halo");

    salam.push_str(", Dunia");

    salam.push('!');

    println!("Hasil String: {salam}");

    println!("\n=== 2. MENGGABUNGKAN STRING (CONCATENATION) ===");
    let str1 = String::from("Belajar");
    let str2 = String::from("Rust");

    let gabung_format = format!("{} {} itu Seru!", str1, str2);
    println!("Hasil format: '{gabung_format}'");
    println!("str1 dan str2 masih tetap utuh: '{str1}', '{str2}'");

    println!("\n=== 3. UTF-8 INTERNALS & ITERASI KARAKTER ===");

    let teks_multi_bahasa = "🦀 Rust 日本語";

    println!("Teks: {teks_multi_bahasa}");
    println!("Panjang dalam BYTE (.len()): {}", teks_multi_bahasa.len());
    println!("Jumlah Karakter Unicode (.chars().count()): {}", teks_multi_bahasa.chars().count());

    print!("Karakter demi karakter: ");
    for c in teks_multi_bahasa.chars() {
        print!("['{c}'] ");
    }
    println!();

    print!("Bytes pertama (5 byte): ");
    for b in teks_multi_bahasa.bytes().take(5) {
        print!("{:#04x} ", b);
    }
    println!();
}
