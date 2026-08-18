//! # Level 11.3: Mini Proyek - In-Memory Concurrent Cache Engine
//!
//! Menggabungkan: Arc, RwLock, HashMap, Generics, Option, Concurrency

use std::collections::HashMap;
use std::hash::Hash;
use std::sync::{Arc, RwLock};
use std::thread;
use std::time::Duration;

#[derive(Clone)]
pub struct ConcurrentCache<K, V>
where
    K: Eq + Hash + Clone,
    V: Clone,
{
    storage: Arc<RwLock<HashMap<K, V>>>,
}

impl<K, V> ConcurrentCache<K, V>
where
    K: Eq + Hash + Clone,
    V: Clone,
{
    pub fn new() -> Self {
        Self {
            storage: Arc::new(RwLock::new(HashMap::new())),
        }
    }

    pub fn set(&self, key: K, val: V) {
        let mut map = self.storage.write().unwrap();
        map.insert(key, val);
    }

    pub fn get(&self, key: &K) -> Option<V> {
        let map = self.storage.read().unwrap();
        map.get(key).cloned()
    }

    pub fn len(&self) -> usize {
        let map = self.storage.read().unwrap();
        map.len()
    }
}

pub fn jalankan_demo() {
    println!("=== 11.3 PROYEK MINI: CONCURRENT CACHE ENGINE ===");

    let cache: ConcurrentCache<String, String> = ConcurrentCache::new();

    // Mengisi cache awal
    cache.set(String::from("session:user_1"), String::from("TOKEN_ABC_123"));
    cache.set(String::from("app:version"), String::from("v3.2.0"));

    println!("Total key awal di cache: {}", cache.len());

    // Membaca dan menulis dari multiple threads secara paralel
    let mut worker_handles = vec![];

    for i in 1..=4 {
        let cache_clone = cache.clone();
        let handle = thread::spawn(move || {
            let key = format!("thread_data_{i}");
            let val = format!("Hasil komputasi thread #{i}");
            cache_clone.set(key.clone(), val);

            // Baca ulang
            if let Some(v) = cache_clone.get(&key) {
                println!("   [Worker {i}] Tersimpan di Cache -> {key}: \"{v}\"");
            }
            thread::sleep(Duration::from_millis(10));
        });
        worker_handles.push(handle);
    }

    for h in worker_handles {
        h.join().unwrap();
    }

    println!("Total key di cache setelah operasi multi-thread: {}", cache.len());
    println!("Nilai 'app:version': {:?}", cache.get(&String::from("app:version")));
    println!();
}
