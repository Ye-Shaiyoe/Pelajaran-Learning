fn main() {
    println!("=== 1. MEMBUAT DAN MENAMBAHKAN ELEMEN ===");

    let mut angka: Vec<i32> = Vec::new();
    angka.push(10);
    angka.push(20);
    angka.push(30);

    let mut buah = vec!["Apel", "Pisang", "Jeruk"];
    buah.push("Mangga");

    println!("Vector Angka : {:?}", angka);
    println!("Vector Buah  : {:?}", buah);
    println!("Panjang Buah : {}", buah.len());

    println!("\n=== 2. MENGAKSES ELEMEN VECTOR ===");

    let item_pertama = &buah[0];
    println!("Buah pertama: {item_pertama}");

    let index_uji = 10;
    match buah.get(index_uji) {
        Some(item) => println!("Elemen pada index {index_uji}: {item}"),
        None => println!("Index {index_uji} di luar jangkauan (aman dari crash!)"),
    }

    println!("\n=== 3. MENGHAPUS ELEMEN DENGAN .pop() ===");

    if let Some(terakhir) = buah.pop() {
        println!("Buah yang dihapus: {terakhir}");
    }
    println!("Kondisi vector buah sekarang: {:?}", buah);

    println!("\n=== 4. ITERASI DAN MODIFIKASI ELEMEN ===");
    let mut nilai_siswa = vec![70, 85, 90, 65];

    print!("Nilai asli: ");
    for n in &nilai_siswa {
        print!("{n} ");
    }
    println!();

    for n in &mut nilai_siswa {
        *n += 5;
    }

    println!("Nilai setelah ditambah bonus 5: {:?}", nilai_siswa);
}
