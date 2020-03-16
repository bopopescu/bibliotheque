#include <stdio.h>
#include <stdlib.h>
#include "somme.h"

int main(int argc,char **argv,char **envp)
{
    /*;
    somme =atoi(argv[1])+atoi(argv[2]);
    printf("la somme1 est:%d\n",somme);*/
    int somme=somme_fact(atoi(argv[1]),atoi(argv[2]));
    printf("la somme est:%d\n",somme);
    
    return 0;

}