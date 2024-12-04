; This program is intended to calculate the fibonnaci sequence, where the result
; is the sum of the last 2 numbers in the sequence.
; for example if we start from 0:
; 0 1 1 2 3 5 8 13 21 (and so on)
;
; Like last time, read the code and there are lab exercises at the bottom of this
; file to try!

section .data
    ; Define a variable to hold the user input
    user_input dd 0

    ; Define variables to store the results
    fibonacci_result dd 0

section .text
    global _start

_start:
    ; Prompt the user for input
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt
    mov edx, prompt_len
    int 0x80

    ; Read user input
    mov eax, 3
    mov ebx, 0
    mov ecx, user_input
    mov edx, 4
    int 0x80

    ; Convert the string to an integer
    mov eax, user_input
    call str_to_int
    mov [user_input], eax

    ; Calculate the Fibonacci sequence using recursion
    mov eax, [user_input]
    call calculate_fibonacci
    mov [fibonacci_result], eax

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

; Subroutine to calculate the Fibonacci sequence using recursion
calculate_fibonacci:
    ; Check if the input is 0 or 1 (base cases)
    cmp eax, 0
    je .base_case
    cmp eax, 1
    je .base_case

    ; Recursive case: Calculate F(n-1) and F(n-2)
    push eax                ; Save the current value of n on the stack
    dec eax                 ; Calculate F(n-1)
    call calculate_fibonacci ; Recursive call
    pop ebx                 ; Restore the original value of n from the stack

    push eax                ; Save the result of F(n-1) on the stack
    sub ebx, 2              ; Calculate F(n-2)
    call calculate_fibonacci ; Recursive call
    pop eax                 ; Restore the result of F(n-1) from the stack

    ; Add F(n-1) and F(n-2)
    add eax, ebx
    ret

.base_case:
    ; Base cases: F(0) = 0, F(1) = 1
    mov eax, 1
    ret

; Subroutine to convert a string to an integer
str_to_int:
    xor eax, eax      ; Clear eax to store the result
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
    prompt db "Enter a number to calculate its Fibonacci value: ", 0
    prompt_len equ $ - prompt
    result_msg db "Fibonacci Value: ", 0
    result_msg_len equ $ - result_msg

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; The below labs will require research and effort!
;
; LAB 1
;
; There is a bug in the calculation of the Fibonacci sequence. Trace the code 
; and identify the issue, then fix it to ensure the correct calculation.
;
; LAB 2
;
; Modify the program to have a comparison statement to check if the user input is 
; negative. If the input is negative, display an error message. If the input is 
; non-negative, proceed with the Fibonacci calculation.
