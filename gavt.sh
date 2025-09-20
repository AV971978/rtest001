

 pkg install git openssh
 pkg update && pkg upgrade
 git config --global user.name "AV971978"       
 git config --global user.email "akkvyas@gmail.com"
 git config --list
 ssh-keygen -t ed25519 -C "akkvyas@gmail.com"
  
~ $ git config --global user.name "AV971978"       ~ $ git config --global user.email "akkvyas@gmail.com"
~ $ git config --list
user.name=AV971978
user.email=akkvyas@gmail.com
~ $ ssh-keygen -t ed25519 -C "akkvyas@gmail.com"   Generating public/private ed25519 key pair.
Enter file in which to save the key (/data/data/com.termux/files/home/.ssh/id_ed2551

~ $ eval $(ssh-agent -s)
Agent pid 32696
~ $ ssh-add ~/.ssh/id_ed25519
Identity added: /data/data/com.termux/files/home/.ssh/id_ed25519 (akkvyas@gmail.com)
~ $ cat ~/.ssh/id_ed25519.pub
ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAILcVvBqzbW2AEe3aMKpTaUH5isHnIVljqvbcDY7w0TeZ akkvyas@gmail.com
~ $ ssh -T git@github.com
Hi AV971978! You've successfully authenticated, but GitHub does not provide shell access.
~ $ git clone git@github.com:AV971978/rtest001

~ $ cd rtest001
~/rtest001 $ ls
LICENSE                            index.html
VID-20241104-WA-1730914727227.mp4  mson.gif
image1.jpg                         pup.html
~/rtest001 $ pwd
/data/data/com.termux/files/home/rtest001

git add .
git commit -m "GAVT"
git push origin main
