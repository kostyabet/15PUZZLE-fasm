mdOpen          db      $90, $23, $7F, $F7
mdOpenLen       dw      $ - mdOpen
mdWin           db      $90, $25, $7F, $F7
mdWinLen        dw      $ - mdWin
mdPause         db      $90, $15, $7F, $F7
mdPauseLen      dw      $ - mdPause
mdGame          db      $90, $20, $7F, $80, $50, $7F, $F7
mdGameLen       dw      $ - mdGame
mdClose         db      $90, $10, $7F, $F7
mdCloseLen      dw      $ - mdClose