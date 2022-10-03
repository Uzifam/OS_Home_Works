gcc -pthread ex3.c
sudo time -a -o ex3.txt ./a.out 10000000 1
sudo time -a -o ex3.txt ./a.out 10000000 2 >> ex3.txt
sudo time -a -o ex3.txt ./a.out 10000000 4 >> ex3.txt
sudo time -a -o ex3.txt ./a.out 10000000 10 >> ex3.txt
sudo time -a -o ex3.txt ./a.out 10000000 100 >> ex3.txt
rm ./a.out
