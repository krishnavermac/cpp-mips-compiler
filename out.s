.text
.globl main

main:
    addi $sp,$sp,-8
    sw $ra,4($sp)
    sw $fp,0($sp)
    addi $fp,$sp,8

    li $t0,5
    sw $t0,-4($fp)
    li $t1,2
    sw $t1,-8($fp)
    lw $t0,-4($fp)
    lw $t1,-8($fp)
    mul $t2,$t0,$t1
    li $t3,3
    add $v0,$t2,$t3
    move $a0,$v0
    li $v0,1
    syscall

    li $v0,10
    syscall

