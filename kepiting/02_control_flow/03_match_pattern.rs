fn main() {
    println!("=== 1. DASAR MATCHING DENGAN 'match' ===");

    let angka = 3;

    match angka {
        1 => println!("Satu!"),
        2 => println!("Dua!"),
        3 => println!("Tiga!"),

        4 | 5 => println!("Empat atau Lima!"),

        6..=10 => println!("Antara Enam sampai Sepuluh!"),

        _ => println!("Angka lainnya!"),
    }

    println!("\n=== 2. MATCH SEBAGAI EKSPRESI (RETURN VALUE) ===");
    let kode_status = 404;
    let pesan = match kode_status {
        200 => "OK - Berhasil",
        201 => "Created - Data dibuat",
        400 => "Bad Request - Permintaan tidak valid",
        401 | 403 => "Unauthorized / Forbidden",
        404 => "Not Found - Halaman tidak ditemukan",
        500..=599 => "Server Error",
        _ => "Status tidak dikenal",
    };
    println!("HTTP {kode_status}: {pesan}");

    println!("\n=== 3. MATCH GUARDS (KONDISI TAMBAHAN DENGAN 'if') ===");

    let angka_uji = 14;
    match angka_uji {
        x if x < 0 => println!("{x} adalah bilangan negatif"),
        x if x % 2 == 0 => println!("{x} adalah bilangan genap positif"),
        x => println!("{x} adalah bilangan ganjil positif"),
    }

    println!("\n=== 4. MATCHING DESTRUCTURING PADA TUPLE ===");
    let koordinat = (0, -5);
    match koordinat {
        (0, 0) => println!("Titik berada di pusat Origin (0, 0)"),
        (x, 0) => println!("Titik berada di sumbu X pada x = {x}"),
        (0, y) => println!("Titik berada di sumbu Y pada y = {y}"),
        (x, y) => println!("Titik berada di kuadran bebas pada ({x}, {y})"),
    }
}
