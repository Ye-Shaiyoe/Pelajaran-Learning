use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

#[derive(Debug)]
struct AkunNasabah {
    id: u32,
    nama: String,
    saldo: Mutex<u64>,
}

struct Bank {
    daftar_akun: Vec<Arc<AkunNasabah>>,
}

impl Bank {
    fn baru() -> Self {
        Self {
            daftar_akun: Vec::new(),
        }
    }

    fn buka_rekening(&mut self, id: u32, nama: &str, saldo_awal: u64) -> Arc<AkunNasabah> {
        let akun = Arc::new(AkunNasabah {
            id,
            nama: nama.to_string(),
            saldo: Mutex::new(saldo_awal),
        });
        self.daftar_akun.push(Arc::clone(&akun));
        akun
    }

    fn transfer(dari: &Arc<AkunNasabah>, ke: &Arc<AkunNasabah>, jumlah: u64) -> Result<(), String> {

        let (akun_pertama, akun_kedua) = if dari.id < ke.id {
            (dari, ke)
        } else {
            (ke, dari)
        };

        let mut lock_pertama = akun_pertama.saldo.lock().unwrap();
        let mut lock_kedua = akun_kedua.saldo.lock().unwrap();

        let (saldo_dari, saldo_ke) = if dari.id < ke.id {
            (&mut *lock_pertama, &mut *lock_kedua)
        } else {
            (&mut *lock_kedua, &mut *lock_pertama)
        };

        if *saldo_dari < jumlah {
            return Err(format!(
                "Transfer gagal: Saldo {} (Rp{}) tidak cukup untuk transfer Rp{}",
                dari.nama, *saldo_dari, jumlah
            ));
        }

        *saldo_dari -= jumlah;
        *saldo_ke += jumlah;

        println!(
            "  [TRANSFER SUKSES] Rp{} dari '{}' ke '{}'",
            jumlah, dari.nama, ke.nama
        );
        Ok(())
    }
}

fn main() {
    println!("=== SIMULASI SISTEM BANK MULTI-THREADING ===");

    let mut bank = Bank::baru();
    let akun_andi = bank.buka_rekening(1, "Andi", 1_000_000);
    let akun_budi = bank.buka_rekening(2, "Budi", 500_000);
    let akun_citra = bank.buka_rekening(3, "Citra", 750_000);

    println!("Kondisi Saldo Awal:");
    println!("  - Andi  : Rp{}", *akun_andi.saldo.lock().unwrap());
    println!("  - Budi  : Rp{}", *akun_budi.saldo.lock().unwrap());
    println!("  - Citra : Rp{}", *akun_citra.saldo.lock().unwrap());

    println!("\nMenjalankan 6 transaksi transfer paralel antar thread...");
    let mut worker_handles = vec![];

    {
        let a = Arc::clone(&akun_andi);
        let b = Arc::clone(&akun_budi);
        worker_handles.push(thread::spawn(move || {
            thread::sleep(Duration::from_millis(20));
            let _ = Bank::transfer(&a, &b, 100_000);
        }));
    }

    {
        let b = Arc::clone(&akun_budi);
        let c = Arc::clone(&akun_citra);
        worker_handles.push(thread::spawn(move || {
            thread::sleep(Duration::from_millis(15));
            let _ = Bank::transfer(&b, &c, 50_000);
        }));
    }

    {
        let c = Arc::clone(&akun_citra);
        let a = Arc::clone(&akun_andi);
        worker_handles.push(thread::spawn(move || {
            thread::sleep(Duration::from_millis(30));
            let _ = Bank::transfer(&c, &a, 200_000);
        }));
    }

    {
        let a = Arc::clone(&akun_andi);
        let c = Arc::clone(&akun_citra);
        worker_handles.push(thread::spawn(move || {
            thread::sleep(Duration::from_millis(25));
            let _ = Bank::transfer(&a, &c, 150_000);
        }));
    }

    for h in worker_handles {
        h.join().unwrap();
    }

    println!("\n=== KONDISI SALDO AKHIR SETELAH TRANSAKSI SELESAI ===");
    let total_andi = *akun_andi.saldo.lock().unwrap();
    let total_budi = *akun_budi.saldo.lock().unwrap();
    let total_citra = *akun_citra.saldo.lock().unwrap();

    println!("  - Andi  : Rp{}", total_andi);
    println!("  - Budi  : Rp{}", total_budi);
    println!("  - Citra : Rp{}", total_citra);

    let total_uang = total_andi + total_budi + total_citra;
    println!("\nTotal uang dalam sistem bank: Rp{} (Konservasi nilai terbukti aman!)", total_uang);
    assert_eq!(total_uang, 2_250_000);
}
