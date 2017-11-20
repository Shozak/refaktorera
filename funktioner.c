#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double multiplicera(double a , double b){
    return (a*b);
}
double ohms_lag(double r, double i){
    return multiplicera( i,r );
}

double res_tot(double r1, double r2, double r3){
    double rtot= (1/r1) + (1/r2) + (1/r3);
    rtot= 1/rtot;
    return rtot;
}

double eff_enk(double u, double i){
    return multiplicera( u,i );
}

double sken_eff(double u, double i){
    return multiplicera( u,i );
}

double aktiv_eff(double u, double i, double cos){
    return multiplicera( multiplicera( u,i ),cos );
}

double sken_3fas(double u, double i){
    return multiplicera( multiplicera( u,i ),sqrt(3) );
}

double aktiv_3fas(double u, double i, double cos){
    return multiplicera( ( multiplicera( u,i ),sqrt(3) ),cos );
}

void print_menu(){
        printf("\n");
        printf("Välj vilka storheter du vill beräkna:\n");
        printf("Välj 1 för: OHMS LAG\n");
        printf("Välj 2 för: Rtot\n");
        printf("Välj 3 för: EFFEKTLAGEN ENKEL\n");
        printf("Välj 4 för: SKENBAR EFFEKT ENFAS\n");
        printf("Välj 5 för: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n");
        printf("Välj 6 för: SKENBAR EFFEKT 3-FAS\n");
        printf("Välj 7 för: AKTIV EFFEKT 3-FAS\n");
        printf("Välj 0 för: FöR ATT AVSLUTA\n");
}
double print_resistans(){
    double r;
    printf("Skriv resistans R < 20 000ohm: \n ");
    scanf("%lf", &r);
    return r;
}
double print_ampere(){
    double i;
    printf("Skriv ström I < 440 Ampere: \n");
    scanf("%lf", &i);
    return i;
}
double print_volts(){
    double u;
    printf("Skriv spännngen U i volt(V): \n ");
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
        printf("För högt värde, försök igen: \n");
}

int val_menu_1(){
    printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n");
    printf("gånger Strömmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
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
    printf("Resistans sammankopplade i parallella kretsar är lika med 1 delat Resistans R total är lika med\n");
    printf("Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder tre resistanser.\n\n");
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
    printf("Effektlagen enkel för likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n");
    printf("gånger strömmen I i Ampere(A): \n\n");
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
    printf("Skenbar effekt enfas räknas med storheten VA(VoltAmpere) som är lika med spänningen U i volt(V)\n");
    printf("gånger strömmen I i ampere(A)\n\n");
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
    printf("Aktiv medelefdekt enfas är lika med effekt P i watt(W) lika med spänningen U i volt(V) gånger strömmen I \n");
    printf("i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n");
    double u, i, cos;
    u=print_volts();
    i=print_ampere();
    if(i > 440){
        print_fel();
        return 1;
    }
    cos=print_cos();
    if (cos < 0 && cos > 1){
        printf("Fel värde, försök igen\n");
        return 1;
    }
    printf("%f W\n", aktiv_eff(u, i, cos));
    return 0;
}
int val_menu_6(){
    printf("3-fas skenbar effekt är växelspänning är skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n");
    printf("gånger strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n");
    double u, i;
    u=print_volts();
    if(u > 400){
        printf("För högt värde, försök igen: \n");
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
    printf("3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen U i volt(V) gånger strömmen I i ampere(A)\n");
    printf("gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n");
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
