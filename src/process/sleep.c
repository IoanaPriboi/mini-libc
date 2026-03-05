#include <time.h>
#include <unistd.h>

/* Documentation: https://man7.org/linux/man-pages/man3/sleep.3.html */
unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = (time_t)seconds;

    /* Test if nanosleep function succeeded */
    int ret = nanosleep(&req, &rem);   /* ret >= 0 -> succes, ret < 0 -> error */
    if (ret < 0)       /* error => returns time remaining */
        return rem.tv_sec;

    return 0;
}
