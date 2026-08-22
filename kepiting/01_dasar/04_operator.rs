fn main() {
    println!("=== 1. OPERATOR ARITMATIKA ===");
    let a = 20;
    let b = 6;

    let tambah = a + b;
    let kurang = a - b;
    let kali = a * b;
    let bagi_int = a / b;
    let bagi_float = 20.0 / 6.0;
    let sisa_bagi = a % b;

    println!("{a} + {b} = {tambah}");
    println!("{a} - {b} = {kurang}");
    println!("{a} * {b} = {kali}");
    println!("{a} / {b} (integer) = {bagi_int}");
    println!("20.0 / 6.0 (float) = {bagi_float:.2}");
    println!("{a} % {b} = {sisa_bagi}");

    println!("\n=== 2. OPERATOR PERBANDINGAN (RELASIONAL) ===");
    println!("{a} == {b} : {}", a == b);
    println!("{a} != {b} : {}", a != b);
    println!("{a} > {b}  : {}", a > b);
    println!("{a} < {b}  : {}", a < b);
    println!("{a} >= {b} : {}", a >= b);
    println!("{a} <= {b} : {}", a <= b);

    println!("\n=== 3. OPERATOR LOGIKA (BOOLEAN) ===");
    let punya_tiket = true;
    let punya_ktp = false;

    let boleh_masuk = punya_tiket && punya_ktp;
    let butuh_bantuan = !punya_ktp || !punya_tiket;

    println!("Punya tiket AND KTP: {boleh_masuk}");
    println!("Butuh verifikasi manual: {butuh_bantuan}");

    println!("\n=== 4. OPERATOR BITWISE ===");
    let x: u8 = 0b0000_1100;
    let y: u8 = 0b0000_1010;

    println!("x & y (Bitwise AND) : {:08b} (nilai: {})", x & y, x & y);
    println!("x | y (Bitwise OR)  : {:08b} (nilai: {})", x | y, x | y);
    println!("x ^ y (Bitwise XOR) : {:08b} (nilai: {})", x ^ y, x ^ y);
    println!("!x    (Bitwise NOT) : {:08b} (nilai: {})", !x, !x);
    println!("x << 2 (Shift Left) : {:08b} (nilai: {})", x << 2, x << 2);
    println!("x >> 1 (Shift Right): {:08b} (nilai: {})", x >> 1, x >> 1);

    println!("\n=== 5. COMPOUND ASSIGNMENT ===");
    let mut skor = 100;
    skor += 50;
    skor -= 20;
    skor *= 2;
    println!("Skor akhir: {skor}");
}
