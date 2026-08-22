fn main() {

    println!("Halo, Dunia! Selamat datang di pembelajaran Rust 🦀");

    print!("Ini dicetak menggunakan print! ");
    print!("(dalam satu baris yang sama)\n");

    let nama = "Ferris Si Kepiting";
    let tahun = 2026;
    println!("Nama maskot: {}, Dibuat/Dipakai tahun: {}", nama, tahun);

    println!("Halo, {nama}! Semangat belajar di tahun {tahun}!");

    println!("Posisi argumen: {0} suka makan {1}, dan {0} suka coding Rust", "Budi", "Nasi Goreng");
    println!("Format biner: {:b}", 42);
    println!("Format hex: 0x{:x}", 255);
    println!("Format padding: {:0>5}", 7);

    eprintln!("Ini adalah pesan log error/peringatan ke stderr");
}
