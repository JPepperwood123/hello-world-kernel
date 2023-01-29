# About
Creates a kernel module that prints "Hello World" when you insert the module into the kernel, and prints "Goodbye!" when you remove it

# Getting Started

## Navigating the Repository

There are four files present in this repository:

1. `PART-1.txt` : A file with the summary, shortcomings, and future directions for Part 1 of the assignment
2. `hello-world.c` : The source code for your module
3. `Makefile` : The source code for compiling the code written for the module
3. `README.md` : This file consisting of instructions to run my module and test that it works correctly on the VM provided. It also provides a list of all the bugs I encountered below.


## First Steps
1. Download the provided VM image for writing and testing the code
2. Download the script `practice.sh` to run the vm and ensure both of them are in the same directory. Rename the file to `run-vm.sh`.
3. Run: 

```jsx
   ./run-vm.sh img 6500
```

If you get the error message “qemu: command not found”, follow the below installation process to download qemu, specifically qemu-system-x86_64. If you do not get any such error, skip the below section.

## Qemu Installation

### For Ubuntu and Debian users:

1. Ensure that you have sudo by typing `sudo` into the terminal and press Enter. If you do not have sudo you will receive error message `sudo command not found`. If you do not receive this message, go to Step 3.

2. Install sudo by running:

```jsx
   apt-get install sudo -y
```

If that does not work, try:

```jsx
   apt install sudo
```

Confirm you have sudo installed by typing `sudo` in the terminal and pressing Enter. If you have sudo installed, the system will display a short help message

3. Install qemu by running:

```jsx
   sudo apt-get install qemu-system
```


### For CentOS and Fedora users:

1. Ensure that you have sudo by typing `sudo` into the terminal and press Enter. If you do not have sudo you will receive error message `sudo command not found`. If you do not receive this message, go to Step 3.

2. Install sudo by running:

```jsx
   yum install sudo
```

Confirm you have sudo installed by typing `sudo` in the terminal and pressing Enter. If you have sudo installed, the system will display a short help message

3. Install qemu by running:

```jsx
   dnf install qemu-system-x86-core-2
```


### For Mac users:
1. macOS X uses Homebrew as their default package manager. Check if you have brew by running `brew` in the terminal. 

If you get the message `-bash: brew: command not found error`, it means that it didn't find the brew environment on your Mac. If you do not receive this message, go to Step 3.

2. In a macOS Terminal or Linux shell prompt, enter:

```jsx
    $ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" 
```

found in the [Homebrew](https://brew.sh/) site.

3. Now, install qemu by running:

```jsx
    $ brew install qemu
```

4. If that does not work, ensure you are the administrator of the Mac because only the administrator of the Mac can run the sudo command in Terminal. After becoming the admin,

Install sudo with `sudo port install sudo` and subsequently qemu with `sudo port install qemu`.


## Running the VM image

1. Re-run 

```jsx
    ./run-vm.sh img 6500
```

The Terminal should now display the message `Booting from Hard Disk`. 

2. Open another window and run `Ssh -p 6500 suneja@127.0.0.1` with password `suneja`.

3. Inside the VM, update sudo according to latest update by running:

```jsx
    sudo apt update && sudo apt upgrade
```

4. To get the new software packages we will need for the kernel module, run:

```jsx
    sudo apt install gcc make build-essential libncurses-dev exuberant-ctags
```


5. Create a new directory by using `mkdir <dir-name>`. cd inside the directory.

6. Create a .c file called hello-world.c using vim, nano or another text editor and paste the code above in the repo 

7. Create a file called Makefile and paste the code above in the repo for compilation

8. Ensure both are in the same directory by clicking `ls`

9. In the directory of your two files, run 

```jsx
    make
```

10. At this point, you should see some console output of your module compiling, and this whole process should create a file named `hello-world.ko`, the fully-functional, complied kernel module

11. To insert the module into the kernel, run:

```jsx
    sudo insmod hello-world.ko
```

and this can be verified this by running `lsmod`, which lists all of the modules currently in the kernel. Among them, you should see `hello_world`

12. Run 

```jsx
    dmesg
```

This command is a shortcut for printing the kernel’s logs to the screen. You should see “Hello World” being logged there.

13. To remove the module into the kernel, run:

```jsx
    sudo rmmod hello_world
```

14. Run 

```jsx
    dmesg
```

This time we can see “Goodbye!” logged there.


# BUGS ENCOUNTERED: 
1. I ran the most problems with the setup. The downloading portion seemed to work easily, even if it took a bit of time. Then, as per recommendation, I used scp to put the downlaoded VM img and script onto attu. However, attu did not work for me as I could not find any way to download `qemu`. There was no way to get
the root password for attu so I could not download sudo in order to download qemu. However, on researching
qemu, I realized it worked as well as it could with Mac and re-ran the script after downloading qemu from
`brew` which worked really well and gave me the desired output.

2. The second problem was actually understanding the "print" portion of the question. I looked for various ways to print the messages onto the Terminal screen, but encountered docs which stated that all messages
using `pr_info()` or `printk(KERN_INFO "Message")` were "printed" onto the kernel log buffer, a ring buffer exported to userspace through /dev/kmsg. The usual way to read it, as stated above, is using `dmesg`.

The closest way to print it in the terminal was using `/proc`. However, this required creating the module's custom readline() function that can be called by creating a Python code in a script, which can be printed after opening the driver and calling readline() on the opened module. However, the printing did not happen with consequence to inserting the module, and was hence not chosen to be submitted by me.