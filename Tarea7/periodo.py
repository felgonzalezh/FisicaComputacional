import sys, string, os
import numpy as np

data = np.loadtxt('tarea7.dat')
radio=data[:,1]
tiempo=data[:,0]
CERO=10;
radio_estable=np.mean(radio)
pos=np.linspace(0,len(radio)-1,len(radio))

Radio_estable=radio_estable*pow(10,12)
for i in pos:
    if radio[i+1]>radio[i]:
        Periodo_seg=2*tiempo[i]
        break
Periodo_dias=Periodo_seg*1000*(1/3600.0)*(1/24.0)

f2=open('period_amplitude.txt','w')
f2.write(str(Periodo_dias)+" "+"dias"+"  "+str(Radio_estable)+" "+"cm")

  
    
        
