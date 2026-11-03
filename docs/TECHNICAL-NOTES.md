# Catatan Teknis

## Status saat ini
- Source awal antarmuka menggunakan SDL2 dan OpenOrbis.
- Workflow GitHub Actions disiapkan untuk membuat PKG.
- Belum ada hasil build yang diverifikasi dan belum ada pengujian pada PS4.
- Menu saat ini hanya prototipe navigasi; fitur pengelolaan file, terjemahan, dan mod belum diimplementasikan.

## Build
Workflow menggunakan OpenOrbis Toolchain melalui GitHub Actions. Dokumentasi OpenOrbis menjelaskan penggunaan toolchain-action untuk menjalankan proses build di GitHub Actions. Hasil build yang berhasil akan diunggah sebagai artifact workflow.

## Keputusan desain
- Offline-first: aplikasi tidak memerlukan koneksi internet saat dijalankan.
- Operasi file bersifat aman: baca dahulu, konfirmasi sebelum menyalin/menimpa/menghapus, dan buat cadangan.
- Kompatibilitas eksplisit: setiap paket mod/terjemahan harus mencatat game ID, versi, format, dan status pengujian.
- Tidak mengubah file game asli secara otomatis.
- Tidak melewati DRM atau lisensi.

## Hal yang perlu diverifikasi
1. Build OpenOrbis berhasil pada runner GitHub.
2. Aplikasi dapat berjalan dan menampilkan menu pada PS4 HEN firmware 12.52.
3. Cara akses USB dan lokasi penyimpanan yang diperbolehkan untuk aplikasi homebrew.
4. Format dan kompatibilitas file terjemahan/mod untuk FC 27 CUSA57220 v1.07.
