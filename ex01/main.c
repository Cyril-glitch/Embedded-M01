/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/07 20:18:00 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
    SET(DDR_B, 1);                                //set ddr on output mode
    OCR1A =((F_CPU / PRESCALER) - 1) / 2;         //timer comparation (cf p.132)
    SET(TCCR1A, 6);                               //set COM1A0 on 1 (cf p.140) (Compare match)
    SET(TCCR1B, 3);                               //set WGM12 on 1 (cf p.142) (CTC mode)
}