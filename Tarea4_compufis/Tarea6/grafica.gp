
set term gif
set output "x-y.gif"
plot "tarea6_1.dat" using 2:3, "tarea6_2.dat" using 2:3, "tarea6_3.dat" using 2:3 , "tarea6_4.dat" using 2:3 ,"tarea6_5.dat" using 2:3 ,"tarea6_6.dat" using 2:3 ,"tarea6_7.dat" using 2:3 ,"tarea6_8.dat" using 2:3 ,"tarea6_9.dat" using 2:3 ,"tarea6_10.dat" using 2:3  title "x-y"

set output "y-z.gif"
plot "tarea6_1.dat" using 3:4, "tarea6_2.dat" using 3:4, "tarea6_3.dat" using 3:4 , "tarea6_4.dat" using 3:4 ,"tarea6_5.dat" using 3:4 ,"tarea6_6.dat" using 3:4 ,"tarea6_7.dat" using 3:4 ,"tarea6_8.dat" using 3:4 ,"tarea6_9.dat" using 3:4 ,"tarea6_10.dat" using 3:4  title "y-z"

set output "z-x.gif"
plot "tarea6_1.dat" using 2:4, "tarea6_2.dat" using 2:4, "tarea6_3.dat" using 2:4 , "tarea6_4.dat" using 2:4 ,"tarea6_5.dat" using 2:4 ,"tarea6_6.dat" using 2:4 ,"tarea6_7.dat" using 2:4 ,"tarea6_8.dat" using 2:4 ,"tarea6_9.dat" using 2:4 ,"tarea6_10.dat" using 2:4  title "x-z"



