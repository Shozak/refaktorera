
/*Detta program �r en r�knare som kan anv�ndas f�r ell�ra med enbart v�xelsp�nningar och v�xelstr�mmar. R�knaren
tar upp r�kning med sp�nningar i volt(U), resistanser upp till 20 000/ohm(R).
Str�m upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
�ven tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas d�r cosinus fi/cosinus() anv�nds
som effektfaktorn som �r mindre �n 1 och inte mindre �n 0.
Frekvenser i (Hz):  och totala motst�ndet i parallellkopplade kretsar med max 3 motst�nd.

50 Hertz(Hz) Finns det i v�ra uttag i sverige Vid 50 Hz byter �sp�nningen polaritet och str�mmen riktning 100 g�nger per
sekund. Sp�nningen i svenska eluttag pendlar upp och ner fr�n -325 V till +325 V. Att vi talar om 230 V beror p� att det
�r sp�nningens(v�xelstr�m ~) effektivv�rde eller roten ur. Sp�nningen V(U)=Toppv�rdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Sp�nning i volt(U)=Resistans i ohm(R)*Str�m i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL f�r likstr�m: Effekt i watt(P)=U*I
SKENBAR EFFEKT ENFAS ~: Skenbar(S/VA)=U*I
AKTIV EFFEKT/MEDELEFFEKT ENFAS ~:P=U*I*cos()
SKENBAR EFFEKT 3-FAS ~: Skenbar S/VA=U*I*sqrt(3)
AKTIV EFFEKT 3-FAS ~: P=U*I*sqrt(3)*cos()

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "funktioner.h"

int main()
{
    system("chcp 1252");
    system("cls");
    bool exit = false;

    while (exit == false){
        int val;
        print_menu();
        scanf("%d", &val);

        if(val == 1){
            if(val_menu_1()){
                continue;
            }
        }
        else if(val == 2){
            if(val_menu_2()){
                continue;
            }
        }
        else if(val == 3){
            if(val_menu_3()){
                continue;
            }
        }
        else if(val == 4){
            if(val_menu_4()){
                continue;
            }
        }
        else if(val == 5){
            if(val_menu_5()){
                continue;
            }
        }
        else if(val == 6){
            if(val_menu_6()){
                continue;
            }
        }
        else if(val == 7){
            if(val_menu_7()){
                continue;
            }
        }
        else if (val == 0){
            exit = true;
        }
        else{
            printf("Fel alternativ f�rs�k igen!: \n");
        }
    }
    return 0;
}
