;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; shift.s
; MOS 6502 shift instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 22/10/2020
;

asl a
asl $50
asl $50, x
asl $50ff
asl $50ff, x

lsr a
lsr $50
lsr $50, x
lsr $50ff
lsr $50ff, x

rol a
rol $50
rol $50, x
rol $50ff
rol $50ff, x

ror a
ror $50
ror $50, x
ror $50ff
ror $50ff, x

