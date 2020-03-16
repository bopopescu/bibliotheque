#include <stdlib.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <mysql/mysql.h>
#include <math.h>
#include "insertion.h"
#include <ctype.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gtk/gtkx.h>
GtkBuilder *builder;
GtkWidget *g6;


void Insertion(const gchar *nom,const gchar *prenom, const gchar *numero_carte,int age, const gchar *classe)
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"INSERT INTO bd1(nom,prenom,numero_carte,date_creation_compte,age,classe) VALUES('%s','%s','%s',NOW(),'%d','%s')"};
  sprintf(buf, query_string, nom, prenom, numero_carte,age,classe);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    (mysql_query(con, buf));
  }
}
void Insertion_livre(char categories[25], char auteur[25], char titre_livre[25], int nbr_livre, char description[500])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"INSERT INTO livre(categories,titre_livre,description,date_enregistrement,auteur,nmbre_livre) VALUES('%s','%s','%s',NOW(),'%s','%d')"};
  sprintf(buf, query_string, categories, titre_livre, description, auteur, nbr_livre);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    (mysql_query(con, buf));
  }
}
void lister()
{
  
  

}
void rechercher_client(const gchar *numero_carte)
{
 
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[]={"SELECT * FROM bd1 where numero_carte='%s'"};
  sprintf(buf,query_string,numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
      printf("id  nom  prenom  numero_carte  date  age  classe\n");
      while ((row = mysql_fetch_row(result)))
      {
        for (int i = 0; i < num_fields; i++)
        {
           printf("%s \t", row[i] ? row[i]:"NULL");
        }
        printf("\n");
      }
  }

}
void rechercher_livre(char titre_livre[25], char categories[25])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
 char query_string[] = {"SELECT * FROM livre where titre_livre='%s' and categories='%s'"};
  sprintf(buf, query_string,titre_livre, categories);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
      while ((row = mysql_fetch_row(result)))
      {
        for (int i = 0; i < num_fields; i++)
        {
          printf("%s \t", row[i] ? row[i]:"NULL");
        }
        printf("\n");
      }
  }
}

void lister_livre()
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  //char query_string[]={};
  sprintf(buf, "SELECT * FROM livre");
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    //printf("id  nom  prenom  numero_carte  date  age  classe\n");
  
      while ((row = mysql_fetch_row(result)))
      {
        for (int i = 0; i < num_fields; i++)
        {
          printf("%s \t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
      }
    }
}
void lister_emprunt()
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  //char query_string[]={};
  sprintf(buf, "SELECT * FROM emprunt");
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    //printf("id  nom  prenom  numero_carte  date  age  classe\n");
  
      while ((row = mysql_fetch_row(result)))
      {
        for (int i = 0; i < num_fields; i++)
        {
          printf("%s \t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
      }
    }
}
void lister_depot()
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  //char query_string[]={};
  sprintf(buf, "SELECT * FROM depot_global");
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    //printf("id  nom  prenom  numero_carte  date  age  classe\n");
      while ((row = mysql_fetch_row(result)))
      {
        for (int i = 0; i < num_fields; i++)
        {
          printf("%s \t", row[i] ? row[i] : "NULL");
        }
        printf("\n");
      }
    }
}
void update(const gchar *nom,const gchar *prenom, const gchar *numero_carte,int age, const gchar *classe)
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"UPDATE bd1 set nom='%s',prenom='%s',date_creation_compte=NOW(),age='%d',classe='%s' where numero_carte='%s'"};
  sprintf(buf, query_string, nom, prenom,age,classe,numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
  }
}
void update_livre(char d[10],int e,char a[10],char b[10],char c[10])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"UPDATE livre set description='%s',date_enregistrement=NOW(),nmbre_livre='%d' where categories='%s' and titre_livre='%s' and auteur='%s'"};
  sprintf(buf, query_string,d,e,a,b,c);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
  }
}

int rechercher(char suUser[25], char suPwd[25])
{

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM superU where username='%s' and password='%s'"};
  sprintf(buf, query_string, suUser, suPwd);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
    }
    else
    {
      b = 0;
    }
  }

  return b;
}

int verifier_exit(char titre_livre[25], char categories[25], char auteur[25])
{

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM livre where titre_livre='%s' and categories='%s' and auteur='%s'"};
  sprintf(buf, query_string, titre_livre, categories, auteur);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
    }
    else
    {
      b = 0;
    }
  }

  return b;
}

int verifier_client(char nom[25], char prenom[25], char numero_carte[25])
{

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM bd1 where nom='%s' and prenom='%s' and numero_carte='%s'"};
  sprintf(buf, query_string, nom, prenom, numero_carte);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
    }
    else
    {
      b = 0;
    }
  }

  return b;
}
int verifier_client1(const gchar *numero_carte)
{

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM bd1 where numero_carte='%s'"};
  sprintf(buf, query_string,numero_carte);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
    }
    else
    {
      b = 0;
    }
  }

  return b;
}
void Insertion_emprunt(char nom_client[25], char nom_su[25], char livre[25], char categories[25], char numero_carte[25])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"INSERT INTO emprunt(nom_superU,nom_client,livre,date_emprunt,categories,numero_carte) VALUES('%s','%s','%s',NOW(),'%s','%s')"};
  sprintf(buf, query_string, nom_client, nom_su, livre, categories, numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    (mysql_query(con, buf));
    printf("ok");
  }
}

void Insertion_emprunt_global(char nom_client[25], char nom_su[25], char livre[25], char categories[25], char numero_carte[25])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"INSERT INTO emprunt_global(nom_superU,nom_client,livre,date_emprunt,categories,numero_carte) VALUES('%s','%s','%s',NOW(),'%s','%s')"};
  sprintf(buf, query_string, nom_client, nom_su, livre, categories, numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    (mysql_query(con, buf));
    //printf("ok");
  }
}
void Insertion_depot_global(char nom_su[25], char nom_client[25], char livre[25], char categories[25], char numero_carte[25])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"INSERT INTO depot_global(nom_superU,nom_client,livre,date_depot,categories,numero_carte) VALUES('%s','%s','%s',NOW(),'%s','%s')"};
  sprintf(buf, query_string, nom_client, nom_su, livre, categories, numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    (mysql_query(con, buf));
    //printf("ok");
  }
}

int verifier_livre(char livre[25], char categorie[25])
{

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM livre where categories='%s' and titre_livre='%s'"};
  sprintf(buf, query_string,categorie,livre);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
    }
    else
    {
      b = 0;
    }
  }

  return b;
}

int verifier_emprunt(char numero_carte[25], char livre[25], char categorie[25])
{

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM emprunt where categories='%s' and livre='%s' and numero_carte='%s'"};
  sprintf(buf, query_string, categorie, livre, numero_carte);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
    }
    else
    {
      b = 0;
    }
  }

  return b;
}
void supprimer_emprunt(char numero_carte[25], char livre[25], char categorie[25])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"DELETE FROM emprunt where numero_carte='%s' and livre='%s' and categories='%s'"};
  sprintf(buf, query_string, numero_carte, livre, categorie);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
  }
}

void supprimer_livre(char auteur[25], char livre[25], char categorie[25])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"DELETE FROM livre where auteur='%s' and titre_livre='%s' and categories='%s'"};
  sprintf(buf, query_string, auteur, livre, categorie);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
  }
}

void supprimer_client(const gchar *numero_carte)
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  char query_string[] = {"DELETE FROM bd1 where numero_carte='%s'"};
  sprintf(buf, query_string, numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
  }

  
}

int return_quantite()
{
  MYSQL *con = mysql_init(NULL);
  MYSQL *con1 = mysql_init(NULL);
  char buf[1024] = {};
   char buf1[1024] = {};
  int b=0,i=0;
  char b0[10]="MBDS2";
  int num_fields;
  char query_string[] = {"SELECT id FROM bd1 where classe='%s'"};
  sprintf(buf,query_string,b0);
  printf("\n");
  char query_string1[] = {"INSERT INTO compter_bd1 (nmbre_pers,classe) VALUES('%d','%s')"};
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    num_fields = mysql_num_fields(result);
    while (row=mysql_fetch_row(result))
    {
      i+=1;
    }
    //printf("%d",i);
    sprintf(buf1,query_string1,i,b0);
    mysql_query(con1, buf1);
    //printf("ok");
  }
  return i;
}
int verifier_bd(char classe[20])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM compter_bd1 where classe='%s'"};
  sprintf(buf, query_string,classe);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
    }
    else
    {
      b = 0;
    }
  }

  return b;
}

void return_quantite1()
{

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b=0,i=0;
  char b0[10]="MBDS2";
  printf("\n");
  int a=verifier_bd(b0);
  if (a)
  {
      i=return_quantite();
      char query_string[] = {"UPDATE compter_bd1 set nmbre_pers='%d' where classe='%s'"};
    sprintf(buf,query_string,i,b0);
    if(mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
    {
      mysql_query(con, buf);
      //printf("ok");
    }
  }
  else
  {
    i=return_quantite();
     char query_string1[] = {"INSERT INTO compter_bd1 (nmbre_pers,classe) VALUES('%d','%s')"};
    sprintf(buf,query_string1,i,b0);
    if(mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
    {
      mysql_query(con, buf);
      //printf("ok");
    }
  }
}























int return_quantite01()
{
  MYSQL *con = mysql_init(NULL);
  MYSQL *con1 = mysql_init(NULL);
  char buf[1024] = {};
   char buf1[1024] = {};
  int b=0,i=0;
  char b0[10]="c_avance";
  int num_fields;
  char query_string[] = {"SELECT id FROM emprunt where livre='%s'"};
  sprintf(buf,query_string,b0);
  printf("\n");
  char query_string1[] = {"INSERT INTO compter_emprunt (nmbre_pers,livre) VALUES('%d','%s')"};
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    num_fields = mysql_num_fields(result);
    while (row=mysql_fetch_row(result))
    {
      i+=1;
    }
    //printf("%d",i);
    sprintf(buf1,query_string1,i,b0);
    mysql_query(con1, buf1);
    //printf("ok");
  }
  return i;
}
int verifier_bd1(char classe[20])
{
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM compter_emprunt where livre='%s'"};
  sprintf(buf, query_string,classe);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
    }
    else
    {
      b = 0;
    }
  }

  return b;
}

void return_quantite11()
{

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b=0,i=0;
  char b0[10]="c_avance";
  printf("\n");
  int a=verifier_bd1(b0);
  if (a)
  {
      i=return_quantite01();
      char query_string[] = {"UPDATE compter_emprunt set nmbre_pers='%d' where livre='%s'"};
    sprintf(buf,query_string,i,b0);
    if(mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
    {
      mysql_query(con, buf);
      //printf("ok");
    }
  }
  else
  {
    i=return_quantite01();
     char query_string1[] = {"INSERT INTO compter_emprunt (nmbre_pers,livre) VALUES('%d','%s')"};
    sprintf(buf,query_string1,i,b0);
    if(mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
    {
      mysql_query(con, buf);
      //printf("ok");
    }
  }
}

