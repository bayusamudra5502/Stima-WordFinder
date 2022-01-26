# Word Search Puzzle

### Tugas Kecil IF2211 Strategi Algoritma 2022 - 1

Program ini merupakan program pencari kata-kata pada suatu table huruf. Kata yang ditemukan dapat berada di 8 arah seperti arah mata angin. Implementasi dari program ini menggunakan algoritma Brute Force dan menggunakan bahasa C++.

## Struktur Folder

Repositori ini memiliki folder yaitu

- Folder `docs` berisi laporan dari tugas kecil ini.
- Folder `src` berisi semua kode sumber program utama untuk mencari kata pada puzzle.
  - Folder `lib` berisi pustaka yang berkaitan dalam proses pemecahan puzzle.
  - Folder `lib/io` berisi pustaka pemrosesan input dan output.
- Folder `util` berisi skrip python yang digunakan untuk membuat puzzle dari kata-kata yang diinginkan.
- Folder `test` yang berisi unit test menggunakan Google Test, input serta output dari program word finder.
  - Folder `data` berisi input yang digunakan untuk pengujian e2e program
  - Folder `output` berisi output dari e2e testing.
  - Foder `unit` berisi unit testing library program.

## Spesifikasi Dasar Program

Program ini dapat berjalan dengan baik pada lingkungan berikut:

- Ubuntu 20.04
- g++ versi 11.2.0
- make versi 4.3
- Google Test minimal versi 1.10.0 (untuk melakukan unit testing)

Untuk menginstall depedencies program ini jalankan perintah berikut

```shell
sudo apt install build-essential
```

Untuk melakukan testing, jalankan perintah berikut

```shell
sudo apt install libgtest-dev
```
