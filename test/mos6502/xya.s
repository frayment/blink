;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; xya.s
; MOS 6502 compare, load and store to X/Y/A instruction test
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

cpx #$ff
cpx $ff
cpx $ffaa

cpy #$ff
cpy $ff
cpy $ffaa

lda #$ff
lda $ff
lda $ff, x
lda $ffaa
lda $ffaa, x
lda ($ff, x)
lda ($ff), y

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

sta $ff
sta $ff, x
sta $ffaa
sta $ffaa, x
sta ($ff, x)
sta ($ff), y

stx $ff
stx $ff, y
stx $ffaa

sty $ff
sty $ff, x
sty $ffaa

