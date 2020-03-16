#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "addition.h"
#include "soustration.h"
#include "multi.h"
#include "div.h"

int main(int argc ,char **argv ,char **enpv)
{
     int operations=0;
    /*printf("UNE ADDITION\n");
    printf("UNE SOUSTRATION\n");
    printf("UNE MULTIPLICATION\n");
    printf("UNE DIVISION\n");
    printf("VOTRE CHOIX\n");*/
    //scanf("%d",&choix);
    if(strcmp((argv[2]),"+")==0)
    {
        operations=0;
       operations = addi(atoi(argv[1]),atoi(argv[3]));
        printf("la somme est %d\n",operations);
    }
    else if(strcmp((argv[2]),"-")==0)
    {
        operations=0;
            operations = soustra(atoi(argv[1]),atoi(argv[3]));
            printf("la somme est %d\n",operations);
    }
     else if(strcmp((argv[2]),"x")==0)
    {
        operations=0;
            operations= multip(atoi(argv[1]),atoi(argv[3]));
            printf("la somme est %d\n",operations);
    }
     else if(strcmp((argv[2]),"/")==0)
    {
         operations=0;
          operations = divi(atoi(argv[1]),atoi(argv[3]));
            printf("la somme est %d\n",operations);
    }
    else
     {
            printf("pas d'operations");
     }
    printf("------------------------------------------------------------------------------------------\n");
    /*do
    {
        
        else if(choix==2)
        {
            int soustration = soustra(atoi(argv[1]),atoi(argv[2]));
            printf("la somme est %d\n",soustration);
        }
        else if(choix==3)
        {
            int multiplication = multip(atoi(argv[1]),atoi(argv[2]));
            printf("la somme est %d\n",multiplication);
        }
        else if(choix==4)
        {
            int division = divi(atoi(argv[1]),atoi(argv[2]));
            printf("la somme est %d\n",division);
        }
        printf("VOULEZ-VOUS FAIRE UNE AUTRE OPERATION\n");
        scanf("%d",&choice);
    } while (choice==1);*/
    
    
    return 0;

}