;
; This file is licensed under BSD 3-Clause.
; All license information is available in the included COPYING file.
;

;
; bitwise.s
; MOS 6502 bitwise instruction test
;
; Author       : Finn Rayment <finn@rayment.fr>
; Date created : 16/10/2020
;

and #$50
and $50
and $50, x
and $50ff
and $50ff, x
and $50ff, y
and ($50, x)
and ($50), y

eor #$50
eor $50
eor $50, x
eor $50ff
eor $50ff, x
eor $50ff, y
eor ($50, x)
eor ($50), y

ora #$50
ora $50
ora $50, x
ora $50ff
ora $50ff, x
ora $50ff, y
ora ($50, x)
ora ($50), y

