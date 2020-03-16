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
#include <python2.7/Python.h>
#include <python3.6/Python.h>

#define SHELLSCRIPT "\
#/bin/bash \n\
python code_python_statistique.py \n\
"

#define SHELLSCRIPT0 "\
#/bin/bash \n\
python affiche.py \n\
"

#define SHELLSCRIPT01 "\
#/bin/bash \n\
python affichelivre.py \n\
"

#define SHELLS "\
#/bin/bash \n\
python pp.py \n\
"


#define SHELLSCRIPT03 "\
#/bin/bash \n\
python affichedepot.py \n\
"

#define SHELLSCRIPT1 "\
#/bin/bash \n\
python livre_emprunt.py \n\
"


#define SHELLSCRIPT2 "\
#/bin/bash \n\
python livre_emprunter.py \n\
"

GtkWidget *window;
GtkWidget *window2;
GtkWidget *statistique;
GtkWidget *fermer_statistique;
GtkWidget *stat1;
GtkWidget *stat2;
GtkWidget *stat3;
GtkWidget *quitter_statistique;
GtkWidget *fixed1;
GtkWidget *button1;
GtkWidget *G_livre8;
GtkWidget *G_livre7;
GtkWidget *G_livre;
GtkWidget *G_livre5;
GtkWidget *G_livre00;
GtkWidget *gtk1;
GtkWidget *gtk2;
GtkWidget *gtk0;
GtkWidget *gtk00;
GtkWidget *gtk3;
GtkWidget *gtk01;
GtkWidget *gtk5;
GtkWidget *gtk6;
GtkWidget *gtk7;
GtkWidget *bt1;
GtkWidget *bt2;
GtkWidget *img1;
GtkWidget *img3;
GtkWidget *label5;
GtkWidget *label1;
GtkWidget *label2;
GtkBuilder *builder;
GtkWidget *pSaisie;
GtkWidget *pSaisie1;
GtkWidget *g1;
GtkWidget *g2;
GtkWidget *g3;
GtkWidget *g4;
GtkWidget *g5;
GtkWidget *g6;
GtkWidget *g7;
GtkWidget *g8;
GtkWidget *g9;
GtkWidget *g10;
GtkWidget *rechercher1;
GtkWidget *g11;
GtkWidget *g13;
GtkWidget *g14;
GtkWidget *g15;
GtkWidget *g16;
GtkWidget *g17;
GtkWidget *g18;
GtkWidget *g19;
GtkWidget *g20;
GtkWidget *g21;

GtkWidget *g22;
GtkWidget *g23;
GtkWidget *g24;
GtkWidget *g25;
GtkWidget *g26;

GtkWidget *azz;
GtkWidget *Dep;


GtkWidget *g27;
GtkWidget *g28;
GtkWidget *g29;
GtkWidget *g30;
GtkWidget *g31;
GtkWidget *g32;


GtkWidget *quitter_window1;
GtkWidget *livre;
GtkWidget *valider;
GtkWidget *label3;
GtkWidget *label4;
GtkWidget *bt3;
GtkWidget *bt4;
GtkWidget *bt5;
GtkWidget *gtk4;
GtkWidget *bt6;
GtkWidget *g12;
GtkWidget *valider2;
GtkWidget *valider1;
GtkWidget *valider3;
GtkWidget *label6;
GtkWidget *label7;
GtkWidget *pTable;
GtkWidget *G_livre3;
GtkWidget *G_livre4;
GtkWidget *emprunt;
GtkWidget *pWindow;
GtkWidget *dialog, *label, *content_area;
GtkDialogFlags flags;
const GdkRGBA red = {0, 0xffff, 0x0000, 0x0000};

GtkWidget *valider4;
GtkWidget *rechercher2;
GtkWidget *valider5;
GtkWidget *valider6;
GtkWidget *valider7;
GtkWidget *etudiant;

GtkWidget *bt7;
GtkWidget *bt8;
GtkWidget *bt9;
GtkWidget *bt10;
GtkWidget *bt11;
GtkWidget *bt12;
GtkWidget *em;
GtkWidget *depott;
GtkWidget *img4;
GtkWidget *label13;
GtkWidget *bk;

GtkWidget *a1;
GtkWidget *a2;
GtkWidget *a3;
GtkWidget *a4;
GtkWidget *a5;
GtkWidget *lab;
GtkWidget *a6;
GtkWidget *a7;
GtkWidget *a8;
GtkWidget *a9;
GtkWidget *a10;
GtkWidget *lab1;
GtkWidget *dep;
GtkWidget *G_livre2;
GtkWidget *lab2;
GtkWidget *lab;
GtkWidget *lab3;
GtkWidget *label8;
GtkWidget *label9;
GtkWidget *label11;
GtkWidget *label10;
GtkWidget *label12;
GtkWidget *img2;
GtkWidget *retour_window1;
GtkWidget *retour_window2;
GtkWidget *retour_window3;
GtkWidget *retour_window4;

const gchar *entry1_text;
const gchar *entry0_text;
const gchar *nom;
const gchar *supcart;
const gchar *prenom;
const gchar *numero_carte;
const gchar *age;
const char *s1;
const gchar *pp;
const gchar *classe;
int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkRGBA colorRed = {1, 0, 0, 1};
  builder = gtk_builder_new_from_file("connexion.glade");

  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
  etudiant = GTK_WIDGET(gtk_builder_get_object(builder, "etudiant"));
    depott = GTK_WIDGET(gtk_builder_get_object(builder, "depott"));
    G_livre2 = GTK_WIDGET(gtk_builder_get_object(builder, "G_livre2"));
    lab2 = GTK_WIDGET(gtk_builder_get_object(builder, "lab2"));

  gtk_window_set_title(GTK_WINDOW(window), "BIBLIOTHEQUE NUMERIQUE DE L'ESATIC");
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(etudiant, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_modify_bg(window, GTK_STATE_NORMAL, &colorWht);
    em = GTK_WIDGET(gtk_builder_get_object(builder, "em"));
    Dep = GTK_WIDGET(gtk_builder_get_object(builder, "Dep"));
  gtk0 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk0"));
  gtk00 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk00"));
  gtk1 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk1"));
  gtk2 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk2"));
  gtk3 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk3"));
  gtk4 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk4"));
  gtk01 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk01"));
  gtk5 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk5"));
  gtk6 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk6"));
  gtk7 = GTK_WIDGET(gtk_builder_get_object(builder, "gtk7"));
  emprunt = GTK_WIDGET(gtk_builder_get_object(builder, "emprunt"));
  valider = GTK_WIDGET(gtk_builder_get_object(builder, "valider"));
  valider3 = GTK_WIDGET(gtk_builder_get_object(builder, "valider3"));
   valider4 = GTK_WIDGET(gtk_builder_get_object(builder, "valider4"));
  valider5 = GTK_WIDGET(gtk_builder_get_object(builder, "valider5"));
    valider7 = GTK_WIDGET(gtk_builder_get_object(builder, "valider7"));
  rechercher2 = GTK_WIDGET(gtk_builder_get_object(builder, "rechercher2"));
  label11 = GTK_WIDGET(gtk_builder_get_object(builder, "label11"));
  gtk_widget_hide(label11);
  bt7 = GTK_WIDGET(gtk_builder_get_object(builder, "bt7"));
  bt8 = GTK_WIDGET(gtk_builder_get_object(builder, "bt8"));
  bt9 = GTK_WIDGET(gtk_builder_get_object(builder, "bt9"));
  bt10 = GTK_WIDGET(gtk_builder_get_object(builder, "bt10"));
  bt11 = GTK_WIDGET(gtk_builder_get_object(builder, "bt11"));
  bt12 = GTK_WIDGET(gtk_builder_get_object(builder, "bt12"));
  img4 = GTK_WIDGET(gtk_builder_get_object(builder, "img4"));
  label13 = GTK_WIDGET(gtk_builder_get_object(builder, "label13"));
  label8 = GTK_WIDGET(gtk_builder_get_object(builder, "label8"));
  label9 = GTK_WIDGET(gtk_builder_get_object(builder, "label9"));
gtk_widget_hide(label8);
gtk_widget_hide(label9);
a1 = GTK_WIDGET(gtk_builder_get_object(builder, "a1"));
  a2 = GTK_WIDGET(gtk_builder_get_object(builder, "a2"));
  a3 = GTK_WIDGET(gtk_builder_get_object(builder, "a3"));
  a4 = GTK_WIDGET(gtk_builder_get_object(builder, "a4"));
  a5 = GTK_WIDGET(gtk_builder_get_object(builder, "a5"));
  lab = GTK_WIDGET(gtk_builder_get_object(builder, "lab"));
  label12 = GTK_WIDGET(gtk_builder_get_object(builder, "label12"));
  retour_window1 = GTK_WIDGET(gtk_builder_get_object(builder, "retour_window1"));
  retour_window2 = GTK_WIDGET(gtk_builder_get_object(builder, "retour_window2"));
  retour_window3 = GTK_WIDGET(gtk_builder_get_object(builder, "retour_window3"));
  retour_window4 = GTK_WIDGET(gtk_builder_get_object(builder, "retour_window4"));

  G_livre5 = GTK_WIDGET(gtk_builder_get_object(builder, "G_livre5"));
  G_livre7 = GTK_WIDGET(gtk_builder_get_object(builder, "G_livre7"));
  bk = GTK_WIDGET(gtk_builder_get_object(builder, "bk"));


a6 = GTK_WIDGET(gtk_builder_get_object(builder, "a6"));
  a7 = GTK_WIDGET(gtk_builder_get_object(builder, "a7"));
  a8 = GTK_WIDGET(gtk_builder_get_object(builder, "a8"));
  a9 = GTK_WIDGET(gtk_builder_get_object(builder, "a9"));
  a10 = GTK_WIDGET(gtk_builder_get_object(builder, "a10"));
  lab1 = GTK_WIDGET(gtk_builder_get_object(builder, "lab1"));
  lab2 = GTK_WIDGET(gtk_builder_get_object(builder, "lab2"));
  lab = GTK_WIDGET(gtk_builder_get_object(builder, "lab"));
  lab3 = GTK_WIDGET(gtk_builder_get_object(builder, "lab3"));
    gtk_widget_hide(lab);
    gtk_widget_hide(lab3);

  label6 = GTK_WIDGET(gtk_builder_get_object(builder, "label6"));
    label10 = GTK_WIDGET(gtk_builder_get_object(builder, "label10"));
    gtk_widget_hide(label10);
  gtk_widget_modify_bg(gtk0, GTK_STATE_NORMAL, &colorWht);
gtk_widget_hide(label6);
  //relier ses composants ici
  button1 = GTK_WIDGET(gtk_builder_get_object(builder, "quitter"));
  bt3 = GTK_WIDGET(gtk_builder_get_object(builder, "bt3"));
  bt4 = GTK_WIDGET(gtk_builder_get_object(builder, "bt4"));
  bt5 = GTK_WIDGET(gtk_builder_get_object(builder, "bt5"));
  g12 = GTK_WIDGET(gtk_builder_get_object(builder, "g12"));
  valider1 = GTK_WIDGET(gtk_builder_get_object(builder, "valider1"));



  //g_signal_connect(G_OBJECT(button1), "clicked", G_CALLBACK(on_quitter_clicked), window);
  G_livre8 = GTK_WIDGET(gtk_builder_get_object(builder, "G_livre8"));
  G_livre = GTK_WIDGET(gtk_builder_get_object(builder, "G_livre"));
  quitter_statistique = GTK_WIDGET(gtk_builder_get_object(builder, "quitter_statistique"));
  fermer_statistique = GTK_WIDGET(gtk_builder_get_object(builder, "fermer_statistique"));
  img1 = GTK_WIDGET(gtk_builder_get_object(builder, "img1"));
  img3 = GTK_WIDGET(gtk_builder_get_object(builder, "img3"));
  img2= GTK_WIDGET(gtk_builder_get_object(builder, "img2"));
  label5 = GTK_WIDGET(gtk_builder_get_object(builder, "label5"));
  gtk_widget_hide(img3);
  gtk_widget_hide(img2);
  gtk_widget_hide(label12);
  gtk_widget_hide(label5);
  stat1 = GTK_WIDGET(gtk_builder_get_object(builder, "stat1"));
  stat2 = GTK_WIDGET(gtk_builder_get_object(builder, "stat2"));
  stat3 = GTK_WIDGET(gtk_builder_get_object(builder, "stat3"));
  livre = GTK_WIDGET(gtk_builder_get_object(builder, "livre"));
  gtk_widget_hide(gtk2);
  gtk_widget_hide(gtk1);
  gtk_widget_hide(gtk3);
  gtk_widget_hide(gtk4);
    gtk_widget_hide(gtk01);
      gtk_widget_hide(gtk5);
      gtk_widget_hide(gtk6);
            gtk_widget_hide(gtk7);



  bt1 = GTK_WIDGET(gtk_builder_get_object(builder, "bt1"));
  bt2 = GTK_WIDGET(gtk_builder_get_object(builder, "bt2"));
  bt6 = GTK_WIDGET(gtk_builder_get_object(builder, "bt6"));
  gtk_builder_connect_signals(builder, NULL);
  label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
  label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
  label3 = GTK_WIDGET(gtk_builder_get_object(builder, "label3"));
  label4 = GTK_WIDGET(gtk_builder_get_object(builder, "label4"));
  label7 = GTK_WIDGET(gtk_builder_get_object(builder, "label7"));

  //gtk_widget_override_background_color(fixed1, GTK_STATE_NORMAL, &red);
  pSaisie = GTK_WIDGET(gtk_builder_get_object(builder, "pSaisie"));
  pSaisie1 = GTK_WIDGET(gtk_builder_get_object(builder, "pSaisie1"));

  g1 = GTK_WIDGET(gtk_builder_get_object(builder, "g1"));
  g2 = GTK_WIDGET(gtk_builder_get_object(builder, "g2"));
  g3 = GTK_WIDGET(gtk_builder_get_object(builder, "g3"));
  g4 = GTK_WIDGET(gtk_builder_get_object(builder, "g4"));
  g5 = GTK_WIDGET(gtk_builder_get_object(builder, "g5"));
  g6 = GTK_WIDGET(gtk_builder_get_object(builder, "g6"));
  g7 = GTK_WIDGET(gtk_builder_get_object(builder, "g7"));
  g8 = GTK_WIDGET(gtk_builder_get_object(builder, "g8"));
  g9 = GTK_WIDGET(gtk_builder_get_object(builder, "g9"));
  g10 = GTK_WIDGET(gtk_builder_get_object(builder, "g10"));

   g11 = GTK_WIDGET(gtk_builder_get_object(builder, "g11"));
  g13 = GTK_WIDGET(gtk_builder_get_object(builder, "g113"));
  g14 = GTK_WIDGET(gtk_builder_get_object(builder, "g14"));
  g15 = GTK_WIDGET(gtk_builder_get_object(builder, "g15"));
  g16 = GTK_WIDGET(gtk_builder_get_object(builder, "g16"));

    g17 = GTK_WIDGET(gtk_builder_get_object(builder, "g17"));
  g18 = GTK_WIDGET(gtk_builder_get_object(builder, "g18"));
  g19 = GTK_WIDGET(gtk_builder_get_object(builder, "g19"));
  g20 = GTK_WIDGET(gtk_builder_get_object(builder, "g20"));
  g21 = GTK_WIDGET(gtk_builder_get_object(builder, "g21"));

  g22 = GTK_WIDGET(gtk_builder_get_object(builder, "g22"));
  g23 = GTK_WIDGET(gtk_builder_get_object(builder, "g23"));
  g24 = GTK_WIDGET(gtk_builder_get_object(builder, "g24"));
  g25 = GTK_WIDGET(gtk_builder_get_object(builder, "g25"));
  g26 = GTK_WIDGET(gtk_builder_get_object(builder, "g26"));
  G_livre3 = GTK_WIDGET(gtk_builder_get_object(builder, "G_livre3"));

      g27 = GTK_WIDGET(gtk_builder_get_object(builder, "g27"));
  g28 = GTK_WIDGET(gtk_builder_get_object(builder, "g28"));
  g29 = GTK_WIDGET(gtk_builder_get_object(builder, "g29"));
  g30 = GTK_WIDGET(gtk_builder_get_object(builder, "g30"));
  g31 = GTK_WIDGET(gtk_builder_get_object(builder, "g31"));
    g32 = GTK_WIDGET(gtk_builder_get_object(builder, "g32"));

    gtk_widget_hide(lab1);
    gtk_widget_hide(lab2);
  gtk_entry_set_text(GTK_ENTRY(pSaisie), "");
  gtk_entry_set_visibility(GTK_ENTRY(pSaisie), TRUE);
  gtk_entry_set_text(GTK_ENTRY(pSaisie1), "");
  gtk_entry_set_visibility(GTK_ENTRY(pSaisie1), TRUE);
  gtk_entry_set_visibility(GTK_ENTRY(pSaisie1), FALSE);
  gtk_entry_set_invisible_char(GTK_ENTRY(pSaisie1), '*');
  g_signal_connect_swapped(button1, "clicked", G_CALLBACK(gtk_widget_destroy), window);
  g_signal_connect_swapped(bt4, "clicked", G_CALLBACK(gtk_widget_destroy), livre);
    g_signal_connect_swapped(bt11, "clicked", G_CALLBACK(gtk_widget_destroy), etudiant);
  g_signal_connect_swapped(retour_window2, "clicked", G_CALLBACK(gtk_widget_destroy), emprunt);
    g_signal_connect_swapped(retour_window4, "clicked", G_CALLBACK(gtk_widget_destroy), depott);

    g_signal_connect_swapped(bt11, "clicked", G_CALLBACK(gtk_widget_destroy), etudiant);


            gtk_widget_hide(label7);
  gtk_widget_show(window);
  gtk_main();

  return EXIT_SUCCESS;
}
void valider6_clicked_cb(GtkButton *b80)
{
  int i = 0;
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
    nom = gtk_entry_get_text(GTK_ENTRY(g27));
  numero_carte = gtk_entry_get_text(GTK_ENTRY(g28));
  printf("%s", numero_carte);
  char query_string[] = {"SELECT * FROM livre where titre_livre='%s' and categories='%s'"};
  sprintf(buf, query_string,nom, numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    //printf("id  nom  prenom  numero_carte  date  age  classe\n");

  if ((row=mysql_fetch_row(result)))
    {
            gtk_widget_hide(label11);
       gtk_entry_set_text(GTK_ENTRY(g27), row[2]);
        gtk_entry_set_text(GTK_ENTRY(g28), row[1]);
        gtk_entry_set_text(GTK_ENTRY(g29), row[5]);
        gtk_entry_set_text(GTK_ENTRY(g30), row[6]);
        gtk_entry_set_text(GTK_ENTRY(g31), row[3]);
    }
    else
    {
      gtk_widget_show(label11);
      gtk_entry_set_text(GTK_ENTRY(g27), "");
      gtk_entry_set_text(GTK_ENTRY(g28), "");
      gtk_entry_set_text(GTK_ENTRY(g29), "");
      gtk_entry_set_text(GTK_ENTRY(g30), "");
      gtk_entry_set_text(GTK_ENTRY(g31), "");
    }

    }
}


void rechercher2_clicked_cb(GtkButton *b80)
{
  int i = 0;
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
    nom = gtk_entry_get_text(GTK_ENTRY(g22));
  numero_carte = gtk_entry_get_text(GTK_ENTRY(g23));
  printf("%s", numero_carte);
  char query_string[] = {"SELECT * FROM livre where titre_livre='%s' and categories='%s'"};
  sprintf(buf, query_string,nom, numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    //printf("id  nom  prenom  numero_carte  date  age  classe\n");

  if ((row=mysql_fetch_row(result)))
    {
            gtk_widget_hide(label10);
       gtk_entry_set_text(GTK_ENTRY(g22), row[2]);
        gtk_entry_set_text(GTK_ENTRY(g23), row[1]);
        gtk_entry_set_text(GTK_ENTRY(g24), row[5]);
        gtk_entry_set_text(GTK_ENTRY(g25), row[6]);
        gtk_entry_set_text(GTK_ENTRY(g26), row[3]);
    }
    else
    {
      gtk_widget_show(label10);
      gtk_entry_set_text(GTK_ENTRY(g22), "");
      gtk_entry_set_text(GTK_ENTRY(g23), "");
      gtk_entry_set_text(GTK_ENTRY(g24), "");
      gtk_entry_set_text(GTK_ENTRY(g25), "");
      gtk_entry_set_text(GTK_ENTRY(g26), "");
    }

    }
}


void valider4_clicked_cb(GtkButton *b80)
{
    int p;
  int pp1, pp2, pp3, pp4, pp5;
  nom = gtk_entry_get_text(GTK_ENTRY(g17));
  prenom = gtk_entry_get_text(GTK_ENTRY(g18));
  numero_carte = gtk_entry_get_text(GTK_ENTRY(g19));
  age = gtk_entry_get_text(GTK_ENTRY(g20));
  s1 = gtk_entry_get_text(GTK_ENTRY(g4));
  classe = gtk_entry_get_text(GTK_ENTRY(g21));
  p = atoi(age);
  pp1 = gtk_entry_get_text_length(GTK_ENTRY(g17));
  pp2 = gtk_entry_get_text_length(GTK_ENTRY(g18));
  pp3 = gtk_entry_get_text_length(GTK_ENTRY(g19));
  pp4 = gtk_entry_get_text_length(GTK_ENTRY(g20));
  pp5 = gtk_entry_get_text_length(GTK_ENTRY(g21));

  if (pp1 == 0 || pp2 == 0 || pp3 == 0 || pp4 == 0 || pp5 == 0)
  {
    
    gtk_widget_show(label8);
  }
  else
  {
    gtk_widget_hide(label8);
    gtk_widget_show(label9);
    Insertion_livre(nom, prenom, numero_carte, p, classe);
    gtk_label_set_text(GTK_LABEL(label4), (const gchar *)"Insertion Effectuee");
    gtk_entry_set_text(GTK_ENTRY(g17), "");
    gtk_entry_set_text(GTK_ENTRY(g18), "");
    gtk_entry_set_text(GTK_ENTRY(g19), "");
    gtk_entry_set_text(GTK_ENTRY(g20), "");
    gtk_entry_set_text(GTK_ENTRY(g21), "");
  }
}



void em_clicked_cb(GtkButton *b80)
{
    int p;
  int pp1, pp2, pp3, pp4, pp5;
  nom = gtk_entry_get_text(GTK_ENTRY(a1));
  prenom = gtk_entry_get_text(GTK_ENTRY(a2));
  numero_carte = gtk_entry_get_text(GTK_ENTRY(a3));
  age = gtk_entry_get_text(GTK_ENTRY(a4));
  classe = gtk_entry_get_text(GTK_ENTRY(a5));
  pp1 = gtk_entry_get_text_length(GTK_ENTRY(a1));
  pp2 = gtk_entry_get_text_length(GTK_ENTRY(a2));
  pp3 = gtk_entry_get_text_length(GTK_ENTRY(a3));
  pp4 = gtk_entry_get_text_length(GTK_ENTRY(a4));
  pp5 = gtk_entry_get_text_length(GTK_ENTRY(a5));

  if (pp1 == 0 || pp2 == 0 || pp3 == 0 || pp4 == 0 || pp5 == 0)
  {
    gtk_widget_show(lab3);
    gtk_widget_hide(lab);
  }
  else
  {
    gtk_widget_show(lab);
        gtk_widget_hide(lab3);

    Insertion_emprunt(nom, prenom, numero_carte, age, classe);
    gtk_entry_set_text(GTK_ENTRY(a1), "");
    gtk_entry_set_text(GTK_ENTRY(a2), "");
    gtk_entry_set_text(GTK_ENTRY(a3), "");
    gtk_entry_set_text(GTK_ENTRY(a4), "");
    gtk_entry_set_text(GTK_ENTRY(a5), "");
  }
}

void Dep_clicked_cb(GtkButton *b80)
{
    int p;
  int pp1, pp2, pp3, pp4, pp5;
  nom = gtk_entry_get_text(GTK_ENTRY(a6));
  prenom = gtk_entry_get_text(GTK_ENTRY(a7));
  numero_carte = gtk_entry_get_text(GTK_ENTRY(a8));
  age = gtk_entry_get_text(GTK_ENTRY(a9));
  classe = gtk_entry_get_text(GTK_ENTRY(a10));
  pp1 = gtk_entry_get_text_length(GTK_ENTRY(a6));
  pp2 = gtk_entry_get_text_length(GTK_ENTRY(a7));
  pp3 = gtk_entry_get_text_length(GTK_ENTRY(a8));
  pp4 = gtk_entry_get_text_length(GTK_ENTRY(a9));
  pp5 = gtk_entry_get_text_length(GTK_ENTRY(a10));

  if (pp1 == 0 || pp2 == 0 || pp3 == 0 || pp4 == 0 || pp5 == 0)
  {
      gtk_widget_show(lab2);    
  }
  else
  {
    gtk_widget_show(lab1);
    gtk_widget_hide(lab2);

    Insertion_depot_global(nom, prenom, numero_carte, age, classe);
    gtk_entry_set_text(GTK_ENTRY(a6), "");
    gtk_entry_set_text(GTK_ENTRY(a7), "");
    gtk_entry_set_text(GTK_ENTRY(a8), "");
    gtk_entry_set_text(GTK_ENTRY(a9), "");
    gtk_entry_set_text(GTK_ENTRY(a10), "");
  }
}


void G_livre1_clicked_cb(GtkButton *b80)
{
    GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_modify_bg(etudiant, GTK_STATE_NORMAL, &colorWht);
    gtk_widget_show(etudiant);
     gtk_widget_hide(window2);
}
void bt7_clicked_cb(GtkButton *b80)
{
   gtk_widget_hide(img4);
    gtk_widget_hide(label13);

    GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_modify_bg(gtk01, GTK_STATE_NORMAL, &colorBlue);
    gtk_widget_show(gtk01);
    gtk_widget_hide(gtk5);
    gtk_widget_hide(gtk6);
        gtk_widget_hide(gtk7);

}
void bt8_clicked_cb(GtkButton *b80)
{
   gtk_widget_hide(img4);
    gtk_widget_hide(label13);
    GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_modify_bg(gtk5, GTK_STATE_NORMAL, &colorBlue);
   gtk_widget_show(gtk5);
    gtk_widget_hide(gtk01);
    gtk_widget_hide(gtk6);
        gtk_widget_hide(gtk7);
}
void bt9_clicked_cb(GtkButton *b80)
{
   gtk_widget_hide(img4);
    gtk_widget_hide(label13);
    GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_modify_bg(gtk6, GTK_STATE_NORMAL, &colorBlue);
    gtk_widget_show(gtk6);
       gtk_widget_hide(gtk5);
    gtk_widget_hide(gtk01);
        gtk_widget_hide(gtk7);
}

void bt10_clicked_cb(GtkButton *b80)
{
   gtk_widget_hide(img4);
    gtk_widget_hide(label13);
    GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_modify_bg(gtk7, GTK_STATE_NORMAL, &colorBlue);
    gtk_widget_show(gtk7);
       gtk_widget_hide(gtk5);
    gtk_widget_hide(gtk01);
        gtk_widget_hide(gtk6);
}
void G_livre4_clicked_cb(GtkButton *b80)
{
  system(SHELLSCRIPT0);
}
void valider2_clicked_cb(GtkButton *b80)
{
  supcart = gtk_entry_get_text(GTK_ENTRY(g12));
  if (verifier_client1(supcart) == 1)
  {
    supprimer_client(supcart);
    gtk_widget_show(img3);
    gtk_widget_show(label5);
  }
  else
  {
    gtk_widget_hide(img3);
    gtk_widget_hide(label5);
  }
}

void valider7_clicked_cb(GtkButton *b80)
{
  supcart = gtk_entry_get_text(GTK_ENTRY(g32));
  if (verifierlivre(supcart) == 1)
  {
    supprimerlivre(supcart);
    gtk_widget_show(img2);
    gtk_widget_show(label12);
  }
  else
  {
    gtk_widget_hide(img2);
    gtk_widget_hide(label12);
  }
}

void valider3_clicked_cb(GtkButton *b90)
{

  int i = 0;
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  numero_carte = gtk_entry_get_text(GTK_ENTRY(g8));
  printf("%s", numero_carte);
  char query_string[] = {"SELECT * FROM bd1 where numero_carte='%s'"};
  sprintf(buf, query_string, numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    //printf("id  nom  prenom  numero_carte  date  age  classe\n");

  if ((row=mysql_fetch_row(result)))
    {
            gtk_widget_hide(label6);
       gtk_entry_set_text(GTK_ENTRY(g6), row[1]);
        gtk_entry_set_text(GTK_ENTRY(g7), row[2]);
        gtk_entry_set_text(GTK_ENTRY(g8), row[3]);
        gtk_entry_set_text(GTK_ENTRY(g9), row[5]);
        gtk_entry_set_text(GTK_ENTRY(g10), row[6]);
    }
    else
    {
      gtk_widget_show(label6);
      gtk_entry_set_text(GTK_ENTRY(g6), "");
      gtk_entry_set_text(GTK_ENTRY(g7), "");
      gtk_entry_set_text(GTK_ENTRY(g8), "");
      gtk_entry_set_text(GTK_ENTRY(g9), "");
      gtk_entry_set_text(GTK_ENTRY(g10), "");
    }

    }
}

void G_livre2_clicked_cb(GtkButton *b901)
{
  
    GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_modify_bg(emprunt, GTK_STATE_NORMAL, &colorWht);
  gtk_widget_hide(window2);
  gtk_widget_show(emprunt);
}

void G_livre3_clicked_cb(GtkButton *b901)
{
  
    GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_modify_bg(emprunt, GTK_STATE_NORMAL, &colorWht);
  gtk_widget_hide(window2);
  gtk_widget_show(depott);
}
void rechercher1_clicked_cb(GtkButton *b90)
{

  int i = 0;
  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  numero_carte = gtk_entry_get_text(GTK_ENTRY(g14));
  printf("%s", numero_carte);
  char query_string[] = {"SELECT * FROM bd1 where numero_carte='%s'"};
  sprintf(buf, query_string, numero_carte);
  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {
    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    //printf("id  nom  prenom  numero_carte  date  age  classe\n");

  if ((row=mysql_fetch_row(result)))
    {
            gtk_widget_hide(label7);
       gtk_entry_set_text(GTK_ENTRY(g11), row[1]);
        gtk_entry_set_text(GTK_ENTRY(g13), row[2]);
        gtk_entry_set_text(GTK_ENTRY(g14), row[3]);
        gtk_entry_set_text(GTK_ENTRY(g15), row[5]);
        gtk_entry_set_text(GTK_ENTRY(g16), row[6]);
    }
    else
    {
      gtk_widget_show(label7);
      gtk_entry_set_text(GTK_ENTRY(g11), "");
      gtk_entry_set_text(GTK_ENTRY(g13), "");
      gtk_entry_set_text(GTK_ENTRY(g14), "");
      gtk_entry_set_text(GTK_ENTRY(g15), "");
      gtk_entry_set_text(GTK_ENTRY(g16), "");
    }

    }
}

void valider1_clicked_cb(GtkButton *b08)
{
  int p;
  int pp1, pp2, pp3, pp4, pp5;
  nom = gtk_entry_get_text(GTK_ENTRY(g6));
  prenom = gtk_entry_get_text(GTK_ENTRY(g7));
  numero_carte = gtk_entry_get_text(GTK_ENTRY(g8));
  age = gtk_entry_get_text(GTK_ENTRY(g9));
  s1 = gtk_entry_get_text(GTK_ENTRY(g4));
  classe = gtk_entry_get_text(GTK_ENTRY(g10));
  p = atoi(age);
  pp1 = gtk_entry_get_text_length(GTK_ENTRY(g1));
  pp2 = gtk_entry_get_text_length(GTK_ENTRY(g2));
  pp3 = gtk_entry_get_text_length(GTK_ENTRY(g8));
  pp4 = gtk_entry_get_text_length(GTK_ENTRY(g4));
  pp5 = gtk_entry_get_text_length(GTK_ENTRY(g5));

  if (pp3 == 0)
  {
    gtk_label_set_text(GTK_LABEL(label3), (const gchar *)"Le Champs numero_carte est Obigatoire");
    gtk_widget_hide(label4);
    gtk_widget_show(label3);
  }
  else
  {
    //rechercher_client(numero_carte);

    gtk_widget_hide(label3);
    gtk_widget_show(label4);
    update(nom, prenom, numero_carte, p, classe);

    gtk_label_set_text(GTK_LABEL(label4), (const gchar *)"modification Effectuee");
    gtk_entry_set_text(GTK_ENTRY(g6), "");
    gtk_entry_set_text(GTK_ENTRY(g7), "");
    gtk_entry_set_text(GTK_ENTRY(g8), "");
    gtk_entry_set_text(GTK_ENTRY(g9), "");
    gtk_entry_set_text(GTK_ENTRY(g10), "");
  }
}
void bt2_clicked_cb(GtkButton *b8)
{
  GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_hide(img1);
  gtk_widget_modify_bg(gtk3, GTK_STATE_NORMAL, &colorBlue);
  gtk_widget_show(gtk3);
  gtk_widget_hide(label2);
  gtk_widget_hide(gtk4);
  gtk_widget_hide(gtk2);
  gtk_widget_hide(gtk1);
}
void bt1_clicked_cb(GtkButton *b9)
{
  GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_hide(img1);
  gtk_widget_modify_bg(gtk1, GTK_STATE_NORMAL, &colorBlue);
  gtk_widget_hide(label2);
  gtk_widget_hide(gtk3);
  gtk_widget_show(gtk1);
  gtk_widget_hide(gtk2);
  gtk_widget_hide(gtk4);
}
void bt6_clicked_cb(GtkButton *b20)
{
  GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_hide(img1);

  gtk_widget_modify_bg(gtk4, GTK_STATE_NORMAL, &colorBlue);
  gtk_widget_hide(gtk1);
  gtk_widget_hide(label2);
  gtk_widget_hide(gtk3);
  gtk_widget_hide(gtk2);
  gtk_widget_show(gtk4);
}

void valider5_clicked_cb(GtkButton *b08)
{
  int p;
  int pp1, pp2, pp3, pp4, pp5;
  nom = gtk_entry_get_text(GTK_ENTRY(g27));
  prenom = gtk_entry_get_text(GTK_ENTRY(g28));
  numero_carte = gtk_entry_get_text(GTK_ENTRY(g29));
  age = gtk_entry_get_text(GTK_ENTRY(g30));
  s1 = gtk_entry_get_text(GTK_ENTRY(g4));
  classe = gtk_entry_get_text(GTK_ENTRY(g31));
  p = atoi(age);
  pp1 = gtk_entry_get_text_length(GTK_ENTRY(g27));
  pp2 = gtk_entry_get_text_length(GTK_ENTRY(g28));
  pp3 = gtk_entry_get_text_length(GTK_ENTRY(g29));
  pp4 = gtk_entry_get_text_length(GTK_ENTRY(g30));
  pp5 = gtk_entry_get_text_length(GTK_ENTRY(g31));

  if (pp3 == 0)
  {
    gtk_label_set_text(GTK_LABEL(label3), (const gchar *)"Le Champs numero_carte est Obigatoire");
    gtk_widget_hide(label4);
    gtk_widget_show(label3);
  }
  else
  {
    //rechercher_client(numero_carte);

    gtk_widget_hide(label3);
    gtk_widget_show(label4);
    update_livre(classe,p,prenom,nom,numero_carte);

    gtk_label_set_text(GTK_LABEL(label4), (const gchar *)"modification Effectuee");
    gtk_entry_set_text(GTK_ENTRY(g27), "");
    gtk_entry_set_text(GTK_ENTRY(g28), "");
    gtk_entry_set_text(GTK_ENTRY(g29), "");
    gtk_entry_set_text(GTK_ENTRY(g30), "");
    gtk_entry_set_text(GTK_ENTRY(g31), "");
  }
}


void valider_clicked_cb(GtkButton *b10)
{
  int p;
  int pp1, pp2, pp3, pp4, pp5;
  nom = gtk_entry_get_text(GTK_ENTRY(g1));
  prenom = gtk_entry_get_text(GTK_ENTRY(g2));
  numero_carte = gtk_entry_get_text(GTK_ENTRY(g3));
  age = gtk_entry_get_text(GTK_ENTRY(g4));
  s1 = gtk_entry_get_text(GTK_ENTRY(g4));
  classe = gtk_entry_get_text(GTK_ENTRY(g5));
  p = atoi(age);
  pp1 = gtk_entry_get_text_length(GTK_ENTRY(g1));
  pp2 = gtk_entry_get_text_length(GTK_ENTRY(g2));
  pp3 = gtk_entry_get_text_length(GTK_ENTRY(g3));
  pp4 = gtk_entry_get_text_length(GTK_ENTRY(g4));
  pp5 = gtk_entry_get_text_length(GTK_ENTRY(g5));

  if (pp1 == 0 || pp2 == 0 || pp3 == 0 || pp4 == 0 || pp5 == 0)
  {
    gtk_label_set_text(GTK_LABEL(label3), (const gchar *)"Tous Les Champs Sont Obigatoires");
    gtk_widget_hide(label4);
    gtk_widget_show(label3);
  }
  else
  {
    gtk_widget_hide(label3);
    gtk_widget_show(label4);
    Insertion(nom, prenom, numero_carte, p, classe);
    gtk_label_set_text(GTK_LABEL(label4), (const gchar *)"Insertion Effectuee");
    gtk_entry_set_text(GTK_ENTRY(g1), "");
    gtk_entry_set_text(GTK_ENTRY(g2), "");
    gtk_entry_set_text(GTK_ENTRY(g3), "");
    gtk_entry_set_text(GTK_ENTRY(g4), "");
    gtk_entry_set_text(GTK_ENTRY(g5), "");
  }
}
void on_bt3_clicked(GtkButton *b17)
{
  gtk_widget_show(window2);
  gtk_widget_hide(livre);
}
void bt5_clicked_cb(GtkButton *b18)
{
  GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorBlue = {0x0000, 3598, 57054, 61937};
  gtk_widget_hide(img1);

  gtk_widget_modify_bg(gtk2, GTK_STATE_NORMAL, &colorBlue);
  gtk_widget_hide(label2);
  gtk_widget_hide(gtk3);
  gtk_widget_show(gtk2);
  gtk_widget_hide(gtk1);
  gtk_widget_hide(gtk4);
}
void azz_clicked_cb(GtkButton *b2)
{
}

void G_livre_clicked_cb(GtkButton *b7)
{
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  livre = GTK_WIDGET(gtk_builder_get_object(builder, "livre"));
  //quitter_window1 = GTK_WIDGET(gtk_builder_get_object(builder, "quitter_window1"));
  gtk_window_set_title(GTK_WINDOW(livre), "BIBLIOTHEQUE NUMERIQUE DE L'ESATIC");
  g_signal_connect(livre, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_modify_bg(livre, GTK_STATE_NORMAL, &colorWht);
  gtk_widget_show(livre);
  gtk_widget_hide(window2);
}
void G_livre8_clicked_cb(GtkButton *b6)
{
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  statistique = GTK_WIDGET(gtk_builder_get_object(builder, "statistique"));
  //quitter_window1 = GTK_WIDGET(gtk_builder_get_object(builder, "quitter_window1"));
  gtk_window_set_title(GTK_WINDOW(statistique), "BIBLIOTHEQUE NUMERIQUE DE L'ESATIC");
  g_signal_connect(statistique, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_modify_bg(statistique, GTK_STATE_NORMAL, &colorWht);
  gtk_widget_hide(window2);
  gtk_widget_show(statistique);

  g_signal_connect_swapped(fermer_statistique, "clicked", G_CALLBACK(gtk_widget_destroy), statistique);
}

void G_livre5_clicked_cb(GtkButton *b2)
{
    system(SHELLS);

}

void bk_clicked_cb(GtkButton *b2)
{
    system(SHELLSCRIPT03);

}
void G_livre7_clicked_cb(GtkButton *b2)
{
    system(SHELLSCRIPT01);

}
void stat1_clicked_cb(GtkButton *b1)
{
  system(SHELLSCRIPT);
}
void stat2_clicked_cb(GtkButton *b2)
{
  system(SHELLSCRIPT1);
}
void stat3_clicked_cb(GtkButton *b3)
{
  system(SHELLSCRIPT2);
}
void on_connexion_clicked(GtkButton *b0)
{
  GdkColor colorRed2 = {0x0000, 65535, 29555, 24158};
  GdkColor colorWht = {0xffff, 0xffff, 0xffff, 0xffff};
  window2 = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));
  quitter_window1 = GTK_WIDGET(gtk_builder_get_object(builder, "quitter_window1"));
  gtk_window_set_title(GTK_WINDOW(window2), "BIBLIOTHEQUE NUMERIQUE DE L'ESATIC");
  g_signal_connect(window2, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_widget_modify_bg(window2, GTK_STATE_NORMAL, &colorWht);
  //gtk_widget_modify_bg(filet, GTK_STATE_NORMAL, &colorRed2);

  entry0_text = gtk_entry_get_text(GTK_ENTRY(pSaisie));
  entry1_text = gtk_entry_get_text(GTK_ENTRY(pSaisie1));

  MYSQL *con = mysql_init(NULL);
  char buf[1024] = {};
  int b = 0;
  char query_string[] = {"SELECT * FROM superU where username='%s' and password='%s'"};
  sprintf(buf, query_string, entry0_text, entry1_text);

  if (mysql_real_connect(con, "localhost", "abelbd", "abelbd", "bd_biblio", 0, NULL, 0))
  {

    mysql_query(con, buf);
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row;
    int num_fields = mysql_num_fields(result);
    if ((mysql_fetch_row(result)))
    {
      b = 1;
      gtk_widget_hide(window);
      gtk_widget_show(window2);
      gtk_entry_set_text(GTK_ENTRY(pSaisie), "");
      gtk_entry_set_text(GTK_ENTRY(pSaisie1), "");
    }
    else
    {
      b = 0;
      gtk_label_set_text(GTK_LABEL(label1), (const gchar *)"Connexion echouée reessayer");
    }
  }
  g_signal_connect_swapped(quitter_window1, "clicked", G_CALLBACK(gtk_widget_destroy), window2);
}

void retour_window0_clicked_cb(GtkButton *b4)
{
  gtk_widget_hide(window2);
  gtk_widget_show(window);
}
void quitter_statistique_clicked_cb(GtkButton *b5)
{
  gtk_widget_hide(statistique);
  gtk_widget_show(window2);
}

void bt12_clicked_cb(GtkButton *b5)
{
  gtk_widget_hide(etudiant);
  gtk_widget_show(window2);
}


void retour_window1_clicked_cb(GtkButton *b5)
{
  gtk_widget_hide(emprunt);
  gtk_widget_show(window2);
}

void retour_window3_clicked_cb(GtkButton *b5)
{
  gtk_widget_hide(depott);
  gtk_widget_show(window2);
}
