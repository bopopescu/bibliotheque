import pandas as pd
import matplotlib.pyplot as plt
import  mysql.connector


mydb = mysql.connector.connect(
  host="localhost",
  user="abelbd",
  passwd="abelbd",
  database="bd_biblio"
)


fig, ax = plt.subplots()
font = {'family' : 'normal', 'weight' : 'bold', 'size' : 22} 
plt.rc('font', **font)
# hide axes
fig.patch.set_visible(False)
ax.axis('off')
ax.axis('tight')
df = pd.DataFrame(pd.read_sql_query('SELECT * FROM depot_global', mydb))
plt.title('LA LISTE DE TOUS LES ETUDIANTS',loc='center')
ax.table(cellText=df.values, colLabels=df.columns, loc='center')
the_table=ax.table(cellText=df.values, colLabels=df.columns, loc='center')
the_table.auto_set_font_size(False)
the_table.set_fontsize(10.5)
fig.tight_layout()
the_table.scale(1.45, 1)
plt.show()
