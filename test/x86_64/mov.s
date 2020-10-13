;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; mov.s
; x86_64 mov instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 13/10/2020
;

mov rax, rax
mov r8, r8
mov rax, r8
mov r8, rax
mov rax, 0x2000004
mov rdi, 1
mov rsi, r8
mov rdx, 1
mov r8, 0x2000
mov byte [rel rax], 0
mov byte [rel r8], 40

