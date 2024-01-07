#include "Gocar.h"

int main()
{
    //====================================//

    listGocar LG;
    createListGocar(LG);
    adrGocar gP;
    infotypeGocar dataGocar;

    //====================================//

    listCus LC;
    createListCus(LC);
    adrCus cP;
    infotypeCus dataCus;

    //====================================//

    adrRelation rP;

    char YN;

    int input = selectMenu();
    while(input != 0){
        switch(input){
        case 1:
            cout<<"Masukkan merk mobil gocar: ";
            cin>>dataGocar.merkMobil;
            cout<<"Masukkan kapasitas mobil mobil gocar: ";
            cin>>dataGocar.Kapasitas;
            insertLastGocar(LG, dataGocar);
            cout<<endl;
            break;
        case 2:
            cout<<"Masukkan nama customer: ";
            cin>>dataCus.nama;
            cout<<"Masukkan NoHP customer: ";
            cin>>dataCus.NoHP;
            insertLastCus(LC, dataCus);
            cout<<endl;
            break;
        case 3:
            cout<<"Masukkan merk mobil gocar: ";
            cin>>dataGocar.merkMobil;
            cout<<"Masukkan nama customer: ";
            cin>>dataCus.nama;
            gP = searchGocar(LG, dataGocar);
            cP = searchCus(LC, dataCus);
            insertRelation(gP, cP);
            cout<<endl;
            break;
        case 4:
            cout<<endl;
            showAllGocar(LG);
            cout<<endl;
            break;
        case 5:
            cout<<endl;
            showAllCus(LC);
            cout<<endl;
            break;
        case 6:
            cout<<endl;
            showAllRelation(LG);
            cout<<endl;
            break;
        case 7:
            cout<<"Masukkan merk mobil gocar yang dicari: ";
            cin>>dataGocar.merkMobil;
            cout<<endl;
            showGocar(LG, dataGocar);
            cout<<endl;
            break;
        case 8:
            cout<<"Masukkan nama customer yang dicari: ";
            cin>>dataCus.nama;
            cout<<endl;
            showCus(LC, dataCus);
            cout<<endl;
            break;
        case 9:
            cout<<"Masukkan merk mobil gocar yang ingin dicari data customernya: ";
            cin>>dataGocar.merkMobil;
            cout<<endl;
            searchCusOnGocar(LG, dataGocar);
            cout<<endl;
            break;
        case 10:
            cout<<"Masukkan merk mobil gocar yang ingin dihitung banyak customernya: ";
            cin>>dataGocar.merkMobil;
            countCusOnGocar(LG, dataGocar);
            cout<<endl;
            break;
        case 11:
            cout<<"Masukkan merk mobil gocar yang ingin dihapus data customernya: ";
            cin>>dataGocar.merkMobil;
            cout<<endl;
            delAllCusOnGocar(LG, rP, dataGocar);
            cout<<endl;
            break;
        case 12:
            cout<<"Masukkan merk mobil gocar yang ingin dihapus seluruh datanya: ";
            cin>>dataGocar.merkMobil;
            delCusAndGocar(LG, LC, dataGocar);
            cout<<endl;
            break;
        }
//        cout<<"Kembali ke menu informasi?(Y/N)";
//        cin>>YN;
//        if(YN == 'Y'){
//            cout<<endl;
//            input = selectMenu();
//        }else{
//            input = 0;
//        }
        input = selectMenu();
    }
    cout<<"Kamu telah keluar dari program"<<endl;
    return 0;
}
