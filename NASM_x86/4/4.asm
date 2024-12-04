; This ASM program demonstrates reading and writing to files on Linux. This
; program is designed to read integers from an input file (named input.txt),
; multiply them by 2, and write them to an output file (named output.txt).
;
; Lab exercises can be found at the bottom of this file.

section .data
    ; Define variables for file descriptors
    in_file dd 0
    out_file dd 0

    ; Define buffer for reading and writing
    buffer resb 10

    ; Define variables for file operations
    read_bytes dd 0
    write_bytes dd 0

section .text
    global _start

_start:
    ; Open the input file
    mov eax, 5                  ; sys_open system call number
    mov ebx, input_file_name    ; pointer to the input file name
    mov ecx, 0                  ; O_RDONLY mode
    int 0x80                    ; invoke system call to open the file
    mov [in_file], eax          ; store the file descriptor

    ; Check if the file opened successfully
    cmp eax, 0
    jl .file_error

    ; Open the output file
    mov eax, 5                  ; sys_open system call number
    mov ebx, output_file_name   ; pointer to the output file name
    mov ecx, 0x42               ; O_WRONLY | O_CREAT | O_TRUNC mode
    mov edx, 0666               ; file permissions
    int 0x80                    ; invoke system call to open the file
    mov [out_file], eax         ; store the file descriptor

    ; Check if the file opened successfully
    cmp eax, 0
    jl .file_error

    ; Read from the input file and write to the output file
    call read_and_write

    ; Close the files
    mov eax, 6                  ; sys_close system call number
    mov ebx, [in_file]          ; file descriptor of the input file
    int 0x80                    ; invoke system call to close the file

    mov eax, 6
    mov ebx, [out_file]
    int 0x80

    ; Exit the program
    mov eax, 1                  ; sys_exit system call number
    xor ebx, ebx                ; exit code 0
    int 0x80                    ; invoke system call to exit the program

read_and_write:
    ; Read from the input file and write to the output file
    ; Loop until there are no more bytes to read
read_loop:
    mov eax, 3                  ; sys_read system call number
    mov ebx, [in_file]          ; file descriptor of the input file
    mov ecx, buffer             ; pointer to the buffer for reading
    mov edx, 10                 ; number of bytes to read
    int 0x80                    ; invoke system call to read from the file
    mov [read_bytes], eax       ; store the number of bytes read

    ; Check if we've reached the end of the file
    cmp eax, 0
    jle .read_done

    ; Process the data in the buffer
    call process_data

    ; Write to the output file
    mov eax, 4                  ; sys_write system call number
    mov ebx, [out_file]         ; file descriptor of the output file
    mov ecx, buffer             ; pointer to the buffer for writing
    mov edx, [read_bytes]       ; number of bytes to write
    int 0x80                    ; invoke system call to write to the file
    mov [write_bytes], eax      ; store the number of bytes written

    jmp read_loop

.read_done:
    ret

process_data:
    ; Process the data in the buffer (multiply each integer by 2)
    ; (This part would be completed by the learner)
    ; Example: Multiply each integer in the buffer by 2
    ; ...
    ; The incomplete exercise will guide the learner on implementing the data processing.

.file_error:
    ; Display an error message if there was an issue with file operations
    mov eax, 4
    mov ebx, 1
    mov ecx, file_error_msg
    mov edx, file_error_msg_len
    int 0x80

    ; Exit the program
    mov eax, 1
    xor ebx, ebx
    int 0x80

section .data
    input_file_name db "input.txt", 0
    output_file_name db "output.txt", 0
    file_error_msg db "Error with file operations.", 0
    file_error_msg_len equ $ - file_error_msg

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; LAB EXERCISES- Don't forget to research as you solve these!
;
; LAB 1
;
; The process_data subroutine is incomplete. Implement the missing part to
; multiply each integer in the buffer by 2.
;
; LAB 2
;
; Modify the program to handle the case where the input file is empty. If the
; input file is empty, display an appropriate error message and exit the program
; without attempting to read or write to the files.
