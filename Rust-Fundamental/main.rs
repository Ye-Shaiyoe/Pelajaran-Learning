use::std::io;

fn main () {

    let mut umur = String::new();
    let mut name = String::new();

    let x = 5; 
    let y = 10;
    let hasil = x * y;

    println!("Masukan nama mu: ");
    io::stdin().read_line(&mut name).expect("Gagal membaca input");

    println!("Berapa Umur mu: ");
    io::stdin().read_line(&mut umur).expect("Gagal membaca input");

    let mut name = name.trim();
    let umur = umur.trim();
    println!("Halo, perkenalkan namaku {name} dan aku {umur} tahun");
    println!("x({x}) * y({y}) = {hasil}");

}