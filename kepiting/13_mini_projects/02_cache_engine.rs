use std::collections::HashMap;
use std::time::{Duration, Instant};

struct CacheItem<V> {
    nilai: V,
    dibuat_pada: Instant,
    durasi_ttl: Duration,
}

impl<V> CacheItem<V> {
    fn is_expired(&self) -> bool {
        self.dibuat_pada.elapsed() > self.durasi_ttl
    }
}

pub struct SimpleCache<K, V> {
    penyimpanan: HashMap<K, CacheItem<V>>,
    kapasitas_maks: usize,
}

impl<K: std::hash::Hash + Eq + Clone, V: Clone> SimpleCache<K, V> {
    pub fn baru(kapasitas: usize) -> Self {
        Self {
            penyimpanan: HashMap::new(),
            kapasitas_maks: kapasitas,
        }
    }

    pub fn set(&mut self, key: K, value: V, ttl_detik: u64) {

        if self.penyimpanan.len() >= self.kapasitas_maks {
            self.bersihkan_kadaluarsa();
        }

        let item = CacheItem {
            nilai: value,
            dibuat_pada: Instant::now(),
            durasi_ttl: Duration::from_secs(ttl_detik),
        };

        self.penyimpanan.insert(key, item);
    }

    pub fn get(&mut self, key: &K) -> Option<V> {
        if let Some(item) = self.penyimpanan.get(key) {
            if item.is_expired() {

                self.penyimpanan.remove(key);
                None
            } else {
                Some(item.nilai.clone())
            }
        } else {
            None
        }
    }

    pub fn bersihkan_kadaluarsa(&mut self) -> usize {
        let sebelum = self.penyimpanan.len();
        self.penyimpanan.retain(|_, item| !item.is_expired());
        sebelum - self.penyimpanan.len()
    }

    pub fn jumlah_item_aktif(&self) -> usize {
        self.penyimpanan.len()
    }
}

fn main() {
    println!("=== DEMO IN-MEMORY CACHE ENGINE DENGAN TTL ===");

    let mut cache = SimpleCache::baru(5);

    println!("Menyimpan session user (TTL 2 detik)...");
    cache.set(String::from("session:user:101"), String::from("token_abc_123"), 2);

    println!("Menyimpan data statis profil (TTL 10 detik)...");
    cache.set(String::from("profile:user:101"), String::from("{\"name\": \"Akrom\"}"), 10);

    let key_sess = String::from("session:user:101");
    match cache.get(&key_sess) {
        Some(val) => println!("  -> [HIT] Ditemukan: {val}"),
        None => println!("  -> [MISS] Data tidak ada / kadaluarsa"),
    }

    println!("\nMenunggu selama 3 detik untuk simulasi timeout...");
    std::thread::sleep(Duration::from_secs(3));

    match cache.get(&key_sess) {
        Some(val) => println!("  -> [HIT] Ditemukan: {val}"),
        None => println!("  -> [MISS] Session telah otomatis kadaluarsa (Expired)!"),
    }

    let key_prof = String::from("profile:user:101");
    match cache.get(&key_prof) {
        Some(val) => println!("  -> [HIT] Profil masih aktif: {val}"),
        None => println!("  -> [MISS] Profil hilang"),
    }

    println!("\nJumlah item aktif di cache: {}", cache.jumlah_item_aktif());
}
