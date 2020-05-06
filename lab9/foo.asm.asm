
.data
NL:	.asciiz	"\n"

.align 2

.text
main		:		#start of function
		subu $a0, $sp, 12		#adjust stack for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		
		add $a0, $s0, 8		#ID is scaler
				
		li $v0, 5		
		syscall		
		sw $v0, ($a0)		#store read into new location
		add $a0, $s0, 8		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		lw $ra, 4($sp)		#restore ra
		lw $sp, ($sp)		
		li $v0, 10		#leave main
		syscall		#terminate main
