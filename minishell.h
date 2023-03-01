/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:16:39 by smayrand          #+#    #+#             */
/*   Updated: 2023/03/01 02:34:15 by smayrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./lib/readline.h"
# include <readline/readline.h>
# include "./lib/history.h"
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "./lib/rlconf.h"
# include "./lib/rlstdc.h"
# include "./lib/libft/libft.h"

//═══════𖠁 Structures 𖠁════════//
typedef struct s_cmd
{
	char	**save;
	char	**token;
	char	*buffer;
	int		open_error;
	int		token_nb;
	int		fd;
	int		fdt;
	int		i;
}					t_cmd;

typedef struct s_shell
{
	char	*buffer;
	t_cmd	*cmd;
	pid_t	*pid;
	char	heredoc[2];
	char	expand[2];
	int		cmd_nb;
	int		error;

}					t_shell;

//═══════𖠁 Functions 𖠁════════//
int			empty_token(char *buf);

void		sig_break(int signal);
void		signal_checker(int signal);
void		heredoc_maker(char *limiter, char *heredoc);

char		*exp_hrdc_s(t_shell *shell, char *heredoc);

void		sig_on(void);
void		sig_off(void);
void		ft_clear_fd(void);
void		mini_env(int flag);
void		mini_echo(char **arg);
void		mini_unset(char *buffer);
void		free_cmd(t_shell *shell);
void		export_err(t_shell *shell);
void		token_parser(t_shell *shell);
void		heredoc_unlink(t_shell *shell);
void		exec_cmd(t_shell *shell, int nb);
void		mini_execve(t_shell *shell, int nb);
void		mini_cd(t_shell *shell, char *buffer);
void		mini_parser_unset(t_shell *shell, int nb);
void		mini_parser_export(t_shell *shell, int nb);
void		token_cleaner(t_shell *shell, char **token);
void		heredoc_parser(t_shell *shell, char **token);
void		ft_exit(t_shell *shell, char *msg, int errno);
void		mini_export(t_shell *shell, char *arg, int flag);

int			check_pipe(char *buf);
int			quote_check(char *buf);
int			mini_parser(t_shell *shell);
int			check_buf_int(t_shell *shell);
int			mini_open_fd(char *str, int i);
int			token_counter(char *buffer, char sep);
int			mini_open(t_cmd *cmd, char *str, int i);
int			redirection_finder(t_shell *shell, int nb);

char		*rm_char(char *token, char sep);
char		*get_var(char *buffer, int flag);
char		*ft_strtok(char *buffer, char sep);
char		*token_trimmer(char *token, char sep);
int			ft_execute_solo(t_shell *shell, int nb);

bool		char_checker(char *buf, char c);

#endif