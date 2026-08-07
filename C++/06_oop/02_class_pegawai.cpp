#include <iostream>
#include <string>
using namespace std;

class Pegawai {
private:
    string nama;
    int nip;
    int gaji;

public:
    Pegawai()
        : nama("Tidak diketahui"), nip(0), gaji(0)
    {
        cout << "Identitas Pegawai sedang dibuat." << endl;
    }

    Pegawai(string nama, int  nip, int gaji)
        : nama(nama), nip(nip), gaji(gaji)
    {
        cout << "Pembuatan: " << nama
             << " dibuat dengan gaji Rp"
             << gaji << endl;
    }

    Pegawai(const Pegawai &other)
        : nama(other.nama), nip(other.nip), gaji(other.gaji)
    {
        cout << "Data: " << nama
             << " sedang dicopy." << endl;
    }

    ~Pegawai() {
        cout << "Penghapusan: " << nama
             << " telah dihapus." << endl;
    }

    string getNama() const { return nama; }
    int getNip() const { return nip; }
    int getGaji() const { return gaji; }
};