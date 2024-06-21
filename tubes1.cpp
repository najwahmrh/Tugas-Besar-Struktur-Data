#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struktur untuk node linked list
struct Node {
    string nama_pelanggan;
    string pelayan;
    string produk_roti;
    int jumlah_produk;
    int total_harga;
    Node* next;
};

// Deklarasi pointer kepala linked list
Node* head = nullptr;

// Struktur data penjualan TIPE DATA
struct data_penjualan { // untuk mendeklarasikan variabel // struct itu untuk mengelompokkan data
    string jenis_produk; // string digunakan untuk menyimpan teks
    int harga_satuan; // integer digunakan untuk menyimpan bilangan bulat
};

// Deklarasi variabel penjualan
data_penjualan penjualan;

void tambah_pelanggan(string nama_pelanggan, string pelayan, string produk_roti, int jumlah_produk, int total_harga) {
    // Buat node baru
    Node* pelanggan_baru = new Node;
    pelanggan_baru->nama_pelanggan = nama_pelanggan;
    pelanggan_baru->pelayan = pelayan;
    pelanggan_baru->produk_roti = produk_roti;
    pelanggan_baru->jumlah_produk = jumlah_produk;
    pelanggan_baru->total_harga = total_harga;
    pelanggan_baru->next = nullptr;

    // Jika linked list kosong, maka node baru menjadi kepala
    if (head == nullptr) {
        head = pelanggan_baru;
    } else {
        // Jika tidak, cari node terakhir dan tambahkan node baru
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = pelanggan_baru;
    }
}

void tampilkan_nota(Node* pelanggan) {
    // Tampilkan nota pembelian untuk satu pelanggan
    cout << "||==================================================||" << endl;
    cout << "|                  NOTA PEMBELIAN                    |" << endl;
    cout << "||==================================================||" << endl;
    cout << "Nama Pelanggan      : " << pelanggan->nama_pelanggan << endl;
    cout << "Produk Roti         : " << pelanggan->produk_roti << endl;
    cout << "Harga Satuan        : " << penjualan.harga_satuan << endl;
    cout << "Jumlah Produk       : " << pelanggan->jumlah_produk << endl;
    cout << "Total Harga         : " << pelanggan->total_harga << endl;
    cout << "Dilayani Oleh       : " << pelanggan->pelayan << endl;
    cout << "||==================================================||" << endl;
}

void tampilkan_semua_nota() {
    // Tampilkan nota pembelian untuk semua pelanggan dalam linked list
    Node* temp = head;
    while (temp != nullptr) {
        tampilkan_nota(temp);
        temp = temp->next;
    }
}

void hapus_semua_pelanggan() {
    // Hapus semua node dalam linked list
    Node* temp = head;
    Node* next_node = nullptr;
    while (temp != nullptr) {
        next_node = temp->next;
        delete temp;
        temp = next_node;
    }
    // Set head menjadi nullptr
    head = nullptr;
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
    
    cout << endl;
    cout << "Pilih Jenis Produk Anda: ";
    cin >> pilihan_produk;
    cout << "--------------------------------------------------" << endl;

    switch (pilihan_produk) {
        case 1:
            penjualan.jenis_produk = "Roti Abon";
            penjualan.harga_satuan = 7000;
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
            pilih_produk();
    }
}

void registrasi_pelanggan(string pelayan) {
    cin.ignore(); // Membersihkan buffer cin untuk menghindari masalah saat menggunakan getline
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "|           REGISTRASI PELANGGAN               |" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Masukkan Nama Pelanggan: ";
    string nama_pelanggan;
    getline(cin, nama_pelanggan);
    cout << "Masukkan Jumlah Produk: ";
    int jumlah_produk;
    cin >> jumlah_produk;

    int total_harga = penjualan.harga_satuan * jumlah_produk;
    cout << "------------------------------------------------" << endl;

    // Tambahkan pelanggan ke linked list
    tambah_pelanggan(nama_pelanggan, pelayan, penjualan.jenis_produk, jumlah_produk, total_harga);
}

void tampil() {
    int bayar, kembalian;
    ofstream file("nota_pembelian.txt");
    cout << endl;

    if (!file.is_open()) {
        cout << "Tidak dapat membuka file untuk mencetak nota." << endl;
        return;
    }

    // Tampilkan semua nota pembelian
    tampilkan_semua_nota();

    cout << endl;
    cout << "Masukkan Nominal Pembayaran: ";
    cin >> bayar;

    // Hitung kembalian
    Node* temp = head;
    while (temp != nullptr){
        kembalian = bayar - temp->total_harga;
        cout << "Kembalian               : " << kembalian << endl;
        cout << "||==================================================||" << endl;

        // Simpan informasi pembayaran ke file
        file << endl;
        file << "Masukkan Nominal Pembayaran: " << bayar << endl;
        file << "Kembalian               : " << kembalian << endl;
        file << "||==================================================||" << endl;

        temp = temp->next;
    }

    // Tutup file
    file.close();
}

void bersihkan_layar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    char konfirmasi;
    cout << "||========================================================||" << endl;
    cout << "|| PROGRAM PENJUALAN ROTI BERBASIS KOMPILER C++           ||" << endl;
    cout << "||========================================================||" << endl;
    cout << "Masukkan Tanggal Pemesanan: ";
    string tanggal_pemesanan;
    cin.ignore();
    getline(cin, tanggal_pemesanan);

    int client;
    cout << "Masukkan Jumlah Pelanggan: ";
    cin >> client;
    bersihkan_layar();

    for (int i = 1; i <= client; i++) {
        string pelayan;
        while (true) {
            cout << endl;
            cout << "||==================================================||" << endl;
            cout << "||          WELCOME TO TOKO ROTI KAMI               ||" << endl;
            cout << "||==================================================||" << endl;
            cout << "\tDAFTAR NAMA PELAYAN" << endl;
            cout << "\t1. Najwa " << endl;
            cout << "\t2. Amelia " << endl;
            cout << "\t3. Valisha " << endl;
            cout << "||==================================================||" << endl;

            int pilih_pelayan;
            cout << "Pilih Salah Satu Nama Pelayan: ";
            cin >> pilih_pelayan;
            cout << "--------------------------------------------------" << endl;

            if (pilih_pelayan == 1) {
                pelayan = "Najwa";
                break;
            } else if (pilih_pelayan == 2) {
                pelayan = "Amelia";
                break;
            } else if (pilih_pelayan == 3) {
                pelayan = "Valisha";
                break;
            } else {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }

        pilih_produk();
        registrasi_pelanggan(pelayan);
        tampil();

        cout << endl;
        cout << "APAKAH INGIN KEMBALI KE MENU UTAMA? (Y/N): ";
        cin >> konfirmasi;

        if (konfirmasi == 'Y' || konfirmasi == 'y') {
            bersihkan_layar();
        } else {
            break;
        }
    }

    // Hapus semua node dalam linked list sebelum program berakhir
    hapus_semua_pelanggan();

    return 0;
}