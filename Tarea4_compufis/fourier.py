
import matplotlib.pyplot as plt
import sys, math
import numpy as np
from numpy import pi

y=[]
for line in open("monthrg.dat"):
    columns=line.split( )
    if columns[3]>0:
        y.append(columns[3])
    else:
        y=0



n=len(y)
x=np.linspace(1610,1995,n)
plt.plot(x,y)

filename = 'figure1'
plt.savefig(filename + '.pdf',format = 'pdf', transparent=True)
