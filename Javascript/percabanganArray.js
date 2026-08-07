// percabanganArray.js
// Contoh cara membuat array dan menggunakan perulangan serta percabangan di JavaScript.

// 1. Membuat array
const buah = ["apel", "jeruk", "pisang", "mangga"];
console.log("Array buah:", buah);
console.log("Jumlah buah:", buah.length);

// 2. Mengakses elemen array dengan indeks
console.log("Buah pertama:", buah[0]);
console.log("Buah terakhir:", buah[buah.length - 1]);

// 3. Perulangan menggunakan for
console.log("\nPerulangan for biasa:");
for (let i = 0; i < buah.length; i++) {
  console.log("Index", i, "=>", buah[i]);
}

// 4. Perulangan menggunakan for...of
console.log("\nPerulangan for...of:");
for (const item of buah) {
  console.log(item);
}

// 5. Perulangan menggunakan forEach
console.log("\nPerulangan array.forEach:");
buah.forEach((item, index) => {
  console.log(index, ":", item);
});

// 6. Percabangan sederhana (if / else)
const nilai = 75;
if (nilai >= 80) {
  console.log("\nNilai A: Sangat baik");
} else if (nilai >= 70) {
  console.log("\nNilai B: Baik");
} else if (nilai >= 60) {
  console.log("Nilai C: Cukup");
} else {
  console.log("Nilai D atau E: Perlu perbaikan");
}

// 7. Menggabungkan array, perulangan, dan percabangan
const angka = [1, 2, 3, 4, 5, 6];
console.log("\nCek ganjil/genap pada array angka:");
for (let i = 0; i < angka.length; i++) {
  const nilaiAngka = angka[i];
  if (nilaiAngka % 2 === 0) {
    console.log(nilaiAngka, "adalah genap");
  } else {
    console.log(nilaiAngka, "adalah ganjil");
  }
}

// 8. Penjelasan singkat:
// - Array adalah kumpulan data yang disimpan dalam satu variabel.
// - Indeks array dimulai dari 0.
// - Perulangan (loop) digunakan untuk mengakses semua elemen array satu per satu.
// - Percabangan if/else digunakan untuk membuat keputusan berdasarkan kondisi.
// - Kita bisa menggunakan percabangan di dalam perulangan untuk memeriksa setiap elemen.

// Cara menjalankan file ini di terminal:
// node percabanganArray.js
