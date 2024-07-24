#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// file pointer yg diperlukan

FILE*database_loker;
FILE*copy_database_loker;
FILE *database_user;
FILE *suratLamaran;
FILE *filedaftarLowongan;
FILE*copy_database_user;

 // ADMIN
int mainMenu();
void loginAdmin();
void adminpage();
void menambahLowongan();
int menambahLowonganMain();
void menutupLowongan();
void menampilkanDaftarLowongan();
void menerimaLamaran();


// User Premium
void loginPremium();
void premiumMenu();
int idakunprem();
void signUpprem();
void signInprem();
void searchUserPremium();
void searchLoker();
void mendaftarlowonganPremium();
void tampilkanNotifikasi();


// User Silver
void loginSilver();
void silverMenu();





struct Loker {
    char perusahaan[50];
    char posisi[50];
    double gaji;
    char tanggalDibuka[11]; 
    char tanggalDitutup[11]; 
    char persyaratan[3][100];
}loker;

struct premium {
    char nama[50];
    char email[50];
    char kontak[20];
    char alamat[100];
    char username[50];
    char password[50];
    char pekerjaan[50];
    char deskripsi_diri[200];
    char pendidikan[50];
    char pengalaman[200];
    char id_akun[20];
} premium;

struct silver{
    char nama[50];
    char email[50];
    char kontak[20];
    char alamat[100];
    char username[50];
    char password[50];
    char deskripsi_diri[200];
    char pendidikan[50];
    char pengalaman[200];
    char id_akun[20];
}silver;

struct Lamaran {
    char nama[50];
    char posisi[50];
    char status[50];
} lamaran;

char username[100], password[100];


int main() {
    mainMenu();
    return 0;
}


int mainMenu() {
    int pilih;
    system ("cls");
    
        printf("\n=== Menu Utama ===\n");
        printf("1. Login sebagai Admin\n");
        printf("2. Login sebagai User Akun Premium\n");
        printf("3. Login sebagai User Akun Silver\n");
        printf("0. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilih); getchar();
        system("cls");
    

        switch (pilih) {
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
    
}


// ADMIN PAGE YGY
void loginAdmin(){
    char admin_nama[50], admin_pass[50];
    system("cls");
    printf("\tLOGIN ADMIN\n\n");
    for(int kesempatan=3;kesempatan>0;kesempatan--){
        printf("Masukkan username : ");
        scanf("%s", &admin_nama);
        printf("Masukkan password : ");
        scanf("%s", &admin_pass);
        if(strcmp(admin_nama, "admin")==0 && strcmp(admin_pass, "123")==0){
            system("cls");
            printf("\n    !!Selamat Datang!!\n");
            adminpage();
            } else{
            system("cls");
            printf("Mohon maaf nama atau password anda salah.");
            if(kesempatan>1){
                printf("\nKesempatan login anda tersisa %d kali lagi.\n\n", kesempatan-1);
            } else {
                printf("\nKesempatan login anda telah habis.\nSilahkan coba lagi lain kali.\n");
                system("pause");
                mainMenu();
            }
        }
    }
}

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
        scanf("%d", &pilih); getchar();

        switch (pilih) {
            case 1:
                // menambahLowongan();
                printf("Menambah Lowongan Kerja dipilih.\n");
                menambahLowonganMain();
                break;
            case 2:
                // menutupLowongan();
                printf("Menutup Lowongan Kerja dipilih.\n");
                menutupLowongan();
                break;
            case 3:
                menampilkanDaftarLowongan();

                printf("Menampilkan Daftar Lowongan Kerja dipilih.\n");
                // menampilkanDaftarLowongan();
                break;
            case 4:
                menampilkanDaftarAkun();
                printf("Menampilkan Daftar Akun LinkedIn dipilih.\n");
                break;
            case 5:
                menerimaLamaran();
                printf("Menerima Surat Lamaran Kerja dipilih.\n");
                break;
            case 6:
                printf("Logout. Kembali ke menu utama.\n");
                mainMenu();
                break;
            default:

                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

}

void menambahLowongan(int n){
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


int menambahLowonganMain()  {
    int n;

    database_loker = fopen("DaftarLoker.dat", "ab");
    if (database_loker == NULL) {
        printf("Error membuka file!\n");
        return 1;
    }
    else {
        
    printf("Silakan masukkan banyaknya loker tambahan: ");
    scanf("%d", &n);
    getchar(); 

    menambahLowongan(n);

    fclose(database_loker);
    }

    return 0;
}


void menutupLowongan() {
    char perusahaan[50];
    int found = 0;

    printf("Masukkan nama perusahaan dari lowongan yang ingin dihapus: ");
    gets(perusahaan);

    database_loker = fopen("DaftarLoker.dat", "rb");
    copy_database_loker = fopen("temp.dat", "wb");

    if (database_loker == NULL || copy_database_loker == NULL) {
        printf("Error membuka file!\n");
        return;
    }

    while (fread(&loker, sizeof(loker), 1, database_loker)) {
        if (strcmp(loker.perusahaan, perusahaan) != 0) {
            fwrite(&loker, sizeof(loker), 1, copy_database_loker);
        } else {
            found = 1;
        }
    }

    fclose(database_loker);
    fclose(copy_database_loker);

    remove("DaftarLoker.dat");
    rename("temp.dat", "DaftarLoker.dat");

    if (found) {
        printf("Lowongan dari perusahaan %s berhasil dihapus.\n", perusahaan);
    } else {
        printf("Lowongan dari perusahaan %s tidak ditemukan.\n", perusahaan);
    }
}

void sortingtgl(struct Loker arr[], int n) {
    int i, j;
    struct Loker temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(arr[j].tanggalDibuka, arr[j + 1].tanggalDibuka) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void menampilkanDaftarLowongan() {
    struct Loker daftarLoker[100];
    int jumlahLoker = 0;

    database_loker = fopen("DaftarLoker.dat", "rb");

    while (fread(&loker, sizeof(loker), 1, database_loker)) {
        daftarLoker[jumlahLoker++] = loker;
    }

    fclose(database_loker);

    sortingtgl(daftarLoker, jumlahLoker);

    printf("\n=== Daftar Lowongan Kerja ===\n");
    for (int i = 0; i < jumlahLoker; i++) {
        printf("Perusahaan: %s\n", daftarLoker[i].perusahaan);
        printf("Posisi: %s\n", daftarLoker[i].posisi);
        printf("Gaji: %.2f\n", daftarLoker[i].gaji);
        printf("Tanggal Dibuka: %s\n", daftarLoker[i].tanggalDibuka);
        printf("Tanggal Ditutup: %s\n", daftarLoker[i].tanggalDitutup);
        for (int j = 0; j < 3; j++) {
            printf("Persyaratan %d: %s\n", j + 1, daftarLoker[i].persyaratan[j]);
        }
        printf("\n");
    }
    system("pause");
}

void menerimaLamaran() {
    struct Lamaran lamaran;
    FILE *fileLamaran = fopen("Lamaran.dat", "rb");
    FILE *fileNotifikasi = fopen("Notifikasi.dat", "ab");
    if (fileLamaran == NULL || fileNotifikasi == NULL) {
        printf("Error membuka file!\n");
        return;
    }

    int found = 0;
    while (fread(&lamaran, sizeof(struct Lamaran), 1, fileLamaran)) {
        printf("\nLamaran dari %s untuk posisi %s \n", lamaran.nama, lamaran.posisi);
        printf("Terima lamaran ini? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            strcpy(lamaran.status, "Diterima");
            fwrite(&lamaran, sizeof(struct Lamaran), 1, fileNotifikasi);
            printf("Lamaran diterima dan notifikasi dikirim.\n");
            found = 1;
        } else if (choice == 'n' || choice == 'N') {
            strcpy(lamaran.status, "Ditolak");
            fwrite(&lamaran, sizeof(struct Lamaran), 1, fileNotifikasi);
            printf("Lamaran ditolak dan notifikasi dikirim.\n");
            found = 1;
            
        }
    }

    fclose(fileLamaran);
    fclose(fileNotifikasi);
    if (!found) {
        printf("Tidak ada lamaran untuk diproses.\n");
    }
}

void menampilkanDaftarAkun(){
    system("cls");
    int pilih;
    printf("1.User Premium\n");
    printf("2.User Silver\n");
    printf("Pilih Mau searching yg mana :");
    scanf("%d", &pilih);
    getchar();

    switch (pilih) {
            case 1:
                searchUserPremium();
                break;
            case 2:
                searchusersilver();
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }

}


// Premium page

void loginPremium() {
    int pilih;
    do {
        printf("\n=== Menu Akun Premium ===\n");
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("0. Kembali ke menu utama\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilih);
        getchar(); // Membersihkan newline dari buffer

        switch (pilih) {
            case 1:
                signUpprem();
                break;
            case 2:
                signInprem();
                break;
            case 0:
                printf("Kembali ke menu utama.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilih != 0);
}

int idakunprem(FILE *file) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    int count = file_size / sizeof(struct premium);
    fseek(file, 0, SEEK_SET);
    return count;
}

void signUpprem() {
    database_user = fopen("registrasi.dat", "ab+");
    system("cls");

    int idakun = idakunprem(database_user); // Menghitung jumlah akun untuk ID akun
    printf("===Silahkan Registrasi Akun Anda===\n");
    printf("Nama anda\t\t: ");
    fgets(premium.nama, sizeof(premium.nama), stdin);
    premium.nama[strcspn(premium.nama, "\n")] = '\0'; // Menghapus karakter newline

    printf("Masukkan Email\t\t: ");
    fgets(premium.email, sizeof(premium.email), stdin);
    premium.email[strcspn(premium.email, "\n")] = '\0';

    printf("Masukkan kontak\t\t: ");
    fgets(premium.kontak, sizeof(premium.kontak), stdin);
    premium.kontak[strcspn(premium.kontak, "\n")] = '\0';

    printf("Masukkan alamat\t\t: ");
    fgets(premium.alamat, sizeof(premium.alamat), stdin);
    premium.alamat[strcspn(premium.alamat, "\n")] = '\0';

    printf("Masukkan username\t\t: ");
    fgets(premium.username, sizeof(premium.username), stdin);
    premium.username[strcspn(premium.username, "\n")] = '\0';

    printf("Masukkan password\t\t: ");
    fgets(premium.password, sizeof(premium.password), stdin);
    premium.password[strcspn(premium.password, "\n")] = '\0';

    printf("Masukkan Pekerjaan\t\t: ");
    fgets(premium.pekerjaan, sizeof(premium.pekerjaan), stdin);
    premium.pekerjaan[strcspn(premium.pekerjaan, "\n")] = '\0';

    printf("Masukkan deskripsi diri\t\t: ");
    fgets(premium.deskripsi_diri, sizeof(premium.deskripsi_diri), stdin);
    premium.deskripsi_diri[strcspn(premium.deskripsi_diri, "\n")] = '\0';

    printf("Masukkan pendidikan\t\t: ");
    fgets(premium.pendidikan, sizeof(premium.pendidikan), stdin);
    premium.pendidikan[strcspn(premium.pendidikan, "\n")] = '\0';

    printf("Masukkan pengalaman\t\t: ");
    fgets(premium.pengalaman, sizeof(premium.pengalaman), stdin);
    premium.pengalaman[strcspn(premium.pengalaman, "\n")] = '\0';

    snprintf(premium.id_akun, sizeof(premium.id_akun), "1010%05d", idakun + 1);

    fwrite(&premium, sizeof(premium), 1, database_user);
    fclose(database_user);

    printf("\n==Akun Anda Berhasil dibuat, Silahkan Login==\n");
    printf("ID Akun Anda: %s\n", premium.id_akun);
    system("pause");
    main();
}


void signInprem() {
    int x = 0, y = 0;
    system("cls");
    while (x <= 3) {
        printf("=== Silahkan Login ===\n");
        printf("\nMasukkan username anda\t: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Password\t\t: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        database_user = fopen("registrasi.dat", "rb");
        int found = 0;
        while (fread(&premium, sizeof(premium), 1, database_user)) {
            if (strcmp(premium.username, username) == 0 && strcmp(premium.password, password) == 0) {
                found = 1;
                break;
            }
        }
        fclose(database_user);

        if (found) {
            printf("\n=== Login Berhasil ===\n");
            system("pause");
            premiumMenu();
            break;
        } else {
            system("cls");
            printf("== Username atau Password Anda Tidak sesuai, Coba lagi ==\n");
            y++;
            if (y == 3) {
                printf("== Coba Lagi Nanti ==");
                break;
            }
        }
    }
}





void premiumMenu() {
    int pilih;
    do {
        printf("\n=== Menu Premium ===\n");
        printf("1. Search Pengguna Silver\n");
        printf("2. Search Pengguna Premium\n");
        printf("3. Search Loker\n");
        printf("4. Mendaftar Lowongan \n");
        printf("5. Tampilkan Notifikasi\n");
        printf("6. Ganti Password\n");
        printf("7. Logout\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilih);
        getchar(); // Membersihkan newline dari buffer

        switch (pilih) {
            case 1:
                searchusersilver();
                break;
            case 2:
                searchUserPremium();
                break;
            case 3:
                searchLoker();
                break;
            case 4:
                mendaftarlowonganPremium();
                break;
            case 5:
                tampilkanNotifikasi();
                break;
            case 6:
                changePasswordPrem();
                break;
            case 7:
                printf("Logout. Kembali ke menu utama.\n");
                mainMenu();
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilih != 6);
}


void searchUserPremium() {
    char searchName[50];
    struct premium temp_user;
    int found = 0;

    printf("Masukkan nama pengguna yang ingin dicari: ");
    gets(searchName);

    database_user = fopen("registrasi.dat", "rb");
    if (database_user == NULL) {
        printf("Error membuka file!\n");
        return;
    }

    while (fread(&temp_user, sizeof(temp_user), 1, database_user)) {
        // Membandingkan nama pengguna yang diinputkan dengan nama pengguna dalam file
        if (strcmp(temp_user.nama, searchName) == 0) {
            found = 1;
            printf("\n=== Data Pengguna ===\n");
            printf("Nama: %s\n", temp_user.nama);
            printf("Email: %s\n", temp_user.email);
            printf("Kontak: %s\n", temp_user.kontak);
            printf("Alamat: %s\n", temp_user.alamat);
            printf("Username: %s\n", temp_user.username);
            printf("Pekerjaan: %s\n", temp_user.pekerjaan);
            printf("Deskripsi Diri: %s\n", temp_user.deskripsi_diri);
            printf("Pendidikan: %s\n", temp_user.pendidikan);
            printf("Pengalaman: %s\n", temp_user.pengalaman);
            printf("ID Akun: %s\n", temp_user.id_akun);
            printf("\n");
        }
    }

    if (!found) {
        printf("Pengguna dengan nama '%s' tidak ditemukan.\n", searchName);
    }

    fclose(database_user);
}

void searchLoker() {
    char cariloker[100];
    struct Loker temp_loker;
    int found = 0;

    printf("Masukkan nama perusahaan atau posisi pekerjaan yang ingin dicari: ");
    fgets(cariloker, sizeof(cariloker), stdin);
    cariloker[strcspn(cariloker, "\n")] = 0; // Menghapus newline character dari input

    database_loker = fopen("DaftarLoker.dat", "rb");
    if (database_loker == NULL) {
        printf("Error membuka file!\n");
        return;
    }

    while (fread(&temp_loker, sizeof(temp_loker), 1, database_loker)) {
        // Membandingkan query pencarian dengan nama perusahaan atau posisi pekerjaan dalam file
        if (strcmp(temp_loker.perusahaan, cariloker) == 0 || strcmp(temp_loker.posisi, cariloker) == 0) {
            found = 1;
            printf("\n=== Lowongan Kerja Ditemukan ===\n");
            printf("Perusahaan: %s\n", temp_loker.perusahaan);
            printf("Posisi: %s\n", temp_loker.posisi);
            printf("Gaji: %.2f\n", temp_loker.gaji);
            printf("Tanggal Dibuka: %s\n", temp_loker.tanggalDibuka);
            printf("Tanggal Ditutup: %s\n", temp_loker.tanggalDitutup);
            for (int j = 0; j < 3; j++) {
                printf("Persyaratan %d: %s\n", j + 1, temp_loker.persyaratan[j]);
            }
            printf("\n");
        }
    }

    if (!found) {
        printf("Lowongan kerja dengan kriteria '%s' tidak ditemukan.\n", cariloker);
    }

    fclose(database_loker);
}


void mendaftarlowonganPremium() {
    struct Lamaran lamaran;
    printf("\n=== Mendaftarkan Lowongan Kerja ===\n");
    printf("Masukkan Nama: ");
    fgets(lamaran.nama, sizeof(lamaran.nama), stdin);
    lamaran.nama[strcspn(lamaran.nama, "\n")] = 0; // Menghapus karakter newline

    printf("Masukkan Posisi yang dilamar: ");
    fgets(lamaran.posisi, sizeof(lamaran.posisi), stdin);
    lamaran.posisi[strcspn(lamaran.posisi, "\n")] = 0; // Menghapus karakter newline

    FILE *fileLamaran = fopen("Lamaran.dat", "ab");
    if (fileLamaran != NULL) {
        fwrite(&lamaran, sizeof(struct Lamaran), 1, fileLamaran);
        fclose(fileLamaran);
        printf("Lamaran berhasil didaftarkan!\n");
    } else {
        printf("Gagal membuka file Lamaran.dat\n");
    }
    system("pause");
}


void tampilkanNotifikasi() {
    struct Lamaran lamaran;
    FILE *fileNotifikasi = fopen("Notifikasi.dat", "rb");
    if (fileNotifikasi == NULL) {
        printf("Tidak ada notifikasi.\n");
        return;
    }

    printf("\n=== Notifikasi ===\n");
    while (fread(&lamaran, sizeof(struct Lamaran), 1, fileNotifikasi)) {
        printf("Nama: %s\n", lamaran.nama);
        printf("Posisi: %s\n", lamaran.posisi);
        printf("Status: %s\n", lamaran.status);
        if (strcmp(lamaran.status, "Diterima") == 0) {
            printf("Selamat! Lamaran Anda telah diterima.\n");
        } else if (strcmp(lamaran.status, "Ditolak") == 0) {
            printf("Mohon maaf, lamaran Anda ditolak.\n");
        }
        printf("------------------------\n");
    }

    fclose(fileNotifikasi);
    system("pause");
}

void changePasswordPrem() {
    char oldPassword[50], newPassword[50];
    int found = 0;

    printf("Masukkan password lama: ");
    fgets(oldPassword, sizeof(oldPassword), stdin);
    oldPassword[strcspn(oldPassword, "\n")] = 0;

    database_user = fopen("registrasi.dat", "rb+");
    if (database_user == NULL) {
        printf("Error membuka file!\n");
        return;
    }

    while (fread(&premium, sizeof(premium), 1, database_user)) {
        if (strcmp(premium.username, username) == 0 && strcmp(premium.password, oldPassword) == 0) {
            printf("Masukkan password baru: ");
            fgets(newPassword, sizeof(newPassword), stdin);
            newPassword[strcspn(newPassword, "\n")] = 0;

            strcpy(premium.password, newPassword);

            fseek(database_user, -sizeof(premium), SEEK_CUR);
            fwrite(&premium, sizeof(premium), 1, database_user);
            found = 1;
            break;
        }
    }

    fclose(database_user);

    if (found) {
        printf("Password berhasil diganti!\n");
    } else {
        printf("Password lama salah!\n");
    }
}

// Silver Page

void loginSilver() {
    int pilih;
    do {
        printf("\n=== Menu Akun Silver ===\n");
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("0. Kembali ke menu utama\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilih);
        getchar(); 
        switch (pilih) {
            case 1:
                signUpsil();
                break;
            case 2:
                signInsil();
                break;
            case 0:
                printf("Kembali ke menu utama.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilih != 0);
}

int idakunsil(FILE *file) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    int count = file_size / sizeof(struct silver);
    fseek(file, 0, SEEK_SET);
    return count;
}

void signUpsil(){
    database_user = fopen("registrasi1.dat", "ab+");
    system("cls");

    int idakun = idakunsil(database_user);
    printf("===Silahkan Registrasi Akun Anda===\n");
    printf("Nama anda\t\t: ");
    fgets(silver.nama, sizeof(silver.nama), stdin);
    silver.nama[strcspn(silver.nama, "\n")] = '\0';

    printf("Masukkan Email\t\t: ");
    fgets(silver.email, sizeof(silver.email), stdin);
    silver.email[strcspn(silver.email, "\n")] = '\0';

    printf("Masukkan kontak\t\t: ");
    fgets(silver.kontak, sizeof(silver.kontak), stdin);
    silver.kontak[strcspn(silver.kontak, "\n")] = '\0';

    printf("Masukkan alamat\t\t: ");
    fgets(silver.alamat, sizeof(silver.alamat), stdin);
    silver.alamat[strcspn(silver.alamat, "\n")] = '\0';

    printf("Masukkan username\t: ");
    fgets(silver.username, sizeof(silver.username), stdin);
    silver.username[strcspn(silver.username, "\n")] = '\0';

    printf("Masukkan password\t: ");
    fgets(silver.password, sizeof(silver.password), stdin);
    silver.password[strcspn(silver.password, "\n")] = '\0';

    printf("Masukkan deskripsi diri\t: ");
    fgets(silver.deskripsi_diri, sizeof(silver.deskripsi_diri), stdin);
    silver.deskripsi_diri[strcspn(silver.deskripsi_diri, "\n")] = '\0';

    printf("Masukkan pendidikan\t: ");
    fgets(silver.pendidikan, sizeof(silver.pendidikan), stdin);
    silver.pendidikan[strcspn(silver.pendidikan, "\n")] = '\0';

    printf("Masukkan pengalaman\t: ");
    fgets(silver.pengalaman, sizeof(silver.pengalaman), stdin);
    silver.pengalaman[strcspn(silver.pengalaman, "\n")] = '\0';

    snprintf(silver.id_akun, sizeof(silver.id_akun), "2020%05d", idakun + 1);

    fwrite(&silver, sizeof(silver), 1, database_user);
    fclose(database_user);

    printf("\n==Akun Anda Berhasil dibuat, Silahkan Login==\n");
    printf("ID Akun Anda: %s\n", silver.id_akun);
    system("pause");
    main();
}

void signInsil() {
    int x = 0, y = 0;
    system("cls");
    while (x <= 3) {
        printf("=== Silahkan Login ===\n");
        printf("\nMasukkan username anda\t: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';

        printf("Password\t\t: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';

        database_user = fopen("registrasi1.dat", "rb");
        int found = 0;
        while (fread(&silver, sizeof(silver), 1, database_user)) {
            if (strcmp(silver.username, username) == 0 && strcmp(silver.password, password) == 0) {
                found = 1;
                break;
            }
        }
        fclose(database_user);

        if (found) {
            printf("\n=== Login Berhasil ===\n");
            system("pause");
            silverMenu();
            break;
        } else {
            system("cls");
            printf("== Username atau Password Anda Tidak sesuai, Coba lagi ==\n");
            y++;
            if (y == 3) {
                printf("== Coba Lagi Nanti ==");
                break;
            }
        }
    }
}

void silverMenu(){
    int pilih;
    do {
        printf("\n=== Menu Silver ===\n");
        printf("1. Search Pengguna Silver\n");
        printf("2. Search Loker\n");
        printf("3. Upgrade Ke Premium\n");
        printf("4. Logout\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilih);
        getchar();

        switch (pilih) {
            case 1:
                searchusersilver();
                break;
            case 2:
                searchLoker();
                break;
            case 3:
               upgradeakunpremium();
                break;
            case 4:
                printf("Logout. Kembali ke menu utama.\n");
                mainMenu();
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilih != 4);
}

void searchusersilver() {
    char carinama[50];
    struct silver temp_user;
    int found = 0;

    printf("Masukkan nama pengguna yang ingin dicari: ");
    gets(carinama);

    database_user = fopen("registrasi1.dat", "rb");
    if (database_user == NULL) {
        printf("Error membuka file!\n");
        return;
    }

    while (fread(&temp_user, sizeof(temp_user), 1, database_user)) {
        // Membandingkan nama pengguna yang diinputkan dengan nama pengguna dalam file
        if (strcmp(temp_user.nama, carinama) == 0) {
            found = 1;
            printf("\n=== Data Pengguna ===\n");
            printf("Nama: %s\n", temp_user.nama);
            printf("Email: %s\n", temp_user.email);
            printf("Kontak: %s\n", temp_user.kontak);
            printf("Alamat: %s\n", temp_user.alamat);
            printf("Username: %s\n", temp_user.username);
            printf("Deskripsi Diri: %s\n", temp_user.deskripsi_diri);
            printf("Pendidikan: %s\n", temp_user.pendidikan);
            printf("Pengalaman: %s\n", temp_user.pengalaman);
            printf("ID Akun: %s\n", temp_user.id_akun);
            printf("\n");
        }
    }

    if (!found) {
        printf("Pengguna dengan nama '%s' tidak ditemukan.\n", carinama);
    }

    fclose(database_user);
    system("pause");
}

void upgradeakunpremium(){
    char nama[50];
    int found = 0;

    printf("Masukkan nama pengguna silver yang ingin di update: ");
    gets(nama);

    database_user=fopen("registrasi1.dat", "rb");
    copy_database_user=fopen("temp.dat", "wb");

    while (fread(&silver, sizeof(silver), 1, database_user)) {
        if (strcmp(silver.nama, nama) != 0) {
            fwrite(&silver, sizeof(silver), 1, copy_database_user);
        } else {
            found = 1;
        }
    }

    fclose(database_user);
    fclose(copy_database_user);

    remove("registrasi1.dat");
    rename("temp.dat", "registrasi1.dat");

    if (found) {
        printf(" Nama yang akan di upgrade %s telah ditemukan, upgrade sekarang.\n", nama);
        signUpprem();
    } else {
        printf("Nama yang akan di upgrade  %s tidak ditemukan.\n", nama);
    }
}






// THANKS FOR WATCHING LOVE U DASKOM
