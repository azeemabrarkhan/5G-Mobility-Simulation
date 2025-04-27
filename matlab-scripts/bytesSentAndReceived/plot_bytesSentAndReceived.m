numCases = 12;
zValue = 1.960;
numObservations = 10;
numAgents = 125;

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

xAxis = categorical({'Coordinates Slow','Coordinates Fast','Images Slow', 'Images Fast', '15fps, 5sec Video Slow', '15fps, 5sec Video Fast', '15fps, 10sec Video Slow', '15fps, 10sec Video Fast', '30fps, 5sec Video Slow', '30fps, 5sec Video Fast', '30fps, 10sec Video Slow', '30fps, 10sec Video Fast'});
xAxis = reordercats(xAxis,{'Coordinates Slow','Coordinates Fast','Images Slow', 'Images Fast', '15fps, 5sec Video Slow', '15fps, 5sec Video Fast', '15fps, 10sec Video Slow', '15fps, 10sec Video Fast', '30fps, 5sec Video Slow', '30fps, 5sec Video Fast', '30fps, 10sec Video Slow', '30fps, 10sec Video Fast'});

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
    meanBytesReceived(11) meanBytesSent(11);
    meanBytesReceived(12) meanBytesSent(12)
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
    ciBytesReceived(11) ciBytesSent(11);
    ciBytesReceived(12) ciBytesSent(12);
    ]

bar = bar(xAxis,yAxis)

xtips1 = bar(1).XEndPoints; ytips1 = bar(1).YEndPoints;
text(xtips1, ytips1, num2str(yAxis(:,1)./10^10,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom');
xtips2 = bar(2).XEndPoints; ytips2 = bar(2).YEndPoints;
text(xtips2, ytips2, num2str(yAxis(:,2)./10^10,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
ylabel("Number of Bytes");
legend('Received','Sent');



