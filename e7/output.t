i2i rfp => rsp
addI rsp, 4 => rsp
i2i rsp => r24
addI r24, 8 => r24
store rfp => r24
i2i r24 => rfp
i2i rfp => rsp
addI rsp, 12 => rsp
i2i rfp => r25
subI r25, 4 => r25
store rpc => r25
jumpI => L2
jumpI => L3
L1:
nop
i2i rfp => r9
subI r9, 4 => r9
load r9 => r10
addI r10, 2 => r10
store r10 => r9
loadI 2 => r5
i2i rfp => r6
subI r6, 8 => r6
store r5 => r6
i2i rfp => r7
subI r7, 8 => rsp
load rfp => rfp
subI r7, 4 => r7
load r7 => r8
jump => r8
i2i rfp => r11
subI r11, 8 => rsp
load rfp => rfp
subI r11, 4 => r11
load r11 => r12
jump => r12
L2:
nop
i2i rfp => r20
subI r20, 4 => r20
load r20 => r21
addI r21, 2 => r21
store r21 => r20
addI rbss, 4 => r13
loadI 2 => r14
store r14 => r13
addI rbss, 8 => r15
loadI 3 => r16
store r16 => r15
addI rbss, 12 => r17
i2i rsp => r18
addI r18, 8 => r18
store rfp => r18
i2i r18 => rfp
i2i rfp => rsp
addI rsp, 8 => rsp
i2i rfp => r19
subI r19, 4 => r19
store rpc => r19
jumpI => L1
store r0 => r17
i2i rfp => r22
subI r22, 8 => rsp
load rfp => rfp
subI r22, 4 => r22
load r22 => r23
jump => r23
L3:
nop