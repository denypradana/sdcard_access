#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Membuka komunikasi serial dan menunggu port terbuka:
  Serial.begin(9600);
  while (!Serial) {
    ; // menunggu serial port tersambung. Diperlukan hanya untuk Native USB Port
  }


  Serial.print("Inisialisasi Micro SD... ");

  if (!SD.begin(4)) {
    Serial.println("Inisialisasi gagal !");
    while (1);
  }
  Serial.println("Inisialisasi sukses");

  // membuka file. Catat bahwa hanya satu file yang bisa dibuka pada satu waktu,
  // jadi anda harus menutip file ini dulu sebelum membuka yang lain.
  myFile = SD.open("test.txt", FILE_WRITE);

  // jika file terbuka dengan baik, tulis data kedalamnya:
  if (myFile) {
    Serial.print("Menulis data ke test.txt...");
    myFile.println("testing 1, 2, 3.");
    // tutup file:
    myFile.close();
    Serial.println("Selesai.");
  } else {
    // jika file tidak terbuka, tampilkan error:
    Serial.println("Gagal membuka test.txt");
  }

  // buka kembali filenya untuk pembacaan:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // baca data dari file sampai tidak ada lagi yang data bisa dibaca:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // tutup file:
    myFile.close();
  } else {
    // jika file tidak terbuka, tampilkan error:
    Serial.println("Gagal membuka test.txt");
  }
}

void loop() {
  // tidak ada apa-apa disini
}