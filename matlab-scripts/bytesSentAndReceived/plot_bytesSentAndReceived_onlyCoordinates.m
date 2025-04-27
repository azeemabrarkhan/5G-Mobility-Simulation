numCases = 2;
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

xAxis = categorical({'Coordinates Slow','Coordinates Fast'});
xAxis = reordercats(xAxis,{'Coordinates Slow','Coordinates Fast'});

yAxis = [
    meanBytesReceived(1) meanBytesSent(1);
    meanBytesReceived(2) meanBytesSent(2);
    ];

erBar = [
    ciBytesReceived(1) ciBytesSent(1);
    ciBytesReceived(2) ciBytesSent(2);
    ]

bar = bar(xAxis,yAxis)

xtips1 = bar(1).XEndPoints; ytips1 = bar(1).YEndPoints;
text(xtips1, ytips1, num2str(yAxis(:,1)./10^8,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom');
xtips2 = bar(2).XEndPoints; ytips2 = bar(2).YEndPoints;
text(xtips2, ytips2, num2str(yAxis(:,2)./10^8,'%0.2f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
ylabel("Number of Bytes");
legend('Received','Sent');



