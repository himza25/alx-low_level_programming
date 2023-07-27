section .data
    hello db 'Hello, Holberton', 0xa, 0

section .text
    global main
    extern printf

main:
    ; prepare arguments for printf
    mov rdi, hello
    xor rax, rax
    ; call printf
    call printf
    ; exit
    mov eax, 0x60
    xor edi, edi
    syscall
