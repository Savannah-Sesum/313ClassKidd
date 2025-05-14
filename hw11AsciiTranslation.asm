; Converting hex to ASCII in NASM - HW #11 - 313 10am Mon/Wed - Savannah Sesum UMBC
section .data
    inputBuf: db 0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A ; setting up array of hex values for input

section .bss
    outputBuf: resb 25 ; reserve 25 bytes in the outputBuf array, including whitespaces and newline

section .text
    global _start ; initiate special _start label

_start:
    xor esi, esi ; initialize the source index (inputBuf's) by xor itself
    xor edi, edi ; initialize the destination index (outputBuf's) by xor itself

.loop:
    cmp esi, 8 ; process all 8 hexes, each a byte
    jge .print ; if >= 8, go to print subroutine
    mov al, byte [inputBuf + esi] ; use the lower al register and insert [inputbuf + ESI] (processing by 1 byte and al is 1 byte)
    and al, 0xF0 ; mask by using 0xF0 to get only the value on the left only
    shr al, 4 ; shift right by 4 bits to put the leftover value in the correct place value
    call convertToAscii
    mov byte [outputBuf + edi], al ; store the updated al into the outputBuf
    inc edi

    mov al, byte [inputBuf + esi] ; grab the same hexadecimal used previously
    inc esi ; increment the esi pointer for the next inputBuf traversal
    and al, 0x0F ; mask by using 0x0F to get only the value on the right only
    call convertToAscii ; call global function
    mov byte [outputBuf + edi], al ; store the updated al into the outputBuf
    inc edi
    mov byte [outputBuf + edi], ' ' ; store a whitespace between each ASCII pair for printing purposes
    inc edi
    jmp .loop ; loop again

.print:
    mov byte [outputBuf + edi], 0Ah ; put newline at the end of outputBuf array
    mov ebx, 1 ; write to the STDOUT file
    mov ecx, outputBuf ; the message to write
    mov eax, 4 ; SYS_WRITE the opcode 4
    mov edx, 25 ; memory for each ASCII character + whitespaces + newline
    int 80h
    call .exit ; finish up

.exit:
    mov ebx, 0 ; returns status of 0 on exit
    mov eax, 1 ; SYS_EXIT the opcode 1
    int 80h

convertToAscii:
    cmp al, 9 ; compare to 9 to see if the binary value is above or below 9
    jbe .zeroToNine ; go to that local function because it's 0-9
    jmp .tenToFifteen ; immediately go to function because it's automatically 10-15
    ret ; return to loop

.zeroToNine:
    add al, 0x30 ; add 0x30 to get the specific ASCII conversion since 0-9
    ret ; return to convertToAscii

.tenToFifteen:
    add al, 0x37 ; add 0x37 to get the specific ASCII conversion since 10-15
    ret ; return to convertToAscii