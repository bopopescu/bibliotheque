import  mysql.connector
import matplotlib.pyplot as plt
import random

mydb = mysql.connector.connect(
  host="localhost",
  user="abelbd",
  passwd="abelbd",
  database="bd_biblio"
)

mycursor = mydb.cursor()

mycursor.execute("SELECT nmbre_livre FROM livre")
liv = mycursor.fetchall()
mycursor.execute("SELECT titre_livre FROM livre")
cla = mycursor.fetchall()
classe=[]
livre=[]
for c in cla:
      classe.append(c[0])
for p in liv:
      livre.append(p[0])

name = classe
data = livre

plt.title("la statistique sur le nombre de livre dans la bibliotheque",loc="center")
plt.pie(data,labels=name, autopct='%.2f', startangle=100, shadow=False)
plt.axis('equal')
plt.show()