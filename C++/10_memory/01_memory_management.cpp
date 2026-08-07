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
// [note-2026-01-27-20:23:59]
// [note-2026-02-09-11:18:36]
// [note-2026-02-16-08:52:55]
// [note-2026-02-20-08:42:04]
// [note-2026-02-20-15:56:30]
// [note-2026-02-25-13:51:01]
// [note-2026-03-02-19:03:23]
// [note-2026-03-05-15:33:28]
// [note-2026-03-11-08:42:58]
// [note-2026-03-11-20:00:24]
// [note-2026-03-15-21:23:09]
// [note-2026-03-16-19:01:01]
// [note-2026-03-20-22:33:13]
// [note-2026-03-21-16:38:45]
// [note-2026-03-23-15:35:06]
// [note-2026-03-27-15:49:18]
// [note-2026-03-29-08:20:33]
// [note-2026-04-05-08:03:35]
// [note-2026-04-05-18:03:46]
// [note-2026-04-12-19:39:44]
// [note-2026-04-25-12:02:41]
// [note-2026-04-25-12:31:37]
// [note-2026-05-27-16:59:48]
// [note-2026-05-29-12:44:32]
// [note-2026-05-30-18:57:03]
// [note-2026-06-02-10:35:17]
// [note-2026-06-05-09:07:48]
// [note-2026-06-18-14:31:22]
// [note-2026-06-19-15:39:57]
// [note-2026-06-22-17:57:01]
// [note-2026-06-22-19:09:21]
// [note-2026-06-23-15:10:32]
// [note-2026-06-23-19:00:02]
// [note-2026-06-24-15:02:14]
// [note-2026-06-26-19:23:15]
