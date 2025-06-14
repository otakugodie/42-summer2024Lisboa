# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_count;

	(void)context;
	if (signum == SIGUSR1)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
			printf("\n");
		else
			printf("%c", current_char);
		current_char = 0;
		bit_count = 0;
	}
	if (info && kill(info->si_pid, SIGUSR2) == -1)
		printf("Failed to ACK client\n");
}

int	main(int ac, char **av)
{
	static struct sigaction	sa;

	(void)av;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (ac == 1)
	{
		printf("Server PID: %d\n", getpid());
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
		return (0);
	}
	printf("Wrong format, launch just the server!\n");
	return (1);
}
