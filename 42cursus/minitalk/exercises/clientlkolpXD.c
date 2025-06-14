# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>

static int	*received(void)
{
	static int	r;

	return (&r);
}

static void	ack_handler(int sig)
{
	(void)sig;
	*received() = 1;
}

static void	send_char(pid_t server_pid, char c)
{
	int	i;
	int	signal_to_send;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			signal_to_send = SIGUSR1;
		else
			signal_to_send = SIGUSR2;
		if (kill(server_pid, signal_to_send) == -1)
		{
			printf("Error: Server PID doesn't match (%d)\n", server_pid);
			exit(EXIT_FAILURE);
		}
		while (!*received())
			usleep(100);
		*received() = 0;
		i--;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;

	if (ac != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	server_pid = atoi(av[1]);
	message = av[2];
	if (server_pid <= 0)
	{
		printf("Invalid PID: %s\n", av[1]);
		return (1);
	}
	signal(SIGUSR2, ack_handler);
	while (*message)
		send_char(server_pid, *message++);
	send_char(server_pid, '\0');
	return (0);
}
