#include <stdio.h>
#include <math.h>

int main(){
float freq, dist, n,perdida1, hr, perdida2, perdida3,A,A1,A2;
int num,n1;
double l,l1,fc,ht;

printf("Inserte la frecuencia en Hz:");
scanf("%f",&freq);

printf("Inserte la distancia en metros:");
scanf("%f",&dist);

printf("Lista de valores para n segun el area:\n");
printf("1. Free Space = 2\n");
printf("2. Urban Area celular = 2.7 - 3.5\n");
printf("3. Shadowed Celular Radio = 3 - 5\n");
printf("4. In building line of sight = 1.6 - 1.8\n");
printf("5. Obstructed in building  = 4 - 6\n");
printf("6. Obstructed in factories = 2 - 3\n");
printf("Inserte lel valor de n:\n");
scanf("%f",&n);

printf("Inserte lel valor de fc en MHz:");
scanf("%lf",&fc);

printf("Inserte lel valor de hr en m:");
scanf("%f",&hr);

printf("Inserte lel valor de ht en m:");
scanf("%lf",&ht);

printf("A continuacion, se calculara el factor de correccion:\n");
printf("Elija el tipo de ciudad:\n");
printf("1. Ciudad pequena-mediana\n");
printf("2. Ciudad grande\n");
scanf("%i",&n1);

l=log10(fc);

switch (n1){
    case 1:
    A=(1.1* l-0.7)*hr-(1.56*l-0.8);
    printf("El factor de correccion es: %f",A);
    break;
    
    case 2:
if (fc<= 300){
    A1=8.24*((log10(1.54*hr))*(log10(1.54*hr)))-1.1;
    printf("El factor de correccion es: %f",A1);
}

if (fc>= 300){
    A2=3.2*((log10(11.75*hr))*(log10(11.75*hr)))-4.97;
    printf("El factor de correccion es: %f",A2);
}
    break;
}

printf("\n");
printf("Que modelo de propagacion va a usar:\n");
printf("1: Perdida en el espacio libre\n");
printf("2: Okumura Hata\n");

scanf("%i",&num);

l1=log10(ht);

switch (num){
    case 1:
    perdida1= 20 * log10(freq) + 10 * n * log10(dist) - 147.56;
    printf("La perdida en dBs es: %f", perdida1);
    break;
    
    case 2:

    if (fc<= 300){
    perdida2= (69.55+26.16*l-13.82*l1-A1)+(44.9-6.55*l1)*log10(dist/1000);
    printf("La perdida en dBs es: %f", perdida2);
}

if (fc>= 300){
    perdida3= (69.55+26.16*l-13.82*l1-A2)+(44.9-6.55*l1)*log10(dist/1000);
    printf("La perdida en dBs es: %f", perdida3);
}
}
}
