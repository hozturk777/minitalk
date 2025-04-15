#include "lib/ft_printf/ft_printf.h"
#include <signal.h>
#include <unistd.h>

static void	print_bit(int *c, int *bit)
{
	ft_printf("%c", *c);
	*c = 0;
	*bit = 0;
}

static void	pull_bit(int signal)
{
	static int	bit = 0;
	static int	c = 0;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
		print_bit(&c, &bit);
}

int	main(void)
{
	int	pid_num;

	pid_num = getpid();
	ft_printf("Server pid: %d\n", pid_num);
	signal(SIGUSR1, pull_bit);
	signal(SIGUSR2, pull_bit);
	while (1)
			;
	return (0);
}
