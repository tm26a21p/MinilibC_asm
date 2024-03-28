BITS 64
SECTION .text
%ifdef UNIT_TEST
GLOBAL my_strchr
my_strchr:
%else 
GLOBAL strchr
strchr:
%endif

    push rbp
    mov rbp, rsp
    mov rax, rdi
    cmp rsi, 0
    je loop_x
    jmp loop

loop_x:
    cmp[rax], byte 0
    je end
    inc rax
    jmp loop_x

loop:
    cmp[rax], byte 0
    je not_found
    cmp [rax], byte sil 
    je end 
    inc rax
    jmp loop  

end:
    leave
    ret 

not_found:
    mov rax, 0
    leave
    ret
