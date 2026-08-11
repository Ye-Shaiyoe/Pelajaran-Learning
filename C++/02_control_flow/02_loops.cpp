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