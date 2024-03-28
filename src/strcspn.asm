BITS 64
SECTION .text
%ifdef UNIT_TEST
GLOBAL my_strcspn
my_strcspn:
%else
GLOBAL strcspn
strcspn:
%endif

xor rax, rax

check:
    cmp [r10], byte 0
    je loop
    xor r9b, r9b
    mov r9b, [r10]
    cmp [rdi + rax], r9b
    je end
    inc r10
    jmp check

loop:
    xor r10, r10
    mov r10, rsi
    cmp [rdi + rax], byte 0
    je end
    inc rax
    jmp check

end:
    ret
