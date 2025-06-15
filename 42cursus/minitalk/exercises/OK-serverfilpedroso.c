# include <signal.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define END -1
# define MID_BYTE -2

static void	handler(int sig, siginfo_t *s_info, void *context);
void		check_kill(int pid, int sig);

int	ft_putstr_fd(char *s, int fd)
{
	size_t	buffer;

	if (!s)
		return (0);
	buffer = strlen(s);
	write(fd, s, buffer);
	return ((int)buffer);
}

static void	handler(int sig, siginfo_t *s_info, void *context)
{
	static unsigned char	byte;
	static int				index;
	static int				pid;

	(void)context;
	if (s_info->si_pid)
		pid = s_info->si_pid;
	byte |= (sig == SIGUSR1);
	index++;
	if (index == 8)
	{
		if (byte == '\0')
		{
			write(1, "\n", 1);
			check_kill(pid, SIGUSR1);
		}
		else
			write(1, &byte, 1);
		index = 0;
		byte = 0;
	}
	else
		byte = byte << 1;
	check_kill(pid, SIGUSR2);
}

void	check_kill(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("kill failed !\n", 2);
		printf("kill failed ! PID: %i SIG: %i\n", pid, sig);
		exit(1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) < 0 || sigaction(SIGUSR2, &sa, NULL) < 0)
	{
		ft_putstr_fd("sigaction failed !\n", 2);
		exit(1);
	}
	printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
