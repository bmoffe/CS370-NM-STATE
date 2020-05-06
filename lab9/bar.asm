
.data
NL:	.asciiz	"\n"

.align 2

.text
main		:		#start of function
				subu $a0, $sp, 8
				sw $sp, ($a0)
				sw $ra, 4($a0)
				move $sp, $a0
				move $a0, 7
				li $v0 1
				syscall
				lw $ra, 4($sp)
				lw $sp, ($sp)
				li $v0, 10
				syscall
