	
set terminal png
set output "Runge_kutta_4.png"
set datafile separator ","
set title "Runge_kutta avec different h"
set xlabel "temps (t)"
set ylabel "y(t)"
plot "Runge_kutta_4_001.csv" using 1:2 with lines lc "red" title "h = 0.01", \
    "Runge_kutta_4_01.csv" using 1:2 with lines lc "blue" title "h = 0.1", \
    "Runge_kutta_4_05.csv" using 1:2 with lines lc "green" title "h = 0.5"