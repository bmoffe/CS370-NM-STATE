
.data
L0:	.asciiz	"\n"
L1:	.asciiz	"Math operations testing: plus minus multiplication division"
L2:	.asciiz	"\n"
L3:	.asciiz	"6+2 & 6-2 & 6*2 & 6/2"
L4:	.asciiz	"\n"
L5:	.asciiz	"\n"
L6:	.asciiz	"\n"
L7:	.asciiz	"\n"
L8:	.asciiz	"\n"
L9:	.asciiz	"Enter a number. Enter number greater than or equal to 5 to test positive condition, and number less than 5 to test false condition."
L10:	.asciiz	"\n"
L14:	.asciiz	"\n"
L18:	.asciiz	"Original boolean value before testing 'not' operator: "
L19:	.asciiz	"\n"
L20:	.asciiz	"Testing 'not' operation; expected value is 0: "
L21:	.asciiz	"\n"
L22:	.asciiz	"\n"
L23:	.asciiz	"Testing 'and' operation; expected value is 0: "
L24:	.asciiz	"\n"
L25:	.asciiz	"Testing 'or' operation; expected value is 1: "
L26:	.asciiz	"\n"
L15:	.asciiz	"Value at index "
L16:	.asciiz	": "
L17:	.asciiz	"\n"
L11:	.asciiz	"Test passed for true condition."
L12:	.asciiz	"\n"
L13:	.asciiz	"Test passed for false condition."
NL:	.asciiz	"\n"

.align 2
y:	 .space	4
whatdoicallthis:	 .space	40
z:	 .space	4

.text
main:				#start of function
		subu $a0, $sp, 104		#adjust stack for function setup
		sw $sp, ($a0)		
		sw $ra, 4($a0)		
		move $sp, $a0		
		li $a0, 10		#expression is a number

		sw $a0, 40($sp)		#move RHS into temp reg
				
		add $a0, $sp, 8		#ID is scaler
		lw $t0, 40($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
				
		add $a0, $sp, 8		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L0		#write a string
		syscall		
		li $v0 4		
		la $a0, L1		#write a string
		syscall		
		li $v0 4		
		la $a0, L2		#write a string
		syscall		
		li $v0 4		
		la $a0, L3		#write a string
		syscall		
		li $v0 4		
		la $a0, L4		#write a string
		syscall		
		li $a0, 6		#expression is a number

		sw $a0, 44($sp)		#store LHS in temp
		li $a0, 2		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 44($sp)		#load LHS for relop
		add $a0, $a0, $t0		#add
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L5		#write a string
		syscall		
		li $a0, 6		#expression is a number

		sw $a0, 48($sp)		#store LHS in temp
		li $a0, 2		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 48($sp)		#load LHS for relop
		sub $a0, $a0, $t0		#subtraction
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L6		#write a string
		syscall		
		li $a0, 6		#expression is a number

		sw $a0, 52($sp)		#store LHS in temp
		li $a0, 2		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 52($sp)		#load LHS for relop
		mult $a0, $t0		#multi
		mflo $a0		#grab product
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L7		#write a string
		syscall		
		li $a0, 6		#expression is a number

		sw $a0, 56($sp)		#store LHS in temp
		li $a0, 2		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 56($sp)		#load LHS for relop
		div $a0, $t0		#div
		mflo $a0		#grab result
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L8		#write a string
		syscall		
		li $v0 4		
		la $a0, L9		#write a string
		syscall		
		li $v0 4		
		la $a0, L10		#write a string
		syscall		
				
		add $a0, $sp, 12		#ID is scaler
		li $v0, 5		
		syscall		
		sw $v0, ($a0)		#store read into new location
		li $a0, 0		#expression is a number

		sw $a0, 60($sp)		#move RHS into temp reg
				
		add $a0, $sp, 16		#ID is scaler
		lw $t0, 60($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
				
		add $a0, $sp, 12		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 64($sp)		#store LHS in temp
		li $a0, 5		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 64($sp)		#load LHS for relop
		sge $a0, $a0, $t0		#>=
		li $t0, 0		#sets $t0 to 0
		beq $a0, $0, L27		#positive condition
		li $v0 4		
		la $a0, L11		#write a string
		syscall		
		li $v0 4		
		la $a0, L12		#write a string
		syscall		
		j L28		#positive done, jump out of conditional
L27:				#negative
		li $v0 4		
		la $a0, L13		#write a string
		syscall		
L28:				#done
		li $v0 4		
		la $a0, L14		#write a string
		syscall		
L29:				#loop
				
		add $a0, $sp, 8		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 68($sp)		#store LHS in temp
		li $a0, 0		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 68($sp)		#load LHS for relop
		sgt $a0, $a0, $t0		#>
		beq $a0, $0, L30		#positive condition
		li $v0 4		
		la $a0, L15		#write a string
		syscall		
				
		add $a0, $sp, 16		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L16		#write a string
		syscall		
				
		add $a0, $sp, 8		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 72($sp)		#store LHS in temp
		li $a0, 1		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 72($sp)		#load LHS for relop
		sub $a0, $a0, $t0		#subtraction
		sw $a0, 76($sp)		#move RHS into temp reg
				
		add $a0, $sp, 8		#ID is scaler
		lw $t0, 76($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
				
		add $a0, $sp, 8		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 80($sp)		#move RHS into temp reg
				
				
		add $a0, $sp, 16		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sll $t0, $a0, 2		
		la $a0, whatdoicallthis		#ID is global array
		add $a0, $a0, $t0		
		lw $t0, 80($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
				
				
		add $a0, $sp, 16		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sll $t0, $a0, 2		
		la $a0, whatdoicallthis		#ID is global array
		add $a0, $a0, $t0		
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L17		#write a string
		syscall		
				
		add $a0, $sp, 16		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 84($sp)		#store LHS in temp
		li $a0, 1		#expression is a number

		move $t0, $a0		#move RHS to temp reg
		lw $a0, 84($sp)		#load LHS for relop
		add $a0, $a0, $t0		#add
		sw $a0, 88($sp)		#move RHS into temp reg
				
		add $a0, $sp, 16		#ID is scaler
		lw $t0, 88($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
		j L29		#check if condition is still true, if yes, loop again
L30:				#another DO
		li $a0, 1		#expression is a number

		sw $a0, 72($sp)		#move RHS into temp reg
				
		add $a0, $sp, 20		#ID is scaler
		lw $t0, 72($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
		li $v0 4		
		la $a0, L18		#write a string
		syscall		
				
		add $a0, $sp, 20		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L19		#write a string
		syscall		
		li $v0 4		
		la $a0, L20		#write a string
		syscall		
				
		add $a0, $sp, 20		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 76($sp)		#store LHS in temp
		lw $a0, 76($sp)		#load LHS for relop
		sltiu $a0, $a0, 1		#not
		sw $a0, 76($sp)		#move RHS into temp reg
				
		add $a0, $sp, 20		#ID is scaler
		lw $t0, 76($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
				
		add $a0, $sp, 20		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L21		#write a string
		syscall		
		li $a0, 1		#expression is a number

		sw $a0, 80($sp)		#move RHS into temp reg
				
		add $a0, $sp, 28		#ID is scaler
		lw $t0, 80($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
		li $a0, 0		#expression is a number

		sw $a0, 84($sp)		#move RHS into temp reg
				
		add $a0, $sp, 24		#ID is scaler
		lw $t0, 84($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
		li $v0 4		
		la $a0, L22		#write a string
		syscall		
		li $v0 4		
		la $a0, L23		#write a string
		syscall		
				
		add $a0, $sp, 28		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 88($sp)		#store LHS in temp
				
		add $a0, $sp, 24		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		move $t0, $a0		#move RHS to temp reg
		lw $a0, 88($sp)		#load LHS for relop
		and $a0, $t0, $a0		#and
		sw $a0, 92($sp)		#move RHS into temp reg
				
		add $a0, $sp, 32		#ID is scaler
		lw $t0, 92($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
				
		add $a0, $sp, 32		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L24		#write a string
		syscall		
		li $v0 4		
		la $a0, L25		#write a string
		syscall		
				
		add $a0, $sp, 28		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		sw $a0, 96($sp)		#store LHS in temp
				
		add $a0, $sp, 24		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		move $t0, $a0		#move RHS to temp reg
		lw $a0, 96($sp)		#load LHS for relop
		or $a0, $t0, $a0		#or
		sw $a0, 100($sp)		#move RHS into temp reg
				
		add $a0, $sp, 36		#ID is scaler
		lw $t0, 100($sp)		#do some fancy
		sw $t0, ($a0)		#more fancy
				
		add $a0, $sp, 36		#ID is scaler
		lw $a0, ($a0)		#fetch val for ID
		li $v0 1		
		syscall		
		li $v0 4		
		la $a0, L26		#write a string
		syscall		
		lw $ra, 4($sp)		#restore ra
		lw $sp, ($sp)		#restore sp
		li $v0, 10		#leave main
		syscall		#terminate main
