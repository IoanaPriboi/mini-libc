#include <unistd.h>
#include <string.h>

/*  Returns EOF if an error occurs or a value >= 0 if there were no errors.
    Documentation: https://www.geeksforgeeks.org/puts-in-c/,
    https://man7.org/linux/man-pages/man2/write.2.html */
int puts(const char *str)
{
    /* Test if write function succeeded */
    int ret = write(1, str, strlen(str));
    ret = write(1, "\n", 1);   /* ret >= 0 -> succes, ret < 0 -> error */

    return ret;
}
