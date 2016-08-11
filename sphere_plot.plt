set terminal postscript enhanced color portrait "Times-Roman,9"
set output "sphere_plot.ps"

set parametric
set angle radian
set urange [0:2*pi]
set vrange [0:2*pi]
set isosample 40,40
set ticslevel 0
set size 1.0,1.0
r=0.01
splot r*cos(u)*cos(v)+1,r*sin(u)*cos(v)+1,r*sin(v)+1
