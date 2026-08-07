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
// [note-2026-01-27-17:25:54]
// [note-2026-02-05-15:46:00]
// [note-2026-02-15-14:40:37]
// [note-2026-02-18-18:34:43]
// [note-2026-02-18-20:57:19]
// [note-2026-02-19-13:16:40]
// [note-2026-02-19-21:08:53]
// [note-2026-02-20-18:19:50]
// [note-2026-02-21-20:04:52]
// [note-2026-02-26-11:05:53]
// [note-2026-02-26-22:06:20]
// [note-2026-02-28-18:40:33]
// [note-2026-03-03-16:24:33]
// [note-2026-03-05-19:06:37]
// [note-2026-03-06-16:09:40]
// [note-2026-03-08-13:38:51]
// [note-2026-03-09-10:29:17]
// [note-2026-03-09-16:03:09]
// [note-2026-03-10-17:35:42]
// [note-2026-03-14-10:55:35]
// [note-2026-03-15-16:25:15]
// [note-2026-03-19-21:45:00]
// [note-2026-03-19-22:28:54]
// [note-2026-03-21-19:25:53]
// [note-2026-03-25-10:24:31]
// [note-2026-03-27-22:25:13]
// [note-2026-03-29-16:10:22]
// [note-2026-03-30-20:31:53]
// [note-2026-04-03-17:39:53]
// [note-2026-04-05-12:01:59]
// [note-2026-04-10-10:42:01]
// [note-2026-05-03-20:13:05]
// [note-2026-05-27-13:01:24]
// [note-2026-05-28-17:41:53]
// [note-2026-05-29-14:36:25]
// [note-2026-05-29-20:45:54]
// [note-2026-06-01-11:35:22]
// [note-2026-06-01-18:21:57]
// [note-2026-06-11-09:18:21]
// [note-2026-06-11-18:56:34]
// [note-2026-06-18-09:05:30]
// [note-2026-06-19-08:28:41]
// [note-2026-06-22-18:51:52]
// [note-2026-06-25-19:09:46]
// [note-2026-06-25-22:35:59]
// [note-2026-06-26-09:08:01]
// [note-2026-06-26-20:40:25]
