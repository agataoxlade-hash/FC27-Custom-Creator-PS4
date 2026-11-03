# FC27 Custom Creator — PS4 HEN

Proyek aplikasi homebrew pendamping FC 27 untuk PS4 HEN. Target awal: **offline-first**, kontroler PS4, dan pengelolaan file lokal/USB.

## Target kompatibilitas
- Konsol target: PS4 HEN, firmware yang dilaporkan pengguna: 12.52.
- Game target: FC 27, Title ID CUSA57220, versi 1.07 (perlu diverifikasi di konsol).
- Koneksi internet: tidak diperlukan saat aplikasi digunakan.

## Modul yang direncanakan
1. **Bahasa Indonesia** — memeriksa dan mengelola paket terjemahan lokal yang disediakan pengguna. Aplikasi tidak menyertakan atau mengekstrak aset game berhak cipta.
2. **Modifikasi visual** — mengelola arsip mod lokal yang kompatibilitasnya sudah diverifikasi; tidak menjanjikan semua mod dapat dipasang.
3. **Pengelola file** — menampilkan dan menyalin file antara USB dan lokasi yang memang dapat diakses homebrew; membuat cadangan sebelum perubahan.
4. **Antarmuka** — menu sederhana yang dapat dinavigasi dengan kontroler PS4.

## Status saat ini
Ini adalah **kerangka proyek dan spesifikasi**, bukan PKG siap instal. Belum ada binary PS4 yang dibangun atau diuji. Pembuatan PKG memerlukan toolchain homebrew PS4 yang sesuai, dependensi, serta proses build dan pengujian pada konsol.

Lihat [rencana pengembangan](docs/ROADMAP.md) dan [batasan teknis](docs/TECHNICAL-NOTES.md).

## Prinsip keselamatan data
- Tidak mengubah file game asli tanpa cadangan.
- Tidak menghapus atau menimpa file secara diam-diam.
- Tidak menjanjikan dukungan untuk file, patch, atau mod yang belum diuji.
- Tidak melewati DRM, lisensi, atau pemeriksaan keamanan game.

## Kontribusi
Mulai dengan membaca dokumen di folder `docs/`.