// ============================================================
// 03 - Operator: Aritmatik, Relasi, Logika, Bitwise
// ============================================================
#include <iostream>
using namespace std;

int main() {
    // ARITMATIK 
    int a = 17, b = 5;
    cout << "=== ARITMATIK ===" << endl;
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " - " << b << " = " << (a - b) << endl;
    cout << a << " * " << b << " = " << (a * b) << endl;
    cout << a << " / " << b << " = " << (a / b) << " (integer division)" << endl;
    cout << a << " % " << b << " = " << (a % b) << " (modulo/sisa bagi)" << endl;

    double x = 17.0, y = 5.0;
    cout << x << " / " << y << " = " << (x / y) << " (float division)" << endl;

    // INCREMENT / DECREMENT 
    int n = 5;
    cout << "\n=== INCREMENT ===" << endl;
    cout << "n   = " << n   << endl;
    cout << "n++ = " << n++ << " (post: pakai dulu, baru tambah)" << endl;
    cout << "n   = " << n   << endl;
    cout << "++n = " << ++n << " (pre: tambah dulu, baru pakai)" << endl;

    // RELASIONAL 
    cout << "\n=== RELASIONAL ===" << endl;
    cout << boolalpha;
    cout << "5 == 5 : " << (5 == 5) << endl;
    cout << "5 != 3 : " << (5 != 3) << endl;
    cout << "5 >  3 : " << (5 >  3) << endl;
    cout << "5 <  3 : " << (5 <  3) << endl;
    cout << "5 >= 5 : " << (5 >= 5) << endl;
    cout << "5 <= 3 : " << (5 <= 3) << endl;

    // LOGIKA 
    cout << "\n=== LOGIKA ===" << endl;
    bool p = true, q = false;
    cout << "p && q : " << (p && q) << "  (AND: keduanya true)" << endl;
    cout << "p || q : " << (p || q) << "  (OR: salah satu true)" << endl;
    cout << "!p     : " << (!p)     << "  (NOT: balik nilai)" << endl;

    // Short-circuit evaluation
    int val = 0;
    if (val != 0 && 10/val > 1)  
        cout << "tidak akan crash" << endl;
    cout << "Short-circuit: aman!" << endl;

    // BITWISE
    cout << "\n=== BITWISE ===" << endl;
    int m = 0b1100;   // 12 dalam biner
    int k = 0b1010;   // 10 dalam biner
    cout << "m = " << m << " (1100)" << endl;
    cout << "k = " << k << " (1010)" << endl;
    cout << "m & k  = " << (m & k)  << " (AND  : 1000 = 8)" << endl;
    cout << "m | k  = " << (m | k)  << " (OR   : 1110 = 14)" << endl;
    cout << "m ^ k  = " << (m ^ k)  << " (XOR  : 0110 = 6)" << endl;
    cout << "~m     = " << (~m)      << " (NOT  : flip semua bit)" << endl;
    cout << "m << 1 = " << (m << 1) << " (LEFT SHIFT  = *2)" << endl;
    cout << "m >> 1 = " << (m >> 1) << " (RIGHT SHIFT = /2)" << endl;

    // ASSIGNMENT COMPOUND 
    cout << "\n=== COMPOUND ASSIGNMENT ===" << endl;
    int v = 10;
    v += 5;   cout << "v += 5 → " << v << endl;
    v -= 3;   cout << "v -= 3 → " << v << endl;
    v *= 2;   cout << "v *= 2 → " << v << endl;
    v /= 4;   cout << "v /= 4 → " << v << endl;
    v %= 3;   cout << "v %= 3 → " << v << endl;

    // TERNARY OPERATOR 
    cout << "\n=== TERNARY ===" << endl;
    int umur = 18;
    string status = (umur >= 17) ? "Dewasa" : "Anak-anak";
    cout << "Status: " << status << endl;

    return 0;
}