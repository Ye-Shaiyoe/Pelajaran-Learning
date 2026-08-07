// ============================================================
// 03 - Fungsi: Deklarasi, Definisi, Overloading, Default Args
// ============================================================
#include <iostream>
#include <string>
using namespace std;

// ── DEKLARASI (prototype) — ditulis sebelum main ─────────────
int tambah(int a, int b);
double hitung_luas(double radius);
void sapa(string nama);

// ── FUNGSI DENGAN RETURN VALUE ────────────────────────────────
int tambah(int a, int b) {
    return a + b;
}

// ── FUNGSI DENGAN VOID (tidak mengembalikan nilai) ────────────
void sapa(string nama) {
    cout << "Halo, " << nama << "!" << endl;
}

// ── FUNGSI DENGAN DEFAULT ARGUMENT ───────────────────────────
// Argumen default harus di paling kanan
void perkenalan(string nama, int umur = 20, string kota = "Jakarta") {
    cout << "Nama: " << nama << ", Umur: " << umur << ", Kota: " << kota << endl;
}

// ── FUNCTION OVERLOADING ──────────────────────────────────────
// Nama sama, parameter berbeda
int luas(int sisi) {
    return sisi * sisi;             // luas persegi
}

double luas(double panjang, double lebar) {
    return panjang * lebar;         // luas persegi panjang
}

double luas(double r, bool lingkaran) {
    return 3.14159 * r * r;         // luas lingkaran
}

// ── PASS BY VALUE vs PASS BY REFERENCE ───────────────────────
void swap_value(int a, int b) {     // by value — tidak mengubah aslinya
    int temp = a;
    a = b;
    b = temp;
    cout << "  (di dalam fungsi) a=" << a << ", b=" << b << endl;
}

void swap_ref(int& a, int& b) {     // by reference — mengubah aslinya
    int temp = a;
    a = b;
    b = temp;
}

// ── PASS BY CONST REFERENCE ───────────────────────────────────
// Efisien (tidak copy) tapi aman (tidak bisa diubah)
void tampilkan(const string& s) {
    cout << "String: " << s << " (panjang=" << s.length() << ")" << endl;
}

// ── REKURSI ───────────────────────────────────────────────────
int faktorial(int n) {
    if (n <= 1) return 1;           // base case
    return n * faktorial(n - 1);   // recursive case
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// ── INLINE FUNCTION ───────────────────────────────────────────
// Hint ke compiler untuk expand kode di tempat pemanggilan (menghindari overhead fungsi)
inline int kuadrat(int x) {
    return x * x;
}

// ── FUNGSI MENGEMBALIKAN MULTIPLE VALUES (via struct/pair) ────
#include <utility>  // pair
pair<int,int> bagi_dan_sisa(int a, int b) {
    return {a / b, a % b};
}

double hitung_luas(double radius) {
    return 3.14159 * radius * radius;
}

int main() {
    // Memanggil fungsi
    cout << "=== FUNGSI DASAR ===" << endl;
    cout << "tambah(3,4) = " << tambah(3, 4) << endl;
    sapa("Budi");
    cout << "Luas lingkaran r=5: " << hitung_luas(5.0) << endl;

    cout << "\n=== DEFAULT ARGUMENT ===" << endl;
    perkenalan("Ani");                          // pakai default semua
    perkenalan("Budi", 25);                    // override umur
    perkenalan("Citra", 30, "Surabaya");       // override semua

    cout << "\n=== OVERLOADING ===" << endl;
    cout << "luas persegi (5)       = " << luas(5) << endl;
    cout << "luas persegi panjang   = " << luas(4.0, 6.0) << endl;
    cout << "luas lingkaran r=3     = " << luas(3.0, true) << endl;

    cout << "\n=== PASS BY VALUE vs REFERENCE ===" << endl;
    int x = 10, y = 20;
    cout << "Sebelum swap_value: x=" << x << ", y=" << y << endl;
    swap_value(x, y);
    cout << "Setelah swap_value: x=" << x << ", y=" << y << " (tidak berubah!)" << endl;

    swap_ref(x, y);
    cout << "Setelah swap_ref  : x=" << x << ", y=" << y << " (berubah!)" << endl;

    cout << "\n=== REKURSI ===" << endl;
    for (int i = 0; i <= 10; i++)
        cout << i << "! = " << faktorial(i) << endl;

    cout << "\nFibonacci: ";
    for (int i = 0; i < 10; i++)
        cout << fibonacci(i) << " ";
    cout << endl;

    cout << "\n=== MULTIPLE RETURN VALUES ===" << endl;
    auto [hasil, sisa] = bagi_dan_sisa(17, 5);  // C++17 structured binding
    cout << "17 / 5 = " << hasil << " sisa " << sisa << endl;

    cout << "\n=== INLINE ===" << endl;
    cout << "kuadrat(7) = " << kuadrat(7) << endl;

    return 0;
}
// [note-2026-01-21-10:28:35]
// [note-2026-01-21-21:06:27]
// [note-2026-02-09-09:39:58]
// [note-2026-02-09-19:49:35]
// [note-2026-02-09-21:38:10]
// [note-2026-02-18-15:24:20]
// [note-2026-02-21-17:58:29]
// [note-2026-02-21-20:09:46]
// [note-2026-02-23-12:41:44]
// [note-2026-03-12-15:56:53]
// [note-2026-03-15-12:35:50]
// [note-2026-03-15-12:41:41]
// [note-2026-03-15-20:46:39]
// [note-2026-03-15-20:49:09]
// [note-2026-03-19-11:00:15]
// [note-2026-03-21-20:22:54]
// [note-2026-03-24-11:47:02]
// [note-2026-03-25-18:11:06]
// [note-2026-03-25-18:59:18]
// [note-2026-03-29-22:56:30]
// [note-2026-04-01-21:18:43]
// [note-2026-04-10-16:25:19]
// [note-2026-04-25-09:44:07]
// [note-2026-05-27-20:07:01]
// [note-2026-05-31-14:59:12]
// [note-2026-06-01-22:00:29]
// [note-2026-06-03-22:39:30]
// [note-2026-06-04-14:21:54]
// [note-2026-06-04-18:40:28]
// [note-2026-06-08-19:12:46]
// [note-2026-06-08-20:28:53]
// [note-2026-06-10-10:38:05]
// [note-2026-06-10-20:27:57]
// [note-2026-06-14-16:01:57]
// [note-2026-06-19-16:10:07]
// [note-2026-06-23-18:35:53]
// [note-2026-06-24-16:25:42]
// [note-2026-06-25-13:36:43]
