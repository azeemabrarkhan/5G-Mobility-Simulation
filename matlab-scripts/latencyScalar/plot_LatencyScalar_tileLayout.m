numCases = 2;
zValue = 1.960;
numObservations = 10;

latencyInSeconds_onlyCoordinatesInMilli = latencyInSeconds_onlyCoordinates * 1000;
latencyInSecondsInMilli = latencyInSeconds * 1000;

for i=1:numCases
	meanLatency_onlyCoordinates(i)=mean(latencyInSeconds_onlyCoordinatesInMilli(:,i));
    stdLatency_onlyCoordinates(i)=std(latencyInSeconds_onlyCoordinatesInMilli(:,i));
    ciLatency_onlyCoordinates(i)=zValue*(stdLatency_onlyCoordinates(i)/sqrt(numObservations));
end

xAxis = categorical({'Coordinates - Slow','Coordinates - Fast'});
xAxis = reordercats(xAxis,{'Coordinates - Slow','Coordinates - Fast'});

yAxis = meanLatency_onlyCoordinates;

erBar = ciLatency_onlyCoordinates;

tiledlayout(1,3)

nexttile

bar1 = bar(xAxis,yAxis)
%ylim([0,2.75*10^-4]);
%ylim([0,3*10^-3]);

%xtips1 = bar1(1).XEndPoints; ytips1 = bar1(1).YEndPoints;
%text(xtips1, ytips1, num2str(transpose(yAxis(1,:)./10^-3),'%0.5f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
ylabel("Latency in Milliseconds");
legend("Slow","Fast");
set(gca,"FontSize",16);

nexttile(2,[1 2])

numCases = 10;

for i=1:numCases
	meanLatency(i)=mean(latencyInSecondsInMilli(:,i));
    stdLatency(i)=std(latencyInSecondsInMilli(:,i));
    ciLatency(i)=zValue*(stdLatency(i)/sqrt(numObservations));
end

xAxis = categorical({'Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});
xAxis = reordercats(xAxis,{'Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});

yAxis = meanLatency;

erBar = ciLatency;

bar2 = bar(xAxis,yAxis)

%xtips2 = bar2(1).XEndPoints; ytips2 = bar2(1).YEndPoints;
%text(xtips2, ytips2, num2str(transpose(yAxis(1,:)),'%0.3f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
ylabel("Latency in Milliseconds");
legend("Slow","Fast");
set(gca,"FontSize",16);



