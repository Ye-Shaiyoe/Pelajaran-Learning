; hitung.asm - x86-64 NASM, Linux
; Menghitung jumlah 1..100 dan faktorial 10, lalu mencetak hasilnya

section .data
    judul       db "Belajar Assembly basic x86_64", 10
    judul_len   equ $ - judul
    pesan1      db "Jumlah 1 sampai 100 = "
    pesan1_len  equ $ - pesan1
    pesan2      db "Faktorial 10        = "
    pesan2_len  equ $ - pesan2
    newline     db 10

section .bss
    buffer      resb 32             ; tempat string angka

section .text
    global _start

_start:
    ; cetak judul
    mov rsi, judul
    mov rdx, judul_len
    call print_str

    ; ---- jumlah 1..100 ----
    mov rsi, pesan1
    mov rdx, pesan1_len
    call print_str

    xor rax, rax                    
    mov rcx, 1                      
.sum_loop:
    add rax, rcx                    
    inc rcx                         
    cmp rcx, 100
    jle .sum_loop                   

    call print_num
    call print_nl

    mov rsi, pesan2
    mov rdx, pesan2_len
    call print_str

    mov rax, 1                      
    mov rcx, 2                     
.fact_loop:
    imul rax, rcx                  
    inc rcx
    cmp rcx, 10
    jle .fact_loop

    call print_num
    call print_nl

    mov rax, 60
    xor rdi, rdi
    syscall

print_str:
    mov rax, 1                      
    mov rdi, 1
    syscall
    ret

print_nl:
    mov rsi, newline
    mov rdx, 1
    jmp print_str                   

print_num:
    mov rdi, buffer + 31            
    mov rbx, 10                     
    xor r8, r8                   
.convert:
    xor rdx, rdx                
    div rbx                        
    add dl, '0'                   
    dec rdi
    mov [rdi], dl                  
    inc r8
    test rax, rax
    jnz .convert                   

    mov rsi, rdi                        
    mov rdx, r8            
    call print_str
    ret