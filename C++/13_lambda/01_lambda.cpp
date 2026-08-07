// ============================================================
// 13 - Lambda, std::function, Closures, Higher-Order Functions
// ============================================================
#include <iostream>
#include <functional>   // std::function
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// ── HIGHER-ORDER FUNCTION ─────────────────────────────────────
// Fungsi yang menerima/mengembalikan fungsi lain
void terapkan(vector<int>& v, function<int(int)> f) {
    for (auto& x : v) x = f(x);
}

vector<int> filter(const vector<int>& v, function<bool(int)> pred) {
    vector<int> hasil;
    for (int x : v)
        if (pred(x)) hasil.push_back(x);
    return hasil;
}

// Fungsi yang mengembalikan lambda (closure)
function<int(int)> pembuat_penambah(int n) {
    return [n](int x) { return x + n; };   // n di-capture
}

function<bool(int)> dalam_rentang(int min, int max) {
    return [min, max](int x) { return x >= min && x <= max; };
}

int main() {
    // ── LAMBDA DASAR ──────────────────────────────────────────
    cout << "=== LAMBDA DASAR ===" << endl;

    // Syntax: [capture](params) -> return_type { body }
    auto sapa = []() { cout << "  Halo dari lambda!" << endl; };
    sapa();

    auto tambah = [](int a, int b) { return a + b; };
    cout << "  tambah(3,4) = " << tambah(3, 4) << endl;

    auto kuadrat = [](int x) -> int { return x * x; };
    cout << "  kuadrat(7) = " << kuadrat(7) << endl;

    // ── CAPTURE ───────────────────────────────────────────────
    cout << "\n=== CAPTURE ===" << endl;

    int faktor = 3;
    string prefix = "nilai: ";

    // [=] capture by value — salinan
    auto kali_by_val = [=](int x) {
        return x * faktor;   // faktor disalin saat lambda dibuat
    };

    // [&] capture by reference — referensi langsung
    auto kali_by_ref = [&faktor](int x) {
        return x * faktor;   // faktor diakses via referensi
    };

    faktor = 10;   // ubah faktor setelah lambda dibuat

    cout << "  by value (salin waktu buat): 5 * 3 = " << kali_by_val(5) << endl;
    cout << "  by reference (ikut perubahan): 5 * 10 = " << kali_by_ref(5) << endl;

    // Capture spesifik
    int a = 1, b = 2, c = 3;
    auto mixed = [a, &b, c](int x) {
        // a dan c by value, b by reference
        return a + b + c + x;
    };
    b = 20;
    cout << "  mixed(10) = " << mixed(10) << " (1+20+3+10)" << endl;

    // ── MUTABLE LAMBDA ────────────────────────────────────────
    cout << "\n=== MUTABLE LAMBDA ===" << endl;

    int hitung = 0;
    auto counter = [hitung]() mutable {  // mutable: bisa ubah salinan
        return ++hitung;                  // tidak mengubah hitung asli!
    };

    cout << "  counter() = " << counter() << endl;
    cout << "  counter() = " << counter() << endl;
    cout << "  hitung asli = " << hitung << endl;  // tetap 0!

    // Gunakan reference jika mau ubah aslinya
    auto counter_ref = [&hitung]() { return ++hitung; };
    counter_ref(); counter_ref();
    cout << "  hitung setelah ref counter = " << hitung << endl;

    // ── LAMBDA DALAM ALGORITHM ────────────────────────────────
    cout << "\n=== LAMBDA + ALGORITHM ===" << endl;

    vector<int> data = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // sort dengan custom comparator
    sort(data.begin(), data.end(), [](int a, int b) { return a > b; });  // descending
    cout << "  Sorted desc: ";
    for (int x : data) cout << x << " ";
    cout << endl;

    // find_if
    auto it = find_if(data.begin(), data.end(), [](int x) { return x < 4; });
    if (it != data.end())
        cout << "  Pertama yang < 4: " << *it << endl;

    // count_if
    int jumlah_genap = count_if(data.begin(), data.end(), [](int x) { return x % 2 == 0; });
    cout << "  Jumlah genap: " << jumlah_genap << endl;

    // ── STD::FUNCTION ─────────────────────────────────────────
    cout << "\n=== STD::FUNCTION ===" << endl;

    // std::function bisa menyimpan lambda, function pointer, atau functor
    function<double(double, double)> operasi;

    operasi = [](double a, double b) { return a + b; };
    cout << "  Tambah: " << operasi(3.0, 4.0) << endl;

    operasi = [](double a, double b) { return a * b; };
    cout << "  Kali  : " << operasi(3.0, 4.0) << endl;

    // ── HIGHER-ORDER FUNCTION ─────────────────────────────────
    cout << "\n=== HIGHER-ORDER FUNCTION ===" << endl;

    vector<int> angka = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    terapkan(angka, [](int x) { return x * x; });   // kuadratkan semua
    cout << "  Setelah kuadrat: ";
    for (int x : angka) cout << x << " ";
    cout << endl;

    auto ganjil = filter(angka, [](int x) { return x % 2 != 0; });
    cout << "  Filter ganjil: ";
    for (int x : ganjil) cout << x << " ";
    cout << endl;

    // ── CLOSURE (Factory Function) ────────────────────────────
    cout << "\n=== CLOSURE ===" << endl;

    auto tambah5  = pembuat_penambah(5);
    auto tambah10 = pembuat_penambah(10);

    cout << "  tambah5(3)  = " << tambah5(3)  << endl;   // 8
    cout << "  tambah10(3) = " << tambah10(3) << endl;   // 13

    auto rentang_1_10 = dalam_rentang(1, 10);
    auto rentang_5_15 = dalam_rentang(5, 15);

    cout << "  7 dalam 1-10? " << boolalpha << rentang_1_10(7)  << endl;
    cout << "  3 dalam 5-15? " << boolalpha << rentang_5_15(3)  << endl;

    // ── IMMEDIATELY INVOKED LAMBDA ────────────────────────────
    cout << "\n=== IMMEDIATELY INVOKED ===" << endl;

    int hasil = [](int x, int y) { return x * y + 10; }(5, 6);
    cout << "  Hasil: " << hasil << endl;

    // Berguna untuk inisialisasi kompleks
    const string greeting = [&]() -> string {
        string s = "Halo";
        s += " dunia";
        s += "!";
        return s;
    }();
    cout << "  " << greeting << endl;

    // ── GENERIC LAMBDA (C++14) ────────────────────────────────
    cout << "\n=== GENERIC LAMBDA (C++14) ===" << endl;

    auto print_pair = [](auto first, auto second) {
        cout << "  (" << first << ", " << second << ")" << endl;
    };

    print_pair(1, 2);
    print_pair("hello", 3.14);
    print_pair(true, 'A');

    return 0;
}
// [note-2026-02-16-17:53:33]
// [note-2026-02-18-12:17:08]
// [note-2026-02-23-19:19:13]
// [note-2026-02-23-20:02:21]
// [note-2026-02-25-09:01:36]
// [note-2026-02-25-13:44:24]
// [note-2026-02-27-09:16:56]
// [note-2026-02-27-10:15:42]
// [note-2026-02-27-12:08:37]
// [note-2026-02-28-22:06:12]
// [note-2026-03-05-19:52:04]
// [note-2026-03-06-22:26:56]
// [note-2026-03-11-08:33:42]
// [note-2026-03-16-16:00:10]
// [note-2026-03-22-12:36:01]
// [note-2026-03-27-18:26:24]
// [note-2026-03-28-10:48:09]
// [note-2026-05-01-10:40:28]
// [note-2026-05-02-18:24:17]
// [note-2026-05-03-19:12:10]
// [note-2026-05-27-08:52:14]
// [note-2026-05-29-21:25:35]
// [note-2026-06-04-14:56:06]
// [note-2026-06-04-18:13:30]
// [note-2026-06-05-10:16:58]
// [note-2026-06-07-15:06:04]
// [note-2026-06-07-15:57:36]
// [note-2026-06-07-18:31:47]
// [note-2026-06-07-21:53:02]
// [note-2026-06-10-17:01:32]
// [note-2026-06-12-13:27:13]
// [note-2026-06-14-08:00:29]
// [note-2026-06-16-10:05:02]
// [note-2026-06-17-12:14:22]
// [note-2026-06-17-18:07:29]
// [note-2026-06-19-19:06:26]
// [note-2026-06-21-15:07:46]
// [note-2026-06-22-14:06:22]
