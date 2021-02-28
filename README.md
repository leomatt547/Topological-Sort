# Topological Sort with Decrease and Conquer
IF2211 Strategi Algoritmik Tugas Kecil 2

## Algoritma Divide and Conquer
Algoritma Divide and Conquer adalah metode perancangan algoritma dengan mereduksi persoalan menjadi dua upa-persoalan (sub-problem) yang lebih kecil, tetapi selanjutnya hanya memproses satu sub-persoalan saja. Topological sorting secara umum adalah metode yang bertujuan untuk mengurutkan simpul-simpul pada suatu graf dari simpul yang paling penting atau diutamakan sampai simpul yang paling dapat diabaikan atau prioritas terakhir. 

### Penjelasan Algoritma Topological Sort
1. Buatlah suatu Matriks Ordering kosong yang diinisiasi dengan Nil sesuai ukuran matriks yaitu jumlah node x jumlah node (persegi)
2. Buatlah suatu array of boolean yang memiliki jumlah elemen sesuai dengan jumlah node pada graf dan diinisiasi dengan nilai False.
3. Inisiasi nilai i dan j sebesar nilai maksimal pada ukuran matriks yang ada. Hal ini berguna agar mata kuliah yang memiliki banyak prasyarat akan ditempatkan di akhir.
4. Untuk basis yang digunakan, carilah node dimana node belum dikunjungi sama sekali dan bernilai false.
5. Apabila ditemukan node yang belum pernah dikunjungi, panggilan fungsi dfs supaya bisa masuk ke dalam bagian rekursif.
6. Pada saat masuk, node yang dikunjungi langsung di-set True dan terus menjalankan operasi.
7. Pada rekursif kedua, sama dengan langkah 4, hanya yang berbeda, node asal yang ditentukan adalah node yang menembakkan panah ke node yang dituju selanjutnya.
8. Ulangi langkah ini terus menerus hingga seluruh node pada 1 operasi dikunjungi.
9. Mulailah operasi pengisian Matriks Ordering hingga yang terakhir dimasukkan adalah node yang paling awal menjadi prasyaratnya, kurangi angka i sebanyak 1 agar bisa diisi menaik.
10. Setelah selesai, kembalikan nilai j menjadi berkurang satu yang artinya berpindah kolom. Inisiasi nilai i kembali sebesar ukuran jumlah node pada grafik agar bisa melakukan pengisian kedua, dst.
11. Langkah 10 berguna untuk memampatkan mata kuliah yang tidak ada kaitannya dapat diambil di semester awal dan mengefisienkan masa kuliah agar tidak lebih dari 8 semester.

## Requirement program
- Jalankan program pada CMD atau Windows Powershell dengan file ```13519215-main.exe```
- Jalankan program pada Terminal Ubuntu dengan file ```13519215-main.out```
- Library yang digunakan: ```<vector>``` dan ```<map>```

## Cara Menggunakan Program
1. Download zip atau clone git ini
2. Change directory to test
3. Silahkan Ubah ```prereq.txt``` sesuka hati Anda (Jangan lupa diseparasi dengan tanda koma dan tanda titik)
4. Selanjutnya, masuklah ke dalam folder bin
Untuk Pengguna Ubuntu, silahkan masukkan command
```
./13519215-main.out
```
Sedangkan untuk Pengguna Windows, silahkan masukkan command
```
./13519215-main.exe
```
5. Anda akan melihat hasilnya :)


## Author / identitas pembuat
Leonard Matheus - 13519215
