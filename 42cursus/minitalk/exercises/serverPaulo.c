#include <unistd.h>
#include <signal.h>

static void	putnbr(long nb)
{
	char	digit;

	if (nb >= 10)
		putnbr(nb / 10);
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}

static void	bit_handler(int sig, siginfo_t *info, void *unused)
{
	static char	c = 0;
	static int	i = 0;

	(void)unused;
	if (sig == SIGUSR1)
		c += (1 << i);
	if (++i == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &c, 1);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	write (1, "Server PID: ", 12);
	putnbr(getpid());
	write (1, "\n", 1);
	sa.sa_sigaction = bit_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
