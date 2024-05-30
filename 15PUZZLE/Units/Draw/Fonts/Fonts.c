proc Draw.DrawFinishScreen\
     isComplete
     stdcall  Draw.DrawFont
     cmp      [isComplete], 1
     jne      .GameOverFont
.CompleteFont:
     stdcall  Draw.DrawFinishTitle, 97, 20
     stdcall  Draw.DrawExitButton, 120, 80, [clText], [clButton]
     stdcall  Draw.DrawRestartButton, 120, 110, [clText], [clButton]
     jmp      .exit
.GameOverFont:
     stdcall  Draw.DrawResumeTitle, 117, 20
     stdcall  Draw.DrawExitButton, 120, 80, [clText], [clButton]
     stdcall  Draw.DrawReturnButton, 120, 110, [clText], [clButton]
.exit:
     ret
endp

proc Draw.DrawRestartButton uses cx bx,\
     X, Y, FontColor, ButtonColor
     mov     ax, [FontColor]
     stdcall Draw.DrawSquare, [X], [Y], [aLenButton], [bLenButton]
     mov     ax, [ButtonColor]
     inc     [X]
     inc     [Y]
     mov     cx, [bLenButton]
     sub     cx, 2
     mov     bx, [aLenButton]
     sub     bx, 2
     stdcall Draw.DrawSquare, [X], [Y], bx, cx
     sub     [X], 13
     sub     [Y], 7
     stdcall Draw.DrawRestartTitle, [X], [Y], 79
     ret
endp

proc Draw.DrawReturnButton uses cx bx,\
     X, Y, FontColor, ButtonColor
     mov     ax, [FontColor]
     stdcall Draw.DrawSquare, [X], [Y], [aLenButton], [bLenButton]
     mov     ax, [ButtonColor]
     inc     [X]
     inc     [Y]
     mov     cx, [bLenButton]
     sub     cx, 2
     mov     bx, [aLenButton]
     sub     bx, 2
     stdcall Draw.DrawSquare, [X], [Y], bx, cx
     sub     [X], 8
     sub     [Y], 7
     stdcall Draw.DrawReturnTitle, [X], [Y], 79
     ret
endp

proc Draw.DrawExitButton uses cx bx,\
     X, Y, FontColor, ButtonColor
     mov     ax, [FontColor]
     stdcall Draw.DrawSquare, [X], [Y], [aLenButton], [bLenButton]
     mov     ax, [ButtonColor]
     inc     [X]
     inc     [Y]
     mov     cx, [bLenButton]
     sub     cx, 2
     mov     bx, [aLenButton]
     sub     bx, 2
     stdcall Draw.DrawSquare, [X], [Y], bx, cx
     add     [X], 5
     sub     [Y], 7
     stdcall Draw.DrawExitTitle, [X], [Y], 79
     ret
endp
proc Draw.DrawScy uses di cx ax
     xor     di, di
     mov     cx, 320 * 200
     mov     ax, [clFont]
     rep     stosb
     ret
endp

proc Draw.DrawFont uses cx ax
     stdcall Draw.DrawScy
     xor     di, di
     mov     ax, [clButton]
     stdcall Draw.DrawSquare, 72, 10, 180, 180
     mov     ax, [clGameBorder]
     stdcall Draw.DrawSquare, 74, 12, 176, 176
     ret
endp

proc Draw.DrawButtons uses ax cx bx dx si
     mov     cx, 16
.drawAllButtons:
     push    cx
     mov     si, 16
     sub     si, cx
     add     si, si
     cmp     [buttons + si + 1], 0
     je      .exit
     ; search X
     movzx   ax, [buttons + si]
     dec     ax
     mov     dl, 4
     div     dl
     xchg    al, ah
     mov     dx, [XMargin]
     mul     dl
     mov     dx, [XStartMargin]
     add     dx, ax
     ; search Y
     movzx   ax, [buttons + si]
     dec     ax
     mov     bl, 4
     div     bl
     mov     bx, [YMargin]
     mul     bl
     mov     bx, [YStartMargin]
     add     bx, ax
     ; draw square
     mov     ax, [clButton]
     stdcall Draw.DrawSquare, dx, bx, [aSquareLen], [aSquareLen]
     ; draw number in block
     movzx   ax, [buttons + si + 1]
     push    ax bx dx
     mov     ax, [clText]
     stdcall Draw.DrawNumber
.exit:
     pop     cx
     loop    .drawAllButtons
     ret
endp

; input:
;   - color in AX
proc Draw.DrawLine uses bx cx di,\
     X1, Y1, X2, Y2
     xor     di, di
     ; switch di to x1, y1
     mov     cx, [Y1]
.changeDI:
     add     di, 320
     loop    .changeDI
     add     di, [X1]
     ; draw line from x1, y1 to x2, y2
     mov     bx, [X2]
     cmp     bx, [X1]
     je      .topLine
.leftLine:
     mov     cx, [X2]
     sub     cx, [X1]
     rep     stosb
     add     di, 320
     sub     di, [X2]
     add     di, [X1]
     mov     cx, [X2]
     sub     cx, [X1]
     rep     stosb
     jmp     .exit
.topLine:
     dec     di
     mov     cx, [Y2]
     sub     cx, [Y1]
.DrawTopLine:
     stosb
     stosb
     add     di, 318
     loop    .DrawTopLine
.exit:
     ret
endp

proc Draw.DrawSquare uses di,\
     X, Y, H, W
     mov     cx, [Y]
.changeDI:
     add     di, 320
     loop    .changeDI
     add     di, [X]
     mov     cx, [H]
     inc     cx
.drawLoop:
     push    cx
     mov     cx, [W]
     rep stosb
     pop     cx
     add     di, 320
     sub     di, [W]
     loop    .drawLoop
     ret
endp

; input:
;   x =  bp + 4
;   y =  bp + 6
;   num = bp + 8
;   AX - color index
; change:
;   CX
proc Draw.DrawNumber uses bx,\
     X, Y, Num
     mov     bx, [Num]
     dec     bx
     add     bx, bx
     mov     bx, [arrOfLinks + bx]
     stdcall bx, [X], [Y]
     ret
endp