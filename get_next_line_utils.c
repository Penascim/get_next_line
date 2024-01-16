/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: penascim <penascim@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:42:43 by penascim          #+#    #+#             */
/*   Updated: 2024/01/10 20:18:49 by penascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*newstr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char			*temps;
	int				i;
	unsigned char	tempc;

	temps = (char *)s;
	i = 0;
	tempc = (unsigned char)c;
	while (temps[i] != '\0')
	{
		if (temps[i] == tempc)
			return ((char *)&s[i]);
		i++;
	}
	if ((!c))
		return (&temps[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*stemp;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	stemp = (char *)malloc(sizeof(char) * len + 1);
	if (!stemp)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && i < len)
		stemp[i++] = s[start++];
	stemp[i] = '\0';
	return (stemp);
}

char	*ft_strdup(const char *src)
{
	char			*src2;
	char			*new_str;
	char			*pointer;
	unsigned int	count;

	src2 = (char *)src;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	count = ft_strlen(src);
	if (!new_str)
		return (NULL);
	pointer = new_str;
	while (count--)
	{
		*new_str++ = *src2++;
	}
	*new_str = '\0';
	return (pointer);
}
