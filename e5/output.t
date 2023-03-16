i2i rfp => rsp
addI rsp, 4 => rsp
i2i rsp => r19
addI r19, 8 => r19
store rfp => r19
i2i r19 => rfp
i2i rfp => rsp
addI rsp, 16 => rsp
i2i rfp => r20
subI r20, 4 => r20
store rpc => r20
jumpI => L2
jumpI => L3
L1:
nop
i2i rfp => r5
subI r5, 4 => r5
load r5 => r6
addI r6, 2 => r6
store r6 => r5
i2i rfp => r7
subI r7, 8 => rsp
load rfp => rfp
subI r7, 4 => r7
jump => r7
L2:
nop
i2i rfp => r16
subI r16, 4 => r16
load r16 => r17
addI r17, 2 => r17
store r17 => r16
addI rbss, 4 => r8
loadI 2 => r9
store r9 => r8
i2i rsp => r10
addI r10, 8 => r10
store rfp => r10
i2i r10 => rfp
i2i rfp => rsp
addI rsp, 4 => rsp
i2i rfp => r11
subI r11, 4 => r11
store rpc => r11
jumpI => L1
addI rbss, 8 => r12
loadI 3 => r13
store r13 => r12
addI rbss, 12 => r14
loadI 4 => r15
store r15 => r14
i2i rfp => r18
subI r18, 8 => rsp
load rfp => rfp
subI r18, 4 => r18
jump => r18
L3:
nop
