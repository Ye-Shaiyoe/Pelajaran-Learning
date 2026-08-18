//! # Level 10.3: Rust Idiomatic Design Patterns
//!
//! Konsep yang dipelajari:
//! 1. Builder Pattern (Konstruksi objek kompleks dengan method chaining)
//! 2. Newtype Pattern (Type safety ekstra, contoh ID pengguna vs ID produk)
//! 3. Typestate Pattern (Memastikan state machine aman di waktu kompilasi)

// 1. Newtype Pattern
#[derive(Debug, PartialEq, Eq)]
pub struct UserId(pub u64);

#[derive(Debug, PartialEq, Eq)]
pub struct OrderId(pub u64);

// 2. Builder Pattern
#[derive(Debug)]
pub struct ServerConfig {
    pub host: String,
    pub port: u16,
    pub max_koneksi: u32,
    pub tls_aktif: bool,
}

pub struct ServerConfigBuilder {
    host: String,
    port: u16,
    max_koneksi: u32,
    tls_aktif: bool,
}

impl ServerConfigBuilder {
    pub fn new() -> Self {
        Self {
            host: String::from("127.0.0.1"),
            port: 8080,
            max_koneksi: 100,
            tls_aktif: false,
        }
    }

    pub fn host(mut self, host: &str) -> Self {
        self.host = String::from(host);
        self
    }

    pub fn port(mut self, port: u16) -> Self {
        self.port = port;
        self
    }

    pub fn max_koneksi(mut self, max: u32) -> Self {
        self.max_koneksi = max;
        self
    }

    pub fn enable_tls(mut self, enable: bool) -> Self {
        self.tls_aktif = enable;
        self
    }

    pub fn build(self) -> ServerConfig {
        ServerConfig {
            host: self.host,
            port: self.port,
            max_koneksi: self.max_koneksi,
            tls_aktif: self.tls_aktif,
        }
    }
}

pub fn jalankan_demo() {
    println!("=== 10.3 IDIOMATIC DESIGN PATTERNS ===");

    // 1. Newtype Pattern
    let user = UserId(1001);
    let order = OrderId(1001);
    println!("Newtype: User={:?}, Order={:?} (Tidak bisa tertukar secara tipe)", user, order);

    // 2. Builder Pattern
    let config = ServerConfigBuilder::new()
        .host("0.0.0.0")
        .port(443)
        .max_koneksi(5000)
        .enable_tls(true)
        .build();

    println!("Konfigurasi Server via Builder Pattern: {:?}", config);
    println!();
}
