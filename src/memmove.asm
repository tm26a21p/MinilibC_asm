BITS 64
SECTION .text
%ifdef UNIT_TEST
GLOBAL my_memmove
my_memmove:
%else
GLOBAL memmove
memmove:
%endif


    xor rax, rax
    mov rax, rdi
    xor r8, r8
    mov r9, rsi

loop:
    cmp rdx, 0
    je end
    xor r9b, r9b
    ; mov r9b, []
    dec rdx
    jmp loop

end:
    ret
