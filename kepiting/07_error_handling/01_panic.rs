fn periksa_level_bahan_bakar(liter: f64) {
    if liter < 0.0 {

        panic!("KRITIKAL: Kapasitas bahan bakar tidak boleh bernilai negatif: {} liter!", liter);
    }
    println!("Bahan bakar terisi: {:.1} liter. Mesin siap jalan.", liter);
}

fn main() {
    println!("=== 1. MENJALANKAN KONDISI AMAN ===");
    periksa_level_bahan_bakar(45.0);

    println!("\n=== 2. MENANGKAP PANIC DENGAN std::panic::catch_unwind ===");

    let hasil = std::panic::catch_unwind(|| {
        println!("Mencoba memicu kondisi fatal dalam blok catch_unwind...");
        periksa_level_bahan_bakar(-10.5);
    });

    match hasil {
        Ok(_) => println!("Eksekusi normal tanpa panic."),
        Err(_) => println!("BERHASIL MENANGKAP PANIC! Program tetap berjalan dan tidak crash secara fatal."),
    }

    println!("\nProgram utama selesai dengan selamat! 🦀");
}
