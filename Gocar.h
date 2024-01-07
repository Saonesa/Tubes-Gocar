#ifndef GOCAR_H_INCLUDED
#define GOCAR_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) P->info
#define next(P) P->next
#define nextRel(P) P->nextRel
#define nextCus(P) P->nextCus
#define first(L) L.first

//====================================//

struct Cus{
    string nama;
    int NoHP;
};

typedef Cus infotypeCus;

typedef struct elmCus *adrCus;
struct elmCus{
    infotypeCus info;
    adrCus next;

};

struct listCus{
    adrCus first;
};

//====================================//

typedef struct relation *adrRelation;
struct relation{
    adrCus nextCus;
    adrRelation next;
};

//====================================//

struct Gocar{
    string merkMobil;
    int Kapasitas;
};

typedef Gocar infotypeGocar;

typedef struct elmGocar *adrGocar;
struct elmGocar{
    infotypeGocar info;
    adrGocar next;
    adrRelation nextRel;
};

struct listGocar{
    adrGocar first;
};

//====================================//

void createListGocar(listGocar &L);
adrGocar newElmGocar(infotypeGocar x);
void insertLastGocar(listGocar &L, infotypeGocar x);
adrGocar searchGocar(listGocar L, infotypeGocar x);
void showGocar(listGocar L, infotypeGocar x);
void showAllGocar(listGocar L);
void deleteFirstGocar(listGocar &L, adrGocar P);
void deleteLastGocar(listGocar &L, adrGocar P);
void deleteAfterGocar(listGocar &L, adrGocar Prec, adrGocar P);

//====================================//

void createListCus(listCus &L);
adrCus newElmCus(infotypeCus x);
void insertLastCus(listCus &L, infotypeCus x);
adrCus searchCus(listCus L, infotypeCus x);
void showCus(listCus L, infotypeCus x);
void showAllCus(listCus L);
void deleteFirstCus(listCus &L, adrCus P);

//====================================//

adrRelation newRelation();
void insertRelation(adrGocar &G, adrCus C);
void showAllRelation(listGocar LG);

//====================================//

void searchCusOnGocar(listGocar LG, infotypeGocar x);
void countCusOnGocar(listGocar LG, infotypeGocar x);
void delAllCusOnGocar(listGocar LG, adrRelation &P, infotypeGocar x);
void delCusAndGocar(listGocar &LG, listCus &LC, infotypeGocar x);
int selectMenu();

#endif // GOCAR_H_INCLUDED
