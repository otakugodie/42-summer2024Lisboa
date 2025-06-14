# include <errno.h>
# include <signal.h>

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>

void receive_len(int sig, int *len_received, char **str, siginfo_t *info)
{
	static int i = 32;
	static int res = 0;

	--i;
	if (sig == SIGUSR2)
		res |= 1 << i;
	if (i == 0)
	{
		*str = malloc(res + 1);
		(*str)[res] = '\0';
		*len_received = 1;
		i = 32;
		res = 0;
	}
	kill(info->si_pid, SIGUSR1);
	return;
}

void handle_end(char **str, int *str_i, int *len_received, siginfo_t *info)
{
	printf("%s\n", (*str));
	kill(info->si_pid, SIGUSR2);
	free((*str));
	*str = NULL;
	*str_i = 0;
	*len_received = 0;
}

void sig_handler(int sig, siginfo_t *info, void *context)
{
	static char ch;
	static int i = 8;
	static int len_received;
	static char *str = NULL;
	static int str_i = 0;

	(void)context;
	if (!len_received)
		receive_len(sig, &len_received, &str, info);
	else
	{
		--i;
		if (sig == SIGUSR2)
			ch |= 1 << i;
		if (i == 0)
		{
			str[str_i++] = ch;
			if (ch == '\0')
				return (handle_end(&str, &str_i, &len_received, info),
						len_received = 0, ch = 0, i = 8, (void)i);
			ch = 0;
			i = 8;
		}
		kill(info->si_pid, SIGUSR1);
	}
}

int main(void)
{
	int pid;
	struct sigaction action;

	pid = getpid();
	printf("PID: %d\n", pid);
	action.sa_sigaction = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
