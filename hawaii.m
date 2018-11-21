dat = csvread('mauna_loa.csv',1,0);

time = dat(:,1);
co2 = dat(:,2);

plot(time,co2,'b','LineWidth', 4);
set(gca,'FontSize',18);
xlabel('Time (years)','FontSize',18);
ylabel('CO_2 (ppm)','FontSize',18);