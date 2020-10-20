;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; stack.s
; MOS 6502 compare, load and store to X/Y instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 20/10/2020
;

cpx #$ff
cpx $ff
cpx $ffaa

cpy #$ff
cpy $ff
cpy $ffaa

ldx #$ff
ldx $ff
ldx $ff, y
ldx $ffaa
ldx $ffaa, y

ldy #$ff
ldy $ff
ldy $ff, x
ldy $ffaa
ldy $ffaa, x

stx $ff
stx $ff, y
stx $ffaa

sty $ff
sty $ff, x
sty $ffaa

