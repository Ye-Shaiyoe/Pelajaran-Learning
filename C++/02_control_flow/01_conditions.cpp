// ============================================================
// 02 - Control Flow: if/else, switch, goto
// ============================================================
#include <iostream>
using namespace std;

int main() {
    // ── IF / ELSE IF / ELSE ───────────────────────────────────
    int nilai = 78;

    if (nilai >= 90) {
        cout << "Grade: A" << endl;
    } else if (nilai >= 80) {
        cout << "Grade: B" << endl;
    } else if (nilai >= 70) {
        cout << "Grade: C" << endl;
    } else if (nilai >= 60) {
        cout << "Grade: D" << endl;
    } else {
        cout << "Grade: E — Tidak Lulus" << endl;
    }

    // ── NESTED IF ─────────────────────────────────────────────
    int x = 15;
    if (x > 0) {
        if (x % 2 == 0)
            cout << x << " adalah bilangan positif genap" << endl;
        else
            cout << x << " adalah bilangan positif ganjil" << endl;
    }

    // ── SWITCH ───────────────────────────────────────────────
    // Lebih efisien dari if-else untuk banyak kondisi diskrit
    int hari = 3;
    cout << "\nHari ke-" << hari << ": ";
    switch (hari) {
        case 1: cout << "Senin";    break;
        case 2: cout << "Selasa";   break;
        case 3: cout << "Rabu";     break;
        case 4: cout << "Kamis";    break;
        case 5: cout << "Jumat";    break;
        case 6: cout << "Sabtu";    break;
        case 7: cout << "Minggu";   break;
        default: cout << "Tidak valid"; break;
    }
    cout << endl;

    // Switch dengan fall-through (tanpa break)
    int bulan = 4;
    cout << "Bulan " << bulan << " punya ";
    switch (bulan) {
        case 2:
            cout << "28 atau 29 hari" << endl;
            break;
        case 4: case 6: case 9: case 11:   // fall-through: beberapa case sama
            cout << "30 hari" << endl;
            break;
        default:
            cout << "31 hari" << endl;
            break;
    }

    // ── IF DENGAN INITIALIZER (C++17) ─────────────────────────
    // Deklarasi variabel di dalam if — scope terbatas
    if (int result = nilai * 2; result > 100) {
        cout << "\nNilai ganda (" << result << ") lebih dari 100" << endl;
    }

    // ── SWITCH DENGAN STRING (tidak langsung, perlu workaround) ─
    // Switch C++ hanya support tipe integer/enum
    // Untuk string gunakan if-else atau map

    return 0;
}