fn cari_indeks(daftar: &[i32], target: i32) -> Option<usize> {
    for (i, &item) in daftar.iter().enumerate() {
        if item == target {
            return Some(i);
        }
    }
    None
}

fn bagi_aman(pembilang: f64, penyebut: f64) -> Result<f64, String> {
    if penyebut == 0.0 {
        Err(String::from("Penyebut tidak boleh bernilai nol!"))
    } else {
        Ok(pembilang / penyebut)
    }
}

fn main() {
    println!("=== 1. BEKERJA DENGAN Option<T> ===");
    let kumpulan_angka = [10, 25, 40, 75, 90];

    let hasil_cari = cari_indeks(&kumpulan_angka, 40);

    match hasil_cari {
        Some(indeks) => println!("Angka ditemukan pada indeks ke-{}", indeks),
        None => println!("Angka tidak ditemukan dalam array"),
    }

    let hasil_cari_2 = cari_indeks(&kumpulan_angka, 999);
    let indeks_atau_default = hasil_cari_2.unwrap_or(9999);
    println!("Hasil cari 999 (unwrap_or): {indeks_atau_default}");

    if let Some(posisi) = cari_indeks(&kumpulan_angka, 75) {
        println!("Ketemu dengan `if let` di posisi: {posisi}");
    }

    println!("\n=== 2. BEKERJA DENGAN Result<T, E> ===");
    let hasil_sukses = bagi_aman(100.0, 5.0);
    let hasil_gagal = bagi_aman(50.0, 0.0);

    match hasil_sukses {
        Ok(nilai) => println!("Hasil pembagian: {nilai}"),
        Err(e) => println!("Terjadi error: {e}"),
    }

    match hasil_gagal {
        Ok(nilai) => println!("Hasil pembagian: {nilai}"),
        Err(e) => println!("Terjadi error: {e}"),
    }

    let nilai_valid = bagi_aman(20.0, 2.0).unwrap();
    println!("Nilai unwrap aman: {nilai_valid}");

    let nilai_expect = bagi_aman(30.0, 3.0).expect("Operasi pembagian gagal!");
    println!("Nilai expect aman: {nilai_expect}");
}
