#asm
/ BUGBUG, This is assembler code, not C code.  The C compiler
/ emits duplicate extern definitions for everything on page 0.
/ BUGBUG, There is a kind of circular dependency here, since the
/ C compiler uses vm.h, which is computed from the code below.
/ That should be fixed by just writing this in assembler to begin
/ with.
        .ORG 0
        0       / Reserve location zero
/PUBLIC _AX
_AX,    0
/PUBLIC _BX
_BX,    0
/PUBLIC _CX
_CX,    0
/PUBLIC _BP
_BP,    0
/PUBLIC _SP
_SP,    7600    / Grow stack down from here
/ Dispatch pointers for VM operations
/PUBLIC __add12
__add12,  _add12
/PUBLIC __add21
__add21,  _add21
/PUBLIC __add1n
__add1n,  _add1n
/PUBLIC __add2n
__add2n,  _add2n
/PUBLIC __addbpn
__addbpn,
/PUBLIC __addwpn
__addwpn, _addwpn
/PUBLIC __addm_
__addm_,  _addm_
/PUBLIC __addsp
__addsp,  _addsp
/PUBLIC __and12
__and12,  _and12
/PUBLIC __aneg1
__aneg1,  _aneg1
/PUBLIC __argcntn
__argcntn,_argcntn
/PUBLIC __asl
__asl,    _asl
/PUBLIC __asr
__asr,    _asr
/PUBLIC __call1
__call1,  _call1
/PUBLIC __callm
__callm,  _callm
/PUBLIC __com1
__com1,   _com1
/PUBLIC __dbl1
__dbl1,   _dbl1
/PUBLIC __dbl2
__dbl2,   _dbl2
/PUBLIC __decbp
__decbp,
/PUBLIC __decwp
__decwp,  _decwp
/PUBLIC __div
__div,  _div
/PUBLIC __divu
__divu, _divu
/PUBLIC __enter
__enter,  _enter
/PUBLIC __eq10f
__eq10f,  _eq10f
/PUBLIC __ge10f
__ge10f,  _ge10f
/PUBLIC __getb1pu
__getb1pu,
/PUBLIC __getb1p
__getb1p,
/PUBLIC __getw1m
__getw1m, _getw1m
/PUBLIC __getw1n
__getw1n, _getw1n
/PUBLIC __getw1p
__getw1p, _getw1p
/PUBLIC __getw1s
__getw1s, _getw1s
/PUBLIC __getw2m
__getw2m, _getw2m
/PUBLIC __getw2n
__getw2n, _getw2n
/PUBLIC __getw2p
__getw2p, _getw2p
/PUBLIC __getb1su
__getb1su,
/PUBLIC __getb1s
__getb1s, _getb1s
/PUBLIC __getw2s
__getw2s, _getw2s
/PUBLIC __gt
__gt,   _gt
/PUBLIC __gt10f
__gt10f,  _gt10f
/PUBLIC __imul
__imul, _imul
/PUBLIC __le10f
__le10f,  _le10f
/PUBLIC __lt10f
__lt10f,  _lt10f
/PUBLIC __mod
__mod,  _mod
/PUBLIC __ne10f
__ne10f,  _ne10f
/PUBLIC __or12
__or12,   _or12
/PUBLIC __point1l
__point1l, _point1l
/PUBLIC __point1m
__point1m, _point1m
/PUBLIC __point1s
__point1s, _point1s
/PUBLIC __point2m
__point2m, _point2m
/PUBLIC __point2s
__point2s, _point2s
/PUBLIC __pop2
__pop2,   _pop2
/PUBLIC __push1
__push1,  _push1
/PUBLIC __push2
__push2,  _push2
/PUBLIC __pushm
__pushm,  _pushm
/PUBLIC __pushp
__pushp,  _pushp
/PUBLIC __pushs
__pushs,  _pushs
/PUBLIC __put_m
__put_m,  _put_m
/PUBLIC __putbm1
__putbm1,_putbm1
/PUBLIC __putwm1
__putwm1,_putwm1
/PUBLIC __rdec1
__rdec1,  _rdec1
/PUBLIC __rdec2
__rdec2,  _rdec2
/PUBLIC __return
__return, _return
/PUBLIC __rets
__rets,   _rets
/PUBLIC __sub_m
__sub_m,  _sub_m
/PUBLIC __sub12
__sub12,  _sub12
/PUBLIC __sub1n
__sub1n,  _sub1n
/PUBLIC __subwpn
__subwpn, _subwpn
/PUBLIC __swap12
__swap12, _swap12
/PUBLIC __swap1s
__swap1s, _swap1s
/PUBLIC __ule
__ule,  _ule
/PUBLIC __ult
__ult,  _ult
/PUBLIC __uge
__uge,  _uge
/PUBLIC __ugt
__ugt,  _ugt
/PUBLIC __umulu
__umulu,_umulu
/PUBLIC __eq
__eq,   0
        TAD _BX
        CIA
        TAD _AX
        SNA CLA
        IAC
        DCA _AX
        JMP @__eq
/PUBLIC __ne
__ne,   0
        TAD _BX
        CIA
        TAD _AX
        SZA CLA
        IAC
        DCA _AX
        JMP @__ne
/PUBLIC __le
__le,   0
        TAD _BX
        CIA
        TAD _AX
        SPA SNA CLA
        IAC
        DCA _AX
        JMP @__le
/PUBLIC __lt
__lt,   0
        TAD _BX
        CIA
        TAD _AX
        SPA CLA
        IAC
        DCA _AX
        JMP @__lt
/PUBLIC __ge
__ge,   0
        TAD _BX
        CIA
        TAD _AX
        SMA CLA
        IAC     / _AX-_BX >= 0
        DCA _AX
        JMP @__ge
/PUBLIC __lneg
__lneg, 0
        TAD _AX
        SNA CLA
        IAC
        DCA _AX
        JMP @__lneg
/PUBLIC __switch
__switch,0
        TAD @__switch
        ISZ __switch
        SNA
        JMP @__switch
        DCA _CX
        TAD @__switch
        ISZ __switch
        CIA
        TAD _AX
        SZA CLA
        JMP __switch+1
        JMP @_CX
        PAGE
        /EXTRN __main, near
        JMP @__start    / Make start at 0200 work
__start,__main
_add12, 0
        TAD _AX
        TAD _BX
        DCA _AX
        JMP @_add12
_add21, 0
        TAD _AX
        TAD _BX
        DCA _BX
        JMP @_add21
_add1n, 0
        TAD _AX
        TAD @_add1n
        ISZ _add1n
        DCA _AX
        JMP @_add1n
_add2n, 0
        TAD _BX
        TAD @_add1n
        ISZ _add1n
        DCA _BX
        JMP @_add1n
_addbpn,
_addwpn,0
        TAD @_addwpn
        ISZ _addwpn
        TAD @_BX
        DCA @_BX
        JMP @_addwpn
_addm_, 0       / Takes 2 operands, destination first
        TAD @_addm_
        ISZ _addm_
        DCA _add1n
        TAD @_addm_
        ISZ _addm_
        DCA @_add1n
        JMP @_addm_
_addsp, 0
        TAD @_addsp
        ISZ _addsp
        TAD _SP
        DCA _SP
        JMP @_addsp
_and12, 0
        TAD _AX
        AND _BX
        DCA _AX
        JMP @_and12
_aneg1, 0
        TAD _AX
        CIA
        DCA _AX
        JMP @_aneg1
/ _argcntn is implemented inline, as it is only two words long.
/ _asl12 is implemented by a call to __asl.
/ _asr12 is implemented by a call to __asr.
_call1, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _call1      / Get return address
        DCA @_SP        / onto stack
        JMP @_AX        / Go to subroutine address in _AX
_callm, 0
        TAD @_call1     / Get subroutine address
        ISZ _call1
        DCA _aneg1      / Save for now
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _call1      / Get return address
        DCA @_SP        / onto stack
        JMP @_aneg1     / Go to saved subroutine address
_com1,  0
        TAD _AX
        CMA
        DCA _AX
        JMP @_com1
_dbl1,  0
        TAD _AX
        TAD _AX
        DCA _AX
        JMP @_dbl1
_dbl2,  0
        TAD _BX
        TAD _BX
        DCA _BX
        JMP @_dbl2
_decbp,
_decwp, 0
        CLA CMA
        TAD @_BX
        DCA @_BX
        JMP @_decwp
_enter, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _BP
        DCA @_SP        / "push bp"
        TAD _SP
        DCA _BP         / "mov bp,sp"
        JMP @_enter
_eq10f, 0
        TAD _AX
        SZA CLA
        JMP _eq10fa
        ISZ _eq10f
        JMP @_eq10f
_eq10fa,TAD @_eq10f     / Get "branch false" address
        DCA _eq10f
        JMP @_eq10f
_ge10f, 0
        TAD _AX
        SPA CLA
        JMP _ge10fa
        ISZ _ge10f
        JMP @_ge10f
_ge10fa,TAD @_ge10f     / Get "branch false" address
        DCA _ge10f
        JMP @_ge10f
/ _getb1m, _getb1mu are short enough to implement inline.
_getw1m,
_getw2m,0               / One operand
        TAD @_getw2m
        ISZ _getw2m
        DCA _ge10f
        TAD @_ge10f
        DCA _AX
        JMP @_getw2m
        PAGE
_getb1pu,
_getb1p,
_getw1p,0
        TAD @_getw1p
        ISZ _getw1p
        TAD _BX
        DCA _AX
        TAD @_AX
        DCA _AX
        JMP @_getw1p
_getw2p,0
        TAD @_getw2p
        ISZ _getw2p
        TAD _BX
        DCA _BX
        TAD @_BX
        DCA _BX
        JMP @_getw2p
_getb1su,
_getb1s,
_getw1s,0
        TAD @_getw1s
        ISZ _getw1s
        TAD _BP
        DCA _AX
        TAD @_AX
        DCA _AX
        JMP @_getw1s
_getw2s,0
        TAD @_getw2s
        ISZ _getw2s
        TAD _BP
        DCA _BX
        TAD @_BX
        DCA _BX
        JMP @_getw2s
/ _getw1n is done inline.
/ _getw2n is done inline.
_gt,    0
        TAD _BX
        CIA
        TAD _AX
        SMA SZA CLA
        IAC     / _AX-_BX > 0
        DCA _AX
        JMP @_gt
_gt10f, 0
        TAD _AX
        SPA SNA CLA
        JMP _gt10fa
        ISZ _gt10f
        JMP @_gt10f
_gt10fa,TAD @_gt10f     / Get "branch false" address
        DCA _gt10f
        JMP @_gt10f
/ _gt12 and _gt12u are implemented with __gt and __ugt.
/ _incbp and _incwp are implemented inline.
/ word_, wordn, and wordr0 are implemented inline.
/ _jmp is implemented inline.
/ labm is inplemented inline.
_le10f, 0
        TAD _AX
        SMA SZA CLA
        JMP _le10fa
        ISZ _le10f
        JMP @_le10f
_le10fa,TAD @_le10f     / Get "branch false" address
        DCA _le10f
        JMP @_le10f
/ _le12 and _le12u are implemented with __le and __ule.
/ _lneg1 is implemented with __lneg
_lt10f, 0
        TAD _AX
        SMA CLA
        JMP _lt10fa
        ISZ _lt10f
        JMP @_lt10f
_lt10fa,TAD @_lt10f     / Get "branch false" address
        DCA _lt10f
        JMP @_lt10f
/ _lt12 and _lt12u are implemented with __lt and __ult.
/ _mod12 and _mod12u are implemented with __mod and __modu.
/ _move21 is implemented inline.
/ _mul12 and _mul12u are implemented with __imul and __umulu.
_ne10f, 0
        TAD _AX
        SNA CLA
        JMP _ne10fa
        ISZ _ne10f
        JMP @_ne10f
_ne10fa,TAD @_ne10f     / Get "branch false" address
        DCA _ne10f
        JMP @_ne10f
/ nearm is implemented inline.
_or12,  0
        TAD _AX         / Complement _AX
        CMA
        DCA _AX
        TAD _BX         / Complement _BX
        CMA
        AND _AX         / AND
        CMA
        DCA _AX         / Finish DeMorgan
        JMP @_or12
_point1l,
_point1m,0
        TAD @_point1m
        ISZ _point1m
        DCA _AX
        JMP @_point1m
_point1s,0
        TAD @_point1s
        ISZ _point1s
        TAD _BP
        DCA _AX
        JMP @_point1s
_point2m,0
        TAD @_point2m
        ISZ _point2m
        DCA _BX
        JMP @_point2m
_point2s,0
        TAD @_point2s
        ISZ _point2s
        TAD _BP
        DCA _BX
        JMP @_point2s
_pop2,  0
        TAD @_SP
        ISZ _SP
        DCA _BX
        JMP @_pop2
_push1, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _AX
        DCA @_SP
        JMP @_push1
_push2, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _BX
        DCA @_SP
        JMP @_push1
        PAGE
_pushm, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD @_pushm
        ISZ _pushm
        DCA _pushp
        TAD @_pushp
        DCA @_SP
        JMP @_pushm
_pushp, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD @_pushp
        ISZ _pushp
        TAD _BX
        DCA _pushs
        TAD @_pushs
        DCA @_SP
        JMP @_pushp
_pushs, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD @_pushs
        ISZ _pushs
        TAD _BP
        DCA _pushp
        TAD @_pushp
        DCA @_SP
        JMP @_pushs
/ _putbp1, _pugwp1 are implemented inline.
_putbm1,
_putwm1,0
        TAD @_putwm1
        ISZ _putwm1
        DCA _put_m
        TAD _AX
        DCA @_put_m
        JMP @_putwm1
_put_m, 0               / Two operands, destination first
        TAD @_put_m
        ISZ _put_m
        DCA _pushs
        TAD @_put_m
        ISZ _put_m
        DCA @_pushs
        JMP @_put_m
_rdec1, 0
        CLA CMA
        TAD _AX
        DCA _AX
        JMP @_rdec1
_rdec2, 0
        CLA CMA
        TAD _BX
        DCA _BX
        JMP @_rdec1
/ refm is implemented inline.
_return,TAD _BP
        DCA _SP
_rets,  TAD @_SP
        ISZ _SP
        DCA _BP
        TAD @_SP
        ISZ _SP
        DCA _rdec2
        JMP @_rdec2
/ _rinc1, _rinc2 are implemented inline.
_sub_m, 0               / Two operands, destination first
        TAD @_sub_m
        ISZ _sub_m
        DCA _sub12
        TAD @_sub_m
        ISZ _sub_m
        CIA
        TAD @_sub12
        DCA @_sub12
        JMP @_sub_m
_sub12, 0
        TAD _BX
        CIA
        TAD _AX
        DCA _AX
        JMP @_sub12
_sub1n, 0
        TAD @_sub1n
        ISZ _sub1n
        CIA
        TAD _AX
        DCA _AX
        JMP @_sub12
_subbpn,
_subwpn,0
        TAD @_sub1n
        ISZ _sub1n
        CIA
        TAD @_BX
        DCA @_BX
        JMP @_subwpn
_swap12,0
        TAD _AX
        DCA _swap1s
        TAD _BX
        DCA _AX
        TAD _swap1s
        DCA _BX
        JMP @_swap12
_swap1s,0
        TAD @_SP
        DCA _BX
        TAD _AX
        DCA @_SP
        TAD _BX
        DCA _AX
        JMP @_swap1s
/ _xor12 is implemented with __xor.
_ule,   0
        TAD _BX
        CLL CML CIA
        TAD _AX
        SZL SNA CLA
        IAC
        DCA _AX
        JMP @__ule
_ult,   0
        TAD _BX
        CLL CML CIA
        TAD _AX
        SZL CLA
        IAC
        DCA _AX
        JMP @__ult
_uge,   0
        TAD _BX
        CLL CML CIA
        TAD _AX
        SNL CLA
        IAC     / _AX-_BX >= 0
        DCA _AX
        JMP @__uge
_ugt,   0
        TAD _BX
        CLL CML CIA
        TAD _AX
        SNL SZA CLA
        IAC     / _AX-_BX > 0
        DCA _AX
        JMP @__ugt
        END
#endasm
