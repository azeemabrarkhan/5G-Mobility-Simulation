numCases = 12;
zValue = 1.960;
numObservations = 10;
numGNbs = 4;

for j=1:numCases
    for c = 0:numObservations-1
	    sumForSentHandoverReqs = 0;
        sumForSuccessfulHandoverReqs = 0
	    for b = c*numGNbs:(c*numGNbs)+numGNbs-1
		    sumForSentHandoverReqs = sumForSentHandoverReqs + sentHandoverReqs(b+1,j);
            sumForSuccessfulHandoverReqs = sumForSuccessfulHandoverReqs + successfulHandoverReqs(b+1,j);
	    end
	    combinedSentHandoverReqs(c+1,j) = sumForSentHandoverReqs;
        combinedSuccessfulHandoverReqs(c+1,j) = sumForSuccessfulHandoverReqs;
    end
end

for i=1:numCases
	meanSuccessfulHandoverReqs(i)=mean(combinedSuccessfulHandoverReqs(:,i));
    stdSuccessfulHandoverReqs(i)=std(combinedSuccessfulHandoverReqs(:,i));
    ciSuccessfulHandoverReqs(i)=zValue*(stdSuccessfulHandoverReqs(i)/sqrt(numObservations));

    meanSentHandoverReqs(i)=mean(combinedSentHandoverReqs(:,i));
    stdSentHandoverReqs(i)=std(combinedSentHandoverReqs(:,i));
    ciSentHandoverReqs(i)=zValue*(stdSentHandoverReqs(i)/sqrt(numObservations));
end

xAxis = categorical({'Coordinates - Slow','Coordinates - Fast','Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});
xAxis = reordercats(xAxis,{'Coordinates - Slow','Coordinates - Fast','Images - Slow', 'Images - Fast', '15fps, 5secs Video - Slow', '15fps, 5secs Video - Fast', '15fps, 10secs Video - Slow', '15fps, 10secs Video - Fast', '30fps, 5secs Video - Slow', '30fps, 5secs Video - Fast', '30fps, 10secs Video - Slow', '30fps, 10secs Video - Fast'});

yAxis = [
    meanSuccessfulHandoverReqs(1) meanSentHandoverReqs(1);
    meanSuccessfulHandoverReqs(2) meanSentHandoverReqs(2);
    meanSuccessfulHandoverReqs(3) meanSentHandoverReqs(3);
    meanSuccessfulHandoverReqs(4) meanSentHandoverReqs(4);
    meanSuccessfulHandoverReqs(5) meanSentHandoverReqs(5);
    meanSuccessfulHandoverReqs(6) meanSentHandoverReqs(6);
    meanSuccessfulHandoverReqs(7) meanSentHandoverReqs(7);
    meanSuccessfulHandoverReqs(8) meanSentHandoverReqs(8);
    meanSuccessfulHandoverReqs(9) meanSentHandoverReqs(9);
    meanSuccessfulHandoverReqs(10) meanSentHandoverReqs(10);
    meanSuccessfulHandoverReqs(11) meanSentHandoverReqs(11);
    meanSuccessfulHandoverReqs(12) meanSentHandoverReqs(12)
    ];

erBar = [
    ciSuccessfulHandoverReqs(1) ciSentHandoverReqs(1);
    ciSuccessfulHandoverReqs(2) ciSentHandoverReqs(2);
    ciSuccessfulHandoverReqs(3) ciSentHandoverReqs(3);
    ciSuccessfulHandoverReqs(4) ciSentHandoverReqs(4);
    ciSuccessfulHandoverReqs(5) ciSentHandoverReqs(5);
    ciSuccessfulHandoverReqs(6) ciSentHandoverReqs(6);
    ciSuccessfulHandoverReqs(7) ciSentHandoverReqs(7);
    ciSuccessfulHandoverReqs(8) ciSentHandoverReqs(8);
    ciSuccessfulHandoverReqs(9) ciSentHandoverReqs(9);
    ciSuccessfulHandoverReqs(10) ciSentHandoverReqs(10);
    ciSuccessfulHandoverReqs(11) ciSentHandoverReqs(11);
    ciSuccessfulHandoverReqs(12) ciSentHandoverReqs(12);
    ]

bar = bar(xAxis,yAxis)
ylim([0,3500]);

%xtips1 = bar(1).XEndPoints; ytips1 = bar(1).YEndPoints;
%text(xtips1, ytips1, num2str(yAxis(:,1),'%0.0f'),'HorizontalAlignment','center','VerticalAlignment','bottom');
%xtips2 = bar(2).XEndPoints; ytips2 = bar(2).YEndPoints;
%text(xtips2, ytips2, num2str(yAxis(:,2),'%0.0f'),'HorizontalAlignment','center','VerticalAlignment','bottom');

hold

er = errorbar(xAxis,yAxis,erBar,erBar,"LineStyle","none");

hold off

grid on;
ylabel("Number of Handover Requests");
legend('Fulfilled Requests','Total Requests');
set(gca,"FontSize",17);



