/DATA
        FIELD 1
        *0
        0       / Reserve location zero
GLOBAL _AX
_AX,    0
GLOBAL _BX
_BX,    0
GLOBAL _CX
_CX,    0
GLOBAL _BP
_BP,    0
GLOBAL _SP
_SP,    7600    / Grow stack down from here
        *20     / Skip over the autoindex locations
/ Dispatch pointers for VM operations
GLOBAL __add12
__add12,  _add12
GLOBAL __add21
__add21,  _add21
GLOBAL __add1n
__add1n,  _add1n
GLOBAL __add2n
__add2n,  _add2n
GLOBAL __addbpn
__addbpn,
GLOBAL __addwpn
__addwpn, _addwpn
GLOBAL __addm_
__addm_,  _addm_
GLOBAL __addsp
__addsp,  _addsp
GLOBAL __and12
__and12,  _and12
GLOBAL __aneg1
__aneg1,  _aneg1
GLOBAL __argcntn
__argcntn,_argcntn
GLOBAL __asl12
__asl12,  _asl12
GLOBAL __asr12
__asr12,  _asr12
GLOBAL __call1
__call1,  _call1
GLOBAL __callm
__callm,  _callm
GLOBAL __com1
__com1,   _com1
GLOBAL __dbl1
__dbl1,   _dbl1
GLOBAL __dbl2
__dbl2,   _dbl2
GLOBAL __decbp
__decbp,
GLOBAL __decwp
__decwp,  _decwp
GLOBAL __div
__div,  _div
GLOBAL __divu
__divu, _divu
GLOBAL __enter
__enter,  _enter
GLOBAL __eq10f
__eq10f,  _eq10f
GLOBAL __ge10f
__ge10f,  _ge10f
GLOBAL __getb1pu
__getb1pu,
GLOBAL __getb1p
__getb1p,
GLOBAL __getw1m
__getw1m, _getw1m
GLOBAL __getw1n
__getw1n, _getw1n
GLOBAL __getw1p
__getw1p, _getw1p
GLOBAL __getw1s
__getw1s, _getw1s
GLOBAL __getw2m
__getw2m, _getw2m
GLOBAL __getw2n
__getw2n, _getw2n
GLOBAL __getw2p
__getw2p, _getw2p
GLOBAL __getb1su
__getb1su,
GLOBAL __getb1s
__getb1s, _getb1s
GLOBAL __getw2s
__getw2s, _getw2s
GLOBAL __gt
__gt,   _gt
GLOBAL __gt10f
__gt10f,  _gt10f
GLOBAL __imul
__imul, _imul
GLOBAL __jmpm
__jmpm, _jmpm
GLOBAL __le
__le,   _le
GLOBAL __le10f
__le10f,  _le10f
GLOBAL __lt10f
__lt10f,  _lt10f
GLOBAL __mod
__mod,  _mod
GLOBAL __modu
__modu, _modu
GLOBAL __ne10f
__ne10f,  _ne10f
GLOBAL __or12
__or12,   _or12
GLOBAL __point1l
__point1l, _point1l
GLOBAL __point1m
__point1m, _point1m
GLOBAL __point1s
__point1s, _point1s
GLOBAL __point2m
__point2m, _point2m
GLOBAL __point2s
__point2s, _point2s
GLOBAL __pop2
__pop2,   _pop2
GLOBAL __push1
__push1,  _push1
GLOBAL __push2
__push2,  _push2
GLOBAL __pushm
__pushm,  _pushm
GLOBAL __pushp
__pushp,  _pushp
GLOBAL __pushs
__pushs,  _pushs
GLOBAL __put_m
__put_m,  _put_m
GLOBAL __putbm1
__putbm1,_putbm1
GLOBAL __putwm1
__putwm1,_putwm1
GLOBAL __rdec1
__rdec1,  _rdec1
GLOBAL __rdec2
__rdec2,  _rdec2
GLOBAL __return
__return, _return
GLOBAL __rets
__rets,   _rets
GLOBAL __sub_m
__sub_m,  _sub_m
GLOBAL __sub12
__sub12,  _sub12
GLOBAL __sub1n
__sub1n,  _sub1n
GLOBAL __subwpn
__subwpn, _subwpn
GLOBAL __swap12
__swap12, _swap12
GLOBAL __swap1s
__swap1s, _swap1s
GLOBAL __ule
__ule,  _ule
GLOBAL __ult
__ult,  _ult
GLOBAL __uge
__uge,  _uge
GLOBAL __ugt
__ugt,  _ugt
GLOBAL __umulu
__umulu,_umulu
GLOBAL __eq
__eq,   0
        TAD _BX
        CIA
        TAD _AX
        SNA CLA
        IAC
        DCA _AX
        JMP I __eq
GLOBAL __ne
__ne,   0
        TAD _BX
        CIA
        TAD _AX
        SZA CLA
        IAC
        DCA _AX
        JMP I __ne
GLOBAL __lt
__lt,   0
        TAD _BX
        CIA
        TAD _AX
        SPA CLA
        IAC
        DCA _AX
        JMP I __lt
GLOBAL __ge
__ge,   _ge
GLOBAL __lneg1
__lneg1,_lneg1
GLOBAL __switch
__switch,0
        TAD I __switch
        ISZ __switch
        SNA
        JMP I __switch
        DCA _CX
        TAD I __switch
        ISZ __switch
        CIA
        TAD _AX
        SZA CLA
        JMP __switch+1
        JMP I _CX
        PAGE
        EXTERNAL _main
        JMP I __start    / Make start at 0200 work
__start,_main
_add12, 0
        TAD _AX
        TAD _BX
        DCA _AX
        JMP I _add12
_add21, 0
        TAD _AX
        TAD _BX
        DCA _BX
        JMP I _add21
_add1n, 0
        TAD _AX
        TAD I _add1n
        ISZ _add1n
        DCA _AX
        JMP I _add1n
_add2n, 0
        TAD _BX
        TAD I _add1n
        ISZ _add1n
        DCA _BX
        JMP I _add1n
_addbpn,
_addwpn,0
        TAD I _addwpn
        ISZ _addwpn
        TAD I _BX
        DCA I _BX
        JMP I _addwpn
_addm_, 0       / Takes 2 operands, destination first
        TAD I _addm_
        ISZ _addm_
        DCA _add1n
        TAD I _addm_
        ISZ _addm_
        DCA I _add1n
        JMP I _addm_
_addsp, 0
        TAD I _addsp
        ISZ _addsp
        TAD _SP
        DCA _SP
        JMP I _addsp
_and12, 0
        TAD _AX
        AND _BX
        DCA _AX
        JMP I _and12
_aneg1, 0
        TAD _AX
        CIA
        DCA _AX
        JMP I _aneg1
_argcntn,0
        TAD I _argcntn
        ISZ _argcntn
        DCA _CX
        JMP I _argcntn
_asl12, 0
        TAD _BX
        CIA
        SNA
        JMP I _asl12 / Shift 0 bits
        DCA _BX
        TAD _AX
        TAD _AX
        DCA _AX
        ISZ _BX
        JMP .-4
        JMP I _asl12
_asr12, 0
        TAD _BX
        CIA
        SNA
        JMP I _asr12 / Shift 0 bits
        DCA _BX
        TAD _AX
        CLL RAR
        DCA _AX
        ISZ _BX
        JMP .-4
        JMP I _asr12
/ _asr12 is implemented by a call to __asr.
_call1, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _call1      / Get return address
        DCA I _SP        / onto stack
        JMP I _AX        / Go to subroutine address in _AX
_callm, 0
        TAD I _callm     / Get subroutine address
        ISZ _callm
        DCA _aneg1      / Save for now
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _callm      / Get return address
        DCA I _SP        / onto stack
        JMP I _aneg1     / Go to saved subroutine address
_com1,  0
        TAD _AX
        CMA
        DCA _AX
        JMP I _com1
_dbl1,  0
        TAD _AX
        TAD _AX
        DCA _AX
        JMP I _dbl1
_dbl2,  0
        TAD _BX
        TAD _BX
        DCA _BX
        JMP I _dbl2
_decbp,
_decwp, 0
        CLA CMA
        TAD I _BX
        DCA I _BX
        JMP I _decwp
        PAGE
_enter, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _BP
        DCA I _SP        / "push bp"
        TAD _SP
        DCA _BP         / "mov bp,sp"
        JMP I _enter
_eq10f, 0
        TAD _AX
        SZA CLA
        JMP _eq10fa
        ISZ _eq10f
        JMP I _eq10f
_eq10fa,TAD I _eq10f     / Get "branch false" address
        DCA _eq10f
        JMP I _eq10f
_ge10f, 0
        TAD _AX
        SPA CLA
        JMP _ge10fa
        ISZ _ge10f
        JMP I _ge10f
_ge10fa,TAD I _ge10f     / Get "branch false" address
        DCA _ge10f
        JMP I _ge10f
/ _getb1m, _getb1mu are short enough to implement inline.
_getw1m,
_getw2m,0               / One operand
        TAD I _getw2m
        ISZ _getw2m
        DCA _getw1p
        TAD I _getw1p
        DCA _AX
        JMP I _getw2m
_getb1pu,
_getb1p,
_getw1p,0
        TAD I _getw1p
        ISZ _getw1p
        TAD _BX
        DCA _AX
        TAD I _AX
        DCA _AX
        JMP I _getw1p
_getw2p,0
        TAD I _getw2p
        ISZ _getw2p
        TAD _BX
        DCA _BX
        TAD I _BX
        DCA _BX
        JMP I _getw2p
_getb1su,
_getb1s,
_getw1s,0
        TAD I _getw1s
        ISZ _getw1s
        TAD _BP
        DCA _AX
        TAD I _AX
        DCA _AX
        JMP I _getw1s
_getw2s,0
        TAD I _getw2s
        ISZ _getw2s
        TAD _BP
        DCA _BX
        TAD I _BX
        DCA _BX
        JMP I _getw2s
_getw1n,0
        TAD I _getw1n
        ISZ _getw1n
        DCA _AX
        JMP I _getw1n
_getw2n,0
        TAD I _getw2n
        ISZ _getw2n
        DCA _BX
        JMP I _getw2n
_ge,    0
        TAD _BX
        CIA
        TAD _AX
        SMA CLA
        IAC     / _AX-_BX >= 0
        DCA _AX
        JMP I _ge
_gt,    0
        TAD _BX
        CIA
        TAD _AX
        SMA SZA CLA
        IAC     / _AX-_BX > 0
        DCA _AX
        JMP I _gt
_gt10f, 0
        TAD _AX
        SPA SNA CLA
        JMP _gt10fa
        ISZ _gt10f
        JMP I _gt10f
_gt10fa,TAD I _gt10f     / Get "branch false" address
        DCA _gt10f
        JMP I _gt10f
/ _gt12 and _gt12u are implemented with __gt and __ugt.
/ _incbp and _incwp are implemented inline.
/ word_, wordn, and wordr0 are implemented inline.
_jmpm,  0
        TAD I _jmpm
        DCA _jmpm
        JMP I _jmpm
/ labm is inplemented inline.
_le10f, 0
        TAD _AX
        SMA SZA CLA
        JMP _le10fa
        ISZ _le10f
        JMP I _le10f
_le10fa,TAD I _le10f     / Get "branch false" address
        DCA _le10f
        JMP I _le10f
/ _le12 and _le12u are implemented with __le and __ule.
GLOBAL _le
_le,    0
        TAD _BX
        CIA
        TAD _AX
        SPA SNA CLA
        IAC
        DCA _AX
        JMP I _le
_lneg1, 0
        TAD _AX
        SNA CLA
        IAC
        DCA _AX
        JMP I _lneg1
        PAGE
_lt10f, 0
        TAD _AX
        SMA CLA
        JMP _lt10fa
        ISZ _lt10f
        JMP I _lt10f
_lt10fa,TAD I _lt10f     / Get "branch false" address
        DCA _lt10f
        JMP I _lt10f
/ _lt12 and _lt12u are implemented with __lt and __ult.
/ _mod12 and _mod12u are implemented with __mod and __modu.
/ _move21 is implemented inline.
/ _mul12 and _mul12u are implemented with __imul and __umulu.
_ne10f, 0
        TAD _AX
        SNA CLA
        JMP _ne10fa
        ISZ _ne10f
        JMP I _ne10f
_ne10fa,TAD I _ne10f     / Get "branch false" address
        DCA _ne10f
        JMP I _ne10f
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
        JMP I _or12
_point1l,
_point1m,0
        TAD I _point1m
        ISZ _point1m
        DCA _AX
        JMP I _point1m
_point1s,0
        TAD I _point1s
        ISZ _point1s
        TAD _BP
        DCA _AX
        JMP I _point1s
_point2m,0
        TAD I _point2m
        ISZ _point2m
        DCA _BX
        JMP I _point2m
_point2s,0
        TAD I _point2s
        ISZ _point2s
        TAD _BP
        DCA _BX
        JMP I _point2s
_pop2,  0
        TAD I _SP
        ISZ _SP
        DCA _BX
        JMP I _pop2
_push1, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _AX
        DCA I _SP
        JMP I _push1
_push2, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD _BX
        DCA I _SP
        JMP I _push1
_pushm, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD I _pushm
        ISZ _pushm
        DCA _pushp
        TAD I _pushp
        DCA I _SP
        JMP I _pushm
_pushp, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD I _pushp
        ISZ _pushp
        TAD _BX
        DCA _pushs
        TAD I _pushs
        DCA I _SP
        JMP I _pushp
_pushs, 0
        CLA CMA
        TAD _SP
        DCA _SP
        TAD I _pushs
        ISZ _pushs
        TAD _BP
        DCA _pushp
        TAD I _pushp
        DCA I _SP
        JMP I _pushs
/ _putbp1, _pugwp1 are implemented inline.
_putbm1,
_putwm1,0
        TAD I _putwm1
        ISZ _putwm1
        DCA _put_m
        TAD _AX
        DCA I _put_m
        JMP I _putwm1
_put_m, 0               / Two operands, destination first
        TAD I _put_m
        ISZ _put_m
        DCA _pushs
        TAD I _put_m
        ISZ _put_m
        DCA I _pushs
        JMP I _put_m
_rdec1, 0
        CLA CMA
        TAD _AX
        DCA _AX
        JMP I _rdec1
_rdec2, 0
        CLA CMA
        TAD _BX
        DCA _BX
        JMP I _rdec2
/ refm is implemented inline.
        PAGE
_return,TAD _BP
        DCA _SP
_rets,  TAD I _SP
        ISZ _SP
        DCA _BP
        TAD I _SP
        ISZ _SP
        DCA _sub_m
        JMP I _sub_m
/ _rinc1, _rinc2 are implemented inline.
_sub_m, 0               / Two operands, destination first
        TAD I _sub_m
        ISZ _sub_m
        DCA _sub12
        TAD I _sub_m
        ISZ _sub_m
        CIA
        TAD I _sub12
        DCA I _sub12
        JMP I _sub_m
_sub12, 0
        TAD _BX
        CIA
        TAD _AX
        DCA _AX
        JMP I _sub12
_sub1n, 0
        TAD I _sub1n
        ISZ _sub1n
        CIA
        TAD _AX
        DCA _AX
        JMP I _sub12
_subbpn,
_subwpn,0
        TAD I _sub1n
        ISZ _sub1n
        CIA
        TAD I _BX
        DCA I _BX
        JMP I _subwpn
_swap12,0
        TAD _AX
        DCA _swap1s
        TAD _BX
        DCA _AX
        TAD _swap1s
        DCA _BX
        JMP I _swap12
_swap1s,0
        TAD I _SP
        DCA _BX
        TAD _AX
        DCA I _SP
        TAD _BX
        DCA _AX
        JMP I _swap1s
/ _xor12 is implemented with __xor.
_ule,   0
        TAD _BX
        CLL CML CIA
        TAD _AX
        SZL SNA CLA
        IAC
        DCA _AX
        JMP I __ule
_ult,   0
        TAD _BX
        CLL CML CIA
        TAD _AX
        SZL CLA
        IAC
        DCA _AX
        JMP I __ult
_uge,   0
        TAD _BX
        CLL CML CIA
        TAD _AX
        SNL CLA
        IAC     / _AX-_BX >= 0
        DCA _AX
        JMP I __uge
_ugt,   0
        TAD _BX
        CLL CML CIA
        TAD _AX
        SNL SZA CLA
        IAC     / _AX-_BX > 0
        DCA _AX
        JMP I __ugt
div,    0              / Slow but small div for now
        DCA _CX
        TAD _BX
        CIA
        DCA _BX
divlp,  TAD _BX
        STL             / For unsigned version
        TAD _AX
divskp, 0               / SZL or SPA
        JMP divdne
        DCA _AX
        ISZ _CX         / Divide by 0 will skip
        JMP divlp
divdne, CLA
        JMP I div
divspa, SPA
divszl, SZL
_modu,  0               / Unsigned version
        TAD divszl
        DCA divskp
        JMS div
        JMP I _modu
_mod,   0               / Signed version
        TAD divspa
        DCA divskp
        JMS div
        JMP I _mod
_divu,  0
        JMS _modu
        TAD _CX
        DCA _AX
        JMP I _divu
_div,   0
        JMS _mod
        TAD _CX
        DCA _AX
        JMP I _div
        PAGE
_umulu,
_imul,  0
        TAD _AX         / Start with +X*2^0
        DCA _CX
        DCA _AX         / and result of 0
mullp,  TAD _BX         / Y have bits left?
        SNA
        JMP I _imul     / No, we're done
        CLL RAR         / Yes, get the next bit
        DCA _BX         / ...and set up for next time
        SZL             / This bit set?
        TAD _CX         / Yes, add X*2^n
        TAD _AX         / to result
        DCA _AX
        TAD _CX         / Increment 'n' in X*2^n
        TAD _CX
        SNA             / Overflowed?
        JMP I _imul     / Yes, can't affect result anymore
        DCA _CX         / No, set up for next time
        JMP mullp
GLOBAL __ORG
__ORG=. / Force the code to load here!
        END
