fn main() {
    println!("=== 1. SCOPE & OTOMATIS DROP ===");
    {

        let s = String::from("Halo Memori");
        println!("Di dalam scope: {s}");
    }

    println!("\n=== 2. MOVE SEMANTICS (PERPINDAHAN KEPEMILIKAN) ===");
    let s1 = String::from("Rust Language");

    let s2 = s1;

    println!("s2 memiliki data: {s2}");

    println!("\n=== 3. DEEP COPY DENGAN .clone() ===");

    let s3 = String::from("Data Asli");
    let s4 = s3.clone();

    println!("s3 (asli): {s3}, s4 (clone): {s4}");

    println!("\n=== 4. COPY TRAIT (UNTUK TIPE STACK SEDERHANA) ===");

    let x = 42;
    let y = x;
    println!("x: {x}, y: {y} (Keduanya tetap valid)");

    println!("\n=== 5. OWNERSHIP PADA FUNGSI ===");
    let teks = String::from("Kepiting Rust");
    ambil_kepemilikan(teks);

    let angka = 100;
    terima_salinan(angka);
    println!("Nilai angka di main masih ada: {angka}");

    let balik_teks = berikan_kepemilikan();
    println!("Menerima kepemilikan dari fungsi: {balik_teks}");
}

fn ambil_kepemilikan(suatu_string: String) {
    println!("  [Fungsi] Mengambil kepemilikan data: {suatu_string}");
}

fn terima_salinan(suatu_integer: i32) {
    println!("  [Fungsi] Menerima salinan integer: {suatu_integer}");
}

fn berikan_kepemilikan() -> String {
    let pesan = String::from("Pesan Rahasia");
    pesan
}
