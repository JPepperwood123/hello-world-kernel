# About
Creates a kernel module that prints "Hello World" when you insert the module into the kernel, and prints "Goodbye!" when you remove it

# Getting Started

## Navigating the Repository

There are two files present in this repository:

1. First download img VM image
2. Then download script practice.sh, and ensure both of them are in the same directory
3. Rename it to run-vm.sh

Run using ./run-vm.sh img 6500


If you get the error message “qemu: command not found”. You have to download qemu, specifically qemu-system-x86_64

For Ubuntu and Linux:
Check if you have sudo installed by typing sudo, and press Enter. If you have sudo installed the system, will display a short help message. Otherwise, you will see something like sudo command not found.

Install Sudo on Ubuntu and Debian
If you do not have sudo installed, first install it using apt-get install sudo -y
If that does not work, try apt install sudo
Then install qemu, : sudo apt-get install qemu-system


Install Sudo on CentOS and Fedora
yum install sudo
Then install qemu using dnf install qemu-system-x86-core-2


For Mac:
macOS X uses Homebrew as their default package manager.
Check if you have brew by running brew, and if you get the message -bash: brew: command not found error means that it didn't find the brew environment variable on your Mac.

1. Install Homebrew in the link https://brew.sh/ or just enter /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" in a macOS Terminal or Linux shell prompt

2. Now, just type brew install qemu

If that does not work, ensure you are the administrator of the Mac only the administrator of the Mac can run the sudo command in Terminal
1. Install sudo with sudo port install sudo
2. After sudo, type sudo port install qemu 



Re-run ./run-vm.sh img 6500

Open another window and then you know what to do



After going inside the VM, update sudo according to latest
sudo apt update && sudo apt upgrade


Let’s get the new software packages we’ll need for this endeavour. Run:
sudo apt install gcc make build-essential libncurses-dev exuberant-ctags

Now go to root directory by clicking cd ~
Create directory using mkdir project

Create a .c file called hello-world.c using vim, nano or another text editor and paste what is on git above

Create a file called Makefile and paste what is on top for compilation

Ensure both are in the same directory

In the directory of your two files, run make. 

At this point, you should see some console output of your module compiling, and this whole process should create a file named hello-world.ko, the fully-functional, complied kernel module

Run sudo insmod hello-world.ko and your driver should be inserted into the kernel

You can verify this by running lsmod, which lists all of the modules currently in the kernel. Among them, you should see hello_world

Run dmesg from the terminal. This command is a shortcut for printing the kernel’s logs to the screen. You should see “Hello World” being logged there

To remove it, you can run sudo rmmod hello_world

Running dmesg again should make you see “Goodbye!” logged there


Bugs
1. Entire thing with setup
2. Makefile:4: *** missing separator.
3. dmesg problem