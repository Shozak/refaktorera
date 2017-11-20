#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double ohms_lag(double r, double i){
    double u = i * r;
    return u;
}

double res_tot(double r1, double r2, double r3){
    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;
    return rtot;
}

double eff_enk(double u, double i){
    double p = u * i;
    return p;
}

double sken_eff(double u, double i){
    double s = u * i;
    return s;
}

double aktiv_eff(double u, double i, double cos){
    double p = u * i * cos;
    return p;
}

double sken_3fas(double u, double i){
    double s = u * i * sqrt(3);
    return s;
}

double aktiv_3fas(double u, double i, double cos){
    double p = u * i * sqrt(3) * cos;
    return p;
}

void print_menu(){
        printf("\n");
        printf("V�lj vilka storheter du vill ber�kna:\n");
        printf("V�lj 1 f�r: OHMS LAG\n");
        printf("V�lj 2 f�r: Rtot\n");
        printf("V�lj 3 f�r: EFFEKTLAGEN ENKEL\n");
        printf("V�lj 4 f�r: SKENBAR EFFEKT ENFAS\n");
        printf("V�lj 5 f�r: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
        printf("V�lj 6 f�r: SKENBAR EFFEKT 3-FAS\n");
        printf("V�lj 7 f�r: AKTIV EFFEKT 3-FAS\n");
        printf("V�lj 0 f�r: F�R ATT AVSLUTA\n");
}
double print_resistans(){
    double r;
    printf("Skriv resistans R < 20 000ohm: \n ");
    scanf("%lf", &r);
    return r;
}
double print_ampere(){
    double i;
    printf("Skriv str�m I < 440 Ampere: \n");
    scanf("%lf", &i);
    return i;
}
double print_volts(){
    double u;
    printf("Skriv sp�nnngen U i volt(V): \n ");
    scanf("%lf", &u);
    return u;
}
double print_cos(){
    double cos;
    printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
    scanf("%lf", &cos);
    return cos;
}
void print_fel(){
        printf("F�r h�gt v�rde, f�rs�k igen: \n");
}

int val_menu_1(){
    printf("Ohms lag sp�nningen(volt/V) bet�ckning U lika med Resistansen(Ohm) bet�ckning R \n");
    printf("g�nger Str�mmen(Ampere) med bet�ckningen I. Kort U=R*I. \n\n");
    double r, i;
    r=print_resistans();
    if(r > 20000){
        print_fel();
        return 1;
    }
    i=print_ampere();
    if(i > 440){
        print_fel();
        return 1;
    }
    printf("%f V\n", ohms_lag(r, i));
    return 0;
}
int val_menu_2(){
    printf("Resistans sammankopplade i parallella kretsar �r lika med 1 delat Resistans R total �r lika med\n");
    printf("Resistans 1/R1 + 1/R2 + 1/R3 d� vi h�gst anv�nder tre resistanser.\n\n");
    double r1,r2,r3;
    r1=print_resistans();
    if(r1 > 20000){
        print_fel();
        return 1;
    }
    r2=print_resistans();
    if(r2 > 20000){
        print_fel();
        return 1;
    }
    r3=print_resistans();
    if(r3 > 20000){
        print_fel();
        return 1;
    }
    printf("%f Ohm\n", res_tot(r1, r2, r3));
    return 0;
}
int val_menu_3(){
    printf("Effektlagen enkel f�r likstr�m �r effekten P i Watt (W) lika med sp�nningen U i volt(V)\n");
    printf("g�nger str�mmen I i Ampere(A): \n\n");
    double u, i;
    u=print_volts();
    i=print_ampere();
    if(i > 440){
        print_fel();
        return 1;
    }
    printf("%f W\n", eff_enk(u, i));
    return 0;
}
int val_menu_4(){
    printf("Skenbar effekt enfas r�knas med storheten VA(VoltAmpere) som �r lika med sp�nningen U i volt(V)\n");
    printf("g�nger str�mmen I i ampere(A)\n\n");
    double u, i;
    u=print_volts();
    i=print_ampere();
    if(i > 440){
        print_fel();
        return 1;
    }
    printf("%f VA\n", sken_eff(u, i));
    return 0;
}
int val_menu_5(){
    printf("Aktiv medelefdekt enfas �r lika med effekt P i watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I \n");
    printf("i Ampere g�nger cosinus fi/efkektfaktor < 1:\n\n");
    double u, i, cos;
    u=print_volts();
    i=print_ampere();
    if(i > 440){
        print_fel();
        return 1;
    }
    cos=print_cos();
    if (cos < 0 && cos > 1){
        printf("Fel v�rde, f�rs�k igen\n");
        return 1;
    }
    printf("%f W\n", aktiv_eff(u, i, cos));
    return 0;
}
int val_menu_6(){
    printf("3-fas skenbar effekt �r v�xelsp�nning �r skenbar effekt S i voltampere(VA) lika med sp�nningen U i volt(V) \n");
    printf("g�nger str�mmen I i ampere(A) g�nger roten ur 3 SQRT(3).\n\n");
    double u, i;
    u=print_volts();
    if(u > 400){
        printf("F�r h�gt v�rde, f�rs�k igen: \n");
        return 1;
    }
    i=print_ampere();
    if(i > 440){
        print_fel();
        return 1;
    }
    printf("%f VA\n", sken_3fas(u, i));
    return 0;
}
int val_menu_7(){
    printf("3-fas aktiv effekt �r effekten P i Watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I i ampere(A)\n");
    printf("g�nger cos < 1 && cos > 0 g�nger roten ur 3 SQRT(3).\n\n");
    double u, i, cos;
    u=print_volts();
    if(u > 400){
        print_fel();
        return 1;
    }
    i=print_ampere();
    if(i > 440){
        print_fel();
        return 1;
    }
    cos=print_cos();
    if (cos < 0 && cos > 1){
        print_fel();
        return 1;
    }
    printf("%f W\n", aktiv_3fas(u ,i, cos));
    return 0;
}
