/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joloo <joloo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 11:08:17 by joloo             #+#    #+#             */
/*   Updated: 2025/09/10 11:51:58 by joloo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*routine(void *arg)
{
	int a = *(int *)arg;
	int i = 0;
	while (i < 5000)
	{
		printf("num:%d,%d\n", a, a);
		fflush(stdout);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	int count = 25;
	pthread_t tid[count];
	int i = 0;
	int args[count];
	while (i < count)
	{
		args[i] = i;
		pthread_create(&tid[i], NULL, routine, &args[i]);
		i++;
	}
	i = 0;
	while (i < count)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	printf("DONE");
}
