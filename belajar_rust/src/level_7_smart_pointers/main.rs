fn main() {
    println!("Hello, world!");

    let x = 5; //imuntable dari awal 
    let mut y = 10; // mutable pakai mut 

    // x = 6 bakal // error gak bisa
    y = 20; // bisa 
    let hasil = x * y;
    println!("x = {x},y = {y}, \nhasil dari x * y = {hasil}");
    let a: i32 = 10; // i32 adalah tipe data integer 32 bit
    let b: f64 = 9999999999.0; // f64 adalah tipe data floating point 64 bit
    let c: bool = true; // bool adalah tipe data boolean
    let d: char = 'A'; // char adalah tipe data karakter
    let e: u32 = 255; // u32 adalah tipe data unsigned integer 32 bit2

    let b: f64 = 3.14;
    
    let is_linux: bool = true; //boolean

    //string dalam rust ada 2 yaitu string literal dan string object
    let name : &str = "Akrom"; //string literal
    let name2 : String = String::from("Yusuf Akram"); //string object

    println!("a = {a}, b = {b}, c = {c}, d = {d}, e = {e}, 
    \nis_linux = {is_linux},
    \n name = {name}, name2 = {name2}");


}
