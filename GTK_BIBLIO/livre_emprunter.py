import  mysql.connector
import matplotlib.pyplot as plt

mydb = mysql.connector.connect(
  host="localhost",
  user="abelbd",
  passwd="abelbd",
  database="bd_biblio"
)

mycursor = mydb.cursor()

mycursor.execute("SELECT nmbre_pers FROM compter_emprunt")
liv = mycursor.fetchall()
mycursor.execute("SELECT livre FROM compter_emprunt")
cla = mycursor.fetchall()
classe=[]
livre=[]
for c in cla:
      classe.append(c[0])
for p in liv:
      livre.append(p[0])

name = classe
data = livre

plt.title("la statistique sur les livres empruntes par les clients",loc="center")
plt.pie(data,labels=name, autopct='%.2f', startangle=100, shadow=False)
plt.axis('equal')
plt.show()