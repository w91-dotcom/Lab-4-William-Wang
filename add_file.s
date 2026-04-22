    .text
    .globl sum_array

sum_array:
    xorl %eax, %eax          # sum = 0
    xorl %ecx, %ecx          # i = 0

loop_start:
    cmpq %rsi, %rcx          # compare i with n
    jge done                 # if i >= n, stop

    addl (%rdi,%rcx,4), %eax # sum += arr[i]
    incq %rcx                # i++
    jmp loop_start

done:
    ret
    