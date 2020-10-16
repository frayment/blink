;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; xor.s
; x86_64 xor instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 16/10/2020
;

xor rax, rax
xor rdx, rdx
xor rax, r8
xor r8, rax
xor r8, r8

xor eax, eax
xor edx, edx
xor eax, r8d
xor r8d, eax
xor r8d, r8d

