// ============================================================
// 04 - Array, Array 2D, std::string
// ============================================================
#include <iostream>
#include <string>
#include <algorithm>  // sort, reverse, find
using namespace std;

int main() {
    // ── ARRAY 1D ──────────────────────────────────────────────
    cout << "=== ARRAY 1D ===" << endl;
    int arr[5] = {10, 20, 30, 40, 50};

    // Akses elemen
    cout << "arr[0] = " << arr[0] << endl;
    cout << "arr[4] = " << arr[4] << endl;

    // Iterasi
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;

    // Range-based for
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    // Inisialisasi partial — sisanya 0
    int b[5] = {1, 2};  // {1, 2, 0, 0, 0}

    // ── ARRAY 2D ──────────────────────────────────────────────
    cout << "\n=== ARRAY 2D (Matriks) ===" << endl;
    int matrix[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // ── OPERASI ARRAY ─────────────────────────────────────────
    cout << "\n=== OPERASI ARRAY ===" << endl;
    int data[] = {64, 25, 12, 22, 11};
    int ukuran = sizeof(data) / sizeof(data[0]);  // hitung jumlah elemen

    // Sort — menggunakan STL
    sort(data, data + ukuran);
    cout << "Setelah sort: ";
    for (int v : data) cout << v << " ";
    cout << endl;

    // Reverse
    reverse(data, data + ukuran);
    cout << "Setelah reverse: ";
    for (int v : data) cout << v << " ";
    cout << endl;

    // ── STD::STRING ───────────────────────────────────────────
    cout << "\n=== STD::STRING ===" << endl;
    string s1 = "Hello";
    string s2 = " World";
    string s3 = s1 + s2;   // concatenation

    cout << "s3 = " << s3 << endl;
    cout << "Length = " << s3.length() << endl;   // atau s3.size()
    cout << "s3[0] = " << s3[0] << endl;

    // Metode string
    cout << "uppercase check: ";
    cout << s1.substr(1, 3) << endl;        // "ell" (mulai idx 1, 3 karakter)

    // find
    size_t pos = s3.find("World");
    if (pos != string::npos)
        cout << "\"World\" ditemukan di index: " << pos << endl;

    // replace
    s3.replace(6, 5, "C++");
    cout << "Setelah replace: " << s3 << endl;

    // erase
    string temp = "Hapus Ini";
    temp.erase(5, 4);       // hapus 4 karakter mulai index 5
    cout << "Setelah erase: " << temp << endl;

    // to_string dan stoi
    int angka = 42;
    string str_angka = to_string(angka);
    cout << "to_string: " << str_angka << endl;

    string str_num = "123";
    int num = stoi(str_num);
    cout << "stoi: " << num << endl;

    // compare
    string a1 = "apple", a2 = "banana";
    if (a1 < a2)
        cout << a1 << " < " << a2 << " (lexicographic)" << endl;

    // Input string dengan spasi
    cout << "\ngetline mengizinkan spasi dalam input" << endl;
    // getline(cin, namaLengkap);  -- digunakan saat runtime

    // String literal
    const char* cstr = "C-style string";   // immutable
    cout << "C-style: " << cstr << endl;

    string cpp_str = string(cstr);          // konversi ke std::string
    cout << "Converted: " << cpp_str << endl;

    return 0;
}