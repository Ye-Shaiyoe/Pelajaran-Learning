
use std::{thread, time::Duration};
use sysinfo::System;

fn bar(value: f32, width: usize) -> String {
    let filled = ((value.clamp(0.0, 100.0) / 100.0)
        * width as f32)
        .round() as usize;

    format!(
        "[{}{}]",
        "#".repeat(filled),
        "-".repeat(width - filled)
    )
}

fn main() {
    let mut sys = System::new_all();

    sys.refresh_all();

    let hostname =
        System::host_name().unwrap_or_else(|| "Unknown".into());
    let kernel =
        System::kernel_version().unwrap_or_else(|| "Unknown".into());

    loop {
        sys.refresh_cpu_all();
        sys.refresh_memory();
        thread::sleep(Duration::from_secs(1));

        sys.refresh_cpu_all();
        thread::sleep(Duration::from_millis(500));
        sys.refresh_cpu_all();

        let cpu = sys.global_cpu_usage();
        let total_ram = sys.total_memory();
        let used_ram = sys.used_memory();

        let ram_percent = if total_ram > 0 {
            used_ram as f64 / total_ram as f64 * 100.0
        } else {
            0.0
        };

        let gib = 1024.0_f64.powi(3);

        print!("\x1B[2J\x1B[H");

        println!("System monitoring menggunakan Rust");
        println!(" Host   : {hostname}");
        println!(" Kernel : {kernel}");
        println!(" Uptime : {} seconds", System::uptime());

        println!(
            " CPU    : {:>5.1}% {}",
            cpu,
            bar(cpu, 20)
        );

        println!(
            " RAM    : {:>5.1}% {}",
            ram_percent,
            bar(ram_percent as f32, 20)
        );

        println!(
            " Memory : {:.2} / {:.2} GiB",
            used_ram as f64 / gib,
            total_ram as f64 / gib
        );

        println!(" Processes: {}", sys.processes().len());

        println!("Refresh 1.5 detik | ctrl + c buat exit");

        thread::sleep(Duration::from_millis(500));
    }
}
