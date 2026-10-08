/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/08 15:11:48 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
    SET(DDR_B, 1);                                // set ddr on output mode
    OCR1A =((F_CPU / PRESCALER) / 2) - 1;         // timer comparation (cf p.132)
    SET(TCCR1A, COM1A0);                          // set toggle OC1A on Compare match (cf.140)
    SET(TCCR1B, WGM12);                           // (CTC mode) clear on compare match (cf p.141)
    SET(TCCR1B, CS12);                            // set the prescaler using clock select bits (cf p.143)

    while (1); 
}