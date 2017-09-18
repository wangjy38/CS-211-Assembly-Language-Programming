.globl nCr
        .type   nCr, @function
nCr:
  # Your code for nCr should go here
        movl    0x04(%esp), %eax #eax = n
        movl    0x08(%esp), %ebx #ebx = r
        movl    %eax, %ecx       #ecx = n
        subl    %ebx, %eax       #eax = n-r 
        pushl   %eax
        pushl   %ecx
        call    Factorial        #compute n!
        popl    %ecx             #pop the last tuple which is n
        
        movl    %eax, %ecx       #ecx = n!
        cmp     $0,%ecx          #detect OF
	je      .Return0
        pushl   %ebx             #prepare to compute r! 
        
        call    Factorial        #compute r!
        
        popl    %ebx             #pop the last tuple which is r 
        movl    %eax, %ebx       #ebx = r!
        call    Factorial        #compute (n-r)!
        imul    %ebx, %eax       #eax = eax * ebx = r! * (n-r)!
        movl    $0, %edx         #edx = 0
        movl    %eax, %ebx       #ebx = r! * (n-r)!
        movl    %ecx, %eax       #eax = n!
        div     %ebx             #eax = eax/ebx 
        popl    %ebx             #pop the last tuple which is n-r 
        ret                      #return eax 
.Return0:
        popl %ebx
        ret 

.globl Factorial
        .type   Factorial, @function
Factorial:
  # Your code for Factorial should go here
       
        movl    0x04(%esp), %edx #ecx = n
        movl    $1, %eax         #eax = 1 

.loop:
        cmp     $0, %edx         # compare c with 0
        je      .exit0           # if equal to 0 then quit loop 
        imul    %edx, %eax       # eax = eax * ecx = 1 * n (1st run)
        jo      .return0         # detect OF 
        dec     %edx             # ecx = ecx--
        jmp     .loop

.exit0:
       ret
.return0:
        movl $0,%eax 
        ret 
       
