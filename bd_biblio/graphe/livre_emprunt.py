import numpy as np
import matplotlib.pyplot as plt
import  mysql.connector
import pandas as pd



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
cwid = [0.5,0.5,0.5,0.5,0.5,0.5]
df = pd.DataFrame(pd.read_sql_query('SELECT * FROM bd1', mydb))
plt.title('LA LISTE DE TOUS LES ETUDIANTS',loc='center')
ax.table(cellText=df.values, colLabels=df.columns, loc='center')
the_table=ax.table(cellText=df.values, colLabels=df.columns, loc='center')
the_table.auto_set_font_size(False)
the_table.set_fontsize(10.5)
fig.tight_layout()
the_table.scale(1.5, 1)
plt.show()