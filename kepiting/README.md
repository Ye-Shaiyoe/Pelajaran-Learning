# 🦀 Pembelajaran Bahasa Pemrograman Rust (`kepiting`)

Selamat datang di modul pembelajaran bahasa pemrograman **Rust** (yang sering dilambangkan dengan maskot kepiting: **Ferris** 🦀)!

Folder ini berisi materi belajar Rust dari level dasar hingga mahir yang dikemas dalam bentuk **file-file Rust standalone (`.rs`)**. 
Seluruh file di dalam folder ini berdiri sendiri dan **TIDAK** membutuhkan konfigurasi `Cargo.toml` ataupun folder `src/`. Setiap file memiliki fungsi `fn main()` dan dapat langsung dikompilasi dengan compiler `rustc`.

---

## 🚀 Cara Mengompilasi & Menjalankan

Untuk mengompilasi dan langsung mengeksekusi file `.rs`:

```bash
# Format umum:
rustc <nama_file>.rs && ./<nama_file_tanpa_ekstensi>

# Contoh:
rustc 01_dasar/01_hello_world.rs && ./01_hello_world
```

Jika ingin menghapus file biner setelah selesai dijalankan:
```bash
./01_hello_world && rm 01_hello_world
```

---

## 📚 Daftar Modul & Kurikulum

| No | Modul | Topik Utama |
|---|---|---|
| **01** | `01_dasar` | Hello World, Variabel (`let`, `mut`, `const`), Shadowing, Tipe Data, Operator |
| **02** | `02_control_flow` | Percabangan `if`/`else`, Perulangan (`loop`, `while`, `for`, labels), Pattern Matching (`match`) |
| **03** | `03_fungsi_dan_closures` | Fungsi, Statement vs Expression, Closures (`Fn`, `FnMut`, `FnOnce`), `move` |
| **04** | `04_ownership_borrowing` | 3 Hukum Ownership, Stack vs Heap, References (`&`, `&mut`), Borrow Checker, Slices |
| **05** | `05_structs_enums` | Structs (Classic, Tuple, Unit), Methods (`impl`), Enums, `Option<T>`, `Result<T, E>` |
| **06** | `06_koleksi_data` | Dynamic Arrays (`Vec<T>`), UTF-8 Strings (`String` vs `&str`), Hash Maps (`HashMap<K, V>`) |
| **07** | `07_error_handling` | Unrecoverable (`panic!`), Recoverable (`Result<T, E>`), Operator `?`, Custom Error |
| **08** | `08_traits_generics` | Generics, Traits (Interface), Default Implementations, Trait Bounds, Trait Objects |
| **09** | `09_lifetimes` | Borrow Checker Lifetimes (`'a`), Dangling Reference Prevention, Struct Lifetimes |
| **10** | `10_smart_pointers` | `Box<T>` (Heap), `Rc<T>` & `Arc<T>` (Reference Counting), `RefCell<T>` (Interior Mutability) |
| **11** | `11_concurrency` | Threads (`spawn`, `join`), Channels (`mpsc`), Shared State (`Arc<Mutex<T>>`) |
| **12** | `12_advanced_rust` | Unsafe Rust (Raw Pointers, FFI), Macros (`macro_rules!`), Functional Iterators |
| **13** | `13_mini_projects` | Mini Projects: CLI Todo, In-Memory Cache Engine, Text Analyzer, Concurrent Bank System |

---

Selamat belajar Rust! 🦀 *"Fearless Concurrency & Zero-Cost Abstractions!"*
