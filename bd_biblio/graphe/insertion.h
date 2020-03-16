#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <mysql/mysql.h>
#include <math.h>
#include <ctype.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gtk/gtkx.h>

void Insertion(const gchar *nom,const gchar *prenom, const gchar *numero_carte, int age, const gchar *classe);
void lister();
void lister_livre();
void lister_emprunt();
void lister_depot();
int verifier_client1(const gchar *numero_carte);
void rechercher_client(const gchar *numero_carte);
void supprimer_client(const gchar *numero_carte);
void supprimer_livre(char numero_carte[25], char livre[25], char categorie[25]);
void supprimer_emprunt(char numero_carte[25],char livre[25],char categorie[25]);
void update(const gchar *nom,const gchar *prenom, const gchar *numero_carte,int age, const gchar *classe);
void update_livre(char d[10],int e,char a[10],char b[10],char c[10]);
int rechercher(char suUser[25],char suPwd[25]);
void rechercher_livre(char titre_livre[25], char categories[25]);
void Insertion_livre(char categories[25],char auteur[25],char titre_livre[25],int nbr_livre,char description[500]);
int verifier_exit(char titre_livre[25],char categories[25],char auteur[25]);
int verifier_client(char nom[25],char prenom[25],char numero_carte[25]);
void Insertion_emprunt(char nom_client[25],char nom_su[25],char livre[25],char categories[25],char numero_carte[25]);
void Insertion_emprunt_global(char nom_client[25],char nom_su[25],char livre[25],char categories[25],char numero_carte[25]);
int verifier_livre(char livre[25],char categorie[25]);
int verifier_emprunt(char numero_carte[25],char livre[25],char categorie[25]);
void Insertion_depot_global(char nom_su[25],char nom_client[25],char livre[25],char categories[25],char numero_carte[25]);
int return_quantite();
int verifier_bd(char classe[20]);
void return_quantite1();
void return_char();
int return_quantite01();
int verifier_bd1(char classe[20]);
void return_quantite11();
//char text1();