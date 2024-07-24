#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOWONGAN 100
#define MAX_PERSYARATAN 3

typedef struct {
    char perusahaan[50];
    char posisi[50];
    int gaji;
    char tanggalDibuka[11];  // Format: "YYYY-MM-DD"
    char tanggalDitutup[11]; // Format: "YYYY-MM-DD"
    char persyaratan[MAX_PERSYARATAN][100];
    int isOpen;
} LowonganKerja;

LowonganKerja lowongan[MAX_LOWONGAN];
int jumlahLowongan = 0;

// copare date
int compareDates(const char* date1, const char* date2) {
    int year1, month1, day1;
    int year2, month2, day2;

    sscanf(date1, "%d-%d-%d", &year1, &month1, &day1);
    sscanf(date2, "%d-%d-%d", &year2, &month2, &day2);

    if (year1 != year2) {
        return year1 - year2;
    }
    if (month1 != month2) {
        return month1 - month2;
    }
    return day1 - day1;
}

void sortLowonganByDate() {
    for (int i = 0; i < jumlahLowongan - 1; i++) {
        for (int j = 0; j < jumlahLowongan - 1 - i; j++) {
            if (compareDates(lowongan[j].tanggalDibuka, lowongan[j + 1].tanggalDibuka) > 0) {
                LowonganKerja temp = lowongan[j];
                lowongan[j] = lowongan[j + 1];
                lowongan[j + 1] = temp;
            }
        }
    }
}




// Fungsi untuk membersihkan input buffer
void clearBuffer() {
    while (getchar() != '\n');
}

// Fungsi untuk login sebagai admin
void loginAdmin() {
    char username[50];
    char password[50];

    printf("Masukkan username: ");
    scanf("%49s", username);
    clearBuffer();  // Membersihkan buffer untuk menghindari masalah input

    printf("Masukkan password: ");
    scanf("%49s", password);
    clearBuffer();  // Membersihkan buffer untuk menghindari masalah input

    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        printf("Login berhasil! Selamat datang di halaman Admin.\n");
        // Tambahkan logika halaman admin di sini
        adminPage();

    } else {
        printf("Username atau password salah. Kembali ke menu utama.\n");
    }
}

// Fungsi untuk login sebagai user akun premium
void loginPremium() {
    printf("Anda telah memilih login sebagai User Akun Premium.\n");
    // Tambahkan logika login user akun premium di sini
}

// Fungsi untuk login sebagai user akun silver
void loginSilver() {
    printf("Anda telah memilih login sebagai User Akun Silver.\n");
    // Tambahkan logika login user akun silver di sini
}

// adminPage
void adminPage() {
    int choice;

    do {
        printf("\n=== Admin Page ===\n");
        printf("1. Menambah Lowongan Kerja\n");
        printf("2. Menutup Lowongan Kerja\n");
        printf("3. Menampilkan Daftar Lowongan Kerja\n");
        printf("4. Menampilkan Daftar Akun LinkedIn\n");
        printf("5. Menerima Surat Lamaran Kerja\n");
        printf("6. Logout dan kembali ke menu utama\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                // menambahLowongan();
                printf("Menambah Lowongan Kerja dipilih.\n");
                menambahLowongan();
                break;
            case 2:
                // menutupLowongan();
                printf("Menutup Lowongan Kerja dipilih.\n");
                menutupLowongan();
                break;
            case 3:
                // menampilkanDaftarLowongan();
                printf("Menampilkan Daftar Lowongan Kerja dipilih.\n");
                menampilkanDaftarLowongan();
                break;
            case 4:
                // menampilkanDaftarAkun();
                printf("Menampilkan Daftar Akun LinkedIn dipilih.\n");
                break;
            case 5:
                // menerimaSuratLamaran();
                printf("Menerima Surat Lamaran Kerja dipilih.\n");
                break;
            case 6:
                printf("Logout. Kembali ke menu utama.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 6);
}


void menambahLowongan() {
    if (jumlahLowongan < MAX_LOWONGAN) {
        printf("Masukkan nama perusahaan: ");
        scanf("%49s", lowongan[jumlahLowongan].perusahaan);
        clearBuffer();

        printf("Masukkan posisi pekerjaan: ");
        scanf("%49s", lowongan[jumlahLowongan].posisi);
        clearBuffer();

        printf("Masukkan gaji: ");
        scanf("%d", &lowongan[jumlahLowongan].gaji);
        clearBuffer();

        printf("Masukkan tanggal dibuka pendaftaran (YYYY-MM-DD): ");
        scanf("%10s", lowongan[jumlahLowongan].tanggalDibuka);
        clearBuffer();

        printf("Masukkan tanggal ditutup pendaftaran (YYYY-MM-DD): ");
        scanf("%10s", lowongan[jumlahLowongan].tanggalDitutup);
        clearBuffer();

        for (int i = 0; i < MAX_PERSYARATAN; i++) {
            printf("Masukkan persyaratan %d: ", i + 1);
            scanf("%99s", lowongan[jumlahLowongan].persyaratan[i]);
            clearBuffer();
        }

        lowongan[jumlahLowongan].isOpen = 1;  // Lowongan dibuka
        jumlahLowongan++;
        printf("Lowongan berhasil ditambahkan.\n");
    } else {
        printf("Jumlah lowongan sudah maksimal.\n");
    }
}

void menutupLowongan() {
    if (jumlahLowongan == 0) {
        printf("Tidak ada lowongan kerja yang tersedia.\n");
        return;
    }

    printf("\n=== Daftar Lowongan Kerja yang Tersedia ===\n");
    for (int i = 0; i < jumlahLowongan; i++) {
        if (lowongan[i].isOpen) {
            printf("Lowongan #%d\n", i + 1);
            printf("Nama Perusahaan: %s\n", lowongan[i].perusahaan);
            printf("Posisi Pekerjaan: %s\n", lowongan[i].posisi);
            printf("Gaji: %d\n", lowongan[i].gaji);
            printf("Tanggal Dibuka: %s\n", lowongan[i].tanggalDibuka);
            printf("Tanggal Ditutup: %s\n", lowongan[i].tanggalDitutup);
            printf("Status: %s\n", lowongan[i].isOpen ? "Dibuka" : "Ditutup");
            printf("\n");
        }
    }

    char perusahaan[50];
    char posisi[50];
    char tanggalDibuka[11];
    char tanggalDitutup[11];
    int found = 0;

    printf("Masukkan nama perusahaan: ");
    scanf("%49s", perusahaan);
    clearBuffer();

    printf("Masukkan posisi pekerjaan: ");
    scanf("%49s", posisi);
    clearBuffer();

    printf("Masukkan tanggal dibuka pendaftaran (YYYY-MM-DD): ");
    scanf("%10s", tanggalDibuka);
    clearBuffer();

    printf("Masukkan tanggal ditutup pendaftaran (YYYY-MM-DD): ");
    scanf("%10s", tanggalDitutup);
    clearBuffer();

    for (int i = 0; i < jumlahLowongan; i++) {
        if (strcmp(lowongan[i].perusahaan, perusahaan) == 0 &&
            strcmp(lowongan[i].posisi, posisi) == 0 &&
            strcmp(lowongan[i].tanggalDibuka, tanggalDibuka) == 0 &&
            strcmp(lowongan[i].tanggalDitutup, tanggalDitutup) == 0 &&
            lowongan[i].isOpen == 1) {
            
            lowongan[i].isOpen = 0;  // Menutup lowongan
            printf("Lowongan kerja berhasil ditutup.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Lowongan kerja tidak ditemukan atau sudah ditutup.\n");
    }
}


void menampilkanDaftarLowongan() {
    if (jumlahLowongan == 0) {
        printf("Tidak ada lowongan kerja yang tersedia.\n");
    } else {
        // Urutkan lowongan berdasarkan tanggal dibuka
        sortLowonganByDate();

        printf("\n=== Daftar Lowongan Kerja ===\n");
        for (int i = 0; i < jumlahLowongan; i++) {
            printf("Lowongan #%d\n", i + 1);
            printf("Nama Perusahaan: %s\n", lowongan[i].perusahaan);
            printf("Posisi Pekerjaan: %s\n", lowongan[i].posisi);
            printf("Gaji: %d\n", lowongan[i].gaji);
            printf("Tanggal Dibuka: %s\n", lowongan[i].tanggalDibuka);
            printf("Tanggal Ditutup: %s\n", lowongan[i].tanggalDitutup);
            printf("Persyaratan:\n");
            for (int j = 0; j < MAX_PERSYARATAN; j++) {
                printf("  %d. %s\n", j + 1, lowongan[i].persyaratan[j]);
            }
            printf("Status: %s\n", lowongan[i].isOpen ? "Dibuka" : "Ditutup");
            printf("\n");
        }
    }
    
    printf("Tekan enter untuk kembali ke halaman admin...");
    clearBuffer(); // Menunggu input dari pengguna sebelum kembali ke halaman admin
}





// Fungsi untuk menampilkan menu utama dan memproses pilihan pengguna
void mainMenu() {
    int choice;

    do {
        printf("\n=== Menu Utama ===\n");
        printf("1. Login sebagai Admin\n");
        printf("2. Login sebagai User Akun Premium\n");
        printf("3. Login sebagai User Akun Silver\n");
        printf("0. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);
        clearBuffer();  // Membersihkan buffer untuk menghindari masalah input

        switch (choice) {
            case 1:
                loginAdmin();
                break;
            case 2:
                loginPremium();
                break;
            case 3:
                loginSilver();
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 0);
}

int main() {
    mainMenu();
    return 0;
}
