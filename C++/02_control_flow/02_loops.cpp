// ============================================================
// 02 - Loop: for, while, do-while, range-based for
// ============================================================
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // ── FOR LOOP ──────────────────────────────────────────────
    cout << "=== FOR LOOP ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    // For loop mundur
    for (int i = 10; i > 0; i -= 2) {
        cout << i << " ";
    }
    cout << endl;

    // Nested loop — tabel perkalian
    cout << "\n=== TABEL PERKALIAN ===" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }

    // ── WHILE LOOP ────────────────────────────────────────────
    cout << "\n=== WHILE LOOP ===" << endl;
    int n = 1;
    while (n <= 10) {
        cout << n << " ";
        n++;
    }
    cout << endl;

    // ── DO-WHILE LOOP ─────────────────────────────────────────
    // Minimal dieksekusi SEKALI meskipun kondisi false
    cout << "\n=== DO-WHILE ===" << endl;
    int input = 0;
    do {
        cout << "Nilai saat ini: " << input << endl;
        input++;
    } while (input < 3);

    // ── BREAK & CONTINUE ──────────────────────────────────────
    cout << "\n=== BREAK & CONTINUE ===" << endl;
    for (int i = 0; i < 10; i++) {
        if (i == 3) continue;   // lewati i=3
        if (i == 7) break;      // hentikan loop di i=7
        cout << i << " ";
    }
    cout << endl;

    // ── RANGE-BASED FOR (C++11) ───────────────────────────────
    cout << "\n=== RANGE-BASED FOR ===" << endl;
    vector<int> angka = {10, 20, 30, 40, 50};

    // by value — dapat salinan
    for (int val : angka) {
        cout << val << " ";
    }
    cout << endl;

    // by reference — akses langsung (lebih efisien untuk objek besar)
    for (const int& val : angka) {
        cout << val << " ";
    }
    cout << endl;

    // auto — biarkan compiler tentukan tipe
    for (auto val : angka) {
        cout << val * 2 << " ";
    }
    cout << endl;

    // ── INFINITE LOOP ─────────────────────────────────────────
    cout << "\n=== INFINITE LOOP (dengan break) ===" << endl;
    int counter = 0;
    for (;;) {          // atau: while(true)
        if (counter >= 5) break;
        cout << "counter = " << counter << endl;
        counter++;
    }

    // ── LABEL & GOTO (jarang digunakan, tapi C++ support) ─────
    // Berguna untuk break dari nested loop
    cout << "\n=== NESTED BREAK dengan goto ===" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 3) goto done;
            cout << "(" << i << "," << j << ") ";
        }
    }
    done:
    cout << "\n[keluar dari nested loop]" << endl;

    return 0;
}
// [note-2026-01-21-08:51:35]
// [note-2026-02-05-10:10:28]
// [note-2026-02-15-17:56:11]
// [note-2026-02-16-17:03:47]
// [note-2026-02-21-15:14:13]
// [note-2026-02-23-21:07:12]
// [note-2026-02-25-13:25:28]
// [note-2026-03-02-18:02:26]
// [note-2026-03-02-20:59:27]
// [note-2026-03-07-09:41:39]
// [note-2026-03-10-21:30:57]
// [note-2026-03-11-22:11:29]
// [note-2026-03-12-10:49:54]
// [note-2026-03-18-13:59:49]
// [note-2026-03-18-18:27:03]
// [note-2026-03-19-19:43:39]
// [note-2026-03-19-21:49:37]
// [note-2026-03-21-15:57:34]
// [note-2026-03-22-11:03:55]
// [note-2026-03-22-15:52:37]
// [note-2026-03-24-17:29:05]
// [note-2026-03-27-08:24:07]
// [note-2026-03-29-11:23:44]
// [note-2026-04-10-19:23:29]
// [note-2026-04-10-22:25:34]
// [note-2026-05-01-17:49:46]
// [note-2026-05-02-09:50:41]
// [note-2026-05-03-22:57:48]
// [note-2026-05-27-14:57:07]
// [note-2026-06-07-12:07:45]
// [note-2026-06-08-21:46:44]
// [note-2026-06-08-22:45:58]
// [note-2026-06-10-09:38:45]
// [note-2026-06-10-14:28:45]
// [note-2026-06-12-12:01:03]
// [note-2026-06-17-13:58:24]
// [note-2026-06-17-18:43:22]
// [note-2026-06-25-17:12:19]
// [note-2026-06-26-16:42:08]
