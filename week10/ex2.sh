touch ~/OS/OS_Home_Works/week1/file.txt
echo "Nikita_Fed" > ~/OS/OS_Home_Works/week1/file.txt 
link ~/OS/OS_Home_Works/week1/file.txt _ex2.txt
touch ex2.txt
find ~/OS/OS_Home_Works -inum 21650703 > ex2.txt
find ~/OS/OS_Home_Works -inum 21650703 -exec rm {} \; >> ex2.txt
rm _ex2.txt
