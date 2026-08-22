#[derive(Debug)]
enum PesanJaringan {
    Keluar,
    KirimTeks(String),
    PindahPosisi { x: i32, y: i32 },
    UbahWarna(u8, u8, u8),
}

impl PesanJaringan {

    fn proses(&self) {
        match self {
            PesanJaringan::Keluar => {
                println!("[SERVER] User telah keluar dari sesi.");
            }
            PesanJaringan::KirimTeks(konten) => {
                println!("[CHAT] Pesan diterima: '{konten}'");
            }
            PesanJaringan::PindahPosisi { x, y } => {
                println!("[GERAK] Karakter berpindah ke koordinat X: {x}, Y: {y}");
            }
            PesanJaringan::UbahWarna(r, g, b) => {
                println!("[WARNA] Mengubah tema warna ke RGB({r}, {g}, {b})");
            }
        }
    }
}

#[derive(Debug)]
enum StatusPembayaran {
    Pending,
    Sukses { id_transaksi: String, jumlah: u64 },
    Gagal { alasan: String },
}

fn main() {
    println!("=== 1. ENUM DENGAN VARIAN DATA ===");
    let pesan1 = PesanJaringan::KirimTeks(String::from("Halo kawan!"));
    let pesan2 = PesanJaringan::PindahPosisi { x: 120, y: 350 };
    let pesan3 = PesanJaringan::UbahWarna(255, 128, 0);
    let pesan4 = PesanJaringan::Keluar;

    pesan1.proses();
    pesan2.proses();
    pesan3.proses();
    pesan4.proses();

    println!("\n=== 2. MATCHING STATUS TRANSAKSI ===");
    let daftar_status = vec![
        StatusPembayaran::Pending,
        StatusPembayaran::Sukses {
            id_transaksi: String::from("TRX-998811"),
            jumlah: 150_000,
        },
        StatusPembayaran::Gagal {
            alasan: String::from("Saldo rekening tidak mencukupi"),
        },
    ];

    for status in daftar_status {
        match status {
            StatusPembayaran::Pending => println!("[STATUS] Menunggu pembayaran pelanggan..."),
            StatusPembayaran::Sukses { id_transaksi, jumlah } => {
                println!("[STATUS] Pembayaran BERHASIL! ID: {id_transaksi}, Sebesar: Rp{jumlah}");
            }
            StatusPembayaran::Gagal { alasan } => {
                println!("[STATUS] Pembayaran DITOLAK. Alasan: {alasan}");
            }
        }
    }
}
