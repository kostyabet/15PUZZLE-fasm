proc Draw.DrawRestartTitle\
     X, Y, Color
     stdcall  Draw.DrawR, [X], [Y], [Color] ;R;
     add      [X], 10
     stdcall  Draw.DrawE, [X], [Y], [Color] ;E;
     add      [X], 9
     stdcall  Draw.DrawS, [X], [Y], [Color] ;S;
     add      [X], 11
     stdcall  Draw.DrawT, [X], [Y], [Color] ;T;
     add      [X], 12
     stdcall  Draw.DrawA, [X], [Y], [Color] ;A;
     add      [X], 12
     stdcall  Draw.DrawR, [X], [Y], [Color] ;R;
     add      [X], 9
     stdcall  Draw.DrawT, [X], [Y], [Color] ;T;
     ret
endp

proc Draw.DrawReturnTitle\
     X, Y, Color
     stdcall  Draw.DrawR, [X], [Y], [Color] ;R;
     add      [X], 10
     stdcall  Draw.DrawE, [X], [Y], [Color] ;E;
     add      [X], 9
     stdcall  Draw.DrawT, [X], [Y], [Color] ;T;
     add      [X], 12
     stdcall  Draw.DrawU, [X], [Y], [Color] ;U;
     add      [X], 11
     stdcall  Draw.DrawR, [X], [Y], [Color] ;R;
     add      [X], 10
     stdcall  Draw.DrawN, [X], [Y], [Color] ;N;
     add      [X], 10
     ret
endp

proc Draw.DrawExitTitle\
     X, Y, Color
     stdcall  Draw.DrawE, [X], [Y], [Color] ;E;
     add      [X], 9
     stdcall  Draw.DrawX, [X], [Y], [Color] ;X;
     add      [X], 10
     stdcall  Draw.DrawI, [X], [Y], [Color] ;I;
     add      [X], 10
     stdcall  Draw.DrawT, [X], [Y], [Color] ;T;
     ret
endp

proc Draw.DrawFinishTitle\
     X, Y
     stdcall  Draw.DrawC, [X], [Y], 79 ;C;
     add      [X], 12
     stdcall  Draw.DrawO, [X], [Y], 79 ;O;
     add      [X], 14
     stdcall  Draw.DrawM, [X], [Y], 79 ;M;
     add      [X], 17
     stdcall  Draw.DrawP, [X], [Y], 79 ;P;
     add      [X], 12
     stdcall  Draw.DrawL, [X], [Y], 79 ;L;
     add      [X], 11
     stdcall  Draw.DrawE, [X], [Y], 79 ;E;
     add      [X], 10
     stdcall  Draw.DrawT, [X], [Y], 79 ;T;
     add      [X], 14
     stdcall  Draw.DrawE, [X], [Y], 79 ;E;
     add      [X], 6
     stdcall  Draw.DrawDot, [X], [Y], 79 ;!;
     ret
endp

proc Draw.DrawResumeTitle\
     X, Y
     stdcall  Draw.DrawP, [X], [Y], 79 ;P;
     add      [X], 10
     stdcall  Draw.DrawA, [X], [Y], 79 ;A;
     add      [X], 12
     stdcall  Draw.DrawU, [X], [Y], 79 ;U;
     add      [X], 11
     stdcall  Draw.DrawS, [X], [Y], 79 ;S;
     add      [X], 12
     stdcall  Draw.DrawE, [X], [Y], 79 ;E;
     add      [X], 5
     stdcall  Draw.DrawDot, [X], [Y], 79 ;!;
     ret
endp

proc Draw.DrawMainTitle\
     X, Y, Color
     mov      ax, [Color]
     stdcall  Draw.DrawOne, [X], [Y] ;1;
     add      [X], 10
     stdcall  Draw.DrawFive, [X], [Y] ;5;
     add      [X], 20
     stdcall  Draw.DrawP, [X], [Y], [Color] ;P;
     add      [X], 12
     stdcall  Draw.DrawU, [X], [Y], [Color] ;U;
     add      [X], 11
     stdcall  Draw.DrawZ, [X], [Y], [Color] ;Z;
     add      [X], 12
     stdcall  Draw.DrawZ, [X], [Y], [Color] ;Z;
     add      [X], 12
     stdcall  Draw.DrawL, [X], [Y], [Color] ;L;
     add      [X], 11
     stdcall  Draw.DrawE, [X], [Y], [Color] ;E;
     add      [X], 5
     stdcall  Draw.DrawDot, [X], [Y], [Color] ;!;
     ret
endp