BITS 64
SECTION .text
%ifdef UNIT_TEST
GLOBAL my_strlen
my_strlen:
%else
GLOBAL strlen
strlen:
%endif

    xor rax, rax
    cmp rdi, 0
    je end

loop:
    cmp [rdi + rax], byte 0
    je end
    inc rax
    jmp loop

end:
    ret
