#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

static volatile sig_atomic_t	g_sig_received = 0;

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_sig_received = 1;
	else if (sig == SIGUSR2)
		write(1, "Message received by server! ✅\n", 33);
}

static int	ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while (str[result])
	{
		if (!(str[result] >= '0' && str[result] <= '9'))
			exit(write(1, "PID can be only numbers\n", 24));
		result++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*(str)++ - '0');
	return (result);
}

int	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_sig_received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_sig_received)
			usleep(42);
		bit++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		return (write (1, "Usage: ./client [PID] [MESSAGE]\n", 32));
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (*argv[2])
		send_char(pid, *argv[2]++);
	send_char(pid, '\0');
	return (0);
}
