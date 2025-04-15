#include "lib/ft_printf/ft_printf.h"
#include "lib/libft/libft.h"
#include <signal.h>
#include <unistd.h>

static void	push_bit(int pid_num, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid_num, SIGUSR1);
		else
			kill(pid_num, SIGUSR2);
		usleep(200);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid_num;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid_num = ft_atoi(av[1]);
		if (pid_num <= 0)
		{
			ft_putendl_fd("Please Check PID\n", 2);
			return (1);
		}
		while (av[2][i])
		{
			push_bit(pid_num, av[2][i]);
			i++;
		}
	}
	else
	{
		ft_putendl_fd("Please check format!\n", 2);
		return (1);
	}
	push_bit(pid_num, '\n');
	return (0);
}
