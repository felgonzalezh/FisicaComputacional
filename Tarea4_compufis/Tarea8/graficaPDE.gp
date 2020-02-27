set term gif
set output "Primera_condición_inicial_(4x(1-x)).gif"

plot "tarea8_1.dat" using 1:2,"tarea8_2.dat" using 1:3,"tarea8_3.dat"using 1:3 ,"tarea8_4.dat"using 1:3,"tarea8_5.dat"using 1:3,"tarea8_6.dat"using 1:3,"tarea8_7.dat"using 1:3,"tarea8_8.dat"using 1:3,"tarea8_9.dat"using 1:3,"tarea8_10.dat"using 1:3  title "Temperatura-longitud"; set xlabel "x[unidad de longitud]"; set ylabel "T[unidad de temperatura]"



set output "Segunda_condición_inicial_(exp(-x^2)).gif"

plot "tarea81.dat" using 1:2,"tarea82.dat" using 1:3,"tarea83.dat" using 1:3,"tarea84.dat" using 1:3,"tarea85.dat" using 1:3,"tarea86.dat" using 1:3,"tarea87.dat" using 1:3,"tarea88.dat" using 1:3,"tarea89.dat" using 1:3,"tarea810.dat" using 1:3 title "Temperatura-longitud"; set xlabel "x[unidad de longitud]"; set ylabel "T[unidad de temperatura]"






