;
; add.s
; x86_64 add instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 13/10/2020
;

add rax, rax
add r8, r8
add rax, r8
add r8, rax
add rax, 0x2000004
add rdi, 1
add rsi, r8
add rdx, 1
add r8, 0x2000
add byte [rel rax], 0
add byte [rel r8], 40

