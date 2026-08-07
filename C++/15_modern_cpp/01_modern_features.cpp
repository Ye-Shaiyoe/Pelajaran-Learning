// ============================================================
// 15 - Modern C++: Fitur C++11/14/17/20
// ============================================================
#include <iostream>
#include <string>
#include <vector>
#include <optional>      // C++17
#include <variant>       // C++17
#include <any>           // C++17
#include <string_view>   // C++17
#include <tuple>
#include <type_traits>
#include <numeric>
using namespace std;

// ── C++11 FEATURES ────────────────────────────────────────────

// 1. Move Semantics & Rvalue References
class Buffer {
private:
    int* data;
    size_t size;

public:
    Buffer(size_t n) : size(n), data(new int[n]) {
        cout << "  Buffer(" << n << ") dibuat" << endl;
    }

    // Destructor
    ~Buffer() {
        delete[] data;
        cout << "  Buffer dihapus" << endl;
    }

    // Copy constructor — MAHAL (salin semua data)
    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        copy(other.data, other.data + size, data);
        cout << "  Buffer COPIED (mahal!)" << endl;
    }

    // Move constructor — MURAH (curi pointer)
    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        cout << "  Buffer MOVED (murah!)" << endl;
    }

    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    size_t getSize() const { return size; }
};

// 2. Perfect Forwarding
template<typename T>
void wrapper(T&& arg) {
    // forward<T> mempertahankan value category (lvalue/rvalue)
    cout << "  Forwarding..." << endl;
}

// ── C++17 FEATURES ────────────────────────────────────────────

// 3. std::optional — nilai yang mungkin tidak ada
optional<double> bagi_aman(double a, double b) {
    if (b == 0) return nullopt;   // tidak ada nilai
    return a / b;
}

optional<string> cari_pengguna(int id) {
    if (id == 1) return "Budi";
    if (id == 2) return "Ani";
    return nullopt;
}

// 4. std::variant — union yang type-safe
using Nilai = variant<int, double, string, bool>;

void tampilkan_nilai(const Nilai& n) {
    visit([](auto&& val) {
        cout << "  Nilai: " << val << " (tipe: " << typeid(val).name() << ")" << endl;
    }, n);
}

// 5. if constexpr — compile-time branching
template<typename T>
void info_tipe(T val) {
    if constexpr (is_integral_v<T>) {
        cout << "  Integer: " << val << endl;
    } else if constexpr (is_floating_point_v<T>) {
        cout << "  Float  : " << val << endl;
    } else {
        cout << "  Lainnya: " << val << endl;
    }
}

// 6. Fold expressions (C++17) — operasi pada parameter pack
template<typename... Args>
auto sum_fold(Args... args) {
    return (... + args);   // fold expression
}

template<typename... Args>
void print_all(Args... args) {
    ((cout << "  " << args << "\n"), ...);   // comma fold
}

int main() {
    // ── AUTO & DECLTYPE ───────────────────────────────────────
    cout << "=== AUTO & DECLTYPE ===" << endl;
    auto x = 42;
    auto y = 3.14;
    auto z = "hello"s;   // std::string literal

    decltype(x) w = 100;   // tipe sama seperti x (int)
    cout << "  x=" << x << " y=" << y << " z=" << z << " w=" << w << endl;

    // ── MOVE SEMANTICS ────────────────────────────────────────
    cout << "\n=== MOVE SEMANTICS ===" << endl;
    {
        Buffer b1(100);
        Buffer b2 = b1;           // copy — salin data
        Buffer b3 = move(b1);     // move — curi pointer
        cout << "  b2.size=" << b2.getSize() << endl;
        cout << "  b3.size=" << b3.getSize() << endl;
        cout << "  b1.size=" << b1.getSize() << " (kosong setelah move)" << endl;
    }

    // ── STD::OPTIONAL ─────────────────────────────────────────
    cout << "\n=== STD::OPTIONAL (C++17) ===" << endl;
    {
        auto r1 = bagi_aman(10, 3);
        auto r2 = bagi_aman(10, 0);

        // Cek menggunakan has_value() atau operator bool
        if (r1) cout << "  10/3 = " << *r1 << endl;
        if (!r2) cout << "  10/0 = tidak ada hasil (division by zero)" << endl;

        // value_or — nilai default jika nullopt
        cout << "  r2.value_or(-1) = " << r2.value_or(-1) << endl;

        // Penggunaan idiomatis
        for (int id = 1; id <= 3; id++) {
            if (auto user = cari_pengguna(id)) {
                cout << "  ID " << id << ": " << *user << endl;
            } else {
                cout << "  ID " << id << ": tidak ditemukan" << endl;
            }
        }
    }

    // ── STD::VARIANT ──────────────────────────────────────────
    cout << "\n=== STD::VARIANT (C++17) ===" << endl;
    {
        vector<Nilai> daftar = {42, 3.14, string("halo"), true};
        for (const auto& n : daftar)
            tampilkan_nilai(n);

        // holds_alternative — cek tipe saat runtime
        Nilai v = "test";
        if (holds_alternative<string>(v))
            cout << "  Ini string: " << get<string>(v) << endl;

        // get_if — aman, return pointer (nullptr jika salah tipe)
        if (auto* ptr = get_if<int>(&v))
            cout << "  Int: " << *ptr << endl;
        else
            cout << "  Bukan int" << endl;
    }

    // ── STD::ANY ──────────────────────────────────────────────
    cout << "\n=== STD::ANY (C++17) ===" << endl;
    {
        any a;
        a = 42;
        cout << "  any int: " << any_cast<int>(a) << endl;

        a = string("hello");
        cout << "  any string: " << any_cast<string>(a) << endl;

        a = 3.14;
        cout << "  any double: " << any_cast<double>(a) << endl;

        try {
            any_cast<int>(a);   // a berisi double, bukan int!
        } catch (const bad_any_cast& e) {
            cout << "  bad_any_cast: " << e.what() << endl;
        }
    }

    // ── STRING_VIEW ───────────────────────────────────────────
    cout << "\n=== STRING_VIEW (C++17) ===" << endl;
    {
        // Non-owning view ke string — tidak ada alokasi!
        string s = "Hello, World!";
        string_view sv = s;

        cout << "  Full: "    << sv           << endl;
        cout << "  Sub:  "    << sv.substr(7, 5) << endl;
        cout << "  Length: "  << sv.length()   << endl;

        // Sangat efisien untuk passing string ke fungsi
        auto starts_with = [](string_view s, string_view prefix) {
            return s.starts_with(prefix);   // C++20
        };
    }

    // ── STRUCTURED BINDINGS (C++17) ───────────────────────────
    cout << "\n=== STRUCTURED BINDINGS (C++17) ===" << endl;
    {
        auto [a, b, c] = make_tuple(1, 3.14, "hello");
        cout << "  Tuple: " << a << ", " << b << ", " << c << endl;

        map<string, int> scores = {{"A", 90}, {"B", 80}};
        for (auto& [key, val] : scores)
            cout << "  " << key << " = " << val << endl;

        // Structured binding dengan array
        int arr[] = {10, 20, 30};
        auto& [x2, y2, z2] = arr;
        x2 = 100;
        cout << "  arr[0] after x2=100: " << arr[0] << endl;
    }

    // ── IF CONSTEXPR ──────────────────────────────────────────
    cout << "\n=== IF CONSTEXPR ===" << endl;
    info_tipe(42);
    info_tipe(3.14);
    info_tipe(string("hello"));

    // ── FOLD EXPRESSIONS (C++17) ──────────────────────────────
    cout << "\n=== FOLD EXPRESSIONS ===" << endl;
    cout << "  sum(1..5) = " << sum_fold(1, 2, 3, 4, 5) << endl;
    cout << "  print_all:" << endl;
    print_all("satu", 2, 3.0, true);

    // ── CONSTEXPR IF (COMPILE TIME) ───────────────────────────
    cout << "\n=== CONSTEXPR COMPUTATION ===" << endl;
    constexpr auto faktorial = [](auto self, int n) -> int {
        return n <= 1 ? 1 : n * self(self, n - 1);
    };
    // C++17: std::invoke
    cout << "  faktorial(10) = " << faktorial(faktorial, 10) << endl;

    // ── INLINE VARIABLE (C++17) ───────────────────────────────
    // Didefinisikan di header, tidak perlu definisi di .cpp
    inline constexpr double PHI = 1.6180339887;
    cout << "\n  PHI = " << PHI << endl;

    return 0;
}
// [note-2026-02-09-10:30:37]
// [note-2026-02-18-11:45:19]
// [note-2026-02-20-09:52:40]
// [note-2026-02-21-11:33:31]
// [note-2026-02-25-21:58:06]
// [note-2026-02-26-08:02:19]
// [note-2026-02-27-16:20:27]
// [note-2026-03-01-15:43:04]
// [note-2026-03-02-09:35:30]
// [note-2026-03-08-18:54:17]
// [note-2026-03-09-17:16:19]
// [note-2026-03-11-12:47:13]
// [note-2026-03-13-10:34:29]
// [note-2026-03-16-19:00:25]
// [note-2026-03-16-22:14:06]
// [note-2026-03-18-12:46:31]
// [note-2026-03-18-13:36:26]
// [note-2026-03-18-18:50:31]
// [note-2026-03-20-21:29:38]
// [note-2026-03-27-13:58:08]
// [note-2026-04-01-19:31:01]
// [note-2026-04-02-12:29:34]
// [note-2026-04-03-12:05:42]
// [note-2026-05-02-19:35:32]
// [note-2026-06-06-17:28:34]
// [note-2026-06-06-19:50:52]
// [note-2026-06-06-22:58:05]
// [note-2026-06-07-08:59:57]
// [note-2026-06-13-11:50:22]
// [note-2026-06-17-18:51:06]
// [note-2026-06-19-08:26:23]
// [note-2026-06-19-17:20:40]
// [note-2026-06-19-17:29:00]
// [note-2026-06-22-16:31:30]
// [note-2026-06-24-20:27:35]
