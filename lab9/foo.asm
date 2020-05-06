
.data
L0:	.asciiz	","
L1:	.asciiz	","
L2:	.asciiz	"false"
NL:	.asciiz	"\n"

.align 2
y:	 .space	4
z:	 .space	4

.text
main:				#start of function
		subu $a0, $sp, 52		#adjust stack for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		
		li $a0, 5		#expression is a number

		sw $a0, 20($sp)		#move RHS into temp reg
		add $a0, $sp, 8		#ID is scaler
				
		lw $t0, 20($sp)		#do some fancy shit
		sw $t0, ($a0)		#more fancy
		add $a0, $sp, 8		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L0		#write a string
		syscall		
		li $a0, 6		#expression is a number

		sw $a0, 24($sp)		#store LHS in temp
		li $a0, 2		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 24($sp)		#load LHS for relop
		div $a0, $t0		#div
		mflo $a0		#grab result
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L1		#write a string
		syscall		
		add $a0, $sp, 8		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 28($sp)		#store LHS in temp
		li $a0, 5		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 28($sp)		#load LHS for relop
		seq $a0, $a0, $t0		#!=
		sltiu $a0, $a0, 1		#inverse
		li $t0, 0		#sets $t0 to 0
		beq $a0, $0, L3		#positive condition
		li $a0, 7		#expression is a number

		li $v0 1		
		syscall		
		j L4		#positive done, jump out of conditional
L3:				#negative
		li $v0 4		
		la $a0, L2		#write a string
		syscall		
L4:				#done
L5:				#loop
		add $a0, $sp, 8		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 32($sp)		#store LHS in temp
		li $a0, 1		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 32($sp)		#load LHS for relop
		sgt $a0, $a0, $t0		#>
		beq $a0, $0, L6		#positive condition
		add $a0, $sp, 8		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 36($sp)		#store LHS in temp
		li $a0, 1		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 36($sp)		#load LHS for relop
		sub $a0, $a0, $t0		#subtraction
		sw $a0, 40($sp)		#move RHS into temp reg
		add $a0, $sp, 8		#ID is scaler
				
		lw $t0, 40($sp)		#do some fancy shit
		sw $t0, ($a0)		#more fancy
		j L5		#check if condition is still true, if yes, loop again
L6:				#another DO
		add $a0, $sp, 8		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $a0, 1		#expression is a number

		sw $a0, 44($sp)		#move RHS into temp reg
		add $a0, $sp, 16		#ID is scaler
				
		lw $t0, 44($sp)		#do some fancy shit
		sw $t0, ($a0)		#more fancy
		add $a0, $sp, 16		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		add $a0, $sp, 16		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 48($sp)		#store LHS in temp
		lw $a0, 48($sp)		#load LHS for relop
		sltiu $a0, $a0, 1		#not
		sw $a0, 48($sp)		#move RHS into temp reg
		add $a0, $sp, 16		#ID is scaler
				
		lw $t0, 48($sp)		#do some fancy shit
		sw $t0, ($a0)		#more fancy
		add $a0, $sp, 16		#ID is scaler
				
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		lw $ra, 4($sp)		#restore ra
		lw $sp, ($sp)		#restore sp
		li $v0, 10		#leave main
		syscall		#terminate main
