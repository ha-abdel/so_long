#include "so_long.h"

int	countspace(long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count++;
		return (count);
	}
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count * 2);
}

char	*ft_rev(char *arr, int sign)
{
	int		i;
	int		len;
	char	swap;

	len = ft_strlen(arr);
	i = sign;
	len = len - 1;
	while (i < len)
	{
		swap = arr[len];
		arr[len] = arr[i];
		arr[i] = swap;
		i++;
		len--;
	}
	return (arr);
}

char	*checknbr(long nb, char *arr, int *sign)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		arr[i++] = '-';
		*sign = 1;
		nb = -nb;
	}
	if (nb == 0)
	{
		arr[0] = '0';
		arr[1] = '\0';
		return (arr);
	}
	while (nb > 0)
	{
		arr[i++] = nb % 10 + '0';
		arr[i++] = ' ';
		nb = nb / 10;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	char *arr;
	long nb;
	int sign;

	nb = n;
	sign = 0;
	arr = malloc(countspace(nb) + 1);
	if (!arr)
		return (NULL);
	arr = checknbr(nb, arr, &sign);
	return (ft_rev(arr, sign));
}