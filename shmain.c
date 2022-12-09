/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukeles <mukeles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 02:01:50 by mukeles           #+#    #+#             */
/*   Updated: 2022/12/09 13:50:07 by mukeles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_shell.h"
//halloldu
int main(int argc, char **argv, char **env)
{
  t_builtin_str *str;

  str = malloc(sizeof(t_builtin_str));
  if (!str)
		return (-1);
  str->builtin_str = malloc(sizeof(char) * 999);
  if (!str->builtin_str)
		return (-1);
  
  if (!str)
    return (0);
  init(str);

  g_env = get_new_env(env);

  lsh_loop(str);
  
  free(str->builtin_str);
  free(str);
  free(g_env);
  return EXIT_SUCCESS;
}
