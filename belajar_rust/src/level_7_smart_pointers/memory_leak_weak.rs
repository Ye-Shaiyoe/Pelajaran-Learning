//! # Level 7.4: `Weak<T>` & Mencegah Memory Leak (Reference Cycles)
//!
//! Konsep yang dipelajari:
//! 1. Bagaimana Reference Cycle terjadi pada `Rc<RefCell<T>>`
//! 2. `Weak<T>` (Non-owning reference, tidak menaikkan `strong_count`)
//! 3. Metode `.upgrade()` untuk mengakses data `Weak<T>` secara aman

use std::cell::RefCell;
use std::rc::{Rc, Weak};

#[derive(Debug)]
pub struct Node {
    pub nilai: i32,
    pub parent: RefCell<Weak<Node>>, // Menggunakan Weak agar tidak terjadi siklus memori
    pub children: RefCell<Vec<Rc<Node>>>,
}

pub fn jalankan_demo() {
    println!("=== 7.4 WEAK<T> & PENCEGAHAN MEMORY LEAK ===");

    // Membuat Root Node
    let root = Rc::new(Node {
        nilai: 1,
        parent: RefCell::new(Weak::new()),
        children: RefCell::new(vec![]),
    });

    println!("Root strong count: {}, weak count: {}", Rc::strong_count(&root), Rc::weak_count(&root));

    // Membuat Child Node di dalam scope
    {
        let child = Rc::new(Node {
            nilai: 2,
            parent: RefCell::new(Rc::downgrade(&root)), // child merujuk parent via Weak
            children: RefCell::new(vec![]),
        });

        root.children.borrow_mut().push(Rc::clone(&child));

        println!("Dalam scope child:");
        println!("   Root strong count: {}, weak count: {}", Rc::strong_count(&root), Rc::weak_count(&root));
        println!("   Child strong count: {}, weak count: {}", Rc::strong_count(&child), Rc::weak_count(&child));

        // Mengakses parent dari child via .upgrade()
        let parent_opt = child.parent.borrow().upgrade();
        if let Some(parent_node) = parent_opt {
            println!("   Child berhasil mengakses nilai parent: {}", parent_node.nilai);
        }
    }

    println!("Di luar scope child:");
    println!("   Root strong count: {}, weak count: {}", Rc::strong_count(&root), Rc::weak_count(&root));
    println!();
}
