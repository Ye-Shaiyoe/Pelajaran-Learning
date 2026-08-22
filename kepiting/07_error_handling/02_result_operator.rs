fn konversi_dan_kalikan(input_str: &str, pengali: i32) -> Result<i32, std::num::ParseIntError> {

    let angka: i32 = input_str.trim().parse()?;

    Ok(angka * pengali)
}

fn kalkulasi_kompleks(s1: &str, s2: &str) -> Result<i32, String> {
    let num1: i32 = s1
        .trim()
        .parse()
        .map_err(|e| format!("Gagal parsing s1 ('{s1}'): {e}"))?;

    let num2: i32 = s2
        .trim()
        .parse()
        .map_err(|e| format!("Gagal parsing s2 ('{s2}'): {e}"))?;

    if num2 == 0 {
        return Err(String::from("Error: Pembagian oleh angka 0!"));
    }

    Ok(num1 / num2)
}

fn main() {
    println!("=== 1. ERROR PROPAGATION DENGAN OPERATOR '?' ===");
    let uji_1 = konversi_dan_kalikan("25", 4);
    println!("konversi_dan_kalikan('25', 4) -> {:?}", uji_1);

    let uji_2 = konversi_dan_kalikan("bukan_angka", 4);
    println!("konversi_dan_kalikan('bukan_angka', 4) -> {:?}", uji_2);

    println!("\n=== 2. MAPPING DAN MENGGABUNGKAN ERROR ===");
    let sukses = kalkulasi_kompleks("100", "5");
    println!("kalkulasi_kompleks('100', '5') -> {:?}", sukses);

    let gagal_parse = kalkulasi_kompleks("abc", "5");
    println!("kalkulasi_kompleks('abc', '5') -> {:?}", gagal_parse);

    let gagal_bagi = kalkulasi_kompleks("100", "0");
    println!("kalkulasi_kompleks('100', '0') -> {:?}", gagal_bagi);
}
