# include "so_long.h"

long	ft_timeval_ms(struct timeval *time)
{
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}

