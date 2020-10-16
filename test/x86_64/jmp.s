;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; jmp.s
; x86_64 jmp instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 16/10/2020
;

; these offsets are not valid in real assembler, they represent label offsets

jmp -2
jmp 2
jmp -255
jmp 255

jne -2
jne 2
jne 255
jne -255

