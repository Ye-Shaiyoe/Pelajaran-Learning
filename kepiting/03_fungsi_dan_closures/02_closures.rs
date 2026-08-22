fn main() {
    println!("=== 1. DASAR SINTAKS CLOSURE ===");

    let kuadrat = |x: i32| x * x;
    println!("Kuadrat dari 7 adalah: {}", kuadrat(7));

    let kali_dua = |x| x * 2;
    println!("5 * 2 = {}", kali_dua(5));

    println!("\n=== 2. CAPTURING ENVIRONMENT (MEMINJAM DARI SCOPE LUAR) ===");
    let teks_pembuka = "Halo dari scope luar:";

    let sapa = |nama: &str| {
        println!("{teks_pembuka} Selamat datang, {nama}!");
    };
    sapa("Akrom");
    sapa("Rustacean");

    println!("\n=== 3. CLOSURE MUTABLE (FnMut) ===");
    let mut total_klik = 0;

    let mut klik_tombol = || {
        total_klik += 1;
        println!("Tombol ditekan! Total klik: {total_klik}");
    };

    klik_tombol();
    klik_tombol();
    klik_tombol();

    println!("\n=== 4. KEYWORD 'move' (MENGAMBIL ALIH KEPEMILIKAN DATA) ===");

    let daftar_pesan = vec!["Pesan 1", "Pesan 2", "Pesan 3"];

    let cetak_semua = move || {
        println!("Mencetak koleksi data yang sudah dipindahkan (moved):");
        for pesan in daftar_pesan {
            println!("  - {pesan}");
        }
    };

    cetak_semua();

    println!("\n=== 5. CLOSURE SEBAGAI ARGUMEN FUNGSI ===");
    fn terapkan_operasi<F>(angka: i32, operasi: F) -> i32
    where
        F: Fn(i32) -> i32,
    {
        operasi(angka)
    }

    let hasil_tambah_seratus = terapkan_operasi(50, |n| n + 100);
    println!("50 diterapkan operasi (+100): {hasil_tambah_seratus}");
}
