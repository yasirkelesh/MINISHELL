/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 02:01:50 by mukeles           #+#    #+#             */
/*   Updated: 2022/12/02 16:08:54 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"

int main(int argc, char **argv, char **env)
{
  t_builtin_str *str;

  str = malloc(sizeof(t_builtin_str));
  str->builtin_str = malloc(sizeof(char) * 999);
  if (!str)
    return (0);
  init(str);

  g_env = get_new_env(env);

  lsh_loop(str);
  return EXIT_SUCCESS;
}
