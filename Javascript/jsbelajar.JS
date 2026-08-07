// var: lama, bisa diubah, dan kurang aman
var nama = "Muhammad Yusuf Akram";
nama = "Muhammad Akram";
var nama ="Yusuf Akram"; // bisa deklarasi ulang
// let: bisa diubah, lebih aman tapi tidak bisa deklarasi ulang
let umur = 20;
umur = 18

// let umur = 21; // error karena tidak bisa deklarasi ulang

// const: tidak bisa diubah dan tidak bisa di deklarasi, Bisa dipakai untuk data tetap
const namaSekolah = "SMK_Alfalah";

console.log("Nama saya", nama," Dan umur saya" , umur, ", saya sekolah di", namaSekolah);
// namaSekolah = "SMA 12"; // error 
// const namaSekolah = "SMA"; // error karena tidak bisa deklarasi ulang

// Contoh:
var hidup = "Hidup itu indah";
hidup = "mungking";

// Math Programming
const pi = 3.14;
let a = 10;
let b = 5;
console.log("Penjumlahan:", a + b);
console.log("Pengurangan:", a - b);
console.log("Perkalian:", a * b);
console.log("Pembagian:", a / b);
console.log("Sisa bagi:", a % b);

let Luas = 10 * 7; 
console.log("Luas: ", Luas);  


// array js
const buah = [
    "apel", 
    "jeruk", 
    "pisang", "mangga"
];

buah[0] = "anggur"; // mengubah elemen pertama
buah [1] = "semangka"; // mengubah elemen kedua
console.log("Array buah:", buah);

if (buah[0] == "anggur"){
    let kendaraan = "Pesawat"
} // == -> perbandingan,  = -> deklarasi
else if (buah[0] == "anggur" ){
    let kendaraan = "Kapal"
}
else{
    let kendaraan = "Helikopter"
}

//Perulangan
for(let x =0; x <= 5; x += 1){
    console.log(x)
}

//Object 
// const = tipe,, deklarasi
//Contoh object js
//Key : Value

const Pegawai = {
    name         : "Akrom..", 
    nip          : "20080812..",
    jenisKelamin : "Laki-laki",
    Job          : "Operation System Engineer",
    Devisi       : "IT Firmware",
    usia         : 18,
    perkenalan   : function(){
        console.log(`Hai saya yanto`);
    }
}
console.log(Pegawai.name);
Pegawai.perkenalan()

// ; = limiter

//Function 
// isi dalam (bla2) = parameter si bla2
function perkenalan(usia) {
    console.log(`Hai, Saya ${Pegawai.name}
        Usia saya ${usia} tahun`
    );
}

perkenalan(17);
