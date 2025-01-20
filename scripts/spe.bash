#!/bin/bash

echo "> Compiling code..."
g++ -Wall -I/usr/include/ -L/usr/local/lib ../src/nanoshell_num.cxx -o ../bin/nsh -lgsl -lgslcblas -lm -larmadillo
echo "> Done!"
omemi=2.615
omema=3.02

N=100

dome=`echo "($omema - $omemi)/$N"| bc -l`
rm ../data/output/spe.dat
for (( i=0; i<=$N; i++ ))
    do 
        ome=`echo "$omemi+$dome*$i"|bc -l`
        output=`./../bin/nsh $ome`
        echo $output 
        echo $output >> ../data/output/spe.dat
done
