fn main() {
    println!("=== 1. PERULANGAN TAK TERBATAS: 'loop' & RETURN DENGAN BREAK ===");

    let mut hitungan = 0;
    let hasil = loop {
        hitungan += 1;
        if hitungan == 10 {

            break hitungan * 2;
        }
    };
    println!("Hasil dari perulangan loop: {hasil}");

    println!("\n=== 2. PERULANGAN BERSYARAT: 'while' ===");
    let mut countdown = 3;
    while countdown > 0 {
        println!("Hitung mundur: {countdown}...");
        countdown -= 1;
    }
    println!("Meluncur! 🚀");

    println!("\n=== 3. PERULANGAN KOLEKSI & RANGE: 'for in' ===");

    print!("Range eksklusif (1..5): ");
    for i in 1..5 {
        print!("{i} ");
    }
    println!();

    print!("Range inklusif (1..=5): ");
    for i in 1..=5 {
        print!("{i} ");
    }
    println!();

    print!("Reverse range (1..=3).rev(): ");
    for i in (1..=3).rev() {
        print!("{i} ");
    }
    println!();

    let daftar_bahasa = ["Rust", "C++", "Python", "Go"];
    println!("Daftar Bahasa Pemrograman:");
    for (index, bahasa) in daftar_bahasa.iter().enumerate() {
        println!("  {}. {}", index + 1, bahasa);
    }

    println!("\n=== 4. NESTED LOOP & LABELS ('label:) ===");

    let mut count = 0;
    'outer_loop: loop {
        println!("Memasuki outer loop (count = {count})");
        let mut remaining = 5;

        loop {
            println!("  Remaining inner: {remaining}");
            if remaining == 3 {
                println!("  -> Keluar dari inner loop dengan break biasa");
                break;
            }
            if count == 1 {
                println!("  -> Menghentikan SEMUA loop dengan 'break 'outer_loop'");
                break 'outer_loop;
            }
            remaining -= 1;
        }

        count += 1;
    }
    println!("Perulangan bersarang selesai.");
}
