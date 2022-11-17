// TWORING
// Simulator Turingovog stroja
// Autor: Ivan Vucica 0036431411 2R2 2008.
// Predmet: Uvod u teoriju racunarske znanosti
//
// Zadatak:
// 2048. Napisati program za simulaciju rada Turingovog stroja koji
// provjerava da li je zapisani dekadski broj palindrom, odnosno da li
// je simetrican (primjer simetricnih brojeva: 034565430, 789987).
//                                                      (R(Sh))
//
// Ovaj simulator je opcenit ako mu se promijeni sadrzaj:
// * state_t - popis stanja
// * state_representations - navedena stanja, ali kao stringovi (zbog ispisa)
// * funkcija getRepresentation - vraca ascii reprezentaciju za dan ulazni znak
// * funkcija loadTransitions - definira tablicu prijelaza
// * funkcija loadTrack - definira sadrzaj trake
//
// Ako se fiksiraju sama stanja, ostali parametri simulatora daju se izuzetno lako
// ucitavati iz datoteke (no to ovdje nije uradjeno jer bi pisanje datoteke bilo
// dugotrajno, a nepotrebno).
// Ako se ne fiksiraju sama stanja, simulator je potrebno malo vise preraditi
// (npr. prebaciti da klasa cellid_t sprema std::string -- tj ime stanja --
// umjesto state_t, napraviti da se ne koristi state_representations
// nego izravno ispisuje ime stanja, i slicno).
//
// Kako izrada posve generickog simulatora Turingovog stroja nije bila
// eksplicitno zadana u zadatku, to nisam ucinio.

#include <stdio.h>
#include <vector>
#include <string>
#include <map>

#define BRISIEKRAN system("cls");//"clear");
#define PAUZA { \
    char tmp[10]; \
    printf("[ENTER]\n"); \
    gets(tmp); \
    }

enum state_t {
    qS=0, // seek start
    qX, // execute
    q0, q1, q2, q3, q4, q5, q6, q7, q8, q9,
    q0c,q1c,q2c,q3c,q4c,q5c,q6c,q7c,q8c,q9c,
    qU, // success
    qF // fail
};
const char*state_representations[] = {
    "qS",
    "qX",
    "q0", "q1", "q2", "q3", "q4", "q5", "q6", "q7", "q8", "q9",
    "q0c","q1c","q2c","q3c","q4c","q5c","q6c","q7c","q8c","q9c",
    "qU",
    "qF"
};

enum direction_t {
    LEFT=0,
    RIGHT
};

const char*direction_representations[] = {
    "LEFT",
    "RIGHT"
};

struct cellid_t {
    cellid_t(){}
    bool operator< (const cellid_t& dva) const{return state*20+chr<dva.state*20+dva.chr;}
    cellid_t(state_t state, char chr){this->state = state; this->chr = chr;}
    state_t state;
    char chr;
};

struct action_t {
    action_t() {}
    action_t(state_t s,char c,direction_t d) {newstate=s;newchar=c;direction=d;}
    state_t newstate;
    char newchar;
    direction_t direction;
};

std::map<cellid_t, action_t> actions;
std::string track;

std::string::iterator ptr;
state_t state;
bool success = false;
bool performAction() {
    std::map<cellid_t, action_t>::iterator action = actions.find(cellid_t(state, (*ptr)));
    if (action == actions.end()) {
        return state=qF, false;
    }

    (*ptr)=action->second.newchar;
    state = action->second.newstate;
    if (action->second.direction == LEFT)
        ptr--;
    else
        ptr++;
    if (ptr < track.begin())
        return state=qF, false;
    if (ptr == track.end()) {
        track += "B";
        ptr = track.begin() + track.size() - 1;
    }
    if (state == qU) {// success state
        success = true;
        return false;
    }
    return true;
}

char getRepresentation(char chr) {
    if (chr >= '0' && chr < '9')
        return chr;
    if (chr == -1)
        return 'B';
    return 'B';
}

void printTrack() {
    printf("[");
    for (std::string::iterator c = track.begin(); c != track.end(); c++) {
        printf("%c",getRepresentation(*c));
    }
    printf("]\n");

    printf(" ");
    for (std::string::iterator c = track.begin(); c != track.end(); c++) {
        if (c == ptr)
            printf("^");
        else
            printf(" ");
    }
    printf(" \n");

    printf("State %s, char %c\n", state_representations[state], getRepresentation(*ptr));
}


void loadTransitions() {
    // Hardkodirana tablica prijelaza
    // Prikaz tablice dan je u prilozenoj dokumentaciji/seminaru


    // kad smo u qS, idemo u lijevo trazeci pocetak
    for (state_t s = q0; s <= q9; s=(state_t)(((int)s)+1))
        actions[cellid_t(qS,((int)s-(int)q0+'0'))] = action_t(qS, ((int)s-(int)q0+'0'),LEFT);
    // kad nadjemo prazninu -- to je pocetak, prvo sto uradimo je korak udesno da se vratimo na same podatke
    actions[cellid_t(qS,'B')] = action_t(qX,'B',RIGHT);
    // prvo kad se vratimo na prave podatke, ulovimo koji je taj prvi podatak i prijedjemo u odgovarajuce qn stanje
    for (state_t s = q0; s <= q9; s=(state_t)(((int)s)+1))
        actions[cellid_t(qX,((int)s-(int)q0+'0'))] = action_t(s,'B',RIGHT);
    // ako smo kojim slucajem naletili na prazninu -- onda ce to biti uspjeh jer nema vise s cime raditi
    actions[cellid_t(qX,'B')] = action_t(qU,'B',RIGHT);

    // kad smo u odgovarajucem qn stanju, idemo udesno sve dok ne naletimo na prazninu
    for (state_t s = q0; s <= q9; s=(state_t)(((int)s)+1)) {
        for (char c = '0'; c <= '9'; c++)
            actions[cellid_t(s,c)] = action_t(s,c,RIGHT);
        // kad smo dosli do praznine, prijedjemo u qnc i vratimo se
        // qnc je tocno udaljen za 10 od qn
        actions[cellid_t(s,'B')] = action_t((state_t)(((int)s)+10),'B',LEFT);
    }

    // kad smo u qnc, dozvoljavamo prolaz jedino u slucaju kada je znak jednak odgovarajucem znaku 'n' za stanje qn
    // i tada se pomocu stanja qS vracamo na pocetak (do praznine)
    for (state_t s = q0c; s <= q9c; s=(state_t)(((int)s)+1)) {
        actions[cellid_t(s,((int)s-(int)q0c+'0'))] = action_t(qS,'B',LEFT);
        // a ako smo iz qnc opet naletili na prazninu, to znaci da vise niceg nema
        // ako smo sve ispraznili bez da smo srusili tezu da je to palindrom (tako da smo naletili na nepostojeci prijelaz)
        //   -- to onda jest palindrom
        // prijedjimo u stanje za uspjeh!
        actions[cellid_t(s,'B')] = action_t(qU,'B',RIGHT);
    }
}


void loadTrack() {
    //track = "B12321";
    char tmp[1024];
    printf("Unesite ulazne znakove trake.\n");
    printf("Znakovi se nece odmah provjeriti. Smiju biti 0,1,2,3,4,5,6,7,8,9,B.\n");
    printf("Slovo B obavezno mora biti napisano velikim slovom i oznacava prazninu.\n");
    printf("\n");
    printf("VAZNO! Da bi simulirani stroj valjano radio, na pocetku MORA stajati praznina.\n");
    printf("Stoga valjani unos je npr: B12321, B1221 (palindromi), B1541 (nije palindrom)\n");
    printf("Valjani unosi NISU: 12321, 1221, 1541.\n");
    printf("Primijetite B na prvom mjestu.\n");
    printf("\n> ");
    gets(tmp);
    //tmp[strlen(tmp)-2]=0;
    printf("Uneseno: %s\n",tmp);
    PAUZA
    track = tmp;
}

int main() {
    printf("Sveuciliste u Zagrebu\n");
    printf("Fakultet elektrotehnike i racunarstva\n");
    printf("Ivan Vucica, 0036431411, 2R2\n");
    printf("Zadatak 2048 - \"Otkrivanje palindroma\"\n");
    printf("\n");


    loadTransitions();
    loadTrack();

    ptr = track.begin();

    BRISIEKRAN

    printTrack();
    PAUZA
    BRISIEKRAN

    while(performAction()){
        printTrack();
        PAUZA
        BRISIEKRAN
    }
    printf("------------------------\n");
    if (success) {
        printf("PALINDROM\n");
    } else {
        printf("NIJE PALINDROM ILI DRUGA GRESKA\n");
    }
    PAUZA

    return 0;
}
