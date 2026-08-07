// ============================================================
// 08 - Templates: Generic Programming
// ============================================================
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// ── FUNCTION TEMPLATE ─────────────────────────────────────────
// Satu fungsi untuk banyak tipe data
template<typename T>
T maks(T a, T b) {
    return (a > b) ? a : b;
}

// Template dengan beberapa parameter tipe
template<typename T, typename U>
void tampilkan_pasangan(T a, U b) {
    cout << "(" << a << ", " << b << ")" << endl;
}

// Template dengan non-type parameter
template<typename T, int N>
void isi_array(T arr[], T nilai) {
    for (int i = 0; i < N; i++)
        arr[i] = nilai;
}

// Template specialization — perilaku khusus untuk tipe tertentu
template<typename T>
bool sama(T a, T b) {
    return a == b;
}

// Specialization untuk double (perbandingan floating point)
template<>
bool sama<double>(double a, double b) {
    return abs(a - b) < 1e-9;
}

// ── CLASS TEMPLATE ────────────────────────────────────────────
template<typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(const T& val) {
        data.push_back(val);
    }

    T pop() {
        if (data.empty())
            throw underflow_error("Stack kosong!");
        T val = data.back();
        data.pop_back();
        return val;
    }

    T& top() {
        if (data.empty())
            throw underflow_error("Stack kosong!");
        return data.back();
    }

    bool empty() const { return data.empty(); }
    size_t size() const { return data.size(); }

    void tampilkan() const {
        cout << "  Stack [";
        for (size_t i = 0; i < data.size(); i++) {
            cout << data[i];
            if (i + 1 < data.size()) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// ── CLASS TEMPLATE dengan MULTIPLE PARAMETER ─────────────────
template<typename Key, typename Value>
class Pasangan {
private:
    Key   key;
    Value value;

public:
    Pasangan(Key k, Value v) : key(k), value(v) {}

    Key   getKey()   const { return key;   }
    Value getValue() const { return value; }

    void tampilkan() const {
        cout << key << " → " << value << endl;
    }
};

// ── VARIADIC TEMPLATE (C++11) ─────────────────────────────────
// Fungsi yang menerima jumlah argumen berapa pun
template<typename T>
void cetak(T t) {   // base case
    cout << t << endl;
}

template<typename T, typename... Args>
void cetak(T t, Args... args) {   // recursive case
    cout << t << " ";
    cetak(args...);   // pack expansion
}

// Sum variadic
template<typename T>
T sum(T t) { return t; }

template<typename T, typename... Args>
T sum(T t, Args... args) {
    return t + sum(args...);
}

// ── TEMPLATE ALIAS (C++11) ────────────────────────────────────
template<typename T>
using Vec = vector<T>;

template<typename K, typename V>
using Map = Pasangan<K, V>;

int main() {
    // ── FUNCTION TEMPLATE ─────────────────────────────────────
    cout << "=== FUNCTION TEMPLATE ===" << endl;
    cout << "maks(3, 7)       = " << maks(3, 7)       << endl;
    cout << "maks(3.14, 2.71) = " << maks(3.14, 2.71) << endl;
    cout << "maks('a', 'z')   = " << maks('a', 'z')   << endl;
    cout << "maks(\"abc\",\"xyz\") = " << maks(string("abc"), string("xyz")) << endl;

    cout << "\nPasangan: ";
    tampilkan_pasangan(42, "Hello");
    tampilkan_pasangan(3.14, true);

    // ── CLASS TEMPLATE ─────────────────────────────────────────
    cout << "\n=== CLASS TEMPLATE: Stack<T> ===" << endl;
    Stack<int> s_int;
    s_int.push(10);
    s_int.push(20);
    s_int.push(30);
    s_int.tampilkan();
    cout << "  pop() = " << s_int.pop() << endl;
    s_int.tampilkan();

    Stack<string> s_str;
    s_str.push("Apel");
    s_str.push("Mangga");
    s_str.push("Jeruk");
    s_str.tampilkan();
    cout << "  top() = " << s_str.top() << endl;

    // Exception handling
    try {
        Stack<int> empty_stack;
        empty_stack.pop();
    } catch (const underflow_error& e) {
        cout << "  Error: " << e.what() << endl;
    }

    // ── MULTIPLE PARAMETER ─────────────────────────────────────
    cout << "\n=== MULTIPLE PARAMETER TEMPLATE ===" << endl;
    Pasangan<string, int> p1("Budi", 25);
    Pasangan<int, double> p2(1, 3.14);
    p1.tampilkan();
    p2.tampilkan();

    // ── VARIADIC TEMPLATE ──────────────────────────────────────
    cout << "\n=== VARIADIC TEMPLATE ===" << endl;
    cetak("Hello", 42, 3.14, true);
    cout << "Sum(1,2,3,4,5) = " << sum(1, 2, 3, 4, 5) << endl;

    // ── TEMPLATE ALIAS ─────────────────────────────────────────
    cout << "\n=== TEMPLATE ALIAS ===" << endl;
    Vec<int> bilangan = {1, 2, 3, 4, 5};
    for (auto n : bilangan) cout << n << " ";
    cout << endl;

    return 0;
}
// [note-2026-01-27-17:33:40]
// [note-2026-02-05-08:08:40]
// [note-2026-02-15-17:43:32]
// [note-2026-02-20-08:44:22]
// [note-2026-02-21-09:58:56]
// [note-2026-02-23-21:16:38]
// [note-2026-02-25-14:44:58]
// [note-2026-02-25-22:41:15]
// [note-2026-02-27-16:04:35]
// [note-2026-02-28-19:34:03]
// [note-2026-03-03-08:07:59]
// [note-2026-03-05-13:41:39]
// [note-2026-03-07-16:12:49]
// [note-2026-03-09-14:18:39]
// [note-2026-03-17-19:28:00]
// [note-2026-03-19-11:32:33]
// [note-2026-03-21-12:42:38]
// [note-2026-03-21-12:57:37]
// [note-2026-03-21-13:22:12]
// [note-2026-03-29-08:11:59]
// [note-2026-04-03-21:19:50]
// [note-2026-04-10-12:05:01]
// [note-2026-04-25-18:54:49]
// [note-2026-04-25-22:06:15]
// [note-2026-05-09-17:20:06]
// [note-2026-05-27-18:34:28]
// [note-2026-05-28-12:41:40]
// [note-2026-05-31-08:42:06]
// [note-2026-06-01-18:44:37]
// [note-2026-06-03-18:04:45]
// [note-2026-06-05-11:53:52]
// [note-2026-06-06-14:25:15]
// [note-2026-06-07-17:06:11]
// [note-2026-06-08-11:35:13]
// [note-2026-06-09-09:51:43]
// [note-2026-06-10-15:13:59]
// [note-2026-06-11-14:06:45]
// [note-2026-06-12-22:27:21]
// [note-2026-06-13-14:26:41]
// [note-2026-06-18-19:06:59]
// [note-2026-06-24-14:34:05]
// [note-2026-06-26-10:20:46]
