proc Draw.DrawDot uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawVertical, 11, 21, 12, [X], [Y]
     stdcall Draw.DrawVertical, 2, 21, 25, [X], [Y]
     ret
endp

proc Draw.DrawX uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawVertical, 2, 17, 12, [X], [Y]
     stdcall Draw.DrawVertical, 2, 18, 14, [X], [Y]
     stdcall Draw.DrawVertical, 2, 19, 16, [X], [Y]
     stdcall Draw.DrawVertical, 3, 20, 18, [X], [Y]
     stdcall Draw.DrawVertical, 2, 21, 21, [X], [Y]
     stdcall Draw.DrawVertical, 2, 22, 23, [X], [Y]
     stdcall Draw.DrawVertical, 2, 23, 25, [X], [Y]
     stdcall Draw.DrawVertical, 2, 23, 12, [X], [Y]
     stdcall Draw.DrawVertical, 2, 22, 14, [X], [Y]
     stdcall Draw.DrawVertical, 2, 21, 16, [X], [Y]
     stdcall Draw.DrawVertical, 3, 20, 18, [X], [Y]
     stdcall Draw.DrawVertical, 2, 19, 21, [X], [Y]
     stdcall Draw.DrawVertical, 2, 18, 23, [X], [Y]
     stdcall Draw.DrawVertical, 2, 17, 25, [X], [Y]
     ret
endp

proc Draw.DrawZ\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 7, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 7, 25, [X], [Y]
     stdcall Draw.DrawVertical, 2, 23, 12, [X], [Y]
     stdcall Draw.DrawVertical, 2, 22, 14, [X], [Y]
     stdcall Draw.DrawVertical, 2, 21, 16, [X], [Y]
     stdcall Draw.DrawVertical, 3, 20, 18, [X], [Y]
     stdcall Draw.DrawVertical, 2, 19, 21, [X], [Y]
     stdcall Draw.DrawVertical, 2, 18, 23, [X], [Y]
     stdcall Draw.DrawVertical, 2, 17, 25, [X], [Y]
     ret
endp

proc Draw.DrawR uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 7, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 7, 18, [X], [Y]
     stdcall Draw.DrawVertical, 15, 17, 12, [X], [Y]
     stdcall Draw.DrawVertical, 7, 22, 12, [X], [Y]
     stdcall Draw.DrawVertical, 1, 18, 20, [X], [Y]
     stdcall Draw.DrawVertical, 1, 19, 21, [X], [Y]
     stdcall Draw.DrawVertical, 3, 20, 22, [X], [Y]
     stdcall Draw.DrawVertical, 1, 21, 25, [X], [Y]
     stdcall Draw.DrawVertical, 1, 22, 26, [X], [Y]
     ret
endp

proc Draw.DrawN uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawVertical, 15, 17, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 23, 12, [X], [Y]
     stdcall Draw.DrawVertical, 3, 18, 12, [X], [Y]
     stdcall Draw.DrawVertical, 3, 19, 15, [X], [Y]
     stdcall Draw.DrawVertical, 3, 20, 18, [X], [Y]
     stdcall Draw.DrawVertical, 3, 21, 21, [X], [Y]
     stdcall Draw.DrawVertical, 3, 22, 24, [X], [Y]
     ret
endp

proc Draw.DrawI uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 8, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 8, 25, [X], [Y]
     stdcall Draw.DrawVertical, 15, 20, 12, [X], [Y]
     ret
endp

proc Draw.DrawA uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 10, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 10, 18, [X], [Y]
     stdcall Draw.DrawVertical, 15, 17, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 25, 12, [X], [Y]
     ret
endp

proc Draw.DrawS uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 18, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 7, 17, 12, [X], [Y]
     stdcall Draw.DrawVertical, 7, 24, 19, [X], [Y]
     ret
endp

proc Draw.DrawU uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     stdcall Draw.DrawVertical, 15, 17, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 24, 12, [X], [Y]
     ret
endp

proc Draw.DrawT uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 10, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 21, 12, [X], [Y]
     ret
endp

proc Draw.DrawE uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 7, 25, [X], [Y]
     stdcall Draw.DrawHorizontal, 7, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 7, 18, [X], [Y]
     stdcall Draw.DrawVertical, 15, 16, 12, [X], [Y]
     ret
endp

proc Draw.DrawL uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 7, 25, [X], [Y]
     stdcall Draw.DrawVertical, 15, 16, 12, [X], [Y ]
     ret
endp


proc Draw.DrawP uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 7, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 8, 18, [X], [Y]
     stdcall Draw.DrawVertical, 15, 16, 12, [X], [Y]
     stdcall Draw.DrawVertical, 7, 23, 12, [X], [Y]
     ret
endp


proc Draw.DrawM uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 11, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 16, 12, [X], [Y]
     stdcall Draw.DrawVertical, 7, 22, 12, [X], [Y]
     stdcall Draw.DrawVertical, 15, 28, 12, [X], [Y]
     ret
endp

proc Draw.DrawO uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 13, 17, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     stdcall Draw.DrawVertical, 15, 25, 12, [X], [Y]
     ret
endp

proc Draw.DrawC uses ax,\
     X, Y, Color
     mov     ax, [Color]
     stdcall Draw.DrawHorizontal, 9, 12, [X], [Y]
     stdcall Draw.DrawVertical, 13, 17, 12, [X], [Y]
     stdcall Draw.DrawHorizontal, 9, 25, [X], [Y]
     ret
endp