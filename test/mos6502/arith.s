;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; arith.s
; MOS 6502 arithmetic instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 16/10/2020
;

adc #$50
adc $50
adc $50, x
adc $50ff
adc $50ff, x
adc $50ff, y
adc ($50, x)
adc ($50), y

sbc #$50
sbc $50
sbc $50, x
sbc $50ff
sbc $50ff, x
sbc $50ff, y
sbc ($50, x)
sbc ($50), y

