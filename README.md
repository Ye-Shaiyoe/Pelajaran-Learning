# 🚀 Multi-Language Programming Lab & Learning Journey

> *"Di sekolah 30%, di rumah 70%"* — Koleksi catatan kode, eksperimen, dan modul pembelajaran mandiri lintas berbagai bahasa pemrograman.

---

[![C](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](./C%2B%2B/)
[![Rust](https://img.shields.io/badge/Language-Rust-DEA584?style=for-the-badge&logo=rust&logoColor=black)](./kepiting/)
[![Ada](https://img.shields.io/badge/Language-Ada-02569B?style=for-the-badge&logo=ada&logoColor=white)](./Ada/)
[![MATLAB](https://img.shields.io/badge/Language-MATLAB-ED592B?style=for-the-badge&logo=mathworks&logoColor=white)](./Matlab/)
[![JavaScript](https://img.shields.io/badge/Language-JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)](./Javascript/)
[![TypeScript](https://img.shields.io/badge/Language-TypeScript-3178C6?style=for-the-badge&logo=typescript&logoColor=white)](#-6-javascript--typescript-javascript-)
[![Arch Linux](https://img.shields.io/badge/OS-Arch%20Linux-1793D1?style=for-the-badge&logo=arch-linux&logoColor=white)](https://archlinux.org)

---

## 📌 Daftar Isi

- [Tentang Repositori](#-tentang-repositori)
- [Struktur & Direktori Bahasa](#-struktur--direktori-bahasa)
  - [1. Rust (`kepiting/` & `belajar_rust/`)](#-1-rust-kepiting--belajar_rust)
  - [2. C++ (`C++/`)](#-2-c-c)
  - [3. C (`C/`)](#-3-c-c)
  - [4. Ada (`Ada/`)](#-4-ada-ada)
  - [5. MATLAB (`Matlab/`)](#-5-matlab-matlab)
  - [6. JavaScript / TypeScript (`Javascript/`)](#-6-javascript--typescript-javascript)
- [Panduan Instalasi Toolchain (Arch Linux)](#-panduan-instalasi-toolchain-arch-linux)
- [Target & Roadmap Pembelajaran](#-target--roadmap-pembelajaran)
- [Lisensi & Penulis](#-lisensi--penulis)

---

## 📖 Tentang Repositori

Repositori ini merupakan laboratorium belajar pribadi (*coding playground & learning journey*) yang dirancang untuk menguasai berbagai paradigma pemrograman:

- **System Programming & Memory Safety**: C, C++, Rust, Ada
- **Mathematical & Scientific Computing**: MATLAB
- **Web, Full-Stack & Scripting**: JavaScript / TypeScript
- **Embedded & IoT**: ESP-8266, Microcontrollers

---

## 📂 Struktur & Direktori Bahasa

```plaintext
pembelajaran/
├── 🦀 kepiting/            # Modul belajar Rust standalone (01_dasar -> 13_mini_projects)
├── 📦 belajar_rust/        # Proyek belajar Rust berbasis Cargo
├── ⚡ C++/                 # Kurikulum komprehensif C++ (Basics, STL, OOP, Concurrency, ESP-8266)
├── 🧮 C/                   # Latihan memori tingkat rendah, pointer, dan sistem C (Persiapan/Modul C)
├── 🏛️ Ada/                 # Pemrograman sistem mission-critical & type safety (GNAT/GPRBuild)
├── 🔬 Matlab/              # Komputasi numerik & kalkulasi kedirgantaraan (aerospace)
└── 🌐 Javascript/          # Dasar JS, JS Modern/Advanced, dan integrasi Firebase/TypeScript
```

---

### 🦀 1. Rust (`kepiting/` & `belajar_rust/`)

Folder `kepiting/` berisi modul terstruktur dari tingkat dasar hingga mahir tanpa ketergantungan `Cargo` (kompilasi langsung via `rustc`), dilengkapi juga dengan folder `belajar_rust/` untuk proyek berbasis Cargo.

| Modul | Cakupan Materi |
|---|---|
| `01_dasar` | Hello World, Variabel (`mut`, `const`), Shadowing, Tipe Data, Operator |
| `02_control_flow` | `if/else`, Perulangan (`loop`, `while`, `for`), Pattern Matching (`match`) |
| `03_fungsi_dan_closures` | Fungsi, Statement vs Expression, Closures (`Fn`, `FnMut`, `FnOnce`) |
| `04_ownership_borrowing` | 3 Hukum Ownership, Stack vs Heap, References (`&`, `&mut`), Borrow Checker |
| `05_structs_enums` | Structs, Methods (`impl`), Enums, `Option<T>`, `Result<T, E>` |
| `06_koleksi_data` | Dynamic Vectors (`Vec<T>`), UTF-8 Strings, Hash Maps |
| `07_error_handling` | `panic!`, `Result<T, E>`, Operator `?`, Custom Error Handling |
| `08_traits_generics` | Generics, Traits (Interfaces), Trait Bounds, Trait Objects |
| `09_lifetimes` | Lifetime Annotations (`'a`), Struct Lifetimes, Pencegahan Dangling Pointer |
| `10_smart_pointers` | `Box<T>`, `Rc<T>`, `Arc<T>`, `RefCell<T>` (Interior Mutability) |
| `11_concurrency` | Multithreading (`spawn`, `join`), Channels (`mpsc`), `Arc<Mutex<T>>` |
| `12_advanced_rust` | Unsafe Rust, Raw Pointers, Macros (`macro_rules!`), Functional Iterators |
| `13_mini_projects` | CLI Todo List, In-Memory Cache Engine, File Analyzer, Concurrent Bank System |

**Cara Menjalankan:**
```bash
# Mengompilasi dan mengeksekusi file standalone
rustc kepiting/01_dasar/01_hello_world.rs && ./01_hello_world

# Atau via Cargo (pada belajar_rust)
cd belajar_rust && cargo run
```

---

### ⚡ 2. C++ (`C++/`)

Modul pembelajaran C++ mulai dari konsep fundamental, paradigma Object-Oriented Programming (OOP), Modern C++ (C++11 hingga C++20), hingga pemrograman embedded microcontroller.

- **01_basics s/d 05_pointers**: Dasar sintaks, kontrol alur, fungsi, array, string, dan alokasi pointer.
- **06_oop & 07_inheritance**: Class, Constructor/Destructor, Encapsulation, Polymorphism, Inheritance.
- **08_templates & 09_stl**: Generic programming, STL Containers (Vector, Map, Set, Algorithm).
- **10_memory s/d 12_file_io**: Dynamic memory management (`new`/`delete`), RAII, Exception handling, File I/O.
- **13_lambda s/d 15_modern_cpp**: Lambda expressions, Smart pointers (`unique_ptr`, `shared_ptr`), Multithreading & Concurrency.
- **16_design_patterns**: Creational, Structural, & Behavioral patterns di C++.
- **ESP-8266**: Sketch Arduino/C++ untuk IoT dan kontrol perangkat keras.

**Cara Menjalankan:**
```bash
# Kompilasi C++ dengan standar C++17/20
g++ -std=c++17 C++/01_basics/01_hello_world.cpp -o hello_cpp && ./hello_cpp
```

---

### 🧮 3. C (`C/`)

Fokus pada penguasaan pemrograman tingkat rendah, manipulasi memori manual, struct & union, pointer aritmatika, alokasi memori dinamis (`malloc`/`free`), dan struktur data dasar (Linked List, Stack, Queue).

**Cara Menjalankan:**
```bash
gcc -Wall -Wextra -std=c11 program.c -o program && ./program
```

---

### 🏛️ 4. Ada (`Ada/`)

Bahasa yang dirancang khusus untuk keandalan tinggi (*high-integrity*), *type-safety* ketat, sistem avionik, dan *embedded safety-critical*.

- `src/` — File sumber Ada (`.adb` & `.ads`).
- `belajar.gpr` — File konfigurasi proyek GNAT/GPRBuild.
- Skrip otomatisasi: `build.sh` dan `run.sh`.

**Cara Menjalankan:**
```bash
cd Ada
./build.sh   # Membangun biner ke bin/
./run.sh     # Menjalankan aplikasi
```

---

### 🔬 5. MATLAB (`Matlab/`)

Modul komputasi numerik, analisis data matriks, dan simulasi fisika/kedirgantaraan:
- `aerospace_calc.m` — Perhitungan parameter aerodinamika / kedirgantaraan.
- `main.m` — Titik masuk skrip komputasi utama.

**Cara Menjalankan:**
```bash
# Jalankan via MATLAB CLI atau GNU Octave
octave Matlab/main.m
# atau
matlab -batch "run('Matlab/main.m')"
```

---

### 🌐 6. JavaScript / TypeScript (`Javascript/`)

Materi pemrograman web modern, pemrosesan array/objek, pemrograman asynchronous, dan integrasi backend:
- `helloworld.js` & `percabanganArray.js` — Logika dasar dan manipulasi array.
- `jsbelajar.JS` & `JSadvance.js` — Fitur modern ES6+ (Async/Await, Promises, Closures, Destructuring).
- `Firebase/belajar_firebase.js` — Integrasi database NoSQL dan auth via Firebase SDK.
- *TypeScript Support* — Pengetikan statis, interface, types, dan konfigurasi compiler `tsc`.

**Cara Menjalankan:**
```bash
# Menjalankan dengan Node.js / Bun
node Javascript/helloworld.js

# Menjalankan TypeScript
npx tsx file.ts
# atau kompilasi tsc
npx tsc file.ts && node file.js
```

---

## 🛠️ Panduan Instalasi Toolchain (Arch Linux)

Untuk menyiapkan seluruh environment compiler dan runtime di sistem Linux (Arch Linux):

```bash
# 1. C & C++ (GCC, G++, Clang, GDB, Make, CMake)
sudo pacman -S base-devel gcc clang cmake gdb

# 2. Rust (Rustup & Cargo)
sudo pacman -S rustup
rustup default stable

# 3. Ada (GNAT compiler & GPRBuild)
sudo pacman -S gcc-ada gprbuild

# 4. JavaScript / TypeScript (Node.js, npm, Bun/Deno)
sudo pacman -S nodejs npm
sudo npm install -g typescript ts-node

# 5. MATLAB / Alternatif Open Source (GNU Octave)
sudo pacman -S octave
```

---

## 🎯 Target & Roadmap Pembelajaran

- [x] Menyelesaikan kurikulum dasar & lanjutan Rust (`kepiting`)
- [x] Eksplorasi C++ Modern (C++17/C++20) dan Design Patterns
- [x] Eksperimen Ada dengan GPRBuild toolchain
- [x] Pemrograman IoT berbasis C++ (ESP-8266)
- [ ] Penguatan C Tingkat Rendah & Memory Management
- [ ] Implementasi algoritma lanjutan di TypeScript
- [ ] Komputasi lanjutan & simulasi numerik di MATLAB / Octave

---

## 📝 Catatan & Kontribusi

Repo ini bersifat publik untuk dokumentasi progres belajar. Jika kamu menemukan kesalahan logika kode atau ingin berbagi solusi alternatif, jangan ragu untuk membuat issue atau pull request!

⭐ *Happy Coding & Never Stop Learning!* 🚀
