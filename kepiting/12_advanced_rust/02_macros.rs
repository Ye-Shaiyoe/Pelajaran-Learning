macro_rules! sapa {
    () => {
        println!("Halo dari macro tanpa argumen!");
    };
    ($nama:expr) => {
        println!("Halo, {}! Senang bertemu denganmu.", $nama);
    };
}

macro_rules! buat_vector {

    ( $( $x:expr ),* ) => {
        {
            let mut temp_vec = Vec::new();
            $(
                temp_vec.push($x);
            )*
            temp_vec
        }
    };
}

macro_rules! kalkulasi {
    (tambah $a:expr, $b:expr) => {
        $a + $b
    };
    (kali $a:expr, $b:expr) => {
        $a * $b
    };
}

fn main() {
    println!("=== 1. MACRO SEDERHANA ===");
    sapa!();
    sapa!("Ferris si Kepiting");

    println!("\n=== 2. MACRO VARIADIC (MIRIP VEC!) ===");
    let list_angka = buat_vector![10, 20, 30, 40, 50];
    let list_kata = buat_vector!["Rust", "Adalah", "Masa", "Depan"];

    println!("Vector Angka: {:?}", list_angka);
    println!("Vector Kata : {:?}", list_kata);

    println!("\n=== 3. MACRO CUSTOM SYNTAX ===");
    let hasil_tambah = kalkulasi!(tambah 15, 35);
    let hasil_kali = kalkulasi!(kali 6, 7);

    println!("kalkulasi!(tambah 15, 35) = {hasil_tambah}");
    println!("kalkulasi!(kali 6, 7)     = {hasil_kali}");
}
