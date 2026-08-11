// ============================================================
// 07 - Inheritance, Polymorphism, Virtual Function, Abstract Class
// ============================================================
#include <iostream>
#include <string>
#include <vector>
#include <memory>   // smart pointer
using namespace std;

// ── BASE CLASS (Parent) ───────────────────────────────────────
class Hewan {
protected:
    string nama;
    int    umur;

public:
    Hewan(const string& nama, int umur)
        : nama(nama), umur(umur) {}

    // Virtual = bisa di-override oleh derived class
    // PENTING: destructor HARUS virtual jika class akan diwariskan
    virtual ~Hewan() {
        cout << "  ~Hewan(" << nama << ")" << endl;
    }

    // Pure virtual = WAJIB di-override (class menjadi abstract)
    virtual void bersuara() const = 0;

    // Virtual biasa — punya implementasi default tapi bisa di-override
    virtual string info() const {
        return "Hewan: " + nama + " (umur " + to_string(umur) + ")";
    }

    // Non-virtual — tidak bisa di-override (hati-hati!)
    void makan() const {
        cout << nama << " sedang makan" << endl;
    }

    string getNama() const { return nama; }
};

// ── DERIVED CLASS ─────────────────────────────────────────────
class Anjing : public Hewan {
private:
    string ras;

public:
    Anjing(const string& nama, int umur, const string& ras)
        : Hewan(nama, umur), ras(ras) {}   // panggil constructor parent

    ~Anjing() override {
        cout << "  ~Anjing(" << nama << ")" << endl;
    }

    // override keyword (C++11) — kompiler cek apakah benar-benar override
    void bersuara() const override {
        cout << nama << ": Woof! Woof!" << endl;
    }

    string info() const override {
        return Hewan::info() + " | Ras: " + ras;  // panggil parent method
    }

    void main_air() const {
        cout << nama << " suka main air!" << endl;
    }
};

class Kucing : public Hewan {
public:
    Kucing(const string& nama, int umur)
        : Hewan(nama, umur) {}

    void bersuara() const override {
        cout << nama << ": Meow~" << endl;
    }
};

class Burung : public Hewan {
private:
    bool bisaTerbang;

public:
    Burung(const string& nama, int umur, bool bisaTerbang)
        : Hewan(nama, umur), bisaTerbang(bisaTerbang) {}

    void bersuara() const override {
        cout << nama << ": Tweet tweet!" << endl;
    }

    void terbang() const {
        if (bisaTerbang)
            cout << nama << " sedang terbang" << endl;
        else
            cout << nama << " tidak bisa terbang" << endl;
    }
};

// ── MULTIPLE INHERITANCE ──────────────────────────────────────
class Bisa_Berenang {
public:
    virtual void berenang() const {
        cout << "Sedang berenang..." << endl;
    }
};

class Bebek : public Hewan, public Bisa_Berenang {
public:
    Bebek(const string& nama, int umur) : Hewan(nama, umur) {}

    void bersuara() const override {
        cout << nama << ": Kwek kwek!" << endl;
    }

    void berenang() const override {
        cout << nama << " berenang dengan anggun" << endl;
    }
};

int main() {
    // ── POLYMORPHISM ─────────────────────────────────────────
    cout << "=== POLYMORPHISM (pointer ke base class) ===" << endl;

    // Menggunakan smart pointer (modern C++ — tidak perlu delete manual)
    vector<unique_ptr<Hewan>> kebun_binatang;
    kebun_binatang.push_back(make_unique<Anjing>("Rex", 3, "Labrador"));
    kebun_binatang.push_back(make_unique<Kucing>("Mimi", 2));
    kebun_binatang.push_back(make_unique<Burung>("Tweety", 1, true));
    kebun_binatang.push_back(make_unique<Bebek>("Donald", 4));

    // Satu loop, banyak perilaku berbeda — INILAH polymorphism!
    for (const auto& h : kebun_binatang) {
        cout << h->info() << endl;
        h->bersuara();
        h->makan();
        cout << endl;
    }

    // ── DYNAMIC CAST ──────────────────────────────────────────
    cout << "=== DYNAMIC CAST ===" << endl;
    Hewan* ptr = new Anjing("Buddy", 2, "Golden");

    // dynamic_cast: cek tipe saat runtime
    Anjing* anjing = dynamic_cast<Anjing*>(ptr);
    if (anjing) {
        cout << anjing->info() << endl;
        anjing->main_air();
    }

    Kucing* kucing = dynamic_cast<Kucing*>(ptr);
    if (!kucing)
        cout << "Bukan kucing!" << endl;

    delete ptr;

    // ── VIRTUAL TABLE (vtable) — konsep internal ──────────────
    // Setiap class dengan virtual function punya vtable
    // Vtable berisi pointer ke implementasi fungsi yang benar
    // Itulah yang memungkinkan runtime polymorphism

    cout << "\n=== MULTIPLE INHERITANCE ===" << endl;
    Bebek bebek("Daffy", 3);
    bebek.bersuara();
    bebek.berenang();
    bebek.makan();

    return 0;
}