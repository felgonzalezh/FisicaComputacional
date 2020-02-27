import re, string, sys, os

print "This program runs with the following arguments:", sys.argv
n_args = len(sys.argv)

if n_args == 2:
    print "La cadena introducida tiene",n_args,"argumentos";
else:
    print "Este programa necesita un archivo de texto de entrada";
    exit(1)
namefile=sys.argv[1]

def numletras(s):
    lista = string.split(s)
    return len(lista)

def remove_punctuation ( text ):
    return re.sub('[%s]' % re.escape(string.punctuation), '', text)

def remove_espacios (text):
    return re.sub('[%s]' % re.escape(string.whitespace), '', text)
    
import codecs
#infile = codecs.open(namefile, encoding='utf-8')
infile = codecs.open(namefile, 'r')
contador=0
total=0
lista = []
lista1 = []
lista=infile.read()
lista1 = remove_punctuation(lista)
cadena = remove_espacios(lista1)

for tletras in cadena:
    total=total+numletras(tletras)

caracter= []
nuevoc =  []
outfile="frecuencias_"+namefile
archivo_salida = open(outfile,"w")

for h in cadena:
    contador=0
    for s in cadena:
        if h==s:
            contador+=1
            n=(contador*100.0)/total
  
    caracter.append("%s , %f " %(h,n))
f= [nuevoc.append(nn) for nn in caracter if nn not in nuevoc]

for salida in nuevoc:
    archivo_salida.write(salida + '\n')
archivo_salida.close()
