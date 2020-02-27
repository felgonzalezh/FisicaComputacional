set term gif
set output "r-t.gif"
plot "tarea7.dat" using 1:2 title "r-t"; set xlabel "t(10^3s)"; set ylabel "r(10^12cm)"

set output "v-t.gif"
plot "tarea7.dat" using 1:3 title "v-t"; set xlabel "t(10^3s)"; set ylabel "v(10^9 cm/s)"

set output "P-t.gif"
plot "tarea7.dat" using 1:4 title "P-t"; set xlabel "t(10^3s)"; set ylabel "P(10^-11 din cm^-2)"