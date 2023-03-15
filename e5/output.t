addI rbss, 0 => r4
loadI 15 => r5
store r5 => r4
L1: nop
addI rbss, 0 => r6
load r6 => r7
loadI 5 => r8
cmp_GE r7, r8 => r9
cbr r9 => L2, L3
L2: nop
addI rfp, 0 => r10
loadI 8 => r11
store r11 => r10
addI rbss, 0 => r12
addI rbss, 0 => r13
load r13 => r14
loadI 1 => r15
sub r14, r15 => r16
store r16 => r12
jumpI => L1
L3: nop
addI rbss, 0 => r17
load r17 => r18
loadI 10 => r19
cmp_GT r18, r19 => r20
cbr r20 => L4, L5
L4: nop
addI rbss, 4 => r21
loadI 5 => r22
store r22 => r21
L5: nop
addI rbss, 4 => r23
loadI 77 => r24
store r24 => r23
