BITS 64
SECTION .text
%ifdef UNIT_TEST
GLOBAL my_memcpy
my_memcpy:
%else
GLOBAL memcpy
memcpy:
%endif

    mov rax, rdi
    xor r8, r8
    mov r10, rsi
loop:
    cmp rdx, 0
    je end
    xor r9b, r9b
    mov r9b, [r10 + r8]
    mov [rax + r8], r9b
    ; inc r10
    inc r8
    dec rdx
    jmp loop

end:
    ret
