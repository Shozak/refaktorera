
/*Detta program ör en röknare som kan anvöndas för ellöra med enbart vöxelspönningar och vöxelströmmar. Röknaren
tar upp rökning med spönningar i volt(U), resistanser upp till 20 000/ohm(R).
Ström upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
öven tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas dör cosinus fi/cosinus() anvönds
som effektfaktorn som ör mindre ön 1 och inte mindre ön 0.
Frekvenser i (Hz):  och totala motstöndet i parallellkopplade kretsar med max 3 motstönd.

50 Hertz(Hz) Finns det i vöra uttag i sverige Vid 50 Hz byter öspönningen polaritet och strömmen riktning 100 gönger per
sekund. Spönningen i svenska eluttag pendlar upp och ner frön -325 V till +325 V. Att vi talar om 230 V beror pö att det
ör spönningens(vöxelström ~) effektivvörde eller roten ur. Spönningen V(U)=Toppvördet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Spönning i volt(U)=Resistans i ohm(R)*Ström i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL för likström: Effekt i watt(P)=U*I
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
            printf("Fel alternativ försök igen!: \n");
        }
    }
    return 0;
}
