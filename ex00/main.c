/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/07 17:22:14 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void    ft_wait(volatile uint32_t val)
{
    while(val-- != 0);                  //27 cycle mcu
}

int main()
{
    SET(DDR_B , 0);
    while (1)
    {
        ft_wait(296296);               
        TOGGLE(PORT_B, 0);
    }

    /*
        F_CPU = 16 000 000Hz
        0,5s  = 8 000 000Hz
        1 loop = 27 cycles (cf. Datasheet p.)
        8 000 000 / 27 = 296 296
        296 296 loop = 0.5s;
    */
}