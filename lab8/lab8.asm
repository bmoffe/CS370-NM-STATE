 #Brianna Moffett
 #CS370
 #lab8.asm
 #04.20.20
      #  this program calculates the sum of squares up to and including whatever variable the user feeds in
           
        
  .data #global variables
  L1: .asciiz "Please enter value: "
  L2: .asciiz "The number read was "
  L3:  .asciiz "The square is "
  NL:  .asciiz "\n"
        .align 0
str:
        .asciiz "The sum from 0 .. "
str1:
	.asciiz " is"
 .text  # directive that we are in the code segment

main:
        subu $a0, $sp, 20 # We want 4 mem locations for main SP, RA, i , s
        sw $ra, 4($a0)  # we need to store the RA in the Activation record
        sw $sp, ($a0) # store SP
        move $sp, $a0  # adjust SP

        sw $0, 8($sp)  # store 0 into memory -- counting variable 
        sw $0, 12($sp)  # store 0 into memory -- accumulating variable
        
        #Prints the prompt2 string
	li $v0, 4
	la $a0, L1
	syscall 

	#reads one integer from user and saves in t0
	li $v0, 5
	#addu $t0, $sp, 8   #$t0 is the memory location for our variable
	syscall
	sw $v0 16($sp)
 
       
loop:
        lw $t6, 8($sp)  #   
        mul $t7, $t6, $t6  #  i * i
        lw $t8, 12($sp)   #  s
        addu $t9, $t8, $t7  #  s + i*i
        sw $t9, 12($sp)  #   s= s + i*i 
        lw $t6, 8($sp)   # i 
        addu $t0, $t6, 1  # i+1
        sw $t0, 8($sp)  #  i = i + 1
        lw $t1, 16($sp) #$t1 stores user input var, we use this to determine how many times we loop
        ble $t0, $t1, loop  #   keep doing it n times (where n is user input var)
        nop   # 
        
        la $a0, str
        li $v0 4  #   print the first string
        syscall # 
        nop   # 
        
        li $v0, 1 
	lw $a0, 16($sp) #print user input number 
	syscall           
        
        la $a0, str1
        li $v0 4  #   print the second string
        syscall # 
        nop   #
        
        li $v0, 4   #  these 3 lines do a new line
	la $a0, NL
	syscall 
        
        lw $a0, 12($sp)
        li $v0 1 #   Print the number
        syscall
        
       
        lw $ra, 4($sp)
        lw $sp , ($sp)  # put backl Ra and SP
        
        li $v0, 10 
        syscall     #  exit for MAIN only

        
