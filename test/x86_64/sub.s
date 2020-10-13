;
; sub.s
; x86_64 sub instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 13/10/2020
;

sub rax, rax
sub r8, r8
sub rax, r8
sub r8, rax
sub rax, 0x2000004
sub rdi, 1
sub rsi, r8
sub rdx, 1
sub r8, 0x2000
sub byte [rel rax], 0
sub byte [rel r8], 40

