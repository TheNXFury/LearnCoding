;This is a simple NASM assembly program that is intended to calculate the sum of 
;two numbers. Comments are extensively used to explain each part of the code.
;at the end, there are 2 lab exercises.

section .data
    ; Define two variables to hold the numbers
    num1 dd 0
    num2 dd 0
    ; Define a variable to store the result
    result dd 0

section .text
    global _start

_start:
    ; Prompt the user for input
    mov eax, 4 ; eax, ebx, ecx, edx, and so forth are registers. eax is 32 bit while ax is 16 bit.
    mov ebx, 1  ; ah and al stand for register a, higher or lower 16 bits. 
    mov ecx, prompt
    mov edx, prompt_len
    int 0x80 ; On x86_64 Linux and UNIX based devices, 0x80 is the system call.
    ; a chart for available system calls for your OS can be found online.

    ; Read the first number
    mov eax, 3       ; sys_read system call
    mov ebx, 0       ; file descriptor 0 (stdin)
    mov ecx, num1    ; buffer to store the input
    mov edx, 4       ; number of bytes to read
    int 0x80

    ; Convert the string to an integer
    mov eax, num1
    call str_to_int
    mov [num1], eax  ; store the integer value back in num1

    ; Prompt the user for the second number
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt2
    mov edx, prompt2_len
    int 0x80

    ; Read the second number
    mov eax, 3
    mov ebx, 0
    mov ecx, num2
    mov edx, 4
    int 0x80

    ; Convert the string to an integer
    mov eax, num2
    call str_to_int
    mov [num2], eax  ; store the integer value back in num2

    ; Calculate the sum
    mov eax, [num1]
    add rax, [num2]
    mov [result], eax

    ; Display the result
    mov eax, 4
    mov ebx, 1
    mov ecx, result_msg
    mov edx, result_msg_len
    int 0x80

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80

; Subroutine to convert a string to an integer
str_to_int:
    xor eax, eax      ; Clear eax to store the result because xor'ing the same val == 0
    xor ebx, ebx      ; Clear ebx for index
.next_digit:
    movzx edx, byte [eax] ; Load the next byte of the string into edx
    cmp edx, 10      ; Check if it's the null terminator (end of string)
    je .done         ; If it is, we are done
    sub edx, '0'     ; Convert ASCII character to integer ('0' -> 0, '1' -> 1, etc.)
    imul eax, 10      ; Multiply the current result by 10
    add eax, edx      ; Add the new digit to the result
    inc ebx          ; Move to the next character in the string
    jmp .next_digit  ; Repeat the process for the next character
.done:
    ret

section .data
    prompt db "Enter the first number: ", 0
    prompt_len equ $ - prompt
    prompt2 db "Enter the second number: ", 0
    prompt2_len equ $ - prompt2
    result_msg db "The sum is: ", 0
    result_msg_len equ $ - result_msg


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; the below labs are challenging and will require research!

; LAB 1

; Currently, the program does not display the correct sum. Find and fix the bug
; to make the program display the correct result. This trains basic debugging and
; reverse engineering skills.


; LAB 2

; Modify the code to calculate and display both the sum and the product of the 
; two numbers entered by the user. This trains your ability to modify already
; existing binaries at such a low level.
