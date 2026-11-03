# FC27 Custom Creator — PS4 HEN

Aplikasi homebrew pendamping FC 27 untuk PS4 HEN. Sasaran desain: **offline-first**, navigasi dengan kontroler PS4, dan pengelolaan file lokal/USB secara aman.

## Target yang dilaporkan
- Konsol: PS4 HEN, firmware 12.52.
- Game: FC 27, Title ID CUSA57220, versi 1.07 (perlu diverifikasi di konsol).
- Aplikasi dirancang dapat digunakan tanpa internet setelah terpasang.

## Status pengembangan
- Kerangka source code antarmuka SDL2 sudah ditambahkan.
- Workflow GitHub Actions untuk mencoba membangun PKG dengan OpenOrbis sudah ditambahkan.
- Build pertama masih perlu berjalan dan diperiksa. PKG belum boleh dianggap berhasil sebelum artefak muncul dan diuji pada PS4.
- Menu saat ini adalah prototipe; modul terjemahan, mod visual, dan pengelola USB belum aktif.

## Modul yang direncanakan
1. **Bahasa Indonesia** — mengelola paket terjemahan lokal yang disediakan pengguna setelah format dan kompatibilitasnya diketahui.
2. **Visual Mods** — mengelola paket mod lokal yang sudah diverifikasi.
3. **USB File Manager** — menampilkan dan menyalin file pengguna antara USB dan lokasi yang dapat diakses aplikasi homebrew.
4. **Antarmuka** — menu offline dengan kontroler PS4.

## Prinsip keamanan data
- Tidak mengubah file game asli tanpa cadangan.
- Tidak menghapus atau menimpa file secara diam-diam.
- Tidak menjanjikan kompatibilitas file/mod yang belum diuji.
- Tidak melewati DRM, lisensi, atau pemeriksaan keamanan game.

## Build
Setiap perubahan ke branch `main` memicu GitHub Actions. Jika build berhasil, file PKG tersedia pada bagian **Artifacts** dari hasil workflow. File tersebut tetap harus diuji di konsol sebelum dianggap siap digunakan.

Lihat [rencana pengembangan](docs/ROADMAP.md) dan [catatan teknis](docs/TECHNICAL-NOTES.md).
