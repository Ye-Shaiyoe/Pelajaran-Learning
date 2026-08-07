// ============================================================
// 12 - File I/O: fstream, baca/tulis file teks & biner
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// ── STRUCT DATA ───────────────────────────────────────────────
struct Mahasiswa {
    string nama;
    int    nim;
    double ipk;

    void tampilkan() const {
        cout << "  Nama: " << nama << ", NIM: " << nim << ", IPK: " << ipk << endl;
    }
};

int main() {
    // ── TULIS FILE TEKS ───────────────────────────────────────
    cout << "=== TULIS FILE TEKS ===" << endl;
    {
        ofstream ofs("data_siswa.txt");   // buka untuk tulis (hapus isi lama)
        if (!ofs) {
            cerr << "Gagal membuka file untuk tulis!" << endl;
            return 1;
        }

        ofs << "Budi,12345,3.75\n";
        ofs << "Ani,67890,3.90\n";
        ofs << "Citra,11111,3.20\n";
        ofs << "Dodi,22222,2.85\n";

        cout << "  File berhasil ditulis" << endl;
    }   // ofs otomatis ditutup (RAII)

    // ── BACA FILE TEKS (baris per baris) ─────────────────────
    cout << "\n=== BACA FILE TEKS ===" << endl;
    {
        ifstream ifs("data_siswa.txt");
        if (!ifs) {
            cerr << "File tidak ditemukan!" << endl;
            return 1;
        }

        string baris;
        while (getline(ifs, baris)) {
            cout << "  Baris: " << baris << endl;
        }
    }

    // ── BACA FILE DAN PARSE CSV ───────────────────────────────
    cout << "\n=== PARSE CSV ===" << endl;
    {
        ifstream ifs("data_siswa.txt");
        vector<Mahasiswa> daftar;

        string baris;
        while (getline(ifs, baris)) {
            if (baris.empty()) continue;

            stringstream ss(baris);   // gunakan stringstream untuk parsing
            string token;
            Mahasiswa mhs;

            getline(ss, mhs.nama, ',');   // ambil sampai ','
            getline(ss, token, ',');
            mhs.nim = stoi(token);
            getline(ss, token, ',');
            mhs.ipk = stod(token);

            daftar.push_back(mhs);
        }

        cout << "  Jumlah data: " << daftar.size() << endl;
        for (const auto& m : daftar)
            m.tampilkan();
    }

    // ── APPEND (tambah tanpa hapus) ───────────────────────────
    cout << "\n=== APPEND KE FILE ===" << endl;
    {
        ofstream ofs("data_siswa.txt", ios::app);   // mode append
        ofs << "Eva,33333,3.55\n";
        cout << "  Data Eva ditambahkan" << endl;
    }

    // ── BACA SEMUA SEKALIGUS ──────────────────────────────────
    cout << "\n=== BACA SELURUH FILE ===" << endl;
    {
        ifstream ifs("data_siswa.txt");
        // Trick: baca seluruh isi file ke string
        string isi((istreambuf_iterator<char>(ifs)),
                    istreambuf_iterator<char>());
        cout << "Isi file:\n" << isi << endl;
    }

    // ── FILE BINER ────────────────────────────────────────────
    cout << "=== FILE BINER ===" << endl;
    {
        // Tulis struct ke file biner
        ofstream ofs("data_biner.bin", ios::binary);

        vector<Mahasiswa> data = {
            {"Budi",  12345, 3.75},
            {"Ani",   67890, 3.90},
            {"Citra", 11111, 3.20}
        };

        // Tulis jumlah data dulu
        size_t n = data.size();
        ofs.write(reinterpret_cast<const char*>(&n), sizeof(n));

        // Tulis tiap struct (hanya works untuk POD struct)
        // Untuk string, perlu serialisasi custom
        for (const auto& m : data) {
            // Tulis nama dengan panjangnya
            size_t len = m.nama.size();
            ofs.write(reinterpret_cast<const char*>(&len), sizeof(len));
            ofs.write(m.nama.c_str(), len);
            ofs.write(reinterpret_cast<const char*>(&m.nim), sizeof(m.nim));
            ofs.write(reinterpret_cast<const char*>(&m.ipk), sizeof(m.ipk));
        }
        cout << "  File biner ditulis" << endl;
    }

    {
        // Baca file biner
        ifstream ifs("data_biner.bin", ios::binary);
        size_t n;
        ifs.read(reinterpret_cast<char*>(&n), sizeof(n));

        cout << "  Jumlah record: " << n << endl;
        for (size_t i = 0; i < n; i++) {
            Mahasiswa m;
            size_t len;
            ifs.read(reinterpret_cast<char*>(&len), sizeof(len));
            m.nama.resize(len);
            ifs.read(&m.nama[0], len);
            ifs.read(reinterpret_cast<char*>(&m.nim), sizeof(m.nim));
            ifs.read(reinterpret_cast<char*>(&m.ipk), sizeof(m.ipk));
            m.tampilkan();
        }
    }

    // ── STRINGSTREAM ──────────────────────────────────────────
    cout << "\n=== STRINGSTREAM ===" << endl;
    {
        // Bangun string seperti stream
        ostringstream oss;
        oss << "Nama: " << "Budi" << ", Nilai: " << 95 << ", IPK: " << 3.75;
        string hasil = oss.str();
        cout << "  " << hasil << endl;

        // Parse string
        string data_str = "100 200 300 400 500";
        istringstream iss(data_str);
        int num;
        int total = 0;
        while (iss >> num) total += num;
        cout << "  Total: " << total << endl;
    }

    // ── POSISI DALAM FILE ─────────────────────────────────────
    cout << "\n=== SEEK/TELL ===" << endl;
    {
        fstream fs("data_siswa.txt");

        // Cari ukuran file
        fs.seekg(0, ios::end);      // pergi ke akhir
        streampos ukuran = fs.tellg();  // posisi saat ini = ukuran file
        cout << "  Ukuran file: " << ukuran << " byte" << endl;

        fs.seekg(0, ios::beg);      // kembali ke awal
        string baris1;
        getline(fs, baris1);
        cout << "  Baris pertama: " << baris1 << endl;
    }

    return 0;
}
// [note-2026-02-09-17:41:37]
// [note-2026-02-17-17:42:28]
// [note-2026-02-18-21:27:04]
// [note-2026-02-20-15:33:36]
// [note-2026-02-23-17:03:27]
// [note-2026-02-23-22:27:39]
// [note-2026-02-26-17:08:33]
// [note-2026-03-01-18:04:09]
// [note-2026-03-02-18:54:32]
// [note-2026-03-06-18:17:18]
// [note-2026-03-09-08:52:13]
// [note-2026-03-11-16:04:38]
// [note-2026-03-13-21:45:52]
// [note-2026-03-16-09:26:28]
// [note-2026-03-17-14:23:59]
// [note-2026-03-18-22:17:38]
// [note-2026-03-20-09:19:20]
// [note-2026-03-23-18:08:09]
// [note-2026-03-24-19:42:46]
// [note-2026-03-27-12:20:29]
// [note-2026-04-10-13:35:57]
// [note-2026-05-09-15:38:48]
// [note-2026-05-28-19:13:33]
// [note-2026-06-08-14:33:41]
// [note-2026-06-12-11:50:27]
// [note-2026-06-18-13:43:57]
// [note-2026-06-19-11:14:49]
// [note-2026-06-21-15:42:32]
// [note-2026-06-23-10:19:44]
// [note-2026-06-27-13:58:22]
