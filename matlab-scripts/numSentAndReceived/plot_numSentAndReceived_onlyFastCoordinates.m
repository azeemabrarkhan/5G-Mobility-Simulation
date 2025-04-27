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

bar(xAxis,yAxis)

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
xlabel("Coordinates Fast");
ylabel("Number of Packets");
legend('Received','Sent');



