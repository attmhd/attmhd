#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

//struct laundry
struct laundry
{
    vector<string>nama, kasir, paket, status, tanggal;
    vector<int>qty;
    vector<float>ttl_byr, sisa_byr;

};

//variabel
laundry lndry;
int choice, i, n, pchoice, len, id, j,pil, schoice;
string nm, paket, kasir, sts, tanggal;
char status, struk;
float qty, ttl_byr, bayar, kembalian, tsbyar, tbbyar, sisa_byr;
enum choice{selesai = 0, create, get, deleted, update};

//modular

int choices(){
    system("clear");
    cout << "           Givin Laundry           " << endl;
    cout << "==============================================" << endl;
    cout << "1. Entri Data" << endl;
    cout << "2. Tampilkan Data" << endl;
    cout << "3. Delete Data" << endl;
    cout << "4. Update Data" << endl;
    cout << "0. Selesai" << endl;
    cout << "==============================================" << endl;
    cout << "Masukkan pilihan anda : "; cin >> choice;

    return choice;
}

void printOutData(){
    ofstream myFile;
    myFile.open(nm, ios::trunc);
    myFile << "Givin Laundry\n============================================\n";
    myFile << "Tanggal  : " << __DATE__ << endl;
    myFile << "Waktu    : " << __TIME__ << endl;
    myFile << "Nama     : " << nm << "\n";
    myFile << "Kasir    : " << kasir << endl;
    myFile << "Qty      : " << qty << " Kg" << endl;
    myFile << "============================================" << endl;
    myFile << "Paket    : " << paket << endl;
    myFile << "Total Bayar: Rp." << ttl_byr << endl;
    myFile << "Status Pembayaran: " << sts << endl;
    myFile << "============================================" << endl;
    myFile.close();
}

void entriData(){
    system("clear");
    cout << "Masukkan jumlah data yang akan diinput : "; cin >> n;

    for ( i = 0; i < n; i++){
        cout << "Masukkan Nama Pelanggan ke-" << i+1 << " : ";getline(cin >> ws, nm);
        cout << "Masukkan Nama Kasir : ";getline(cin >> ws, kasir);
        cout << "Masukkan Qty dalam KG : "; cin >> qty;
        cout << "Pilih paket laundry :" << endl;
        cout << "1. Paket Regular : Rp.5000/kg" << endl;
        cout << "2. Paket 2 Hari : Rp.7000/kg" << endl;
        cout << "3. Paket Express 24 Jam : Rp.10000/kg" << endl;
        cout << "Masukkan pilihan : "; cin >> pchoice;

        //variabel untuk menanmpung nilai
        ttl_byr = 0;
        paket = "";

        switch (pchoice)
        {
        case 1:
            ttl_byr = qty * 5000;
            paket = "Regular";
            break;
        case 2:
            ttl_byr = qty * 7000;
            paket = "2 Hari";
            break;
        case 3:
            ttl_byr = qty * 10000;
            paket = "Express";
            break;
        default:
            cout << "Pilihan out of context..." << endl;
            break;
                }

        sts = "";

        cout << "Bayar Langsung? [Y/N] : "; cin >> status;
        if((status == 'Y')||(status == 'y')){
            
            
            cout << "Total yang harus dibayar Rp." << ttl_byr << endl;;
            cout << "Masukkan jumlah uang yang dibayar : ";cin >> bayar;
            kembalian = bayar - ttl_byr;
            if(bayar < ttl_byr){
                cout << "Jumlah uang kurang dari total yang harus dibayar " << endl;
                cout << "Jumlah uang yang harus bayar sebanyak Rp." << kembalian * -1 << " lagi." << endl;
                sisa_byr = kembalian * -1;
                sts = "Belum lunas";
            }else{
                cout << "Kembalian uang sebanyak Rp." << kembalian << endl;
                sts = "Sudah dibayar";
                sisa_byr = 0;

            }

        }else if((status == 'N')||(status == 'n')){
            sts = "Belum bayar";
            sisa_byr = 0;
        }else{
            cout << "Pilihan out of context..." << endl;
        }

        cout << "Cetak struk? [Y/N] : "; cin >> struk;
        if((struk == 'Y')||(struk == 'y')){

            //print out to text file using fstream libraries
            printOutData();
            cout << "Entri data selesai" << endl;
        
        }else if((struk == 'N')||(struk == 'n')){
            cout << "Entri data selesai" << endl;

        }else{
            cout << "Pilihan out of context..." << endl;
        }



        tanggal = __DATE__;

        //append data to array
        lndry.nama.push_back(nm);
        lndry.kasir.push_back(kasir);
        lndry.paket.push_back(paket);
        lndry.qty.push_back(qty);
        lndry.ttl_byr.push_back(ttl_byr);
        lndry.status.push_back(sts);
        lndry.sisa_byr.push_back(sisa_byr);
        lndry.tanggal.push_back(tanggal);

    }

    system("sleep 10s");

}

void tampilData(){
    system("clear");
            
    cout << "ID     |       Tanggal     |       Nama        |       Kasir       |       Quantity        |       Paket       |       Total Bayar     |       Status Bayar        |       Sisa Bayar" << endl;
    cout << "=======================================================================================================================================================================================" << endl;
    
    tsbyar = 0;
    tbbyar = 0;

    for ( i = 0; i < len; i++)
    {
        cout << i+1 << "        " << lndry.tanggal[i] << "                " << lndry.nama[i] << "          " << lndry.kasir[i] << "                " << lndry.qty[i] << " Kg" << "              " << lndry.paket[i] << "                " << "Rp." << lndry.ttl_byr[i] << "              " << lndry.status[i] << "              " << "Rp." << lndry.sisa_byr[i] << endl;

        if((lndry.status[i] == "Belum bayar")){
            tbbyar += lndry.ttl_byr[i];
        }else{
            tsbyar += lndry.ttl_byr[i];
        }
    }

    cout << endl << endl;
    cout << "Jumlah pelanggan : " << len << endl;
    cout << "Jumlah yang belum bayar : Rp." << tbbyar << endl;
    cout << "Jumlah yang sudah bayar : Rp." << tsbyar << endl;
    system("sleep 10s");
}

void deleteData(){
    system("clear");
    cout << "Masukkan ID yang akan di hapus : "; cin >> id;
    j = id - 1;

    if((j < len)and(j >= 0)){

        //hapus data seluruh struct laundry berdasarkan index dari array
        lndry.nama.erase(lndry.nama.begin()+j);
        lndry.kasir.erase(lndry.kasir.begin()+j);
        lndry.qty.erase(lndry.qty.begin()+j);
        lndry.paket.erase(lndry.paket.begin()+j);
        lndry.status.erase(lndry.status.begin()+j);
        lndry.ttl_byr.erase(lndry.ttl_byr.begin()+j);

        cout << "ID ke-" << id << " berhasil dihapus..." << endl;
    }else{
        cout << "ID not found..." << endl;
    }
    system("sleep 10s");
}

void updateData(){
    system("clear");
    cout << "Masukkan id yang akan diupdate : ";cin >> id;
    j = id -1;

    if (j < len)
    {

        cout << "Update status bayar : " << endl;
        cout << "1. Sudah dibayar" << endl;
        cout << "2. Belum bayar" << endl;
        cout << "Masukkan pilihan anda : "; cin >> schoice;

        switch (schoice)
        {
        case 1:
            lndry.status[j] = "Sudah dibayar";
            lndry.sisa_byr[j] = 0;
            break;
        case 2:
            lndry.status[j] = "Belum bayar";
            lndry.sisa_byr[j] = 0;
            break;
        default:
            cout << "Pilihan out of context..." << endl;
            break;
        }
        
        cout << "Update data selesai..." << endl;
    }else{
        cout << "ID not found..." << endl;
    }

    system("sleep 10s");
}

int main(){

    do{
        choices();

        len = lndry.nama.size();

        //pengkondisian
        switch (choice)
        {
        case create:
            entriData();
            break;
        case get:
            tampilData();
            break;
        case deleted:
            deleteData();
            break;
        case update:
            updateData();            
            break;
        default:
            cout << "Program selesai..." << endl;
            break;
        }    
    }while (choice != selesai);
    

}