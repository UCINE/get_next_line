/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahamoun <lahamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 02:09:17 by lahamoun          #+#    #+#             */
/*   Updated: 2022/11/20 05:45:11 by lahamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*search(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
#endif