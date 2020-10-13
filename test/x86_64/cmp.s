;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; cmp.s
; x86_64 cmp instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 13/10/2020
;

cmp r8, 0
cmp rax, 0
cmp rdx, 0
cmp byte [rel r8], 0
cmp byte [rel rax], 0
cmp byte [rel rdx], 0

