#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define var yg diperlukan
FILE* database_loker;

// Struct untuk menyimpan informasi lowongan kerja
struct Loker {
    char perusahaan[50];
    char posisi[50];
    double gaji;
    char tanggalDibuka[11];
    char tanggalDitutup[11];
    char persyaratan[3][100];
} loker;

// Deklarasi fungsi
int mainMenu();
void loginAdmin();
void adminpage();
void menambahLowongan(int n);
int menambahLowonganMain();

int main() {
    mainMenu();
    return 0;
}

// Fungsi untuk menampilkan menu utama
int mainMenu() {
    int pilih;

    printf("\n=== Menu Utama ===\n");
    printf("1. Login sebagai Admin\n");
    printf("2. Login sebagai User Akun Premium\n");
    printf("3. Login sebagai User Akun Silver\n");
    printf("0. Keluar\n");
    printf("Pilih opsi: ");
    scanf("%d", &pilih);
    getchar();
    system("cls");

    switch (pilih) {
        case 1:
            loginAdmin();
            break;
        case 2:
            // loginPremium();
            break;
        case 3:
            // loginSilver();
            break;
        case 0:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
    }
}

// Fungsi untuk login sebagai admin
void loginAdmin() {
    char admin_nama[50], admin_pass[50];
    system("cls");
    printf("\tLOGIN ADMIN\n\n");
    for (int kesempatan = 3; kesempatan > 0; kesempatan--) {
        printf("Masukkan nama : ");
        scanf("%s", &admin_nama);
        printf("Masukkan password : ");
        scanf("%s", &admin_pass);
        if (strcmp(admin_nama, "admin") == 0 && strcmp(admin_pass, "123") == 0) {
            printf("\n    !!Selamat Datang!!\n");
            adminpage();
        } else {
            system("cls");
            printf("Mohon maaf nama atau password anda salah.");
            if (kesempatan > 1) {
                printf("\nKesempatan login anda tersisa %d kali lagi.\n\n", kesempatan - 1);
            } else {
                printf("\nKesempatan login anda telah habis.\nSilahkan coba lagi lain kali.\n");
                system("pause");
                mainMenu();
            }
        }
    }
}

// Fungsi untuk menu admin
void adminpage() {
    int pilih;

    printf("\n=== Admin Page ===\n");
    printf("1. Menambah Lowongan Kerja\n");
    printf("2. Menutup Lowongan Kerja\n");
    printf("3. Menampilkan Daftar Lowongan Kerja\n");
    printf("4. Menampilkan Daftar Akun LinkedIn\n");
    printf("5. Menerima Surat Lamaran Kerja\n");
    printf("6. Logout dan kembali ke menu utama\n");
    printf("Pilih opsi: ");
    scanf("%d", &pilih);
    getchar();

    switch (pilih) {
        case 1:
            printf("Menambah Lowongan Kerja dipilih.\n");
            menambahLowonganMain();
            break;
        case 2:
            printf("Menutup Lowongan Kerja dipilih.\n");
            // menutupLowongan();
            break;
        case 3:
            printf("Menampilkan Daftar Lowongan Kerja dipilih.\n");
            // menampilkanDaftarLowongan();
            break;
        case 4:
            printf("Menampilkan Daftar Akun LinkedIn dipilih.\n");
            break;
        case 5:
            printf("Menerima Surat Lamaran Kerja dipilih.\n");
            break;
        case 6:
            printf("Logout. Kembali ke menu utama.\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan coba lagi.\n");
    }
}

// Fungsi untuk menambahkan lowongan kerja
void menambahLowongan(int n) {
    int i, j;

    for (i = 1; i <= n; i++) {
        printf("Nama Perusahaan: ");
        gets(loker.perusahaan);

        printf("Posisi Pekerjaan: ");
        gets(loker.posisi);

        printf("Gaji: ");
        scanf("%lf", &loker.gaji);
        getchar();

        printf("Tanggal Dibuka (YYYY-MM-DD): ");
        gets(loker.tanggalDibuka);

        printf("Tanggal Ditutup (YYYY-MM-DD): ");
        gets(loker.tanggalDitutup);

        for (j = 0; j < 3; j++) {
            printf("Persyaratan %d: ", j + 1);
            gets(loker.persyaratan[j]);
        }

        fwrite(&loker, sizeof(loker), 1, database_loker);
    }
}

// Fungsi utama untuk menambahkan lowongan kerja
int menambahLowonganMain() {
    int n;

    database_loker = fopen("DaftarLoker.dat", "ab");
    if (database_loker == NULL) {
        printf("Error membuka file!\n");
        return 1;
    } else {

        printf("Silakan masukkan banyaknya loker tambahan: ");
        scanf("%d", &n);
        getchar();

        menambahLowongan(n);

        fclose(database_loker);
    }

    return 0;
}
