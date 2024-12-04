; The following code sample is an example of calculating the sum of numbers up 
; to a given input. The example uses a recursive approach and includes conditionals 
; to check for the base case to reinforce knowledge from the previous lesson. This 
; code sample also makes use of the stack, and provides the learner with a new 
; opportunity to understand how it works.
;
; As always, lab exercises are found at the bottom of this file.

section .data
    ; Define a variable to hold the user input
    user_input dd 0

    ; Define variables to store the results
    sum_result dd 0

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

    ; Calculate the sum using recursion
    mov eax, [user_input]
    call calculate_sum
    mov [sum_result], eax

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

; Subroutine to calculate the sum using recursion
calculate_sum:
    ; Check if the input is 0 (base case)
    cmp eax, 0
    je .base_case

    ; Recursive case: Calculate sum(n-1)
    dec eax                  ; Decrement n
    push eax                 ; Save the current value of n on the stack
    call calculate_sum      ; Recursive call
    pop eax                  ; Restore the original value of n from the stack

    ; Add n to the result of sum(n-1)
    add eax, [rsp]           ; Add n to the value on top of the stack
    ret

.base_case:
    ; Base case: return 0
    mov eax, 0
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
    prompt db "Enter a number to calculate the sum: ", 0
    prompt_len equ $ - prompt
    result_msg db "Sum: ", 0
    result_msg_len equ $ - result_msg

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; The following lab exercises are similar to the last labs, but the above code
; makes this more challenging.
;
; LAB 1
; 
; There is a bug in the calculation of the sum. Identify this issue and fix it
; to ensure the correct calculation.
;
; LAB 2
;
; Modify the program to add a conditional statement inside the calculate_sum
; subroutine to check if the user input is negative. If the input is negative,
; display an error message. If the input is non-negative, proceed with the sum
; calculation.
