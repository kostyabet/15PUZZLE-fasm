        org 100h

Start:
        mov     ah, $0F
        int     10h
        mov     [bOldMode], al
        mov     [bOldPage], bh
        mov     ax, $0013
        int     10h
        push    $A000
        pop     es

        xor     di, di
        mov     cx, 256
stm:
        mov     ax, 256
        sub     ax, cx
        ; draw color
        push    cx
        mov     cx, 10
        rep stosb
        add     di, 310
        mov     cx, 10
        rep stosb
        add     di, 310
        mov     cx, 10
        rep stosb
        pop     cx
        ; change offset
        add     di, 310
        add     di, 320
        ; next step
        loop    stm

        mov     ax, $0C08
        int     21h

        movzx   ax, [bOldMode]
        int     10h
        mov     ah, $05
        mov     al, [bOldPage]
        int     10h
        ret

bOldMode        db      ?
bOldPage        db      ?