%uranium decay over time plot
%U-238
%Half-life 4.468 X^9 yr
%Nt = N0*e^-(rt)
%r = ln(2)/half-life

No = 3;%kilograms to start
t = 0:10^8:5*10^10;%in 1000 years progressiving 50 years
HalfLife = 4.468*(10^9);%half-life
r = log(2)/HalfLife;
Nt = No*exp(-r*t);%Exponential decay function

plot(t,Nt,'b');
xlabel('Time (years)');
ylabel('Uranium (kg)');












%Radium decay over time plot
%U-226
%Half-life 4.468 X^9 yr
%Nt = N0*e^-(rt)
%r = ln(2)/half-life

N0 = 1.365*10^23;%kilograms to start
HalfLife = 1600;%half-life
r = log(2)/HalfLife;


t = 0:-10000:-4.4*10^9;%inback to the origin of the earth
Nt = No*exp(-r*t);%Exponential decay function

plot(t,Nt,'r');
xlabel('Time (years)');
ylabel('Amount (kg)');
%Notes: The problem is that radium is daughter