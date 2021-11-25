/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:28:41 by dpiza             #+#    #+#             */
/*   Updated: 2021/11/24 23:39:18 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
/*
** Common definition
*/
# define INT_MIN			-2147483648
# define TRUE				1
# define STDIN				0
/*
** INT_QSORT is the minimum size to use quick sort algo
*/
# define MIN_QSORT			50
/*
** Interval sizes based on stack size
** BIG_INTERVAL for over BIG_INTERVAL_LEN size
** SMALL_INTERVAL for under that
*/
# define SMALL_INTERVAL		22
# define BIG_INTERVAL		40
# define BIG_INTERVAL_LEN	150

#endif