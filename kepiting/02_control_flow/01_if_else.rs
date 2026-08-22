fn main() {
    println!("=== 1. PERCABANGAN STANDAR IF - ELSE IF - ELSE ===");
    let nilai = 85;

    if nilai >= 90 {
        println!("Grade: A (Luar Biasa!)");
    } else if nilai >= 80 {
        println!("Grade: B (Sangat Baik)");
    } else if nilai >= 70 {
        println!("Grade: C (Cukup)");
    } else {
        println!("Grade: D (Perlu Belajar Lagi)");
    }

    println!("\n=== 2. IF SEBAGAI EKSPRESI (EXPRESSION) ===");

    let is_member = true;
    let diskon = if is_member { 0.20 } else { 0.05 };

    println!("Status Member: {is_member} -> Diskon: {}%", diskon * 100.0);

    let status_kelulusan = if nilai >= 75 {
        "LULUS"
    } else {
        "TIDAK LULUS"
    };
    println!("Status Hasil Ujian: {status_kelulusan}");
}
