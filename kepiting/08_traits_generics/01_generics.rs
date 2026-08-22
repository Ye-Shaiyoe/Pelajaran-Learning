fn cari_terbesar<T: PartialOrd + Copy>(list: &[T]) -> T {
    let mut terbesar = list[0];
    for &item in list {
        if item > terbesar {
            terbesar = item;
        }
    }
    terbesar
}

#[derive(Debug)]
struct Titik<T, U> {
    x: T,
    y: U,
}

impl<T, U> Titik<T, U> {
    fn buat(x: T, y: U) -> Self {
        Self { x, y }
    }

    fn campur<V, W>(self, other: Titik<V, W>) -> Titik<T, W> {
        Titik {
            x: self.x,
            y: other.y,
        }
    }
}

fn main() {
    println!("=== 1. GENERIC FUNCTION ===");
    let daftar_i32 = [34, 50, 25, 100, 65];
    let max_i32 = cari_terbesar(&daftar_i32);
    println!("Nilai terbesar i32: {max_i32}");

    let daftar_char = ['y', 'm', 'a', 'q', 'z'];
    let max_char = cari_terbesar(&daftar_char);
    println!("Nilai terbesar char: '{max_char}'");

    let daftar_f64 = [1.2, 5.8, 3.4, 9.9, 0.5];
    let max_f64 = cari_terbesar(&daftar_f64);
    println!("Nilai terbesar f64: {max_f64}");

    println!("\n=== 2. GENERIC STRUCT & METHOD ===");
    let p1 = Titik::buat(5, 10.4);
    let p2 = Titik::buat("Halo", '🦀');

    println!("Titik 1: {:?}", p1);
    println!("Titik 2: {:?}", p2);

    let p3 = p1.campur(p2);
    println!("Titik 3 (hasil mixup): {:?}", p3);
}
