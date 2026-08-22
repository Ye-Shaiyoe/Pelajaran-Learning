fn main() {
    println!("=== 1. RAW POINTERS (*const T dan *mut T) ===");
    let mut angka = 100;

    let r1: *const i32 = &angka as *const i32;
    let r2: *mut i32 = &mut angka as *mut i32;

    unsafe {
        println!("Membaca r1 via unsafe: {}", *r1);
        *r2 = 250;
        println!("Mengubah r2 via unsafe, nilai sekarang: {}", *r2);
    }

    println!("Nilai variabel angka di safe code: {angka}");

    println!("\n=== 2. MEMANGGIL FUNGSI UNSAFE ===");
    unsafe {
        operasi_berbahaya();
    }

    println!("\n=== 3. FOREIGN FUNCTION INTERFACE (FFI) DENGAN C STANDARD LIBRARY ===");

    extern "C" {
        fn abs(input: i32) -> i32;
    }

    let nilai_negatif = -42;
    let nilai_positif = unsafe { abs(nilai_negatif) };

    println!("Nilai C abs({nilai_negatif}) = {nilai_positif}");
}

unsafe fn operasi_berbahaya() {
    println!("  [UNSAFE BLOCK] Menjalankan operasi memori langsung level rendah!");
}
