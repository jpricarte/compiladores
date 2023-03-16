jumpI => L6
store rfp => rsp
L6: nop
L1: nop
addI rbss, 0 => r4
load r4 => r5
loadI 5 => r6
cmp_GE r5, r6 => r7
cbr r7 => L2, L3
L2: nop
addI rfp, 0 => r8
loadI 8 => r9
store r9 => r8
addI rbss, 0 => r10
addI rbss, 0 => r11
load r11 => r12
loadI 1 => r13
sub r12, r13 => r14
store r14 => r10
jumpI => L1
L3: nop
addI rbss, 0 => r15
load r15 => r16
loadI 10 => r17
cmp_GT r16, r17 => r18
cbr r18 => L4, L5
L4: nop
addI rbss, 4 => r19
loadI 5 => r20
store r20 => r19
L5: nop
addI rbss, 4 => r21
loadI 77 => r22
store r22 => r21
