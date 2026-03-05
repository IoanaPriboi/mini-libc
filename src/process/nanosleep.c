git commit -m "Initial commit: mini-libc implementation"#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

/* Documentation: https://elixir.bootlin.com/musl/v1.2.5/source/src/time/nanosleep.c */
int nanosleep(const struct timespec *req, struct timespec *rem)
{
	int ret = syscall(__NR_nanosleep, req, rem);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
