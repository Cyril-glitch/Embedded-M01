	.file	"main.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	ft_wait
	.type	ft_wait, @function
ft_wait:
	push r28
	push r29
	rcall .
	rcall .
	in r28,__SP_L__
	in r29,__SP_H__
/* prologue: function */
/* frame size = 4 */
/* stack size = 6 */
.L__stack_usage = 6
	std Y+1,r22
	std Y+2,r23
	std Y+3,r24
	std Y+4,r25
.L2:
	ldd r24,Y+1
	ldd r25,Y+2
	ldd r26,Y+3
	ldd r27,Y+4
	movw r20,r24
	movw r22,r26
	subi r20,1
	sbc r21,__zero_reg__
	sbc r22,__zero_reg__
	sbc r23,__zero_reg__
	std Y+1,r20
	std Y+2,r21
	std Y+3,r22
	std Y+4,r23
	or r24,r25
	or r24,r26
	or r24,r27
	brne .L2
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.size	ft_wait, .-ft_wait
	.section	.text.startup,"ax",@progbits
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	sbi 0x4,0
	ldi r28,lo8(1)
.L5:
	ldi r22,lo8(104)
	ldi r23,lo8(-123)
	ldi r24,lo8(4)
	ldi r25,0
	call ft_wait
	in r24,0x5
	eor r24,r28
	out 0x5,r24
	rjmp .L5
	.size	main, .-main
	.ident	"GCC: (Fedora 15.2.0-1.fc44) 15.2.0"
