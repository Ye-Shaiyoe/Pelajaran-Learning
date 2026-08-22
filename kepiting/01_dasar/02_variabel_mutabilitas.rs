const KECEPATAN_CAHAYA_M_S: u64 = 299_792_458;
const APP_NAME: &str = "Rust Pembelajaran";

fn main() {
    println!("=== 1. IMMUTABILITY BY DEFAULT ===");

    let x = 10;
    println!("Nilai x (immutable): {x}");

    println!("\n=== 2. MUTABILITAS DENGAN 'mut' ===");

    let mut saldo = 50_000;
    println!("Saldo awal: Rp{saldo}");
    saldo = saldo + 25_000;
    println!("Saldo setelah ditambah: Rp{saldo}");

    println!("\n=== 3. KONSTANTA ===");
    println!("Aplikasi: {APP_NAME}");
    println!("Kecepatan Cahaya: {KECEPATAN_CAHAYA_M_S} m/s");

    println!("\n=== 4. VARIABLE SHADOWING ===");

    let data = "42";
    println!("Data string: '{data}'");

    let data: i32 = data.parse().expect("Harus angka valid");
    println!("Data integer (setelah shadowing): {data}");

    let angka = 5;
    {
        let angka = angka * 10;
        println!("Nilai angka di DALAM block: {angka}");
    }
    println!("Nilai angka di LUAR block: {angka}");
}
