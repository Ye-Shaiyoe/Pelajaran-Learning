// Without std btw
 
use std::io::{self, Write};

fn main() {
    print!("Nama mu: ");
    io::stdout().flush().unwrap();

    let mut nama = String::new();
    io::stdin().read_line(&mut nama).unwrap();

    println!("Hallo Akrom {}", nama.trim());
}