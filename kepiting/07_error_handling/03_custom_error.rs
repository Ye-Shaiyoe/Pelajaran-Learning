use std::fmt;
use std::error::Error;

#[derive(Debug)]
enum BankError {
    SaldoTidakCukup { saldo_saat_ini: u64, tarik: u64 },
    AkunDibekukan(String),
    JumlahTidakValid,
}

impl fmt::Display for BankError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            BankError::SaldoTidakCukup { saldo_saat_ini, tarik } => {
                write!(
                    f,
                    "Saldo tidak mencukupi! Saldo saat ini: Rp{}, Penarikan: Rp{}",
                    saldo_saat_ini, tarik
                )
            }
            BankError::AkunDibekukan(alasan) => {
                write!(f, "Akun bank sedang dibekukan karena: {}", alasan)
            }
            BankError::JumlahTidakValid => {
                write!(f, "Nominal transaksi harus lebih besar dari 0!")
            }
        }
    }
}

impl Error for BankError {}

struct RekeningBank {
    pemilik: String,
    saldo: u64,
    aktif: bool,
}

impl RekeningBank {
    fn tarik_uang(&mut self, jumlah: u64) -> Result<u64, BankError> {
        if !self.aktif {
            return Err(BankError::AkunDibekukan(String::from("Aktivitas mencurigakan terdeteksi")));
        }

        if jumlah == 0 {
            return Err(BankError::JumlahTidakValid);
        }

        if jumlah > self.saldo {
            return Err(BankError::SaldoTidakCukup {
                saldo_saat_ini: self.saldo,
                tarik: jumlah,
            });
        }

        self.saldo -= jumlah;
        Ok(self.saldo)
    }
}

fn main() {
    println!("=== DEMO CUSTOM ERROR HANDLING ===");
    let mut rekening = RekeningBank {
        pemilik: String::from("Siti Rahma"),
        saldo: 500_000,
        aktif: true,
    };

    println!("Pemilik Akun: {}, Saldo: Rp{}", rekening.pemilik, rekening.saldo);

    match rekening.tarik_uang(200_000) {
        Ok(sisa) => println!("Tarik Rp200.000 sukses! Sisa saldo: Rp{sisa}"),
        Err(e) => eprintln!("Error: {e}"),
    }

    match rekening.tarik_uang(400_000) {
        Ok(sisa) => println!("Tarik sukses! Sisa saldo: Rp{sisa}"),
        Err(e) => eprintln!("Gagal: {e}"),
    }

    rekening.aktif = false;
    match rekening.tarik_uang(50_000) {
        Ok(sisa) => println!("Tarik sukses! Sisa saldo: Rp{sisa}"),
        Err(e) => eprintln!("Gagal: {e}"),
    }
}
