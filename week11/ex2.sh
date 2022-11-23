echo "nikita" > file1
echo "fedorovich" > file2
gcc  ex2.c -o ex2.out
sudo mkdir lofsdisk/bin
sudo mkdir lofsdisk/lib
sudo mkdir lofsdisk/lib64
sudo cp /bin/ls /bin/bash /bin/echo /bin/pwd /bin/cat lofsdisk/bin
sudo cp -r /lib/x86_64-linux-gnu lofsdisk/lib/x86_64-linux-gnu
sudo cp -r /lib64/* lofsdisk/lib64
sudo cp ex2.out lofsdisk
sudo chroot lofsdisk ./ex2.out > ex2.txt
echo "\n\n\n" >> ex2.txt
./ex2.out >> ex2.txt
sudo rm -r lofsdisk/*
rm ex2.out
rm file1
rm file2
