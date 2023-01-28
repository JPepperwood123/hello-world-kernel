/* 
 * hello-world.c - Uses the module_init() and module_exit() macros to write a
 * kernel module that prints "Hello World" when you insert the module into the
 * kernel, and prints "Goodbye!" when you remove it
 */

#include <linux/init.h> /* Needed for the macros */
#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */

static int __init hello_world_init(void) {
    pr_info("Hello World\n");
    return 0;
}

static void __exit hello_world_exit(void) {
    pr_info("Goodbye!\n");
}


module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aditya Akhileshwaran");
