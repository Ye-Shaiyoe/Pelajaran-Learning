// ============================================================
// 14 - Concurrency: thread, mutex, async, future, condition_variable
// Compile: g++ -std=c++17 -pthread -o threads 01_threads.cpp
// ============================================================
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <future>
#include <condition_variable>
#include <vector>
#include <chrono>
#include <queue>
using namespace std;
using namespace chrono;

// ── SHARED RESOURCE ───────────────────────────────────────────
mutex               mtx;
atomic<int>         atomic_counter{0};
int                 counter = 0;   // tanpa proteksi

// ── FUNGSI WORKER ─────────────────────────────────────────────
void worker_unsafe(int id, int iterasi) {
    for (int i = 0; i < iterasi; i++) {
        counter++;   // RACE CONDITION! tidak thread-safe
    }
}

void worker_mutex(int id, int iterasi) {
    for (int i = 0; i < iterasi; i++) {
        lock_guard<mutex> lock(mtx);   // RAII lock — otomatis unlock
        counter++;
    }
}

void worker_atomic(int iterasi) {
    for (int i = 0; i < iterasi; i++) {
        atomic_counter++;   // atomic operation — thread-safe tanpa mutex
    }
}

// ── PRODUCER-CONSUMER PATTERN ─────────────────────────────────
mutex               q_mtx;
condition_variable  cv;
queue<int>          tugas;
bool                selesai = false;

void producer(int n) {
    for (int i = 0; i < n; i++) {
        {
            lock_guard<mutex> lk(q_mtx);
            tugas.push(i);
            cout << "  [Producer] Produksi: " << i << endl;
        }
        cv.notify_one();   // beritahu consumer
        this_thread::sleep_for(milliseconds(10));
    }
    {
        lock_guard<mutex> lk(q_mtx);
        selesai = true;
    }
    cv.notify_all();
}

void consumer(int id) {
    while (true) {
        unique_lock<mutex> lk(q_mtx);
        cv.wait(lk, []{ return !tugas.empty() || selesai; });

        if (tugas.empty() && selesai) break;

        if (!tugas.empty()) {
            int val = tugas.front();
            tugas.pop();
            lk.unlock();    // unlock sebelum proses (biarkan producer/consumer lain)
            cout << "  [Consumer " << id << "] Proses: " << val << endl;
        }
    }
}

// ── FUNGSI ASYNC ──────────────────────────────────────────────
long long hitung_sum(int from, int to) {
    long long total = 0;
    for (int i = from; i <= to; i++) total += i;
    this_thread::sleep_for(milliseconds(50));   // simulasi kerja berat
    return total;
}

int main() {
    // ── BASIC THREAD ──────────────────────────────────────────
    cout << "=== BASIC THREAD ===" << endl;
    {
        auto start = high_resolution_clock::now();

        thread t1([]() {
            cout << "  Thread 1 berjalan di thread: " << this_thread::get_id() << endl;
            this_thread::sleep_for(milliseconds(100));
            cout << "  Thread 1 selesai" << endl;
        });

        thread t2([]() {
            cout << "  Thread 2 berjalan" << endl;
            this_thread::sleep_for(milliseconds(50));
            cout << "  Thread 2 selesai" << endl;
        });

        t1.join();   // tunggu t1 selesai
        t2.join();   // tunggu t2 selesai

        auto end = high_resolution_clock::now();
        auto dur = duration_cast<milliseconds>(end - start);
        cout << "  Total waktu: " << dur.count() << "ms (berjalan parallel)" << endl;
    }

    // ── RACE CONDITION vs MUTEX ────────────────────────────────
    cout << "\n=== RACE CONDITION vs MUTEX ===" << endl;
    {
        const int ITER = 10000;

        // Tanpa proteksi — hasilnya tidak konsisten!
        counter = 0;
        thread u1(worker_unsafe, 1, ITER);
        thread u2(worker_unsafe, 2, ITER);
        u1.join(); u2.join();
        cout << "  Tanpa mutex  (harusnya " << 2*ITER << "): " << counter << endl;

        // Dengan mutex — hasil konsisten
        counter = 0;
        thread m1(worker_mutex, 1, ITER);
        thread m2(worker_mutex, 2, ITER);
        m1.join(); m2.join();
        cout << "  Dengan mutex (harusnya " << 2*ITER << "): " << counter << endl;

        // Dengan atomic — lebih cepat dari mutex untuk operasi simple
        atomic_counter = 0;
        thread a1(worker_atomic, ITER);
        thread a2(worker_atomic, ITER);
        a1.join(); a2.join();
        cout << "  Dengan atomic(harusnya " << 2*ITER << "): " << atomic_counter.load() << endl;
    }

    // ── ASYNC / FUTURE ────────────────────────────────────────
    cout << "\n=== ASYNC / FUTURE ===" << endl;
    {
        // Jalankan fungsi di thread terpisah, ambil hasil nanti
        auto fut1 = async(launch::async, hitung_sum, 1, 1000000);
        auto fut2 = async(launch::async, hitung_sum, 1000001, 2000000);

        cout << "  Menunggu hasil..." << endl;

        long long r1 = fut1.get();   // blokir sampai selesai
        long long r2 = fut2.get();

        cout << "  Sum(1 - 1M)    = " << r1 << endl;
        cout << "  Sum(1M - 2M)   = " << r2 << endl;
        cout << "  Total          = " << (r1 + r2) << endl;
    }

    // ── PROMISE / FUTURE ──────────────────────────────────────
    cout << "\n=== PROMISE / FUTURE ===" << endl;
    {
        promise<string> prom;
        future<string>  fut = prom.get_future();

        thread t([&prom]() {
            this_thread::sleep_for(milliseconds(100));
            prom.set_value("Pesan dari thread lain!");
        });

        cout << "  Menunggu pesan..." << endl;
        string pesan = fut.get();
        cout << "  Diterima: " << pesan << endl;
        t.join();
    }

    // ── PRODUCER-CONSUMER ─────────────────────────────────────
    cout << "\n=== PRODUCER-CONSUMER ===" << endl;
    {
        selesai = false;

        thread prod(producer, 5);
        thread cons1(consumer, 1);
        thread cons2(consumer, 2);

        prod.join();
        cons1.join();
        cons2.join();
    }

    // ── SHARED_MUTEX (read-write lock) ────────────────────────
    cout << "\n=== SHARED_MUTEX (Read-Write Lock) ===" << endl;
    {
        shared_mutex rw_mtx;
        int shared_data = 0;

        auto reader = [&](int id) {
            shared_lock<shared_mutex> lock(rw_mtx);  // multiple readers OK
            cout << "  Reader " << id << " membaca: " << shared_data << endl;
        };

        auto writer = [&](int val) {
            unique_lock<shared_mutex> lock(rw_mtx);  // exclusive write
            shared_data = val;
            cout << "  Writer menulis: " << val << endl;
        };

        thread r1(reader, 1);
        thread r2(reader, 2);
        r1.join(); r2.join();

        thread w(writer, 42);
        w.join();

        thread r3(reader, 3);
        r3.join();
    }

    return 0;
}