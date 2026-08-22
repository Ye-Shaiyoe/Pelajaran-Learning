fn string_terpanjang<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

fn main() {
    println!("=== 1. FUNGSI DENGAN LIFETIME ANNOTATION ===");
    let string1 = String::from("Bahasa Rust itu sangat aman");
    let string2 = "C++";

    let hasil = string_terpanjang(string1.as_str(), string2);
    println!("String yang lebih panjang adalah: '{hasil}'");

    println!("\n=== 2. LIFETIME DENGAN SCOPE BERBEDA ===");
    let teks_luar = String::from("Kalimat dari scope luar");
    {
        let teks_dalam = String::from("Teks scope dalam");
        let hasil_scope = string_terpanjang(teks_luar.as_str(), teks_dalam.as_str());
        println!("Hasil di dalam inner scope: '{hasil_scope}'");
    }

    println!("\n=== 3. STATIC LIFETIME ('static) ===");

    let pesan_abadi: &'static str = "Saya tersimpan di binary executable selamanya!";
    println!("Static Lifetime: {pesan_abadi}");
}
