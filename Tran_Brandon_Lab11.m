%Brandon Tran
age = input('Please input your age: '); %No need to be 100% accurate
month = 12*age;
week = 52*age;
day = 365*age;
hour = 8760*age;
minute = 525600*age;
second = 31536000*age;

%Convert age into years, months, weeks, days, hours, minutes and seconds
fprintf('You are:\n%d years old\n%d months old\n%d weeks old\n%d days old\n%d hours old\n%d minutes old\n%d seconds old\n',age, month, week, day, hour, minute, second);

%Weight conversion
weight = input('\nPlease input your weight in pounds (lbs): ');
weight = weight*0.453592;% This is the conversion (1 pound = 0.453592 kilograms)
fprintf('Your weight in kilograms is %.3f kg\n',weight); %Have it to 3 decimals 


%   The apparent difference between Matlab and C are vast and many.
%from what I have seen. One major difference is how interpreted MatLab
%seems to be. The computer does not require the type of data type and it
%doesn't need a declaration of variables and can assume things for you.
%Another the two is that MatLab has functions that deal with matrices and
%matrix multiplication that doesn't seem apparent within C. MatLab also has
%the command line window below it instead of a terminal window that prints
%out randomly.
%
%   In terms of strength and weaknesses, MatLab is more interpretive so it is
%easier to understand and write. On the other hand, C requires strict
%syntax that can be easily forgotten. Although their are such difference
%the two languages still have similar ideas. They both use variables and
%keep the same old \n and semicolon ending. The formatted print statements
%are structured in the same way with a call to the variable outside the
%print. Overall the major difference is how careful you have to be when
%typing out code. C requires a lot of care, while MatLab gives some room to
%be lazy.
%
%
%
%
%
%
%
%
