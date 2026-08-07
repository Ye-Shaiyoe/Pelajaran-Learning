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
// [note-2026-01-21-19:14:24]
// [note-2026-01-31-11:32:10]
// [note-2026-02-16-14:25:58]
// [note-2026-02-16-16:28:37]
// [note-2026-02-18-16:11:24]
// [note-2026-02-23-22:46:17]
// [note-2026-02-24-13:41:02]
// [note-2026-02-27-14:10:48]
// [note-2026-03-01-22:56:30]
// [note-2026-03-04-15:12:58]
// [note-2026-03-06-12:12:22]
// [note-2026-03-07-16:38:20]
// [note-2026-03-13-09:55:20]
// [note-2026-03-15-16:16:57]
// [note-2026-03-16-22:03:02]
// [note-2026-03-18-17:23:53]
// [note-2026-03-21-08:27:42]
// [note-2026-03-23-09:08:29]
// [note-2026-03-25-14:54:42]
// [note-2026-03-29-09:00:17]
// [note-2026-03-31-10:41:59]
// [note-2026-04-01-15:20:38]
// [note-2026-05-10-22:13:41]
// [note-2026-05-29-16:32:14]
// [note-2026-06-01-12:46:46]
// [note-2026-06-01-15:29:09]
// [note-2026-06-04-17:21:51]
// [note-2026-06-05-08:21:31]
// [note-2026-06-07-11:52:34]
// [note-2026-06-12-19:05:58]
// [note-2026-06-15-16:12:56]
// [note-2026-06-25-08:42:55]
// [note-2026-06-25-18:25:31]
// [note-2026-06-27-16:00:09]
