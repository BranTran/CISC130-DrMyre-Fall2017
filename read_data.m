%Brandon Tran
Dist = csvread('Weird_Distribution_Thingy.csv');
Data = csvread('New_Data_Set.csv');

%This is a ball park estimate on the situations presented in data
plot(Dist);
ylabel('Level of Difficulty');
xlabel('Time (Days)');
title('Lab Difficulty Over Time');

figure, plot(Data);
ylabel('Level Confidence');
xlabel('Time (Days)');
title('Confidence in Doing Labs Over Time');