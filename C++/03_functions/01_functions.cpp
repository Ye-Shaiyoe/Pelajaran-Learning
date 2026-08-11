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