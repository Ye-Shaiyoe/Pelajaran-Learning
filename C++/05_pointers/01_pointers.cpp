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