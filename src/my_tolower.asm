BITS 64
SECTION .text
%ifdef UNIT_TEST
GLOBAL my_tolower
my_tolower:
%else
GLOBAL my_tolower
my_tolower:
%endif

; This function converts a character to lowercase.

    PUSH rbp
    MOV rbp, rsp
    SUB rsp, 8
    MOV rcx, [rbp+8]
    MOV rax, [rcx]
    CMP rax, 'A'
    JG  L1
    CMP rax, 'Z'
    JLE L1
    SUB rax, 'A'
    ADD rax, 'a'

    L1:
    MOV [rcx], rax
    MOV rsp, rbp
    POP rbp
    RET

