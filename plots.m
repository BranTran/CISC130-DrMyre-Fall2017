x = -5:5;
x2= -5:0.01:5;

y = 4*x.^2 - 3*x;
y2 = 4*x2.^2 - 3*x2;

figure;
plot(x,y, x2,y2, 'LineWidth', 8);
%figure;
%plot(x2,y2);
