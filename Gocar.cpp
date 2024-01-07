#include "Gocar.h"

//====================================//

void createListGocar(listGocar &L){
    first(L) = NULL;
}

adrGocar newElmGocar(infotypeGocar x){
    adrGocar P = new elmGocar;
    info(P) = x;
    next(P) = NULL;
    nextRel(P) = NULL;
    return P;
}

void insertLastGocar(listGocar &L, infotypeGocar x){
    adrGocar P = newElmGocar(x);
    adrGocar Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrGocar searchGocar(listGocar L, infotypeGocar x){
    adrGocar P = first(L);
    while(next(P) != NULL && info(P).merkMobil != x.merkMobil){
        P = next(P);
    }
    if(info(P).merkMobil == x.merkMobil){
        return P;
    }else{
        return NULL;
    }
}

void showGocar(listGocar L, infotypeGocar x){
    adrGocar P = searchGocar(L, x);
    if(P != NULL){
        cout<<"Gocar: "<<info(P).merkMobil;
        cout<<", Kapasitas: "<<info(P).Kapasitas<<endl;
    }else{
        cout<<"`Gocar tidak ditemukan`"<<endl;
    }
}

void showAllGocar(listGocar L){
    cout<<"=======LIST GOCAR======="<<endl;
    if(first(L) == NULL){
        cout<<"`Tidak ada gocar`"<<endl;
    }else{
        adrGocar P = first(L);
        int i = 1;

        while(P != NULL){
            cout<<i<<". "<<info(P).merkMobil;
            cout<<", Kapasitas: "<<info(P).Kapasitas<<endl;
            P = next(P);
            i++;
        }
    }
    cout<<"========================"<<endl;
}

void deleteFirstGocar(listGocar &L, adrGocar P){
    adrGocar Q = first(L);
    if(first(L) == NULL){
        cout<<"`Tidak ada Gocar`"<<endl;
    }else if(next(Q) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLastGocar(listGocar &L, adrGocar P){
    if(first(L) == NULL){
        cout<<"`Tidak ada Gocar`"<<endl;
    }else{
        adrGocar Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = NULL;
    }

}

void deleteAfterGocar(listGocar &L, adrGocar Prec, adrGocar P){
    if(first(L) == NULL){
        cout<<"`Tidak ada Gocar`"<<endl;
    }else{
        Prec = first(L);
        while(next(Prec) != P){
            Prec = next(Prec);
        }
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

//====================================//

void createListCus(listCus &L){
    first(L) = NULL;
}

adrCus newElmCus(infotypeCus x){
    adrCus P = new elmCus;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertLastCus(listCus &L, infotypeCus x){
    adrCus P = newElmCus(x);
    adrCus Q = first(L);
    if(first(L) == NULL){
        first(L) = P;
    }else{
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

adrCus searchCus(listCus L, infotypeCus x){
    adrCus P = first(L);
    while(next(P) != NULL && info(P).nama != x.nama){
        P = next(P);
    }
    if(info(P).nama == x.nama){
        return P;
    }else{
        return NULL;
    }
}

void showCus(listCus L, infotypeCus x){
    adrCus P = searchCus(L, x);
    if(P != NULL){
        cout<<"Nama: "<<info(P).nama<<endl;
        cout<<"No.HP: "<<info(P).NoHP<<endl;
    }else{
        cout<<"`Customer tidak ditemukan`"<<endl;
    }
}

void showAllCus(listCus L){
    cout<<"=======DATA CUSTOMER======="<<endl;
    if(first(L) == NULL){
        cout<<"`Tidak ada customer`"<<endl;
    }else{
        adrCus P = first(L);
        int i = 1;

        while(P != NULL){
            cout<<i<<". Nama: "<<info(P).nama<<endl;
            cout<<"   No.HP: "<<info(P).NoHP<<endl;
            P = next(P);
            i++;
        }

    }
    cout<<"==========================="<<endl;
}

void deleteFirstCus(listCus &L, adrCus P){
    adrCus Q = first(L);
    if(first(L) == NULL){
        cout<<"`Tidak ada customer`"<<endl;
    }else if(next(Q) == NULL){
        P = first(L);
        first(L) = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
}

//====================================//

adrRelation newRelation(){
    adrRelation P = new relation;
    nextCus(P) = NULL;
    next(P) = NULL;
    return P;
}

void insertRelation(adrGocar &G, adrCus C){
    adrRelation R = newRelation();
    if(nextRel(G) == NULL){
        nextRel(G) = R;
        nextCus(R) = C;
    }else{
        adrRelation Q = nextRel(G);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = R;
        nextCus(R) = C;
    }
}

void showAllRelation(listGocar LG){
    cout<<"=======GOCAR - CUSTOMER======="<<endl;
    if(first(LG) == NULL){
        cout<<"`Tidak ada gocar dan tidak ada customer`"<<endl;
    }else{
        adrGocar gP = first(LG);
        int i = 1;
        while(gP != NULL){
            cout<<i<<". "<<info(gP).merkMobil;
            cout<<", Kapasitas: "<<info(gP).Kapasitas<<endl;
            adrRelation rP = nextRel(gP);
            while(rP != NULL){
                cout<<"   -Nama: "<<info(nextCus(rP)).nama<<endl;
                cout<<"    No.HP: "<<info(nextCus(rP)).NoHP<<endl;
                rP = next(rP);
            }
            i++;
            gP = next(gP);
            cout<<endl;
        }
    }
    cout<<"=============================="<<endl;
}

//====================================//

void searchCusOnGocar(listGocar LG, infotypeGocar x){
    cout<<"=======CUSTOMER PADA GOCAR TERTENTU======="<<endl;
    adrGocar gP = searchGocar(LG, x);
    if(gP != NULL){
        int i = 1;
        adrRelation rP = nextRel(gP);
        cout<<"Data customer pada gocar "<<info(gP).merkMobil<<": "<<endl;
        while(rP != NULL){
            cout<<i<<". Nama: "<<info(nextCus(rP)).nama<<endl;
            cout<<"   No.HP: "<<info(nextCus(rP)).NoHP<<endl;
            i++;
            rP = next(rP);
        }
    }else{
        cout<<"`Gocar yang ingin dicari customernya tidak ditemukan`"<<endl;
    }
    cout<<"=========================================="<<endl;
}

void countCusOnGocar(listGocar LG, infotypeGocar x){
    cout<<"=======JUMLAH CUSTOMER======="<<endl;
    adrGocar gP = searchGocar(LG, x);
    if(gP != NULL){
        int i = 0;
        adrRelation rP = nextRel(gP);
        while(rP != NULL){
            i++;
            rP = next(rP);
        }
        cout<<"`Jumlah customer pada gocar "<<info(gP).merkMobil<<": "<<i<<"`"<<endl;
    }else{
        cout<<"`Gocar tidak ditemukan`"<<endl;
    }
    cout<<"============================="<<endl;
}

void delAllCusOnGocar(listGocar LG, adrRelation &P, infotypeGocar x){
    adrGocar gP = searchGocar(LG, x);;
    if(gP != NULL){
        adrRelation rP = nextRel(gP);
        if(rP == NULL){
            cout<<"`Gocar "<<info(gP).merkMobil<<" tidak memiliki customer`"<<endl;
        }else if(next(rP) == NULL){
            nextRel(gP) = NULL;
        }else{
            while(rP != NULL){
                P = rP;
                next(P) = NULL;
                rP = next(rP);
            }
            nextRel(gP) = NULL;
        }
        cout<<"`Semua customer pada gocar "<<x.merkMobil<<" telah dihapus`"<<endl;
    }else{
        cout<<"`Gocar tidak ditemukan`"<<endl;
    }
}

void delCusAndGocar(listGocar &LG, listCus &LC, infotypeGocar x){
    adrGocar gP = searchGocar(LG, x);
    if(gP != NULL){
        adrCus P, Prec;
        adrRelation rP = nextRel(gP);
        if(rP == NULL){
            cout<<"`Gocar "<<info(gP).merkMobil<<" tidak memiliki relasi`"<<endl;
        }else{
            while(rP != NULL){
                P = nextCus(rP);
                deleteFirstCus(LC, P);
                rP = next(rP);
            }
        }
        adrRelation R;
        delAllCusOnGocar(LG, R, x);
        adrGocar J = first(LG);
        while(next(J) != NULL){
            J = next(J);
        }
        adrGocar Grec;
        if(gP == first(LG)){
            deleteFirstGocar(LG, gP);
        }else if(gP == J){
            deleteLastGocar(LG, gP);
        }else{
            deleteAfterGocar(LG, Grec, gP);
        }
        cout<<"`Gocar "<<info(gP).merkMobil<<" telah dihapus`"<<endl;
    }else{
        cout<<"`Gocar tidak ditemukan`"<<endl;
    }
}

int selectMenu(){
    cout<<"================ INFORMATION ================"<<endl;
    cout<<"1. Membuat data gocar baru"<<endl;
    cout<<"2. Membuat data customer baru"<<endl;
    cout<<"3. Memambahkan relasi antara gocar dengan customer"<<endl;
    cout<<"4. Menampilkan semua data gocar"<<endl;
    cout<<"5. Menampilkan semua data customer"<<endl;
    cout<<"6. Menampilkan semua data gocar beserta customernya"<<endl;
    cout<<"7. Mencari data gocar"<<endl;
    cout<<"8. Mencari data customer"<<endl;
    cout<<"9. Mencari data customer pada gocar tertentu"<<endl;
    cout<<"10. Banyaknya data customer pada gocar tertentu"<<endl;
    cout<<"11. Mengahapus semua relasi customer pada gocar tertentu"<<endl;
    cout<<"12. Mengahapus data gocar beserta semua relasi dan customernya"<<endl;
    cout<<"0. Selesai"<< endl;
    cout<<"============================================="<<endl;
    cout<<"Pilih menu: ";
    int input = 0;
    cin>>input;
    return input;
}
