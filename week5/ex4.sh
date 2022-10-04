gcc -pthread ex4.c
/bin/time -o ex4.txt -p ./a.out 10000000 1
/bin/time -o ex4.txt -a -p ./a.out 10000000 2
/bin/time -o ex4.txt -a -p ./a.out 10000000 4
/bin/time -o ex4.txt -a -p ./a.out 10000000 10
/bin/time -o ex4.txt -a -p ./a.out 10000000 100
rm ./a.out
