f1 = 'VZLOGR01-11-26-14.CSV';
f2 = 'VZLOGR02-12-09-14.CSV';

% Read file 1
fid = fopen(f1);
d1 = textscan(fid, '%f %f %s %f %f', 'Delimiter', ',', 'headerLines', 1);
fclose(fid);
% Read file 2
fid = fopen(f2);
d2 = textscan(fid, '%f %f %s %f %f', 'Delimiter', ',', 'headerLines', 1);
fclose(fid);

% Get each set of data into their own matrix CO2 (4) aqueous, CO2 (5)
% atmospheric
m1 = [d1{1} d1{2} d1{4} d1{5}];
m2 = [d2{1} d2{2} d2{4} d2{5}];
mwrong = [m1;m2];

special = datenum(m1(end,1));%Where the last millis left off
m2special = [(d2{1}+special) d2{2} d2{4} d2{5}];%Offset that last value of first data
mtotal = [m1;m2special];

%% The functions addtodate, datenum, and datetick will be useful here
%addtodate = (current time ,amount increase,unit of increase) 
%datenum = (date, 'format string')
%datetick = (axis, format)


%Get time data
n = datenum([d1{3};d2{3}]);%year/month/day hour:min:second
%plot(n);
%%WRONG THING
mwr = 1:length(n);
for x = 1:length(n)
    mwr(x) = addtodate(n(x),mwrong(x,1),'millisecond'); %Add millisecond increment to time data baseline
end
%figure;
%plot(mwr);

%%RIGHT THING
m = 1:length(n);
for x = 1:length(n)
    m(x) = addtodate(n(x),mtotal(x,1),'millisecond'); %Add millisecond increment to time data baseline
end
%figure;
%plot(m);
%%
%Combine non-time data into a single variable and time data into a single
%variable
CO2water = mtotal(:,3);
CO2atmos = mtotal(:,4);
figure
plot(m,CO2water,'b','LineWidth',3);
hold on;
plot(m,CO2atmos,'g','LineWidth',3);
xtickangle(30);

ylabel('CO_2 Concentration (ppm)');
xlabel('Date');
title('CO_2 Concentration Over Time');
legend('CO_2 water','CO_2 air');
set(gca,'FontSize',15);
set(gca,'XTick',m(1:60:end)); %Set amount of x ticks based off of time
xlim([min(m) max(m)]);
datetick('x','yyyy mmm dd','keepticks','keeplimits'); %reassign num to time name /keep the new ticks and limits


