proc System.FinishCheck\
     isComplete, buttonNumber

     ; return ax
     ; 1 - exit
     ; 2 - 2th button
     cmp    [buttonNumber], 1
     je     .exit
     cmp    [isComplete], 0
     jne    RestartPointer
     call   Draw.DrawFont
     call   Draw.DrawButtons
     jmp    ContinuePointer
.exit:
     ret
endp

proc System.WaitClick
     stdcall  Sound.Out, mdPause, [mdPauseLen]
     stdcall  Draw.DrawFinishScreen, [blIsComplete]
     stdcall  Mouse.Prepear
     stdcall  System.WaitFinishClick
     push     ax
     stdcall  Mouse.Endl
     pop      ax
     ret
endp

proc System.WaitFinishClick uses dx cx
.SetEvent:
     mov      ax, $0003
     int      33h
     cmp      bx, 1
     je       .OnLeftPress
     jmp      .next
.OnLeftPress:
     stdcall  Mouse.SearchButtonIndex, dx, cx
     cmp      ax, 0
     jne      .exit
.next:
     jmp      .SetEvent
.exit:
     ret
endp

proc System.Endl uses ax
     movzx ax, [bOldMode]
     int   10h
     mov   ah, $05
     mov   al, [bOldPage]
     int   10h
     ret
endp

proc System.DrawPage uses ax
     stdcall  Draw.DrawFont
Buttons:
     stdcall  Game.CreateButtonsPosition
     stdcall  Game.CheckButtons ; ah = 1(false) / 0(true)
     cmp      ah, 1
     je       Buttons
     stdcall  Draw.DrawButtons
     ret
endp

proc System.Prepear uses ax bx,\
     Mode, Code

     mov     ah, $0F
     int     10h
     mov     [bOldMode], al
     mov     [bOldPage], bh
     mov     ax, [Mode];$0013
     int     10h
     push    [Code];$A000
     pop     es
     ret
endp