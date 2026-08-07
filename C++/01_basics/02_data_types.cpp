// ============================================================
// 02 - Tipe Data, Variabel, Konstanta
// ============================================================
#include <iostream>
#include <climits>   // untuk INT_MAX, INT_MIN
#include <cfloat>    // untuk FLT_MAX
using namespace std;

int main() {
    // ── INTEGER ──────────────────────────────────────────────
    int a = 42;             // 4 byte, -2,147,483,648 s/d 2,147,483,647
    short b = 100;          // 2 byte
    long c = 1000000L;      // minimal 4 byte
    long long d = 9000000000LL; // 8 byte
    unsigned int e = 300u;  // hanya positif, range 2x lebih besar

    cout << "=== INTEGER ===" << endl;
    cout << "int max    : " << INT_MAX << endl;
    cout << "int min    : " << INT_MIN << endl;
    cout << "long long  : " << d << endl;

    // ── FLOATING POINT ───────────────────────────────────────
    float  f = 3.14f;       // 4 byte, ~7 digit presisi
    double g = 3.14159265;  // 8 byte, ~15 digit presisi (RECOMMENDED)
    long double h = 3.14159265358979L; // 10-16 byte

    cout << "\n=== FLOAT ===" << endl;
    cout << "float  : " << f << endl;
    cout << "double : " << g << endl;

    // ── CHARACTER ────────────────────────────────────────────
    char ch = 'A';          // 1 byte, nilai ASCII
    cout << "\n=== CHAR ===" << endl;
    cout << "char    : " << ch << endl;
    cout << "ASCII   : " << (int)ch << endl;  // cast ke int = 65

    // ── BOOLEAN ──────────────────────────────────────────────
    bool isTrue  = true;
    bool isFalse = false;
    cout << "\n=== BOOL ===" << endl;
    cout << boolalpha;          // tampilkan true/false bukan 1/0
    cout << "true  = " << isTrue << endl;
    cout << "false = " << isFalse << endl;

    // ── KONSTANTA ────────────────────────────────────────────
    const double PI = 3.14159265358979;     // tidak bisa diubah
    // PI = 3.0; // ERROR: assignment of read-only variable

    // constexpr = dievaluasi saat compile time (lebih cepat)
    constexpr int MAX_SIZE = 100;

    cout << "\n=== CONST ===" << endl;
    cout << "PI       = " << PI << endl;
    cout << "MAX_SIZE = " << MAX_SIZE << endl;

    // ── AUTO (C++11) ──────────────────────────────────────────
    // Compiler menentukan tipe otomatis
    auto x = 10;        // int
    auto y = 3.14;      // double
    auto z = 'Z';       // char
    auto w = true;      // bool

    cout << "\n=== AUTO ===" << endl;
    cout << "x=" << x << " y=" << y << " z=" << z << " w=" << boolalpha << w << endl;

    // ── SIZEOF ────────────────────────────────────────────────
    cout << "\n=== UKURAN TIPE DATA ===" << endl;
    cout << "bool        : " << sizeof(bool)        << " byte" << endl;
    cout << "char        : " << sizeof(char)        << " byte" << endl;
    cout << "int         : " << sizeof(int)         << " byte" << endl;
    cout << "long long   : " << sizeof(long long)   << " byte" << endl;
    cout << "float       : " << sizeof(float)       << " byte" << endl;
    cout << "double      : " << sizeof(double)      << " byte" << endl;

    return 0;
}
