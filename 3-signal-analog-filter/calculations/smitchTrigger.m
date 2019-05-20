clear; clc;
syms R1 R2 R3 real

R123 = (R1^-1 + R2^-1 + R3^-1)^-1

assume(R1 > 0)
assume(R2 > 0)
assume(R3 > 0)

assume(R1 == 3300)

Vcc = 12;
VOn = 6;
VOff = 2;

% opamp_V+ is VCC and opamp_V- is GND, this is important
eqns = [VOn  == Vcc*R123/R2 + Vcc*R123/R3 ,
        VOff == Vcc*R123/R2 + 0.5*R123/R3];

[R1, R2, R3, params, conds] = solve(eqns, [R1, R2, R3], 'ReturnConditions', true)

%% Approximated Solution with commercial resistors

R1 = 330;
R2 = 1e3;
R3 = 470;

R123 = (R1^-1 + R2^-1 + R3^-1)^-1

VOn = vpa(Vcc*R123/R2 + (Vcc - 0.5)*R123/R3,5)
VOff = vpa(Vcc*R123/R2 + 0.5*R123/R3,5)