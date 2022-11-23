dd if=/dev/zero of=lofs.img bs=50M count=1
sudo losetup -fP lofs.img
mkfs.ext4 lofs.img
mkdir lofsdisk
df -hP lofsdisk
mount | grep lofsdisk
