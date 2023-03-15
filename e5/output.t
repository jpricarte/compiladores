jumpI => L3
store rfp => rsp
L1: nop
loadI 5 => r4
addI rfp, 8 => r5
store r4 => r5
loadI 10 => r6
addI rfp, 16 => r7
store r6 => r7
addI rfp, 0 => r8
loadI 3 => r9
store r9 => r8
L2: nop
addI rfp, 16 => r10
loadI 99 => r11
store r11 => r10
L3: nop
