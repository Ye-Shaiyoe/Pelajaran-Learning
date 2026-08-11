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