numCases = 12;
zValue = 1.960;
numObservations = 10;
numAgents = 125;

for j=1:numCases
    for c = 0:numObservations-1
	    sum = 0;
	    for b = c*numAgents:(c*numAgents)+numAgents-1
		    sum = sum + numSent(b+1,j);
	    end
	    combineNumSent(c+1,j) = sum;
    end
end

for i=1:numCases
	meanNumReceived(i)=mean(numReceived(:,i));
    meanNumSent(i)=mean(combineNumSent(:,i));
end

deliveryRatio = meanNumReceived ./ meanNumSent;

xAxis = categorical({'Coordinates - Slow','Coordinates - Fast','Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});
xAxis = reordercats(xAxis,{'Coordinates - Slow','Coordinates - Fast','Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});

yaxis = deliveryRatio;

bar(xAxis,yaxis)

ylim([0,1.1]);

%xtips = bar(1).XEndPoints; ytips = bar(1).YEndPoints;
%text(xtips, ytips, num2str(transpose(yaxis(1,:)),'%0.5f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold;
blank = [0 0 0 0 0 0 0 0 0 0 0 0];
bar(xAxis, yaxis*0)

grid on;
ylabel("Packet Delivery Ratio");
legend("Slow","Fast");
set(gca,"FontSize",17);








