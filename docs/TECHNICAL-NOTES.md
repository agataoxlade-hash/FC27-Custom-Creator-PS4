# Catatan Teknis

## Status dan batasan
Repo ini saat ini baru memiliki README dan dokumen perencanaan. Belum ada source code native PS4, executable, atau PKG.

Aplikasi PS4 HEN bukan sekadar halaman HTML yang diganti ekstensi menjadi PKG. Untuk menghasilkan aplikasi yang benar-benar berjalan di PS4 diperlukan toolchain homebrew PS4 yang cocok, pustaka/SDK yang sesuai, metadata aplikasi, proses packaging, lalu pengujian di konsol.

## Keputusan desain awal
- Offline-first: tidak ada fitur yang mengharuskan server atau internet ketika aplikasi berjalan.
- File lokal: sumber file berasal dari USB atau penyimpanan yang dapat diakses secara sah oleh aplikasi homebrew.
- Aman secara default: operasi baca dahulu; penyalinan/penimpaan memerlukan konfirmasi.
- Non-destruktif: backup sebelum modifikasi.
- Kompatibilitas eksplisit: setiap paket terjemahan/mod harus mencatat game ID, versi game, format, dan status pengujian.

## Informasi yang masih diperlukan sebelum modul game dibuat
1. Contoh paket terjemahan/mod yang memang dimiliki pengguna dan sumbernya.
2. Lokasi file yang dapat diakses pada instalasi FC 27 di konsol.
3. Metode pemasangan yang kompatibel dengan versi game dan lingkungan HEN.
4. Toolchain/build runner PS4 homebrew yang tersedia untuk membuat PKG.

Jangan memasang file yang tidak diketahui asal atau kompatibilitasnya. Jangan menimpa data game tanpa cadangan.