use std::io;
use std::collections::HashMap;

const Pi: f32 = 3.14;
const MAX_SCORE: u32 = 1024;

enum OperatingSystem {
    Windows,
    Linux,
    MacOS,
}

enum Device{
    CPU(u32),
    RAM(u32),
    Storage(String)
}

fn greet(name: &str) {
    println!("Hello, {}!", name);
}

fn add(a: i32, b: i32) -> i32 {
    a + b
}

fn main() { 
    greet("Akrom");
    let result = add(10, 20);
    println!("Result: {}", result);

    let mut umur = String::new();
    let mut name = String::new();

    println!("Masukan nama mu: ");
    io::stdin().read_line(&mut name).expect("Gagal membaca input");

    println!("Berapa Umur mu: ");
    io::stdin().read_line(&mut umur).expect("Gagal membaca input");

    let mut name = name.trim();
    let umur = umur.trim();
    println!("Halo, perkenalkan namaku {name} dan aku {umur} tahun");

    println!("Pi: {}", Pi);
    println!("Max Score: {}", MAX_SCORE);

    let mut score = 80;
    score = 90;
    println!("Score: {}", score);

    // integer
    let b: u8 = 255;
    let c: i32 = 255;
    let d: u32 = 255;
    let e: i64 = 255;
    let f: u64 = 255;

    //floating point 
    let g: f32 = 3.14;
    let h: f64 = 3.141592;

    //boolean
    let is_aktive: bool = true;

    //character
    let letter: char = 'A';

    println!("{}, {}, {}, {}, {}", b, c, d, e, f);
    println!("{}, {}", g, h);
    println!("Is Active: {}", is_aktive);
    println!("Letter: {}", letter);

    // aritmatika
    let x = 90; 
    let y = 120;
    let z = 25;
    
    println!("add: {}", x + y + z);
    println!("sub: {}", x - y - z);
    println!("mul: {}", x * y * z);
    println!("div: {}", x / y / z);
    println!("mod: {}", x % y % z);

    println!("Equal: {}", x == y && y == z);
    println!("Greater: {}", x > y || y > z);
    println!("Less: {}", x < y && y < z);

    let logika = true && false;
    println!("logikanya: {}", logika);

    //string 
    let nama_lengkap : &str = "Yusuf Akrom";
    let mut message = String::from("Hello, ");
    
    message.push_str(", Rust is awesome");
    message.push('!');

    println!("{}", nama_lengkap);
    println!("{}", message);
    
    println!("Full Name: {}", message.len());

    // control flow 
    let mut temperatur = String::new();

    println!("masukan Suhu: ");
    io::stdin().read_line(&mut temperatur).expect("Gagal membaca input");

    let temperatur = temperatur.trim().parse::<f64>().expect("Gagal mengubah input menjadi angka");

    if temperatur > 35.0 {
        println!("Cuaca panas");
    } else if temperatur >= 25.0 {
        println!("Cuaca hangat");    
    } else if temperatur >= 15.0 {
        println!("Cuaca normal");
    } else if temperatur < 15.0 {
        println!("Cuaca dingin");
    } else {
        println!("Cuaca tidak terindentifikasi");
    }
    println!("");
    // loop
    let mut counter = 0;

    loop {
        if counter == 5 {
            break;
        }

        println!("Counter: {}", counter);
        counter += 1;
    }

    // While
    let mut x = 0;

    while x < 3 {
        println!("While: {}", x);
        x += 1;
    }

    // For
    for i in 0..5 {
        println!("For: {}", i);
    }

    println!("");

    let leptop: (&str, u32, bool) = ("Thinkpad T480", 8, true);
    
    println!("Name Leptop: {}", leptop.0);
    println!("RAM Size: {} GB", leptop.1);
    println!("Active Status: {}", leptop.2);

    let (nameLeptop, ram, status) = leptop;
    println!("{nameLeptop} - {ram} GB - {status}");
    
    let angka_ku: [i32; 5] = [1, 2, 3, 4, 5];
    println!("angka pertama: {}", angka_ku[0]);
    println!("angka terakhir: {}", angka_ku[4]);
    println!("panjang array: {}", angka_ku.len());

    for angka_ku in angka_ku.iter() {
        println!("angka: {}", angka_ku);
    }

    // array dengan nilai default  
    let buffer = [0u8; 8];
    println!("{:?}", buffer);

    // slice
    let numbers = [10, 20, 30, 40, 50];

    let slice = &numbers[1..4];

    println!("{:?}", slice);
    println!("Length: {}", slice.len());

    // HashMap
    let mut system = HashMap::new();
    system.insert("OS", "Arch Linux");
    system.insert("Kernel", "Linux 7.3.4-arch1-2");
    system.insert("Init", "SystemD");

    println!("OS: {:?}", system.get("OS"));
    println!("Kernel: {:?}", system.get("Kernel"));
    println!("Init: {:?}", system.get("Init"));
    
    for (key, value) in &system {
        println!("{}: {}", key, value);
    }

    // enum operating system
    let os = OperatingSystem::Linux;
    match os {
        OperatingSystem::Windows => println!("Operating System: Windows"),
        OperatingSystem::Linux => println!("Operating System: Linux"),
        OperatingSystem::MacOS => println!("Operating System: MacOS"),
    }

    let hardware = Device::CPU(8);
    let hardware = Device::RAM(16);
    let hardware = Device::Storage("SSD".into());


    match hardware {
        Device::CPU(cores) => {
            println!("CPU Cores: {}", cores)
        }
        Device::RAM(size) => {
            println!("RAM Size: {} GB", size)
        }
        Device::Storage(storage_type) => {
            println!("Storage Type: {}", storage_type)
        }
    }

    // OWNERSHIP & MEMORY MANAGEMENT
    println!("");
    
    let first = String::from("NyxaraOS");
    let second = first;
    println!("{}", second);
}