using namespace std;

class Proses {
	public :
		void getData(){
			ambil_data.open("api_data.txt");
			bool uang_saku = true;
			while(!ambil_data.eof()){
				if (uang_saku){
					ambil_data >> saku;
					uang_saku = false;
        }
        else{
					ambil_data >> bulan;
				}
			}
			ambil_data.close();
		}

		void toFile(){
      tulis_data.open("api_data.txt");
      tulis_data<<bulan<<endl;
			tulis_data.close();
			for (int i = 1; i <= bulan; i++){ 
      cout << "\nPengeluaran bulan ke-" << i;
      cout << "\nMasukkan pengeluaran (kuliah) : "; cin >> kuliah;
      cout << "Masukkan pengeluaran (jajan) : "; cin >> jajan;
      pengeluaran = kuliah + jajan;
      total = total + pengeluaran;
      sisa = saku - pengeluaran;
      cout << "Sisa uang saku bulan ke-" << i << " = " << sisa;
      tabungan=tabungan+sisa;
      cout << endl;
      cout << "=======================================" << endl;

      tulis_data.open("api_data.txt",ios::app);
			tulis_data << pengeluaran << endl;
			tulis_data.close();
        
      }  

			tulis_data.open("api_data.txt",ios::app);
			tulis_data << total << endl;
			tulis_data << tabungan;
			tulis_data.close();
		}

	private :
		ifstream ambil_data;
		ofstream tulis_data;
    int saku,bulan,kuliah,jajan,pengeluaran,sisa;
    int total=0;
    int tabungan=0;
};