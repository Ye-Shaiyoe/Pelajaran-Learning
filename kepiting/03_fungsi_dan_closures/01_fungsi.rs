fn sapa_pengguna(nama: &str) {
    println!("Halo, {nama}! Selamat datang di dunia Rust.");
}

fn tambah(a: i32, b: i32) -> i32 {
    a + b
}

fn bagi(pembilang: f64, penyebut: f64) -> f64 {
    if penyebut == 0.0 {
        println!("Peringatan: Pembagian dengan nol!");
        return 0.0;
    }
    pembilang / penyebut
}

fn hitung_statistik(nilai: &[i32]) -> (i32, i32, f64) {
    let mut min = nilai[0];
    let mut max = nilai[0];
    let mut total = 0;

    for &n in nilai {
        if n < min { min = n; }
        if n > max { max = n; }
        total += n;
    }

    let rata_rata = total as f64 / nilai.len() as f64;
    (min, max, rata_rata)
}

fn main() {
    println!("=== 1. PEMANGGILAN FUNGSI DASAR ===");
    sapa_pengguna("Ferris");

    println!("\n=== 2. RETURN VALUE (EXPRESSION) ===");
    let hasil_tambah = tambah(15, 27);
    println!("15 + 27 = {hasil_tambah}");

    let hasil_bagi = bagi(100.0, 4.0);
    println!("100.0 / 4.0 = {hasil_bagi}");

    let bagi_nol = bagi(50.0, 0.0);
    println!("50.0 / 0.0 = {bagi_nol}");

    println!("\n=== 3. MULTI RETURN VALUE (TUPLE) ===");
    let data_angka = [12, 45, 78, 23, 9, 56];
    let (terkecil, terbesar, rerata) = hitung_statistik(&data_angka);

    println!("Data: {:?}", data_angka);
    println!("Nilai Min: {terkecil}");
    println!("Nilai Max: {terbesar}");
    println!("Nilai Rerata: {rerata:.2}");
}
