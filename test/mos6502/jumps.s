;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; jump.s
; MOS 6502 compare, jump and return instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 20/10/2020
;

cmp #$5
cmp $5
cmp $5, x
cmp $ffaa
cmp $ffaa, x
cmp $ffaa, y
cmp ($5, x)
cmp ($5), y

jmp $ffaa
jmp ($ffaa)

jsr $ffaa

rti

rts

