numCases = 12;
zValue = 1.960;
numObservations = 10;

latencyInSecondsInMilli = latencyInSeconds * 1000;

for i=1:numCases
	meanLatency(i)=mean(latencyInSecondsInMilli(:,i));
    stdLatency(i)=std(latencyInSecondsInMilli(:,i));
    ciLatency(i)=zValue*(stdLatency(i)/sqrt(numObservations));
end

xAxis = categorical({'Coordinates - Slow','Coordinates - Fast', 'Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});
xAxis = reordercats(xAxis,{'Coordinates - Slow','Coordinates - Fast', 'Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});

yAxis = meanLatency;

erBar = ciLatency;

bar2 = bar(xAxis,yAxis)

xtips2 = bar2(1).XEndPoints; ytips2 = bar2(1).YEndPoints;
text(xtips2, ytips2, num2str(transpose(yAxis(1,:)),'%0.3f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
ylabel("Latency in Milliseconds");
legend("Slow","Fast");
set(gca,"FontSize",17);



