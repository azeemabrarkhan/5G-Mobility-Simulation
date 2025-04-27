zValue = 1.960;
numObservations = 10;
numAgents = 125;

    for c = 0:numObservations-1
	    sum = 0;
	    for b = c*numAgents:(c*numAgents)+numAgents-1
		    sum = sum + numSent_fastCoordinates(b+1,1);
	    end
	    combineNumSent_fastCoordinates(c+1,1) = sum;
    end
    
meanNumReceived_fastCoordinates(1)=mean(numReceived_fastCoordinates(:,1));
stdNumReceived_fastCoordinates(1)=std(numReceived_fastCoordinates(:,1));
ciNumReceived_fastCoordinates(1)=zValue*(stdNumReceived_fastCoordinates(1)/sqrt(numObservations));

meanNumSent_fastCoordinates(1)=mean(combineNumSent_fastCoordinates(:,1));
stdNumSent_fastCoordinates(1)=std(combineNumSent_fastCoordinates(:,1));
ciNumSent_fastCoordinates(1)=zValue*(stdNumSent_fastCoordinates(1)/sqrt(numObservations));

xAxis = categorical({' .'});
xAxis = reordercats(xAxis,{' .'});

yAxis = [
    meanNumReceived_fastCoordinates(1) meanNumSent_fastCoordinates(1);
    ];

erBar = [
    ciNumReceived_fastCoordinates(1) ciNumSent_fastCoordinates(1);
    ]

tiledlayout(1,3)

nexttile

bar1 = bar(xAxis,yAxis)
ylim([0, 6.5*10^6]);

xtips1 = bar1(1).XEndPoints; ytips1 = bar1(1).YEndPoints;
text(xtips1, ytips1, num2str(yAxis(:,1)./10^6,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom', FontSize=15);
xtips2 = bar1(2).XEndPoints; ytips2 = bar1(2).YEndPoints;
text(xtips2, ytips2, num2str(yAxis(:,2)./10^6,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom', FontSize=15);

hold
er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");
grid on;
hold off
xlabel("Coordinates - Fast");
ylabel("Number of Packets");
legend('Received','Sent');

set(gca,"FontSize",16);

nexttile(2,[1 2])

numCases = 11;

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
    stdNumReceived(i)=std(numReceived(:,i));
    ciNumReceived(i)=zValue*(stdNumReceived(i)/sqrt(numObservations));

    meanNumSent(i)=mean(combineNumSent(:,i));
    stdNumSent(i)=std(combineNumSent(:,i));
    ciNumSent(i)=zValue*(stdNumSent(i)/sqrt(numObservations));
end

xAxis = categorical({'Coordinates - Slow','Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});
xAxis = reordercats(xAxis,{'Coordinates - Slow','Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});

yAxis = [
    meanNumReceived(1) meanNumSent(1);
    meanNumReceived(2) meanNumSent(2);
    meanNumReceived(3) meanNumSent(3);
    meanNumReceived(4) meanNumSent(4);
    meanNumReceived(5) meanNumSent(5);
    meanNumReceived(6) meanNumSent(6);
    meanNumReceived(7) meanNumSent(7);
    meanNumReceived(8) meanNumSent(8);
    meanNumReceived(9) meanNumSent(9);
    meanNumReceived(10) meanNumSent(10);
    meanNumReceived(11) meanNumSent(11);
    ];

erBar = [
    ciNumReceived(1) ciNumSent(1);
    ciNumReceived(2) ciNumSent(2);
    ciNumReceived(3) ciNumSent(3);
    ciNumReceived(4) ciNumSent(4);
    ciNumReceived(5) ciNumSent(5);
    ciNumReceived(6) ciNumSent(6);
    ciNumReceived(7) ciNumSent(7);
    ciNumReceived(8) ciNumSent(8);
    ciNumReceived(9) ciNumSent(9);
    ciNumReceived(10) ciNumSent(10);
    ciNumReceived(11) ciNumSent(11);
    ]

bar2 = bar(xAxis,yAxis)

xtips1 = bar2(1).XEndPoints; ytips1 = bar2(1).YEndPoints;
text(xtips1, ytips1, num2str(yAxis(:,1)./10^6,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom', FontSize=15);
xtips2 = bar2(2).XEndPoints; ytips2 = bar2(2).YEndPoints;
text(xtips2, ytips2, num2str(yAxis(:,2)./10^6,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom', FontSize=15);

hold
er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");
grid on;
hold off
ylabel("Number of Packets");
legend('Received','Sent');

set(gca,"FontSize",16);



