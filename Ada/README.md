# Proyek Ada: Belajar

Ini adalah proyek Ada sederhana untuk belajar pemrograman Ada di Arch Linux.

## Persyaratan Arch Linux

Jalankan perintah berikut untuk memasang toolchain Ada:

```bash
sudo pacman -Syu gcc-ada gprbuild
```

## Struktur proyek

- `src/` - kode sumber Ada
- `belajar.gpr` - file proyek GNAT/GPRBuild
- `build.sh` - skrip build
- `run.sh` - skrip jalankan
- `obj/` - direktori objek yang dihasilkan
- `bin/` - direktori eksekusi yang dihasilkan

## Cara membangun

```bash
cd Ada
./build.sh
```

## Cara menjalankan

```bash
cd Ada
./run.sh
```

## Jika ingin membersihkan build

```bash
cd Ada
rm -rf obj bin
```
