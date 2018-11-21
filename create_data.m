%Brandon Tran
%Motivation for school
Time = 1:365;
Mot = -3*Time.^3+5*Time.^2+2*Time+12;

MOT = [Time;Mot];
%First is the index Second is value
csvwrite('Motivation.csv',MOT');%Transpose to get the x,y pair

%Decay of some thing
No = 1000;%kilograms to start
t = 0:1000;%in 1000 years
HalfLife = 432.12;%half-life
r = log(2)/HalfLife;
Nt = No*exp(-r*t);%Exponential decay function

DECAY = [t;Nt];
csvwrite('Decay.csv',DECAY');