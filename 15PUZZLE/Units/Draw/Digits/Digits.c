; input:
;   AX - color index
proc Draw.DrawZero\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 13, 17, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 24, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawOne\
     X, Y
     stdcall Draw.DrawVertical, 15, 20, 12, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawTwo\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 8, 24, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 19, [X], [Y]
     stdcall Draw.DrawVertical, 5, 17, 20, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawThree\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 19, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     stdcall Draw.DrawVertical, 14, 24, 13, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawFour\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 19, [X], [Y]
     stdcall Draw.DrawVertical, 14, 24, 12, [X], [Y]
     stdcall Draw.DrawVertical, 8, 17, 12, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawFive\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 8, 17, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 19, [X], [Y]
     stdcall Draw.DrawVertical, 5, 24, 20, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawSix\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 17, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 19, [X], [Y]
     stdcall Draw.DrawVertical, 5, 24, 20, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawSeven\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 14, 24, 12, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawEight\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 17, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 19, [X], [Y]
     stdcall Draw.DrawVertical, 15, 24, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawNine\
     X, Y
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 7, 17, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 19, [X], [Y]
     stdcall Draw.DrawVertical, 15, 24, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawTen uses cx,\
     X, Y
     mov     cx, [X]
     add     cx, 4
     mov     [X], cx
     stdcall Draw.DrawZero, [X], [Y]
     mov     cx, [X]
     sub     cx, 9
     mov     [X], cx
     stdcall Draw.DrawOne, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawEleven uses cx,\
     X, Y
     mov     cx, [X]
     add     cx, 4
     mov     [X], cx
     stdcall Draw.DrawOne, [X], [Y]
     mov     cx, [X]
     sub     cx, 8
     mov     [bp + 4], cx
     stdcall Draw.DrawOne, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawTwelve uses cx,\
     X, Y
     mov     cx, [X]
     add     cx, 4
     mov     [X], cx
     stdcall Draw.DrawTwo, [X], [Y]
     mov     cx, [X]
     sub     cx, 9
     mov     [X], cx
     stdcall Draw.DrawOne, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawThirteen uses cx,\
     X, Y
     mov     cx, [X]
     add     cx, 4
     mov     [X], cx
     stdcall Draw.DrawThree, [X], [Y]
     mov     cx, [X]
     sub     cx, 9
     mov     [X], cx
     stdcall Draw.DrawOne, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawFourteen uses cx,\
     X, Y
     mov     cx, [X]
     add     cx, 4
     mov     [X], cx
     stdcall Draw.DrawFour, [X], [Y]
     mov     cx, [X]
     sub     cx, 9
     mov     [X], cx
     stdcall Draw.DrawOne, [X], [Y]
     ret
endp

; input:
;   AX - color index
proc Draw.DrawFiveteen uses cx,\
     X, Y
     mov     cx, [X]
     add     cx, 4
     mov     [X], cx
     stdcall Draw.DrawFive, [X], [Y]
     mov     cx, [X]
     sub     cx, 9
     mov     [X], cx
     stdcall Draw.DrawOne, [X], [Y]
     ret
endp

proc Draw.DrawHorizontal uses bx cx dx,\
     Len, MarginY, X, Y
     locals
        MarginX    dw    16
     endl
     stdcall Draw.CreateHorCoords, [X], [Y], [MarginX], [MarginY], [Len]
     stdcall Draw.DrawLine, cx, bx, dx, bx
     ret
endp

; return
;    bx, cx, dx
proc Draw.CreateHorCoords\
     X1, Y1, XMargin, YMargin, Len
     mov     cx, [X1]
     mov     bx, [Y1]
     add     cx, [XMargin]
     add     bx, [YMargin]
     mov     dx, cx
     add     dx, [Len]
     ret
endp

proc Draw.DrawVertical uses cx bx dx,\
     Len, MarginX, MarginY, X, Y
     stdcall Draw.CreateVerCoords, [X], [Y], [MarginX], [MarginY], [Len]
     stdcall Draw.DrawLine, cx, bx, cx, dx
     ret
endp

proc Draw.CreateVerCoords\
     X1, Y1, XMargin, YMargin, Len
     mov cx, [X1]
     mov bx, [Y1]
     add cx, [XMargin]
     add bx, [YMargin]
     mov dx, bx
     add dx, [Len]
     ret
endp