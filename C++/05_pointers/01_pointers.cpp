// ============================================================
// 05 - Pointer dan Referensi — KONSEP INTI C++
// ============================================================
#include <iostream>
using namespace std;

int main() {
    // ── APA ITU POINTER? ──────────────────────────────────────
    // Pointer adalah variabel yang menyimpan ALAMAT MEMORI variabel lain
    cout << "=== POINTER DASAR ===" << endl;

    int x = 42;
    int* ptr = &x;   // ptr menyimpan alamat x
                     // & = address-of operator
                     // * = dereference operator (akses nilai di alamat itu)

    cout << "x     = " << x     << endl;
    cout << "&x    = " << &x    << " (alamat x)" << endl;
    cout << "ptr   = " << ptr   << " (isi ptr = alamat x)" << endl;
    cout << "*ptr  = " << *ptr  << " (nilai di alamat yang disimpan ptr)" << endl;

    // Mengubah nilai melalui pointer
    *ptr = 100;
    cout << "Setelah *ptr = 100, x = " << x << endl;

    // ── POINTER ARITMATIK ─────────────────────────────────────
    cout << "\n=== POINTER ARITMATIK ===" << endl;
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;   // pointer ke elemen pertama

    cout << "p[0] = " << *p << endl;
    p++;    // maju 1 elemen (bukan 1 byte! — maju sizeof(int) byte)
    cout << "p[1] = " << *p << endl;
    p += 2;
    cout << "p[3] = " << *p << endl;

    // Iterasi array dengan pointer
    cout << "Iterasi: ";
    int* start = arr;
    int* end   = arr + 5;
    while (start < end) {
        cout << *start << " ";
        start++;
    }
    cout << endl;

    // ── NULL POINTER ──────────────────────────────────────────
    cout << "\n=== NULL POINTER ===" << endl;
    int* null_ptr = nullptr;   // C++11: gunakan nullptr, bukan NULL atau 0
    if (null_ptr == nullptr)
        cout << "Pointer adalah null — aman" << endl;

    // JANGAN dereferensi null pointer → crash (segfault)!
    // *null_ptr = 5;  // BERBAHAYA!

    // ── POINTER KE POINTER ────────────────────────────────────
    cout << "\n=== POINTER KE POINTER ===" << endl;
    int val  = 7;
    int* p1  = &val;
    int** p2 = &p1;   // pointer ke pointer

    cout << "val  = " << val    << endl;
    cout << "*p1  = " << *p1    << endl;
    cout << "**p2 = " << **p2   << endl;

    // ── REFERENSI ─────────────────────────────────────────────
    cout << "\n=== REFERENSI ===" << endl;
    int original = 50;
    int& ref = original;   // ref adalah ALIAS dari original

    cout << "original = " << original << endl;
    cout << "ref      = " << ref      << endl;

    ref = 99;   // mengubah ref = mengubah original
    cout << "Setelah ref = 99:" << endl;
    cout << "original = " << original << endl;

    // PERBEDAAN pointer vs referensi:
    // - Referensi HARUS diinisialisasi saat deklarasi
    // - Referensi tidak bisa nullptr
    // - Referensi tidak bisa "diarahkan ulang" ke variabel lain
    // - Pointer lebih fleksibel tapi lebih berbahaya

    // ── CONST POINTER ─────────────────────────────────────────
    cout << "\n=== CONST POINTER ===" << endl;
    int a = 10, b2 = 20;

    const int* cp1 = &a;   // pointer ke const int: nilai tidak bisa diubah
    // *cp1 = 5;            // ERROR!
    cp1 = &b2;             // tapi bisa arahkan ke variabel lain

    int* const cp2 = &a;   // const pointer ke int: arah tidak bisa diubah
    *cp2 = 5;              // bisa ubah nilai
    // cp2 = &b2;           // ERROR!

    const int* const cp3 = &a; // keduanya const
    cout << "cp3 = " << *cp3 << endl;

    // ── VOID POINTER ──────────────────────────────────────────
    cout << "\n=== VOID POINTER ===" << endl;
    int   num  = 42;
    float fnum = 3.14f;

    void* vptr = &num;
    cout << "void* ke int   : " << *(int*)vptr   << endl;
    vptr = &fnum;
    cout << "void* ke float : " << *(float*)vptr << endl;

    return 0;
}
// [note-2026-01-21-21:58:00]
// [note-2026-02-05-13:15:41]
// [note-2026-02-09-09:23:30]
// [note-2026-02-16-14:07:37]
// [note-2026-02-18-18:14:25]
// [note-2026-02-23-16:19:58]
// [note-2026-02-27-16:07:24]
// [note-2026-03-01-16:42:18]
// [note-2026-03-05-17:39:22]
// [note-2026-03-07-10:27:26]
// [note-2026-03-07-22:01:10]
// [note-2026-03-08-19:06:29]
// [note-2026-03-09-08:23:27]
// [note-2026-03-09-10:53:42]
// [note-2026-03-10-21:35:00]
// [note-2026-03-12-22:43:55]
// [note-2026-03-13-19:34:04]
// [note-2026-03-21-14:53:58]
// [note-2026-03-23-22:37:46]
// [note-2026-03-24-09:36:48]
// [note-2026-03-24-18:03:16]
// [note-2026-03-24-22:03:50]
// [note-2026-03-25-08:36:11]
// [note-2026-03-26-09:35:17]
// [note-2026-03-26-16:08:13]
// [note-2026-03-28-21:50:08]
// [note-2026-03-31-14:11:48]
// [note-2026-03-31-21:56:44]
// [note-2026-03-31-22:05:30]
// [note-2026-04-03-20:32:16]
// [note-2026-04-03-22:24:53]
// [note-2026-04-03-22:35:26]
// [note-2026-04-12-09:04:17]
// [note-2026-04-25-20:42:02]
// [note-2026-05-09-20:58:01]
// [note-2026-05-27-19:31:38]
// [note-2026-05-30-14:32:25]
// [note-2026-06-02-21:11:13]
// [note-2026-06-04-18:34:41]
// [note-2026-06-04-21:55:32]
// [note-2026-06-06-08:33:02]
// [note-2026-06-09-21:19:39]
// [note-2026-06-10-09:44:51]
// [note-2026-06-10-12:32:46]
// [note-2026-06-12-21:47:33]
// [note-2026-06-22-12:58:25]
// [note-2026-06-25-18:41:37]
