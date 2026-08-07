// ============================================================
// 01 - Hello World & Struktur Program C++
// ============================================================
// Compile: g++ -std=c++17 -o hello 01_hello_world.cpp
// Run:     ./hello

#include <iostream>  // library untuk input/output
#include <string>

// Setiap program C++ HARUS memiliki fungsi main()
// int di depan berarti fungsi ini mengembalikan integer
int main() {
    // std::cout = standard character output (cetak ke layar)
    // <<        = operator "kirim ke"
    // std::endl = end line (pindah baris + flush buffer)
    std::cout << "Hello, World!" << std::endl;

    // Bisa juga pakai '\n' — lebih cepat karena tidak flush
    std::cout << "Belajar C++ itu menyenangkan!\n";

    // Memakai 'using namespace std' agar tidak perlu tulis std::
    using namespace std;
    cout << "Selamat datang di C++ Advanced!" << endl;

    // return 0 = program selesai tanpa error
    return 0;
}