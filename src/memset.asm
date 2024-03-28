BITS 64
SECTION .text
%ifdef UNIT_TEST
GLOBAL my_memset
my_memset:
%else
GLOBAL memset
memset:
%endif

        mov rax, rdi
        xor r8, r8
loop:
        cmp rdx, 0
        je end
        mov [rax + r8], rsi
        inc r8
        dec rdx
        jmp loop

end:
        ret
