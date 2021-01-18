#include "ft_printf.h"

int ft_len_unint(unsigned int i)
{
	int len;

	len = 0;
	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

int print_0s(int *flag, char *cp, int l, int n)
{
	int r;

	r = 0;
	if (n == 1)
		while (r < (flag[3] - l))
			r += write(1, "0", 1);
	else if (n == 2)
		while (r < (flag[2] - l))
			r += write(1, "0", 1);
	else if (n == 3)
		while (r < (flag[2] - l))
			r += write(1, " ", 1);
	else if (n == 4)
	{
		while (r < l)
			r += write(1, " ", 1);
		return (r);
	}
	r += ft_putstr(cp);
	return (r);
}

int flags_w(int *flag, char *cp, int l)
{
	int r;
	int i;

	r = 0;
	i = 0;
	if (flag[0] == 1)
		r += print_0s(flag, cp, l, 2);
	else if (flag[1] == 1)
	{
		r += ft_putstr(cp);
		while (i < (flag[2] - l))
			i += write(1, " ", 1);
		r += i;
	}
	else
		r += print_0s(flag, cp, l, 3);
	return (r);
}

int flags23(int *flag, char *cp, int l)
{
	int r;
	int i;

	r = 0;
	i = 0;
	if (flag[2] < flag[3])
		r += print_0s(flag, cp, l, 1);
	else
	{
		if (flag[1] == 1)
		{
			r += print_0s(flag, cp, l, 1);
			while (i < (flag[2] - flag[3]))
				i += write(1, " ", 1);
			r += i;
		}
		else
		{
			if (flag[3] <= l)
				r += print_0s(flag, cp, l, 3);
			else
			{
				r += print_0s(flag, cp, flag[2] - flag[3], 4);
				r += print_0s(flag, cp, l, 1);
			}
		}
	}
	return (r);
}

int	ft_print_unsigned(va_list ap, int *flag)
{
	unsigned int arg;
	int l;
	int r;
	char *cp;

	r = 0;
	arg = va_arg(ap, unsigned int);
	if (!arg)
		return (0);
	l = ft_len_unint(arg);
	cp = ft_itoa(arg);
	if (flag[2] > 0 && flag[3] > 0)
		r += flags23(flag, cp, l);
	else if (flag[2] > 0)
		r += flags_w(flag, cp, l);
	else if (flag[3] > 0)
		r += print_0s(flag, cp, l, 1);
	else
		r += ft_putstr(cp);
	return (r);
}