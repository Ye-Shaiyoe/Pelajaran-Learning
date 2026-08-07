// ============================================================
// 16 - Design Patterns: Singleton, Factory, Observer, RAII,
//                       Strategy, Builder, Command
// ============================================================
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <unordered_map>
using namespace std;

// 1. SINGLETON — Satu instance saja
class Logger {
private:
    static Logger* instance;
    vector<string> logs;

    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger& getInstance() {
        // Thread-safe di C++11 (static local initialization)
        static Logger inst;
        return inst;
    }

    void log(const string& pesan) {
        logs.push_back("[LOG] " + pesan);
        cout << "  [LOG] " << pesan << endl;
    }

    void tampilkan() const {
        cout << "  Total log: " << logs.size() << endl;
    }
};

// 2. FACTORY METHOD — Buat objek tanpa tentukan kelas konkret
class Shape {
public:
    virtual ~Shape() = default;
    virtual double luas() const = 0;
    virtual string nama() const = 0;
    virtual void gambar() const {
        cout << "  Menggambar " << nama() << " (luas=" << luas() << ")" << endl;
    }
};

class Lingkaran : public Shape {
    double r;
public:
    Lingkaran(double r) : r(r) {}
    double luas() const override { return 3.14159 * r * r; }
    string nama() const override { return "Lingkaran(r=" + to_string(r) + ")"; }
};

class Persegi : public Shape {
    double sisi;
public:
    Persegi(double s) : sisi(s) {}
    double luas() const override { return sisi * sisi; }
    string nama() const override { return "Persegi(" + to_string(sisi) + ")"; }
};

class Segitiga : public Shape {
    double alas, tinggi;
public:
    Segitiga(double a, double t) : alas(a), tinggi(t) {}
    double luas() const override { return 0.5 * alas * tinggi; }
    string nama() const override { return "Segitiga"; }
};

// Factory
class ShapeFactory {
public:
    static unique_ptr<Shape> buat(const string& tipe, double a, double b = 0) {
        if (tipe == "lingkaran")  return make_unique<Lingkaran>(a);
        if (tipe == "persegi")    return make_unique<Persegi>(a);
        if (tipe == "segitiga")   return make_unique<Segitiga>(a, b);
        throw invalid_argument("Tipe tidak dikenal: " + tipe);
    }
};

// ============================================================
// 3. OBSERVER — Notifikasi ke banyak subscriber
// ============================================================
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const string& event, const string& data) = 0;
};

class EventBus {
private:
    unordered_map<string, vector<Observer*>> subscribers;

public:
    void subscribe(const string& event, Observer* obs) {
        subscribers[event].push_back(obs);
    }

    void unsubscribe(const string& event, Observer* obs) {
        auto& vec = subscribers[event];
        vec.erase(remove(vec.begin(), vec.end(), obs), vec.end());
    }

    void publish(const string& event, const string& data = "") {
        if (subscribers.count(event)) {
            for (auto* obs : subscribers[event])
                obs->update(event, data);
        }
    }
};

class EmailNotifier : public Observer {
    string email;
public:
    EmailNotifier(const string& e) : email(e) {}
    void update(const string& event, const string& data) override {
        cout << "  [Email → " << email << "] Event: " << event;
        if (!data.empty()) cout << " | Data: " << data;
        cout << endl;
    }
};

class SMSNotifier : public Observer {
    string nomor;
public:
    SMSNotifier(const string& n) : nomor(n) {}
    void update(const string& event, const string& data) override {
        cout << "  [SMS → " << nomor << "] " << event << ": " << data << endl;
    }
};

// ============================================================
// 4. STRATEGY — Pilih algoritma saat runtime
// ============================================================
class SortStrategy {
public:
    virtual ~SortStrategy() = default;
    virtual void sort(vector<int>& data) = 0;
    virtual string nama() = 0;
};

class BubbleSort : public SortStrategy {
public:
    void sort(vector<int>& v) override {
        for (size_t i = 0; i < v.size(); i++)
            for (size_t j = 0; j < v.size()-i-1; j++)
                if (v[j] > v[j+1]) swap(v[j], v[j+1]);
    }
    string nama() override { return "BubbleSort"; }
};

class QuickSort : public SortStrategy {
    void qsort(vector<int>& v, int lo, int hi) {
        if (lo >= hi) return;
        int pivot = v[hi], i = lo - 1;
        for (int j = lo; j < hi; j++)
            if (v[j] <= pivot) swap(v[++i], v[j]);
        swap(v[i+1], v[hi]);
        qsort(v, lo, i);
        qsort(v, i+2, hi);
    }
public:
    void sort(vector<int>& v) override { qsort(v, 0, v.size()-1); }
    string nama() override { return "QuickSort"; }
};

class Sorter {
    unique_ptr<SortStrategy> strategy;
public:
    void setStrategy(unique_ptr<SortStrategy> s) { strategy = move(s); }

    void sort(vector<int>& data) {
        if (!strategy) throw runtime_error("Strategy belum diset!");
        cout << "  Menggunakan: " << strategy->nama() << endl;
        strategy->sort(data);
    }
};

// ============================================================
// 5. BUILDER — Bangun objek kompleks step-by-step
// ============================================================
class Pizza {
public:
    string ukuran, adonan;
    vector<string> topping;
    bool keju = false, saus = false;

    void tampilkan() const {
        cout << "  Pizza " << ukuran << " | Adonan: " << adonan << endl;
        cout << "  Keju: " << boolalpha << keju << " | Saus: " << saus << endl;
        cout << "  Topping: ";
        for (const auto& t : topping) cout << t << " ";
        cout << endl;
    }
};

class PizzaBuilder {
    Pizza pizza;
public:
    PizzaBuilder& setUkuran(const string& s) { pizza.ukuran = s; return *this; }
    PizzaBuilder& setAdonan(const string& a) { pizza.adonan = a; return *this; }
    PizzaBuilder& tambahTopping(const string& t) { pizza.topping.push_back(t); return *this; }
    PizzaBuilder& denganKeju()  { pizza.keju  = true; return *this; }
    PizzaBuilder& denganSaus()  { pizza.saus  = true; return *this; }
    Pizza build() { return pizza; }
};

// ============================================================
// 6. COMMAND — Enkapsulasi aksi sebagai objek
// ============================================================
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo()    = 0;
};

class Dokumen {
    string teks;
public:
    void tambah(const string& s) { teks += s; }
    void hapus(size_t n)         { if (teks.size() >= n) teks.erase(teks.size()-n); }
    string getTeks() const       { return teks; }
};

class TambahTeks : public Command {
    Dokumen& doc;
    string   teks;
public:
    TambahTeks(Dokumen& d, const string& t) : doc(d), teks(t) {}
    void execute() override { doc.tambah(teks); }
    void undo()    override { doc.hapus(teks.size()); }
};

class History {
    vector<unique_ptr<Command>> riwayat;
public:
    void execute(unique_ptr<Command> cmd) {
        cmd->execute();
        riwayat.push_back(move(cmd));
    }
    void undo() {
        if (!riwayat.empty()) {
            riwayat.back()->undo();
            riwayat.pop_back();
        }
    }
};

// ============================================================
int main() {
    // SINGLETON
    cout << "=== SINGLETON ===" << endl;
    Logger::getInstance().log("Aplikasi dimulai");
    Logger::getInstance().log("User login");
    Logger::getInstance().tampilkan();

    // FACTORY
    cout << "\n=== FACTORY ===" << endl;
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(ShapeFactory::buat("lingkaran", 5));
    shapes.push_back(ShapeFactory::buat("persegi", 4));
    shapes.push_back(ShapeFactory::buat("segitiga", 6, 8));

    for (const auto& s : shapes) s->gambar();

    // OBSERVER
    cout << "\n=== OBSERVER ===" << endl;
    EventBus bus;
    EmailNotifier email("budi@email.com");
    SMSNotifier   sms("+6281234567890");

    bus.subscribe("pembelian", &email);
    bus.subscribe("pembelian", &sms);
    bus.subscribe("login",     &email);

    bus.publish("pembelian", "Item: Baju - Rp150.000");
    bus.publish("login",     "user_id=123");

    // STRATEGY
    cout << "\n=== STRATEGY ===" << endl;
    vector<int> data = {64, 25, 12, 22, 11};
    Sorter sorter;

    sorter.setStrategy(make_unique<BubbleSort>());
    sorter.sort(data);
    for (int x : data) cout << x << " ";
    cout << endl;

    data = {64, 25, 12, 22, 11};
    sorter.setStrategy(make_unique<QuickSort>());
    sorter.sort(data);
    for (int x : data) cout << x << " ";
    cout << endl;

    // BUILDER
    cout << "\n=== BUILDER ===" << endl;
    Pizza pizza = PizzaBuilder()
        .setUkuran("Large")
        .setAdonan("Tipis")
        .tambahTopping("Pepperoni")
        .tambahTopping("Jamur")
        .denganKeju()
        .denganSaus()
        .build();
    pizza.tampilkan();

    // COMMAND
    cout << "\n=== COMMAND (Undo/Redo) ===" << endl;
    Dokumen doc;
    History history;

    history.execute(make_unique<TambahTeks>(doc, "Hello"));
    cout << "  Teks: '" << doc.getTeks() << "'" << endl;

    history.execute(make_unique<TambahTeks>(doc, " World"));
    cout << "  Teks: '" << doc.getTeks() << "'" << endl;

    history.undo();
    cout << "  Setelah undo: '" << doc.getTeks() << "'" << endl;

    history.undo();
    cout << "  Setelah undo lagi: '" << doc.getTeks() << "'" << endl;

    return 0;
}
// [note-2026-01-27-12:52:07]
// [note-2026-02-05-15:39:57]
// [note-2026-02-17-17:04:47]
// [note-2026-02-23-12:43:56]
// [note-2026-02-26-22:36:43]
// [note-2026-02-28-10:26:21]
// [note-2026-03-05-20:59:06]
// [note-2026-03-08-12:34:58]
// [note-2026-03-08-15:29:00]
// [note-2026-03-13-21:37:33]
// [note-2026-03-19-14:09:31]
// [note-2026-03-19-18:55:34]
// [note-2026-03-20-13:18:04]
// [note-2026-03-20-19:17:28]
// [note-2026-03-21-10:24:35]
// [note-2026-03-23-15:26:41]
// [note-2026-03-25-10:04:02]
// [note-2026-03-25-22:52:17]
// [note-2026-03-27-12:12:07]
// [note-2026-03-29-16:10:41]
// [note-2026-03-31-16:13:11]
// [note-2026-04-05-09:35:41]
// [note-2026-04-05-11:55:18]
// [note-2026-04-05-19:33:34]
// [note-2026-05-01-18:23:18]
// [note-2026-05-01-18:53:13]
// [note-2026-05-03-18:23:22]
// [note-2026-05-31-14:44:10]
// [note-2026-05-31-18:45:05]
// [note-2026-06-02-15:16:14]
// [note-2026-06-07-22:46:32]
// [note-2026-06-08-16:59:57]
// [note-2026-06-13-18:39:04]
// [note-2026-06-19-11:22:09]
// [note-2026-06-21-12:25:50]
// [note-2026-06-22-16:47:57]
// [note-2026-06-23-11:53:43]
// [note-2026-06-23-16:50:30]
// [note-2026-06-24-09:44:06]
// [note-2026-06-27-10:33:39]
