%Number 3 in Review
%Import data.dat and plot
%Delimited by ';' has row header
A = dlmread('data.dat',';',1,0);
%First is time, Second is Distance
time = A(:,1);
distance = A(:,2);
plot(time,distance);
xlabel('Time');
ylabel('Distance');