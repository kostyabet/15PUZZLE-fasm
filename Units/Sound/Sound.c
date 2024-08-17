proc Sound.Prepear uses ax dx
     mov     dx, $331
     mov     al, $ff
     out     dx, al
     mov     al, $3f
     out     dx, al

     dec     dx
     mov     al, $C0
     out     dx, al
     mov     al, $26
     out     dx, al
     ret
endp

proc Sound.Out uses si cx dx,\
     MIDI, Len
     mov     dx, $330
     mov     si, [MIDI]
     mov     cx, [Len]
     rep     outsb
     ret
endp