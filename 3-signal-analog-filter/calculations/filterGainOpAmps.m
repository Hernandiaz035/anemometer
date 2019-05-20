clear; clc;
syms RPot R1 R2 real

assume(RPot == 2e3)

GainMin = 1 + 0;
GainMax = 1 + 20;

eqns = [ 1 + (R1)/(RPot + R2) == GainMin ,
         1 + (RPot + R1)/(R2) == GainMax ];

[RPot, R1, R2, params, conds] = solve(eqns, [RPot, R1, R2], 'ReturnConditions', true)

%% Approximated solution to commercial Values

R1 = 0;
R2 = 100;
RPot = 2e3;

vpaGainMin = vpa(1 + (R1)/(RPot + R2),5)
vpaGainMax = vpa(1 + (RPot + R1)/(R2),5)

%% Gain-Potenciometer function

pot = linspace(0,1,100);

gain = 1 + (RPot*pot + R1)./(RPot*(1-pot) + R2);

plot(pot, gain)
