#include "mini_shell.h"

void ctrl_d(void)
{
	printf("Exit");
	exit(1);
}

void ctrl_c(int sig)
{
	(void)sig;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	return;
}

void sig_handler_heredoc(int sig_num)
{
	if (sig_num == SIGINT)
		exit(1);
}
static void	restore_prompt(int sig)
{
	g_list.exit_status = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

static void	back_slash(int sig)
{
	g_list.exit_status = 131;
	ft_putnstr("Quit (core dumped)\n", 1);
	(void)sig;
}
void	run_signals(int sig)
{
	if (sig == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (sig == 2)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, back_slash);
	}
	if (sig == 3)
	{
		printf(RED
			"You terminated the program with exit signal!\n");
		exit(0);
	}
}