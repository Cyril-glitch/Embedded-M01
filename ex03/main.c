/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycolonn <cycolonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:52:29 by cycolonn          #+#    #+#             */
/*   Updated: 2026/10/08 18:35:30 by cycolonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main()
{
     /*
        OCR = Output Compare Register
        COM = Compare Output MOde
        ICR = Input Capture Register
        TCCR = Timer counter control
    */

    SET(DDR_B, 1);                                // set ddr on output mode

    OCR1A = HZ1 / DUTYCYCLE;                      // set Compare match register value

    ICR1 = HZ1;                                   // set timer TOP value

    SET(TCCR1A, COM1A1);                          // clear OC1A on compare match and set it on BOTTOM (cf p.140)

    SET(TCCR1B, CS12);                            // set the prescaler using clock select bits (cf p.143)

    SET(TCCR1A, WGM11);                           // set the waveform generation on mode 14 (PWM) (cf p.142)
    SET(TCCR1B, WGM12);                            
    SET(TCCR1B, WGM13);                            

    volatile uint8_t duty_cycle = DUTYCYCLE;
    while (1)
    {
        increase_duty(&duty_cycle);
        decrease_duty(&duty_cycle);
        OCR1A = HZ1 / duty_cycle;
        _delay_ms(20);
    }; 
   
}