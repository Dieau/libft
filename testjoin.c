/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhdar <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:28:08 by alakhdar          #+#    #+#             */
/*   Updated: 2021/11/04 15:14:15 by alakhdar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char	*dest, char	*src)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

int	total_len(char	**strs, int size)
{
	int	i;
	int	total;

	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i]);
		i++;
	}
	total += 1;
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*buffer;
	int		test;

	j = 0;
	i = 0;
	if (size == 0)
		return (NULL);
	test = total_len(strs, size) + ft_strlen(sep) * (size - 1);
	buffer = (char *)malloc(test * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < (total_len(strs, size) + (ft_strlen(sep) * (size - 1))))
		buffer[i++] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(buffer, strs[i]);
		if (i < size - 1 )
			ft_strcat(buffer, sep);
		i++;
	}
	return (buffer);
}
