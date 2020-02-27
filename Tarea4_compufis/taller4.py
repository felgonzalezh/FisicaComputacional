#!/usr/bin/python
import sys
import mdp
from numpy import*
def residuals(kd,p0,l0,PLP):
    return PLP - func(kd,p0,l0)

t=array([0,0,0])

f=open(sys.argv[1],'r')
for line in f:
    M = line.split( )
    pos_x=M[1]
    t=M[0]
    pos_y=M[2]
    
    print t
    
    import mdp
    y = mdp.pca(pos_x) 

    y = mdp.fastica(pos_x, dtype='float32') 
    import numpy as np
    import scipy.optimize as optimize
    import matplotlib.pylab as plt

    def func(kd,p0,l0):
    return 0.5*(-1-((p0+l0)/kd) + np.sqrt(4*(l0/kd)+(((l0-p0)/kd)-1)**2))

N=1000
kd_guess=3.5  # <-- You have to supply a guess for kd
p0 = np.linspace(0,10,N)
l0 = np.linspace(0,10,N)
PLP = func(kd_guess,p0,l0)+(np.random.random(N)-0.5)*0.1

kd,cov,infodict,mesg,ier = optimize.leastsq(
    residuals,kd_guess,args=(p0,l0,PLP),full_output=True,warning=True)

print(kd)
