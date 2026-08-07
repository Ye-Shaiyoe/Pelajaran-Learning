// ============================================================
// 06 - OOP: Class, Object, Constructor, Destructor, Encapsulation
// ============================================================
#include <iostream>
#include <string>
using namespace std;

//   CLASS DASAR                        ─
class Mahasiswa {
private:
    // Data member (atribut) — private: hanya bisa diakses di dalam class
    string nama;
    int    nim;
    double ipk;

public:
    //   CONSTRUCTOR                      ─
    // Dipanggil otomatis saat objek dibuat
    // Nama sama dengan nama class, tidak ada return type

    // Default constructor
    Mahasiswa() : nama("Unknown"), nim(0), ipk(0.0) {
        cout << "  [Constructor default] Mahasiswa dibuat" << endl;
    }

    // Parameterized constructor
    Mahasiswa(string nama, int nim, double ipk)
        : nama(nama), nim(nim), ipk(ipk)  // initializer list (lebih efisien)
    {
        cout << "  [Constructor param] " << nama << " dibuat" << endl;
    }

    // Copy constructor
    Mahasiswa(const Mahasiswa& other)
        : nama(other.nama), nim(other.nim), ipk(other.ipk)
    {
        cout << "  [Copy constructor] " << nama << " dicopy" << endl;
    }

    //   DESTRUCTOR                       
    // Dipanggil otomatis saat objek dihancurkan (keluar scope)
    ~Mahasiswa() {
        cout << "  [Destructor] " << nama << " dihancurkan" << endl;
    }

    //   GETTER (accessor)                   ─
    string getNama() const { return nama; }
    int    getNim()  const { return nim;  }
    double getIpk()  const { return ipk;  }

    //   SETTER (mutator)                    
    void setNama(const string& n) { nama = n; }
    void setNim(int n)            { nim = n;  }
    void setIpk(double i) {
        if (i >= 0.0 && i <= 4.0)  // validasi
            ipk = i;
        else
            cout << "IPK tidak valid!" << endl;
    }

    void tampilkan() const {
        cout << "  Nama : " << nama << endl;
        cout << "  NIM  : " << nim  << endl;
        cout << "  IPK  : " << ipk  << endl;
    }

    string getStatus() const {
        if (ipk >= 3.5) return "Cumlaude";
        if (ipk >= 2.75) return "Memuaskan";
        if (ipk >= 2.0) return "Cukup";
        return "Tidak Lulus";
    }

    static int jumlahMahasiswa;

    static int getJumlah() {
        return jumlahMahasiswa;
    }
};

// Inisialisasi static member di luar class
int Mahasiswa::jumlahMahasiswa = 0;

//   CLASS DENGAN POINTER                    
class Buku {
private:
    string* judul;   // pointer member — harus kelola memori sendiri

public:
    Buku(const string& j) {
        judul = new string(j);   // alokasi heap
        cout << "  Buku '" << *judul << "' dibuat" << endl;
    }

    // Rule of Three: jika ada destructor custom, buat juga copy constructor & copy assignment
    ~Buku() {
        cout << "  Buku '" << *judul << "' dihapus" << endl;
        delete judul;   // WAJIB bebas memori!
    }

    // Copy constructor — deep copy
    Buku(const Buku& other) {
        judul = new string(*other.judul);
    }

    // Copy assignment operator
    Buku& operator=(const Buku& other) {
        if (this != &other) {            // cek self-assignment
            delete judul;
            judul = new string(*other.judul);
        }
        return *this;
    }

    void tampilkan() const {
        cout << "  Judul: " << *judul << endl;
    }
};

int main() {
    cout << "=== OBJEK DI STACK ===" << endl;
    {
        Mahasiswa m1;                           // default constructor
        Mahasiswa m2("Budi", 12345, 3.75);     // param constructor
        Mahasiswa m3 = m2;                     // copy constructor

        m2.tampilkan();
        cout << "  Status: " << m2.getStatus() << endl;

        m3.setIpk(3.9);
        cout << "\nSetelah setIpk:" << endl;
        m3.tampilkan();

    }   // destructor dipanggil di sini (LIFO: m3, m2, m1)

    cout << "\n=== OBJEK DI HEAP ===" << endl;
    {
        Mahasiswa* ptr = new Mahasiswa("Ani", 67890, 3.2);
        ptr->tampilkan();   // akses anggota lewat pointer pakai ->
        cout << "Status: " << ptr->getStatus() << endl;

        delete ptr;         // WAJIB! jika tidak → memory leak
        ptr = nullptr;
    }

    cout << "\n=== BUKU (dengan pointer member) ===" << endl;
    {
        Buku b1("C++ Primer");
        Buku b2 = b1;       // copy constructor — deep copy
        b1.tampilkan();
        b2.tampilkan();
    }

    return 0;
}