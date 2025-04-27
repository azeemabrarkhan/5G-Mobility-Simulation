numCases = 8;
zValue = 1.960;
numObservations = 10;
numAgents = 125;

for j=1:numCases
    sumForNumVideos = 0;
    sumForVideoLengths = 0;
	for b = 0:numAgents-1
	    sumForNumVideos = sumForNumVideos + NumVideos(b+1,j);
        sumForVideoLengths = sumForVideoLengths + VideoLengths(b+1,j);
	end
	combinedNumVideos(1,j) = sumForNumVideos;
    combinedVideoLengths(1,j) = sumForVideoLengths;
end

for i=1:numCases
	meanVideoLengths(i)=mean(combinedVideoLengths(:,i));
    stdVideoLengths(i)=std(combinedVideoLengths(:,i));
    ciVideoLengths(i)=zValue*(stdVideoLengths(i)/sqrt(numObservations));

    meanNumVideos(i)=mean(combinedNumVideos(:,i));
    stdNumVideos(i)=std(combinedNumVideos(:,i));
    ciNumVideos(i)=zValue*(stdNumVideos(i)/sqrt(numObservations));
end

tiledlayout(1,2);

xAxis = categorical({'15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});
xAxis = reordercats(xAxis,{'15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});

yAxis = meanNumVideos;
erBar = ciNumVideos;

nexttile;
bar1 = bar(xAxis,yAxis)

xtips1 = bar1(1).XEndPoints; ytips1 = bar1(1).YEndPoints;
text(xtips1, ytips1, num2str(transpose(yAxis(1,:)),'%0.0f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");
grid on;
ylabel("Number of Videos Sent by 125 Agents");

hold off

secondsInAMinute = 60;

yAxis = meanVideoLengths./secondsInAMinute;
erBar = ciVideoLengths;

nexttile;
bar2 = bar(xAxis,yAxis);
bar2.FaceColor = [0.8500 0.3250 0.0980];

xtips2 = bar2(1).XEndPoints; ytips2 = bar2(1).YEndPoints;
text(xtips2, ytips2, num2str(transpose(yAxis(1,:)),'%0.0f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

grid on;
ylabel("Combined Length of Videos Sent by 125 Agents in Minutes");
%legend('Fulfilled Requests','Total Requests');



