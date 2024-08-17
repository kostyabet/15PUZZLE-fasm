      include   '/MACRO/PROC16.INC'

      include   'Units/Random/Random.h'
      include   'Units/System/System.h'
      include   'Units/Mouse/Mouse.h'
      include   'Units/Game/Game.h'
      include   'Units/Draw/Draw.h'
      include   'Units/Sound/Sound.h'

      org       100h
Start:
      stdcall   Sound.Prepear
      stdcall   Sound.Out, mdOpen, [mdOpenLen]
      stdcall   System.Prepear, $0013, $A000
RestartPointer:
      stdcall   System.DrawPage
ContinuePointer:
      stdcall   Mouse.Prepear
      stdcall   Mouse.Work
      stdcall   Mouse.Endl
      stdcall   System.WaitClick
      cmp       ax, 1
      je        Exit
      stdcall   Sound.Out, mdWin, [mdWinLen]
      cmp       [blIsComplete], 0
      jne       RestartPointer
      stdcall   Draw.DrawFont
      stdcall   Draw.DrawButtons
      jmp       ContinuePointer
Exit:
      stdcall   System.Endl
      stdcall   Sound.Out, mdClose, [mdCloseLen]
      ret

include    'Units/System/System.du'
include    'Units/System/System.di'

include    'Units/Draw/Color.di'
include    'Units/Draw/Fonts/Sizes.di'
include    'Units/Draw/Digits/DigitsProc.di'

include    'Units/Game/Game.di'
include    'Units/Game/Game.du'

include    'Units/Mouse/Mouse.di'
include    'Units/Mouse/Mouse.du'

include    'Units/Random/Random.di'
include    'Units/Random/Random.du'

include    'Units/Sound/Sound.di'
include    'Units/Sound/Sound.du'

include    'Units/System/System.c'
include    'Units/Mouse/Mouse.c'
include    'Units/Random/Random.c'
include    'Units/Game/Game.c'
include    'Units/Draw/Fonts/Fonts.c'
include    'Units/Draw/Digits/Digits.c'
include    'Units/Draw/Letters/Letters.c'
include    'Units/Draw/Letters/Titles.c'
include    'Units/Sound/Sound.c'