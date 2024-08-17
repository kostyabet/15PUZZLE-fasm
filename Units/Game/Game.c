proc Game.Switch uses ax bx
     push    ax bx
     mov     ax, $0002
     int     33h
     stdcall Game.SwitchButtonsPos
     mov     ax, $0001
     int     33h
     stdcall Sound.Out, mdGame, [mdGameLen]
     ret
endp

proc Game.CheckSwitch uses cx si
     mov     [blIsComplete], 1
     mov     cx, 15
     .checkLoop:
        mov      si, 15
        sub      si, cx
        add      si, si
        movzx    ax, [buttons + si]
        cmp      al, [buttons + si + 1]
        je       .next
        mov      [blIsComplete], 0
     .next:
        loop     .checkLoop
     ret
endp

proc Game.SwitchButtonsPos uses ax bx cx dx si,\
     mvTo, Choosen

     ; search curent
     mov    cx, 16
.searchCurent:
     mov    bx, 16
     sub    bx, cx
     add    bx, bx
     movzx  ax, [buttons + bx]
     cmp    ax, [Choosen]
     je     .switch
     loop   .searchCurent
     jmp    .exit
.switch:
     movzx  cx, [buttons + bx + 1]
     movzx  si, [ClearIndex]
     dec    si
     add    si, si
     mov    [buttons + si + 1], cl
     mov    [ClearIndex], al
     mov    [buttons + bx + 1], 0
.drawClear:
     ; search X
     movzx   ax, [ClearIndex]
     dec     ax
     mov     dl, 4
     div     dl
     mov     al, ah
     mov     dx, [XMargin]
     mul     dl
     mov     dx, [XStartMargin] ; first element margin
     add     dx, ax
     ; search Y
     movzx   ax, [ClearIndex]
     dec     ax
     mov     bl, 4
     div     bl
     mov     bx, [YMargin]
     mul     bl
     mov     bx, [YStartMargin]
     add     bx, ax
     ; draw square
     mov     ax, [clGameBorder]
     stdcall Draw.DrawSquare, dx, bx, [aSquareLen], [aSquareLen]
.drawButton:
     ; search X
     movzx   ax, [buttons + si]
     dec     ax
     mov     dl, 4
     div     dl
     mov     al, ah
     mov     dx, [XMargin]
     mul     dl
     mov     dx, [XStartMargin] ; first element margin
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
     ret
endp

proc Game.CheckButtons
    locals
        K       dw      0
        N       dw      0
        I       dw      0
        J       dw      0
    endl
    ;prepear K
    movzx   ax, [ClearIndex]
    dec     ax
    mov     bl, 4
    div     bl
    xor     ah, ah
    inc     ax
    mov     [K], ax
    ;prepear N
    mov      cx, 15
.ILoop:
    push     cx
    mov      [I], 15
    sub      [I], cx
    movzx    ax, [ClearIndex]
    dec      ax
    cmp      [I], ax
    je       .exitI
    mov      cx, 16
    sub      cx, [I]
    dec      cx
    .JLoop:
        mov     [J], 16
        sub     [J], cx
        movzx   ax, [ClearIndex]
        dec     ax
        cmp     [J], ax
        je      .exitJ
        ; if block
        mov     si, [I]
        add     si, si
        mov     al, [buttons + si + 1]
        mov     si, [J]
        add     si, si
        cmp     al, [buttons + si + 1]
        jbe     .exitJ
        inc     [N]
    .exitJ:
        loop    .JLoop
.exitI:
    pop     cx
    loop    .ILoop
    ; N + K
    mov    ax, [N]
    add    ax, [K]
    mov    bl, 2
    div    bl
    ret
endp

proc Game.CheckMove\
     Curent

     push   ax
     mov    dx, 0
     ; check default
     movzx  bx, [ClearIndex]
     mov    ax, [Curent]
     sub    ax, bx
     cmp    ax, 1
     jne    @F
     mov    ax, [Curent]
     mov    bl, 4
     div    bl
     cmp    ah, 1
     je     @F
     mov    dx, [mvRight]
     jmp    .exit
@@:
     cmp    ax, -1
     jne    @F
     mov    ax, [Curent]
     mov    bl, 4
     div    bl
     cmp    ah, 0
     je     @F
     mov    dx, [mvLeft]
     jmp    .exit
@@:
     cmp    ax, 4
     jne    @F
     mov    dx, [mvTop]
     jmp    .exit
@@:
     cmp    ax, -4
     jne    @F
     mov    dx, [mvDown]
     jmp    .exit
@@:
     mov    dx, 0
.exit:
     pop    ax
     ret
endp

proc Game.CreateButtonsPosition uses cx bx si
     stdcall Random.Initialize
     stdcall Random.Get
     mov     [ClearIndex], al
     mov     cx, 16
     .createRandomValues:
         mov     bx, 16
         sub     bx, cx
         inc     bl
         cmp     bl, [ClearIndex]
         je      .clearIndex
         ; random
         rol     [Random.wPrev], 5
         stdcall Random.Get
         push    cx
         stdcall Random.Check
         cmp     ax, 0
         je      .createRandomValues
         mov     bx, 16
         sub     bx, cx
         mov     si, bx
         add     si, si
         inc     bx
         mov     [buttons + si], bl
         mov     [buttons + si + 1], al
         jmp     .exit
     .clearIndex:
         dec     bl
         mov     si, bx
         add     si, si
         inc     bl
         mov     [buttons + si], bl
         mov     [buttons + si + 1], 0
     .exit:
         loop    .createRandomValues
     ret
endp
