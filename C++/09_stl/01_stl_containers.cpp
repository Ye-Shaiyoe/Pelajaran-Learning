// ============================================================
// 09 - STL: Standard Template Library
//      vector, list, deque, stack, queue, set, map, unordered_map
// ============================================================
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

void separator(const string& title) {
    cout << "\n=== " << title << " ===" << endl;
}

int main() {
    // ── VECTOR ────────────────────────────────────────────────
    // Array dinamis, akses O(1), tambah/hapus di akhir O(1) amortized
    separator("VECTOR");
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    v.push_back(7);          // tambah di akhir
    v.insert(v.begin(), 0);  // tambah di awal (O(n))
    v.erase(v.begin() + 2);  // hapus index ke-2

    cout << "size=" << v.size() << " capacity=" << v.capacity() << endl;
    for (int x : v) cout << x << " ";
    cout << endl;

    // Iterator
    cout << "Front: " << v.front() << ", Back: " << v.back() << endl;

    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // ── LIST ──────────────────────────────────────────────────
    // Doubly linked list, insert/delete O(1), akses O(n)
    separator("LIST");
    list<int> lst = {5, 3, 1, 4, 2};
    lst.push_front(0);
    lst.push_back(6);
    lst.sort();    // sort built-in

    for (int x : lst) cout << x << " ";
    cout << endl;

    lst.remove(3);  // hapus semua elemen bernilai 3
    lst.unique();   // hapus duplikat berurutan

    // ── DEQUE ─────────────────────────────────────────────────
    // Double-ended queue, push/pop di kedua ujung O(1)
    separator("DEQUE");
    deque<int> dq = {3, 4, 5};
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(6);

    for (int x : dq) cout << x << " ";
    cout << endl;

    // ── STACK ─────────────────────────────────────────────────
    // LIFO (Last In First Out), hanya push/pop/top
    separator("STACK");
    stack<string> st;
    st.push("Pertama");
    st.push("Kedua");
    st.push("Ketiga");

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    // ── QUEUE ─────────────────────────────────────────────────
    // FIFO (First In First Out)
    separator("QUEUE");
    queue<string> q;
    q.push("A");
    q.push("B");
    q.push("C");

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Priority Queue — elemen terbesar selalu di atas
    separator("PRIORITY QUEUE");
    priority_queue<int> pq;
    pq.push(5); pq.push(1); pq.push(8); pq.push(3);

    while (!pq.empty()) {
        cout << pq.top() << " ";   // max-heap: 8, 5, 3, 1
        pq.pop();
    }
    cout << endl;

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(5); min_pq.push(1); min_pq.push(8); min_pq.push(3);
    while (!min_pq.empty()) {
        cout << min_pq.top() << " ";   // 1, 3, 5, 8
        min_pq.pop();
    }
    cout << endl;

    // ── SET ───────────────────────────────────────────────────
    // Koleksi unik, terurut otomatis, operasi O(log n)
    separator("SET");
    set<int> s = {5, 3, 1, 4, 1, 5, 9, 2};  // duplikat otomatis hilang

    for (int x : s) cout << x << " ";  // output: 1 2 3 4 5 9
    cout << endl;

    s.insert(7);
    s.erase(3);

    if (s.find(4) != s.end())
        cout << "4 ada di set" << endl;

    cout << "count(5) = " << s.count(5) << endl;  // 0 atau 1

    // ── MAP ───────────────────────────────────────────────────
    // Key-value pairs, key unik dan terurut, operasi O(log n)
    separator("MAP");
    map<string, int> nilai_siswa;

    // Insert berbagai cara
    nilai_siswa["Budi"]  = 85;
    nilai_siswa["Ani"]   = 92;
    nilai_siswa["Citra"] = 78;
    nilai_siswa.insert({"Dodi", 88});
    nilai_siswa.emplace("Eva", 95);  // lebih efisien

    // Iterasi — otomatis terurut berdasarkan key
    for (const auto& [nama, nilai] : nilai_siswa) {  // structured binding C++17
        cout << nama << ": " << nilai << endl;
    }

    // Cek keberadaan key
    if (nilai_siswa.count("Ani"))
        cout << "Ani ada, nilai: " << nilai_siswa["Ani"] << endl;

    // ── UNORDERED_MAP ─────────────────────────────────────────
    // Hash map, operasi rata-rata O(1) — tidak terurut
    separator("UNORDERED_MAP");
    unordered_map<string, string> ibu_kota = {
        {"Indonesia", "Jakarta"},
        {"Jepang",    "Tokyo"},
        {"Amerika",   "Washington D.C."},
        {"Inggris",   "London"}
    };

    ibu_kota["Prancis"] = "Paris";

    for (const auto& [negara, kota] : ibu_kota) {
        cout << negara << " → " << kota << endl;
    }

    // ── ALGORITHM ─────────────────────────────────────────────
    separator("ALGORITHM (STL)");
    vector<int> data = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // find
    auto it = find(data.begin(), data.end(), 9);
    if (it != data.end())
        cout << "9 ditemukan di index: " << (it - data.begin()) << endl;

    // count
    vector<int> d2 = {1, 2, 2, 3, 2, 4};
    cout << "Jumlah 2: " << count(d2.begin(), d2.end(), 2) << endl;

    // min/max_element
    auto [mn, mx] = minmax_element(data.begin(), data.end());
    cout << "Min=" << *mn << ", Max=" << *mx << endl;

    // accumulate (sum)
    int total = accumulate(data.begin(), data.end(), 0);
    cout << "Sum = " << total << endl;

    // transform
    vector<int> doubled(data.size());
    transform(data.begin(), data.end(), doubled.begin(), [](int x){ return x * 2; });
    cout << "Doubled: ";
    for (int x : doubled) cout << x << " ";
    cout << endl;

    // remove_if + erase idiom
    data.erase(remove_if(data.begin(), data.end(), [](int x){ return x % 2 == 0; }),
               data.end());
    cout << "Setelah hapus genap: ";
    for (int x : data) cout << x << " ";
    cout << endl;

    return 0;
}