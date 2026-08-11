// ============================================================
// 11 - Exception Handling: try/catch/throw, Custom Exception
// ============================================================
#include <iostream>
#include <stdexcept>   // runtime_error, logic_error, dll
#include <string>
#include <limits>
using namespace std;

// ── CUSTOM EXCEPTION ──────────────────────────────────────────
class BankException : public exception {
private:
    string pesan;
    int    kode;

public:
    BankException(const string& pesan, int kode)
        : pesan(pesan), kode(kode) {}

    // Override what() dari std::exception
    const char* what() const noexcept override {
        return pesan.c_str();
    }

    int getKode() const { return kode; }
};

class SaldoKurangException : public BankException {
public:
    SaldoKurangException(double saldo, double jumlah)
        : BankException(
            "Saldo tidak cukup! Saldo: " + to_string(saldo) +
            ", Dibutuhkan: " + to_string(jumlah),
            1001
          ) {}
};

class AkunNotFoundException : public BankException {
public:
    AkunNotFoundException(const string& id)
        : BankException("Akun tidak ditemukan: " + id, 1002) {}
};

// ── KELAS BANK ────────────────────────────────────────────────
class RekeningBank {
private:
    string id;
    double saldo;

public:
    RekeningBank(const string& id, double saldoAwal)
        : id(id), saldo(saldoAwal)
    {
        if (saldoAwal < 0)
            throw logic_error("Saldo awal tidak boleh negatif!");
    }

    void tarik(double jumlah) {
        if (jumlah <= 0)
            throw invalid_argument("Jumlah penarikan harus positif!");
        if (jumlah > saldo)
            throw SaldoKurangException(saldo, jumlah);
        saldo -= jumlah;
        cout << "  Berhasil tarik Rp" << jumlah << ", sisa: " << saldo << endl;
    }

    void setor(double jumlah) {
        if (jumlah <= 0)
            throw invalid_argument("Jumlah setoran harus positif!");
        saldo += jumlah;
        cout << "  Berhasil setor Rp" << jumlah << ", saldo: " << saldo << endl;
    }

    string getId()     const { return id; }
    double getSaldo()  const { return saldo; }
};

// ── FUNGSI DENGAN EXCEPTION SPECIFICATION ─────────────────────
double bagi(double a, double b) {
    if (b == 0)
        throw runtime_error("Pembagi tidak boleh nol!");
    return a / b;
}

// noexcept — berjanji tidak throw exception (lebih cepat)
int tambah_safe(int a, int b) noexcept {
    return a + b;
}

// ── NESTED TRY-CATCH ──────────────────────────────────────────
void proses_file(const string& filename) {
    try {
        if (filename.empty())
            throw invalid_argument("Nama file kosong");

        // Coba buka file
        throw runtime_error("File tidak ditemukan: " + filename);

    } catch (const invalid_argument& e) {
        cout << "  [Input Error] " << e.what() << endl;
        throw;   // re-throw untuk ditangani caller
    }
}

int main() {
    // ── TRY/CATCH DASAR ───────────────────────────────────────
    cout << "=== TRY/CATCH DASAR ===" << endl;
    try {
        cout << "5 / 2 = " << bagi(5, 2) << endl;
        cout << "5 / 0 = " << bagi(5, 0) << endl;  // throw!
        cout << "Baris ini tidak akan dieksekusi" << endl;
    } catch (const runtime_error& e) {
        cout << "  [Runtime Error] " << e.what() << endl;
    }

    // ── MULTIPLE CATCH ────────────────────────────────────────
    cout << "\n=== MULTIPLE CATCH ===" << endl;
    RekeningBank* rekening = nullptr;

    try {
        rekening = new RekeningBank("ACC001", 1000.0);
        rekening->setor(500.0);
        rekening->tarik(200.0);
        rekening->tarik(2000.0);   // SaldoKurangException!
    }
    catch (const SaldoKurangException& e) {
        cout << "  [Saldo Error] Kode " << e.getKode() << ": " << e.what() << endl;
    }
    catch (const BankException& e) {
        cout << "  [Bank Error] Kode " << e.getKode() << ": " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "  [Invalid Arg] " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "  [General Error] " << e.what() << endl;
    }
    catch (...) {
        // Catch-all: menangkap semua exception termasuk non-std
        cout << "  [Unknown Error] Exception tidak dikenal!" << endl;
    }

    delete rekening;

    // ── EXCEPTION DALAM CONSTRUCTOR ───────────────────────────
    cout << "\n=== EXCEPTION DI CONSTRUCTOR ===" << endl;
    try {
        RekeningBank invalid("ACC_NEG", -500.0);  // throw logic_error!
    } catch (const logic_error& e) {
        cout << "  Gagal buat rekening: " << e.what() << endl;
    }

    // ── NESTED TRY-CATCH ──────────────────────────────────────
    cout << "\n=== NESTED & RE-THROW ===" << endl;
    try {
        proses_file("");
    } catch (const exception& e) {
        cout << "  [Ditangkap di main] " << e.what() << endl;
    }

    try {
        proses_file("data.txt");
    } catch (const runtime_error& e) {
        cout << "  [File Error] " << e.what() << endl;
    }

    // ── EXCEPTION SAFETY LEVELS ───────────────────────────────
    cout << "\n=== EXCEPTION SAFETY (info) ===" << endl;
    cout << "  1. No-throw guarantee  : fungsi TIDAK pernah throw (noexcept)" << endl;
    cout << "  2. Strong guarantee    : jika throw, state tidak berubah" << endl;
    cout << "  3. Basic guarantee     : jika throw, program tetap valid (no leak)" << endl;
    cout << "  4. No guarantee        : throw bisa korupsi state (hindari!)" << endl;

    // ── STD EXCEPTION HIERARCHY ───────────────────────────────
    cout << "\n=== CONTOH STD EXCEPTIONS ===" << endl;
    vector<pair<string,function<void()>>> tests = {
        {"bad_alloc",        []{ throw bad_alloc(); }},
        {"out_of_range",     []{ vector<int> v; v.at(99); }},
        {"overflow_error",   []{ throw overflow_error("overflow!"); }},
    };

    for (auto& [name, fn] : tests) {
        try {
            fn();
        } catch (const exception& e) {
            cout << "  " << name << ": " << e.what() << endl;
        }
    }

    return 0;
}