/* Documentation: https://elixir.bootlin.com/glibc/glibc-2.40.9000/source/time/time.h,
https://man7.org/linux/man-pages/man0/time.h.0p.html,
https://man7.org/linux/man-pages/man3/timespec.3type.html,
https://man7.org/linux/man-pages/man3/time_t.3type.html */
#ifndef	_TIME_H_
#define _TIME_H_    1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/syscall.h>
#include <internal/types.h>

typedef long time_t;

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#ifdef __cplusplus
extern "C" {
#endif

#endif
