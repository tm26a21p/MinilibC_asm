BITS 64
SECTION .text
%ifdef UNIT_TEST
extern my_strlen
GLOBAL my_strrchr
my_strrchr:
%else
extern strlen
GLOBAL strrchr
strrchr:
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

found:
    xor r8, r8
    mov r8, rax
    inc r8
    cmp[r8], byte sil
    jne end
    mov rax, r8

loop:
    cmp[rax], byte 0
    je not_found
    cmp [rax], byte sil 
    je found
    inc rax
    jmp loop  

end:
    leave
    ret 

not_found:
    mov rax, 0
    leave
    ret
