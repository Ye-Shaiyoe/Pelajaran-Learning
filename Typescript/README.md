# TypeScript Learning Project

Project untuk belajar TypeScript dengan contoh-contoh dasar.

## Setup

### 1. Install dependencies
```bash
cd Typescript
npm install
```

### 2. Menjalankan kode TypeScript

**Mode development (dengan ts-node):**
```bash
npm run dev
```

**Mode compile dan run:**
```bash
npm run build
npm start
```

**Watch mode (otomatis compile saat ada perubahan):**
```bash
npm run watch
```

## Struktur Project

```
Typescript/
├── src/
│   ├── index.ts           # File utama dengan contoh dasar TypeScript
│   └── (tambah file lainnya di sini)
├── dist/                  # Output folder (hasil compile)
├── package.json           # Dependencies dan scripts
├── tsconfig.json          # Konfigurasi TypeScript
└── .gitignore            # File yang diabaikan git
```

## Topik yang Akan Dipelajari

- ✅ Basic Types (string, number, boolean)
- ✅ Arrays dan Union Types
- ✅ Interfaces
- ✅ Functions dengan Type
- ✅ Classes
- [ ] Generics
- [ ] Enums
- [ ] Advanced Types
- [ ] Decorators
- [ ] Modules

## Catatan

- File `src/index.ts` berisi contoh-contoh dasar TypeScript
- Setiap topik dapat ditambahkan di file terpisah di folder `src/`
- Gunakan `npm run dev` untuk testing cepat saat belajar
