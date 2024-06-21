#include <iostream>
#include <fstream>

using namespace std;

int pilih[10], client;
string jam;

struct customer_service {
    string nama_pelanggan;
    string pelayan;
    string produk_roti;
    int jumlah_produk;
};

struct data_penjualan {
    string jenis_produk;
    int harga_satuan;
    int total_harga;
};

customer_service customer;
data_penjualan penjualan;

void daftar_pelayan() {
    int pilih_pelayan;
    cout << endl;
    cout << "||==================================================||" << endl;
    cout << "||          WELCOME TO TOKO ROTI KAMI               ||" << endl;
    cout << "||==================================================||" << endl;
    cout << "\tDAFTAR NAMA PELAYAN" << endl;
    cout << "\t1. Najwa " << endl;
    cout << "\t2. Amelia " << endl;
    cout << "\t3. Valisha " << endl;
    cout << "||==================================================||" << endl;

pelayan:
    cout << endl;
    cout << "Pilih Salah Satu Nama Pelayan: ";
    cin >> pilih_pelayan;
    cout << "--------------------------------------------------" << endl;
    
    switch (pilih_pelayan) {
        case 1:
            customer.pelayan = "Najwa";
            break;
        case 2:
            customer.pelayan = "Amelia";
            break;
        case 3:
            customer.pelayan = "Valisha";
            break;
    }

    while (pilih_pelayan < 1 || pilih_pelayan > 3) {
        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        goto pelayan;
    }
}

void pilih_produk() {
    int pilihan_produk;
   cout << "|===================MY CAKES=================|" << endl;
   cout << "|1. Roti Abon                        Rp.7.000|" << endl;
   cout << "|2. Roti Srikaya                     Rp.5.000|" << endl;
   cout << "|3. Roti Pisang                      Rp.5.000|" << endl;
   cout << "|4. Roti Sisir                       Rp.4.000|" << endl;
   cout << "|5. Bolu Kukus                       Rp.3.000|" << endl;
   cout << "|6. Donat                            Rp.4.000|" << endl;
   cout << "|7. Roti Pandan                      Rp.5.000|" << endl;
   cout << "|8. Roti Coklat                      Rp.5.000|" << endl;
   cout << "|9. Lapis Surabaya                   Rp.5.000|" << endl;
   cout << "|10. Roti Kering                     Rp.6.000|" << endl;
   cout << "|============================================|" << endl;
 
   
pilproduk:
    cout << endl;
    cout << "Pilih Jenis Produk Anda: ";
    cin >> pilihan_produk;
    cout << "--------------------------------------------------" << endl;
    
    switch (pilihan_produk) {
        case 1:
            penjualan.jenis_produk = "Roti Abon";
            penjualan.harga_satuan = 7.000;
            break;
        case 2:
            penjualan.jenis_produk = "Roti Srikaya";
            penjualan.harga_satuan = 5000;
            break;
        case 3:
            penjualan.jenis_produk = "Roti Pisang";
            penjualan.harga_satuan = 5000;
            break;
        case 4:
            penjualan.jenis_produk = "Roti Sisir";
            penjualan.harga_satuan = 4000;
            break;
        case 5:
            penjualan.jenis_produk = "Bolu Kukus";
            penjualan.harga_satuan = 3000;
            break;
        case 6:
            penjualan.jenis_produk = "Donat";
            penjualan.harga_satuan = 4000;
            break;
        case 7:
            penjualan.jenis_produk = "Roti Pandan";
            penjualan.harga_satuan = 5000;
            break;
        case 8:
            penjualan.jenis_produk = "Roti Coklat";
            penjualan.harga_satuan = 5000;
            break;
         case 9:
            penjualan.jenis_produk = "Lapis Surabaya";
            penjualan.harga_satuan = 5000;
            break;
        case 10:
            penjualan.jenis_produk = "Roti Kering";
            penjualan.harga_satuan = 6000;
            break;
        
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            goto pilproduk;
    }
}

void registrasi_pelanggan() {
    cin.ignore(); // Membersihkan buffer cin untuk menghindari masalah saat menggunakan getline
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "|           REGISTRASI PELANGGAN              |" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Masukkan Nama Pelanggan: ";
    getline(cin, customer.nama_pelanggan);
    cout << "Masukkan Jumlah Produk: ";
    cin >> customer.jumlah_produk;

    penjualan.total_harga = penjualan.harga_satuan * customer.jumlah_produk;
    cout << "------------------------------------------------" << endl;
}

void tampil() {
    int bayar, kembalian;
    ofstream file("nota_pembelian.txt");
    cout << endl;

    if (!file.is_open()) {
        cout << "Tidak dapat membuka file untuk mencetak nota." << endl;
        return;
    }

    cout << "||==================================================||" << endl;
    cout << "|                 NOTA PEMBELIAN                    |" << endl;
    cout << "||==================================================||" << endl;
    cout << "Nama Pelanggan      : " << customer.nama_pelanggan << endl;
    cout << "Produk Roti         : " << penjualan.jenis_produk << endl;
    cout << "Harga Satuan        : " << penjualan.harga_satuan << endl;
    cout << "Jumlah Produk       : " << customer.jumlah_produk << endl;
    cout << "Total Harga         : " << penjualan.total_harga << endl;
    cout << "Dilayani Oleh       : " << customer.pelayan << endl;
    cout << "||==================================================||" << endl;

    file << "||==================================================||" << endl;
    file << "|                 NOTA PEMBELIAN                    |" << endl;
    file << "||==================================================||" << endl;
    file << "Nama Pelanggan      : " << customer.nama_pelanggan << endl;
    file << "Produk Roti         : " << penjualan.jenis_produk << endl;
    file << "Harga Satuan        : " << penjualan.harga_satuan << endl;
    file << "Jumlah Produk       : " << customer.jumlah_produk << endl;
    file << "Total Harga         : " << penjualan.total_harga << endl;
    file << "Dilayani Oleh       : " << customer.pelayan << endl;
    file << "||==================================================||" << endl;

    cout << endl;
    cout << "Masukkan Nominal Pembayaran: ";
    cin >> bayar;
    
    kembalian = bayar - penjualan.total_harga;
    cout << "Kembalian               : " << kembalian << endl;
    cout << "||==================================================||" << endl;

    file << endl;
    file << "Masukkan Nominal Pembayaran: " << bayar << endl;
    file << "Kembalian               : " << kembalian << endl;
    file << "||==================================================||" << endl;

    file.close();
}

int main() {
    char konfirmasi;
    cout << "||========================================================||" << endl;
    cout << "||   PROGRAM PENJUALAN ROTI BERBASIS KOMPILER C++         ||" << endl;
    cout << "||========================================================||" << endl;
    cout << "    Masukkan Tanggal Pemesanan!!! [ENTER]\n";
    cout << "    Disini ==> ";
    cin >> client;
    system("cls");

    for (int i = 1; i <= client; i++) {
        menu:
        daftar_pelayan();
        pilih_produk();
        registrasi_pelanggan();
        tampil();

        cout << endl;
        cout << "APAKAH INGIN KEMBALI KE MENU UTAMA? (Y/N): ";
        cin >> konfirmasi;

        if (konfirmasi == 'Y' || konfirmasi == 'y') {
            system("cls");
            goto menu;
        }
    }
    return 0;
}