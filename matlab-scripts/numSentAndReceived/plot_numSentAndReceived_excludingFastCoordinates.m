numCases = 11;
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
    stdNumReceived(i)=std(numReceived(:,i));
    ciNumReceived(i)=zValue*(stdNumReceived(i)/sqrt(numObservations));

    meanNumSent(i)=mean(combineNumSent(:,i));
    stdNumSent(i)=std(combineNumSent(:,i));
    ciNumSent(i)=zValue*(stdNumSent(i)/sqrt(numObservations));
end

xAxis = categorical({'Coordinates Slow','Images Slow', 'Images Fast', '15fps, 5sec Video Slow', '15fps, 5sec Video Fast', '15fps, 10sec Video Slow', '15fps, 10sec Video Fast', '30fps, 5sec Video Slow', '30fps, 5sec Video Fast', '30fps, 10sec Video Slow', '30fps, 10sec Video Fast'});
xAxis = reordercats(xAxis,{'Coordinates Slow','Images Slow', 'Images Fast', '15fps, 5sec Video Slow', '15fps, 5sec Video Fast', '15fps, 10sec Video Slow', '15fps, 10sec Video Fast', '30fps, 5sec Video Slow', '30fps, 5sec Video Fast', '30fps, 10sec Video Slow', '30fps, 10sec Video Fast'});

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

bar(xAxis,yAxis)

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on
ylabel("Number of Packets");
legend('Received','Sent');



