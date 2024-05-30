proc Mouse.Work uses ax cx bx dx
.SetEvent:
     mov      ax, $0003
     int      33h
     cmp      bx, 1
     je       .OnLeftPress
     jmp      exit
.OnLeftPress:
     stdcall  Mouse.SearchChoosenIndex, dx, cx ; ax - choosen index
     stdcall  Game.CheckMove, ax ; dx - move goal
     cmp      dx, 0
     je       Next
     stdcall  Game.Switch
     stdcall  Game.CheckSwitch
     mov      bx, 0
     cmp      [blIsComplete], 1
     je       return
Next:
     jmp      Mouse.Work.SetEvent
exit:
     cmp      bx, 2
     jne      Mouse.Work.SetEvent
return:
     ret
endp

proc Mouse.Endl uses ax
     mov   ax, $0002
     int   33h
     ret
endp

proc Mouse.Prepear uses ax
     mov    ax, $0003
     int    33h
     mov    ax, $0000
     int    33h
     mov    ax, $0004
     int    33h
     mov    ax, $0001
     int    33h
     ret
endp

proc Mouse.SearchButtonIndex\
     Y, X

     xor   ax, ax
     shr   [X], 1
     sub   [X], 120
     sub   [Y], 80
     cmp   [X], 0
     jbe   .exit
     cmp   [Y], 0
     jbe   .exit
     cmp   [X], 80
     ja    .exit
     cmp   [Y], 25
     ja    @F
     mov   ax, 1
     jmp   .exit
@@:
     sub   [Y], 30
     cmp   [Y], 0
     jbe   .exit
     cmp   [Y], 25
     ja    .exit
     mov   ax, 2
.exit:
     ret
endp

proc Mouse.SearchChoosenIndex uses bx,\
     Y, X
     locals
        NX      dw      0
        NY      dw      0
        Curent  dw      0
     endl

     shr   [X], 1
     ; check good X
     mov   ax, [X]
     cmp   ax, [XStartMargin]
     jb    .exit
     mov   bx, [X]
     sub   bx, [XStartMargin]
     cmp   bx, 174
     jg    .exit
     ; check good Y
     mov   ax, [Y]
     cmp   ax, [YStartMargin]
     jb    .exit
     mov   bx, [Y]
     sub   bx, [YStartMargin]
     cmp   bx, 174
     jg    .exit
     ; treatment X
     mov   ax, [X]
     sub   ax, [XStartMargin]
     mov   bx, [XMargin]
     div   bl
        sub   ah, 39
        cmp   ah, 0
        jg    .exit
        mov   ah, 0
     inc   ax
     mov   [NX], ax
     ; treatment Y
     mov   ax, [Y]
     sub   ax, [YStartMargin]
     mov   bx, [YMargin]
     div   bl
        sub   ah, 40
        cmp   ah, 0
        jg    .exit
        mov   ah, 0
     mov   [NY], ax
     ; collect
     mov   bl, 4
     mul   bl
     mov   [Curent], ax
     mov   ax, [NX]
     add   [Curent], ax
     mov   ax, [Curent]
.exit:
     ret
endp