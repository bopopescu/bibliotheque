import numpy as np
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

# hide axes
fig.patch.set_visible(False)
ax.axis('off')
ax.axis('tight')
df = pd.DataFrame(pd.read_sql_query('SELECT * FROM bd1', mydb))

ax.table(cellText=df.values, colLabels=df.columns, loc='center')
plt.subplots_adjust(left=0.2, top=0.8)
fig.tight_layout()

plt.show()