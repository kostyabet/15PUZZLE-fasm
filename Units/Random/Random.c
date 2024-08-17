proc Random.Initialize uses ax cx dx
     mov     ah, $2C
     int     21h
     mov     [Random.wPrev], dx
     ret
endp

proc Random.Get uses cx bx dx
     mov     ax, [Random.wPrev]
     rol     ax, 7
     add     ax, 23
     mov     [Random.wPrev], ax
     inc     ax
     xor     dx, dx
     mov     bx, 256
     div     bx
     mov     ax, dx
     xor     dx, dx
     mov     bx, 15
     div     bx
     mov     ax, dx
     inc     ax
     ret
endp

; input:
;   - Curent Number = AX
; change:
;   - AX: for good work
;     return AX - all is good
;     return 0  - error
proc Random.Check uses cx dx si,\
     Count
     mov     cx, 16
     sub     cx, [Count]
     cmp     cx, 0
     je      .exit
     .checkRepeat:
        mov     si, 16
        sub     si, [Count]
        sub     si, cx
        add     si, si
        movzx   dx, [buttons + si + 1]
        cmp     dx, ax
        jne     @F
        xor     ax, ax
        jmp     .exit
     @@:
        loop    .checkRepeat
.exit:
     ret
endp
