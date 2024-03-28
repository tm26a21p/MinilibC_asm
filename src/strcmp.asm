BITS 64
SECTION .text
%ifdef UNIT_TEST
GLOBAL my_strcmp
my_strcmp:
%else
GLOBAL strcmp
strcmp:
%endif

xor r8, r8
xor rax, rax

loop:
    xor r9b, r9b
    xor r10b, r10b
    mov r9b, [rdi + r8]
    mov r10b, [rsi + r8]
    cmp r9b, 0
    je end
    cmp r10b, 0
    je end
    cmp r9b, r10b
    jne end
    inc r8
    jmp loop

end:
    mov al, r9b
    sub al, r10b
    movsx rax, al
    ret
