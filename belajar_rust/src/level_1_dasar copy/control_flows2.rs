pub fn akrom() {
    println("Percabangan dalam Rust");

    let usia = 18;
    let status = if usia >= 18 {
        "Dewasa"
    } else if usia < 18 && usia > 13 {
        "Remaja"
    } else {
        "Anak-anak"
    };
    println!("Status: {}", status);

    // Looping dengan while loop
    let mut angka = 0;
    let hasil_loop = loop {
        angka += 1;
        if angka == 5 {
            break angka * 10;
        }
    }; 
    println!("Hasil: {}", hasil_loop);

    // While loop
    let mut sisa = 3;
    print!("Hitung mundur:");
    while sisa > 0 {
        print!("{sisa}...");
        sisa -= 1;
    }
    println!("Selesai!");

    // For in loop dan range
    print!("For in 1..=5:");
    for angka in 1..=5 {
        print!("{angka}");
    }
    println!();

    // Loop label
    let mut total_iterasi = 0;
    'outer: for i in 1..=3 {
        for j in 1..=3 {
            total_iterasi += 1;
            if i == 2 && j == 2 {
                println!("Keluar dari 'outer loop saat i={i}, j={j}");
                break 'outer;
            }
        }
    }
    println!("Total iterasi sebelum break 'outer': {total_iterasi}");
    println!();
}