
set term gif
set output "x-y.gif"
plot "tarea6.dat" using 2:3 title "x-y"
set output "y-z.gif"
plot "tarea6.dat" using 3:4 title "y-z"
set output "z-x.gif"
plot "tarea6.dat" using 1:3 title "x-z"