;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; jump.s
; MOS 6502 jump and return instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 20/10/2020
;

jmp $ffaa
jmp ($ffaa)

jsr $ffaa

rti

rts

