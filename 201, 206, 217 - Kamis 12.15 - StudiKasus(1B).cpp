#include <iostream>
using namespace std;

class Resto {

private:
	int jml_goreng = 0, jml_bakar = 0;
	int harga_goreng = 17000, harga_bakar = 21000;
	int total;
	double total_bayar;
	
	void tampil_menu() {
		cout << "======== MENU RESTORAN ======== \n";
		cout << "1. Ayam Goreng\t - Rp 17.0000\n";
		cout << "2. Ayam Bakar\t - Rp 21.0000\n";
		cout << "=============================== \n";
	}
	
public:
	void pesanan() {
		char pesan_lagi;
		
		do {
			tampil_menu();
			int pilihan, jumlah = 0;
			cout << "Pilih menu  (1/2) : ";
			cin >> pilihan;
			cout << "Mau berapa porsi ? : ";
			cin >> jumlah;
			
			if (pilihan == 1) {
				jml_goreng += jumlah;
			} else if (pilihan == 2) {
				jml_bakar += jumlah;
			} else {
				cout << "Pilihan Anda tidak ada !";
			}
			
			cout << "\nApakah Anda ingin memesan lagi ? (y/n) : ";
			cin >> pesan_lagi;
			cin.ignore();
			
		} while (pesan_lagi == 'Y' || pesan_lagi == 'y');
		
		hitung_total();
	}
	
	void hitung_total() {
		total = (jml_goreng * harga_goreng) + (jml_bakar * harga_bakar);
		
		if (total > 45000) {
			total_bayar = total - (total * 0.10);
		} else {
			total_bayar = total;
		}
	}
	
	void cetak_struk() {
		cout << "\n===========================================\n";
		cout << "\t STRUK PEMBAYARAN\n";
		cout << "===========================================\n";
		cout << "Ayam Goreng ( " << jml_goreng << " x Rp " << harga_goreng << " ) = Rp " << jml_goreng * harga_goreng << endl;
		cout << "Ayam Bakar ( " << jml_bakar << " x Rp " << harga_bakar << " ) = Rp " << jml_bakar * harga_bakar << endl << endl;
		cout << "Total Harga : Rp " << total << endl;
		
		if (total > 45000) {
			cout << "Diskon 10% : Rp" << (0.10 * total) << endl << endl;
		}
		
		cout << "Total Bayar : Rp " << total_bayar << endl;
		cout << "===========================================\n";
	}
};

int main() {
	char ulang;
	
	do {
		Resto resto;
		resto.pesanan();
		resto.cetak_struk();
		
		cout << "\nApakah ingin melakukan pesanan baru lagi ? (Y/N) : ";
		cin >> ulang;
		cout << endl;
		cin.ignore();
		
		system("cls");
	} while (ulang == 'Y' || ulang == 'y');
	
	cout << "Terima kasih sudah berkunjung di Restoran kami !!\n";
	
	return 0;
}
