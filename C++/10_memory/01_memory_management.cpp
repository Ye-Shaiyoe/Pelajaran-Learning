// ============================================================
// 10 - Memory Management: new/delete, Smart Pointers
// ============================================================
#include <iostream>
#include <memory>    // unique_ptr, shared_ptr, weak_ptr
#include <string>
#include <vector>
using namespace std;

// Kelas contoh untuk demonstrasi
class Resource {
private:
    string nama;

public:
    Resource(const string& n) : nama(n) {
        cout << "  Resource '" << nama << "' dibuat" << endl;
    }
    ~Resource() {
        cout << "  Resource '" << nama << "' dihapus" << endl;
    }
    void pakai() const {
        cout << "  Menggunakan resource: " << nama << endl;
    }
    string getNama() const { return nama; }
};

// ── DEMONSTRASI MEMORY LEAK (jangan dilakukan!) ───────────────
void contoh_memory_leak() {
    // Resource* r = new Resource("LEAK");  // jika delete tidak dipanggil
    // return;  // ← memory leak! r tidak pernah delete
}

// ── RAII PATTERN ──────────────────────────────────────────────
// Resource Acquisition Is Initialization
// Kelola resource di constructor, bebaskan di destructor
class FileHandle {
private:
    FILE* file;
    string namaFile;

public:
    FileHandle(const string& nama) : namaFile(nama) {
        file = fopen(nama.c_str(), "w");
        if (!file)
            throw runtime_error("Gagal membuka file: " + nama);
        cout << "  File '" << namaFile << "' dibuka" << endl;
    }

    ~FileHandle() {
        if (file) {
            fclose(file);
            cout << "  File '" << namaFile << "' ditutup otomatis" << endl;
        }
    }

    // Tidak izinkan copy
    FileHandle(const FileHandle&)            = delete;
    FileHandle& operator=(const FileHandle&) = delete;

    void tulis(const string& data) {
        fprintf(file, "%s\n", data.c_str());
    }
};

int main() {
    // ── RAW POINTER (cara lama) ───────────────────────────────
    cout << "=== RAW POINTER (new/delete) ===" << endl;
    {
        int* p = new int(42);
        cout << "  *p = " << *p << endl;
        delete p;            // WAJIB
        p = nullptr;         // best practice: set null setelah delete

        int* arr = new int[5]{1,2,3,4,5};
        for (int i = 0; i < 5; i++) cout << "  arr[" << i << "]=" << arr[i] << endl;
        delete[] arr;        // gunakan delete[] untuk array!
    }

    // ── UNIQUE_PTR ────────────────────────────────────────────
    // Exclusive ownership — satu pemilik, otomatis delete saat keluar scope
    cout << "\n=== UNIQUE_PTR ===" << endl;
    {
        unique_ptr<Resource> up = make_unique<Resource>("Unik");
        up->pakai();
        cout << "  Masih hidup dalam scope" << endl;

        // Transfer ownership dengan move
        unique_ptr<Resource> up2 = move(up);   // up sekarang nullptr
        if (!up)
            cout << "  up sudah dikosongkan (moved)" << endl;
        up2->pakai();

        // Array dengan unique_ptr
        unique_ptr<int[]> arr = make_unique<int[]>(5);
        for (int i = 0; i < 5; i++) arr[i] = i * 10;
        for (int i = 0; i < 5; i++) cout << arr[i] << " ";
        cout << endl;

    }   // up2 otomatis dihapus di sini
    cout << "  (keluar scope)" << endl;

    // ── SHARED_PTR ────────────────────────────────────────────
    // Shared ownership — reference counting, delete saat count = 0
    cout << "\n=== SHARED_PTR ===" << endl;
    {
        shared_ptr<Resource> sp1 = make_shared<Resource>("Bersama");
        cout << "  use_count = " << sp1.use_count() << endl;   // 1

        {
            shared_ptr<Resource> sp2 = sp1;   // copy → count naik
            cout << "  use_count = " << sp1.use_count() << endl;   // 2
            sp2->pakai();
        }   // sp2 keluar scope → count turun

        cout << "  use_count = " << sp1.use_count() << endl;   // 1
        sp1->pakai();
    }   // sp1 keluar scope → count 0 → Resource dihapus

    // ── WEAK_PTR ──────────────────────────────────────────────
    // Observasi shared_ptr tanpa menambah reference count
    // Solusi untuk circular reference
    cout << "\n=== WEAK_PTR ===" << endl;
    {
        shared_ptr<Resource> sp = make_shared<Resource>("Lemah");
        weak_ptr<Resource> wp = sp;   // tidak nambah count

        cout << "  sp use_count = " << sp.use_count() << endl;   // 1 (bukan 2!)

        // Untuk menggunakan weak_ptr, harus lock() dulu
        if (auto locked = wp.lock()) {
            locked->pakai();
            cout << "  (locked) use_count = " << locked.use_count() << endl;  // 2
        }

        sp.reset();   // paksa hapus resource
        if (wp.expired())
            cout << "  Resource sudah expired!" << endl;
    }

    // ── CUSTOM DELETER ────────────────────────────────────────
    cout << "\n=== CUSTOM DELETER ===" << endl;
    {
        auto deleter = [](Resource* r) {
            cout << "  Custom deleter dipanggil!" << endl;
            delete r;
        };

        unique_ptr<Resource, decltype(deleter)> up(new Resource("Custom"), deleter);
        up->pakai();
    }

    // ── RAII ──────────────────────────────────────────────────
    cout << "\n=== RAII Pattern ===" << endl;
    {
        // File otomatis tertutup saat keluar scope, bahkan jika exception terjadi
        FileHandle f("test_raii.txt");
        f.tulis("Baris pertama");
        f.tulis("Baris kedua");
        // jika exception terjadi di sini, file tetap ditutup!
    }   // destructor FileHandle dipanggil → fclose otomatis

    // ── PERBANDINGAN UKURAN ───────────────────────────────────
    cout << "\n=== UKURAN POINTER ===" << endl;
    cout << "  raw pointer  : " << sizeof(int*)                << " byte" << endl;
    cout << "  unique_ptr   : " << sizeof(unique_ptr<int>)     << " byte" << endl;
    cout << "  shared_ptr   : " << sizeof(shared_ptr<int>)     << " byte" << endl;
    cout << "  weak_ptr     : " << sizeof(weak_ptr<int>)       << " byte" << endl;

    return 0;
}