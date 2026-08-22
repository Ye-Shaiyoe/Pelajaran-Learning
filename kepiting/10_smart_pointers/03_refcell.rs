use std::cell::RefCell;
use std::rc::Rc;

trait PengirimPesan {
    fn kirim(&self, pesan: &str);
}

struct MockPengirimPesan {

    pesan_terkirim: RefCell<Vec<String>>,
}

impl MockPengirimPesan {
    fn baru() -> Self {
        Self {
            pesan_terkirim: RefCell::new(vec![]),
        }
    }
}

impl PengirimPesan for MockPengirimPesan {
    fn kirim(&self, pesan: &str) {

        self.pesan_terkirim.borrow_mut().push(pesan.to_string());
    }
}

fn main() {
    println!("=== 1. INTERIOR MUTABILITY DENGAN RefCell<T> ===");
    let mock = MockPengirimPesan::baru();

    mock.kirim("Notifikasi 1: Akun dibuat");
    mock.kirim("Notifikasi 2: Pembayaran diterima");
    mock.kirim("Notifikasi 3: Pesanan dikirim");

    println!("Daftar log yang tercatat dalam Mock:");
    for (i, log) in mock.pesan_terkirim.borrow().iter().enumerate() {
        println!("  {}. {}", i + 1, log);
    }

    println!("\n=== 2. MENGGABUNGKAN Rc<RefCell<T>> UNTUK MULTI-OWNER MUTABILITY ===");

    let nilai_bersama = Rc::new(RefCell::new(50));

    let clone_a = Rc::clone(&nilai_bersama);
    let clone_b = Rc::clone(&nilai_bersama);

    *clone_a.borrow_mut() += 30;

    *clone_b.borrow_mut() += 20;

    println!("Nilai akhir setelah dimodifikasi kedua pihak: {}", *nilai_bersama.borrow());
}
