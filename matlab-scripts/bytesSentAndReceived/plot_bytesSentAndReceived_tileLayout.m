numCases = 2;
zValue = 1.960;
numObservations = 10;
numAgents = 125;

for j=1:numCases
    for c = 0:numObservations-1
	    sum = 0;
	    for b = c*numAgents:(c*numAgents)+numAgents-1
		    sum = sum + bytesSent_onlyCoordinates(b+1,j);
	    end
	    combineBytesSent_onlyCoordinates(c+1,j) = sum;
    end
end

for i=1:numCases
	meanBytesReceived_onlyCoordinates(i)=mean(bytesReceived_onlyCoordinates(:,i));
    stdBytesReceived_onlyCoordinates(i)=std(bytesReceived_onlyCoordinates(:,i));
    ciBytesReceived_onlyCoordinates(i)=zValue*(stdBytesReceived_onlyCoordinates(i)/sqrt(numObservations));

    meanBytesSent_onlyCoordinates(i)=mean(combineBytesSent_onlyCoordinates(:,i));
    stdBytesSent_onlyCoordinates(i)=std(combineBytesSent_onlyCoordinates(:,i));
    ciBytesSent_onlyCoordinates(i)=zValue*(stdBytesSent_onlyCoordinates(i)/sqrt(numObservations));
end

xAxis = categorical({'Coordinates - Slow','Coordinates - Fast'});
xAxis = reordercats(xAxis,{'Coordinates - Slow','Coordinates - Fast'});

yAxis = [
    meanBytesReceived_onlyCoordinates(1) meanBytesSent_onlyCoordinates(1);
    meanBytesReceived_onlyCoordinates(2) meanBytesSent_onlyCoordinates(2);
    ];

erBar = [
    ciBytesReceived_onlyCoordinates(1) ciBytesSent_onlyCoordinates(1);
    ciBytesReceived_onlyCoordinates(2) ciBytesSent_onlyCoordinates(2);
    ]

tiledlayout(1,3)

nexttile

bar1 = bar(xAxis,yAxis)

%xtips1 = bar1(1).XEndPoints; ytips1 = bar1(1).YEndPoints;
%text(xtips1, ytips1, num2str(yAxis(:,1)./10^8,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom');
%xtips2 = bar1(2).XEndPoints; ytips2 = bar1(2).YEndPoints;
%text(xtips2, ytips2, num2str(yAxis(:,2)./10^8,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
ylabel("Number of Bytes");
legend('Received','Sent');

set(gca,"FontSize",16);

nexttile(2,[1 2])

numCases = 10;

for j=1:numCases
    for c = 0:numObservations-1
	    sum = 0;
	    for b = c*numAgents:(c*numAgents)+numAgents-1
		    sum = sum + bytesSent(b+1,j);
	    end
	    combineBytesSent(c+1,j) = sum;
    end
end

for i=1:numCases
	meanBytesReceived(i)=mean(bytesReceived(:,i));
    stdBytesReceived(i)=std(bytesReceived(:,i));
    ciBytesReceived(i)=zValue*(stdBytesReceived(i)/sqrt(numObservations));

    meanBytesSent(i)=mean(combineBytesSent(:,i));
    stdBytesSent(i)=std(combineBytesSent(:,i));
    ciBytesSent(i)=zValue*(stdBytesSent(i)/sqrt(numObservations));
end

xAxis = categorical({'Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});
xAxis = reordercats(xAxis,{'Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});

yAxis = [
    meanBytesReceived(1) meanBytesSent(1);
    meanBytesReceived(2) meanBytesSent(2);
    meanBytesReceived(3) meanBytesSent(3);
    meanBytesReceived(4) meanBytesSent(4);
    meanBytesReceived(5) meanBytesSent(5);
    meanBytesReceived(6) meanBytesSent(6);
    meanBytesReceived(7) meanBytesSent(7);
    meanBytesReceived(8) meanBytesSent(8);
    meanBytesReceived(9) meanBytesSent(9);
    meanBytesReceived(10) meanBytesSent(10);
    ];

erBar = [
    ciBytesReceived(1) ciBytesSent(1);
    ciBytesReceived(2) ciBytesSent(2);
    ciBytesReceived(3) ciBytesSent(3);
    ciBytesReceived(4) ciBytesSent(4);
    ciBytesReceived(5) ciBytesSent(5);
    ciBytesReceived(6) ciBytesSent(6);
    ciBytesReceived(7) ciBytesSent(7);
    ciBytesReceived(8) ciBytesSent(8);
    ciBytesReceived(9) ciBytesSent(9);
    ciBytesReceived(10) ciBytesSent(10);
    ]

bar2 = bar(xAxis,yAxis)

%xtips1 = bar2(1).XEndPoints; ytips1 = bar2(1).YEndPoints;
%text(xtips1, ytips1, num2str(yAxis(:,1)./10^10,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom');
%xtips2 = bar2(2).XEndPoints; ytips2 = bar2(2).YEndPoints;
%text(xtips2, ytips2, num2str(yAxis(:,2)./10^10,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
ylabel("Number of Bytes");
legend('Received','Sent');

set(gca,"FontSize",16);



