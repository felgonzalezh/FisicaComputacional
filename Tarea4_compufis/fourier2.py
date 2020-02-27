
import matplotlib.pyplot as plt
import sys, math
import numpy as np
from numpy import pi, real
from scipy.fftpack import fft, fftfreq, ifft

i=0
y=[]

data = np.loadtxt("monthrg.dat")
years = data[:,0]
index = np.where(years>1800)
index = index[0]
spots = data[index,3]
years = years[index]


plt.plot(years,spots)
plt.xlabel("Tiempo (anios)")
plt.ylabel("# Manchas")
filename1='Senial original'
plt.savefig(filename1+ '.pdf',format = 'pdf', transparent=True)
plt.close()

n=len(years)

T=250
f=17.5/T
dt=1/(f*(n/17.5))
freq=fftfreq(n,dt)
fft_x=fft(spots)
fft_x[len(freq)-1]=9

plt.plot(freq,np.abs(fft_x))
plt.xlabel("Frecuencias [1/anios]")
plt.ylabel("Amplitud")
filename2='Espectro de potencias'
plt.savefig(filename2 + '.pdf',format = 'pdf', transparent=True)
plt.close()
#print freq

fft_x_shifted = np.fft.fftshift(fft_x)
freq_shifted = np.fft.fftshift(freq)

Tt=[]
for i in freq:
    if i != 0:
        l=1/i
        Tt.append(l)
    else:
        Tt.append(210)


plt.plot(Tt,np.abs(fft_x))
plt.xlabel("Periodo [anios]")
plt.ylabel("Amplitud")
filename3='Espectro de potencias contra periodo'
plt.savefig(filename3 + '.pdf',format = 'pdf', transparent=True)
plt.close()

fcut=17.5/20
fft_x[np.abs(freq)>fcut]=0

plt.plot(Tt,np.abs(fft_x))
plt.xlim([-30,30])
plt.xlabel("Periodo [anios]")
plt.ylabel("Amplitud")
filename4='Espectro filtrado'
plt.savefig(filename4 + '.pdf',format = 'pdf', transparent=True)
plt.close()

clean_f=ifft(fft_x)
plt.plot(years,spots)
plt.plot(years,real(clean_f),linewidth=5, alpha=0.5)
plt.xlabel("Tiempo [anios]")
plt.ylabel("Numero de manchas")
filename5='Senial original y transformada'
plt.savefig(filename5 + '.pdf',format = 'pdf', transparent=True)
plt.close()
#print real(clean_f)

Periodo=1/f
Ultimo_pico=1990
Prediccion=1990+2*Periodo
f6=open("prediccion.txt","w")
f6.write('La prediccion del proximo pico solar esta dada para el anio '+str(Prediccion))
