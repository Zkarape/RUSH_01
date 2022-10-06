/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:47:18 by zkarapet          #+#    #+#             */
/*   Updated: 2022/10/06 19:55:15 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_double(int tab[4][4], int pos, int num);
int	check_case(int tab[4][4], int pos, int entry[16]);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
int	check(int ac, char **av);
void	ft_putstr(char *str);
int	*get_numbers(char *str);

int	solve(int arr[4][4], int input[16], int pos)
{
	int	floor;

	floor = 0;
	if (pos == 16 )
		return (1);
	while (++floor <= 4)
	{
		if (check_double(arr, pos, floor) == 0)
		{
			arr[pos / 4][pos % 4] = floor;
			if (check_case(arr, pos, input) == 1)
			{
				if (solve(arr, input, pos + 1) == 1)
					return (1);
			}
			else
				arr[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

void	print_solution(int arr[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(arr[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int arc, char *arv[])
{
	int	*input;
	int	arr[4][4] = {
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
	};
	if (check(arc, arv) == 1)
		return (0);
	input = get_numbers(arv[1]);
	if (solve(arr, input, 0) == 1)
		print_solution(arr);
	else
		ft_putstr("Did not find any solutions\n");
	return (0);
}
