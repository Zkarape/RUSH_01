/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 23:37:28 by zkarapet          #+#    #+#             */
/*   Updated: 2022/10/06 19:56:18 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_double(int arr[4][4], int pos, int floor)
{
	int	i;

	i = -1;
	while (++i < pos / 4)
		if (arr[i][pos % 4] == floor)
			return (1);
	i = -1;
	while (++i < pos % 4)
		if (arr[pos / 4][i] == floor)
			return (1);
	return (0);
}

int	check_col_up(int arr[4][4], int pos, int input[16])
{
	int	i;
	int	maxFloor;
	int	viewCount;

	i = 0;
	maxFloor = 0;
	viewCount = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (arr[i][pos % 4] > maxFloor)
			{
				maxFloor = arr[i][pos % 4];
				viewCount++;
			}
			i++;
		}
		if (input[pos % 4] != viewCount)
			return (0);
	}
	return (1);
}

int	check_row_right(int arr[4][4], int pos, int input[16])
{
	int	i;
	int	maxFloor;
	int	visible_towers;

	i = 4;
	maxFloor = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (--i >= 0)
		{
			if (arr[pos / 4][i] > maxFloor)
			{
				maxFloor = arr[pos / 4][i];
				visible_towers++;
			}
		}
		if (input[12 + pos / 4] != visible_towers)
			return (0);
	}
	return (1);
}

int	check_col_down(int arr[4][4], int pos, int input[16])
{
	int	i;
	int	maxFloor;
	int	viewCount;

	i = 3;
	maxFloor = 0;
	viewCount = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (arr[i][pos % 4] > maxFloor)
			{
				maxFloor = arr[i][pos % 4];
				viewCount++;
			}
			i--;
		}
		if (input[4 + pos % 4] != viewCount)
			return (0);
	}
	return (1);
}

int	check_row_left(int arr[4][4], int pos, int input[16])
{
	int	i;
	int	maxFloor;
	int	viewCount;

	i = 0;
	maxFloor = 0;
	viewCount = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (arr[pos / 4][i] > maxFloor)
			{
				maxFloor = arr[pos / 4][i];
				viewCount++;
			}
			i++;
		}
		if (input[8 + pos / 4] != viewCount)
			return (0);
	}
	return (1);
}

int	check_case(int arr[4][4], int pos, int input[16])
{
	if (check_row_left(arr, pos, input) == 0)
		return (0);
	if (check_row_right(arr, pos, input) == 0)
		return (0);
	if (check_col_down(arr, pos, input) == 0)
		return (0);
	if (check_col_up(arr, pos, input) == 0)
		return (0);
	return (1);
}
