mkdir root
cd root
date
sleep 3
ls -lt -r / > root.txt
cat root.txt
cd -
date 
sleep 3
mkdir home
cd home
date 
sleep 3
ls -lt -r ~/ > home.txt
cat home.txt
date
sleep 3
