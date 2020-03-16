#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "addition.h"
#include "soustration.h"
#include "multi.h"
#include "div.h"
#include "math.h"
#define PI 3.14159;

int main(int argc ,char **argv ,char **enpv)
{
    int choix,don;

    printf("OPERATIONS\n");
    printf("RECTANGLE\n");
    printf("TRIANGLE\n");
    printf("CARREE\n");

    printf("votre choix\n");
    scanf("%d",&choix);
    if(choix==1)
    {
        printf("operation sur RECTANGLE\n");
        printf("SURFACE\n");
        don= multip(atoi(argv[1]),atoi(argv[2]));
        printf("\n la surface est:%d \n",don);
        printf("\n PERIMETRE \n");
        don=addi(atoi(argv[1]),atoi(argv[2]))*2;
        printf("\n le perimetre est:%d \n",don);

    }
    if(choix==2)
    {
        printf("operation sur CARRE\n");
        printf("SURFACE\n");
        don= multip(atoi(argv[1]),atoi(argv[1]));
        printf("la surface est:%d\n",don);
        printf("PERIMETRE\n");
        don=multip(atoi(argv[1]),atoi("4"));
        printf("le perimetre est:%d\n",don);
    }
if(choix==3)
    {
        printf("operation sur CERCLE\n");
        printf("SURFACE\n");
        don= multip(atoi(argv[1]),atoi(argv[1]));
        printf("la surface est:%d\n",don);
        printf("PERIMETRE\n");
        float don1=multip(atoi(argv[1]),3.14159);
        printf("le perimetre est:%0.2fd\n",don);
    }
}