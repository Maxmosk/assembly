#!/bin/bash

make clean
sed -i "s/-O4/-O3/" ./Makefile
make
./sort_pas > data_pas_3.txt
make clean
sed -i "s/-O3/-O2/" ./Makefile
make
./sort_pas > data_pas_2.txt
make clean
sed -i "s/-O2/-O1/" ./Makefile
make
./sort_pas > data_pas_1.txt
make clean
sed -i "s/-O1/-Os/" ./Makefile
make
./sort_pas > data_pas_s.txt
make clean
sed -i "s/-Os//" ./Makefile
make
./sort_pas > data_pas_std.txt
make clean

