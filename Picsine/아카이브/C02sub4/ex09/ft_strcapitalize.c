/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:43:57 by sehyan            #+#    #+#             */
/*   Updated: 2020/11/27 01:31:39 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (i == 0 || !(str[i - 1] >= 48 && str[i - 1] <= 57) ||
					!(str[i - 1] >= 65 && str[i - 1] <= 90) ||
					!(str[i - 1] >= 97 && str[i - 1] <= 122))
				str[i] -= 32;
		}
		if (str[i] >= 65 && str[i] <= 90 && i != 0)
		{
			if ((str[i - 1] >= 48 && str[i - 1] <= 57) ||
					(str[i - 1] >= 65 && str[i - 1] <= 90) ||
					(str[i - 1] >= 97 && str[i - 1] <= 122))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
