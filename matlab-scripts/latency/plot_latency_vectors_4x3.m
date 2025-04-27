timeoffset = 25000;
eNumAgents(:,1) = numAgents(:,1) - timeoffset;
eLatency1(:,1) = latency1(:,1) - timeoffset;
eLatency2(:,1) = latency2(:,1) - timeoffset;
eLatency3(:,1) = latency3(:,1) - timeoffset;
eLatency4(:,1) = latency4(:,1) - timeoffset;
eLatency5(:,1) = latency5(:,1) - timeoffset;
eLatency6(:,1) = latency6(:,1) - timeoffset;
eLatency7(:,1) = latency7(:,1) - timeoffset;
eLatency8(:,1) = latency8(:,1) - timeoffset;
eLatency9(:,1) = latency9(:,1) - timeoffset;
eLatency10(:,1) = latency10(:,1) - timeoffset;
eLatency11(:,1) = latency11(:,1) - timeoffset;
eLatency12(:,1) = latency12(:,1) - timeoffset;

latency1(:,2) = latency1(:,2) * 1000;
latency2(:,2) = latency2(:,2) * 1000;
latency3(:,2) = latency3(:,2) * 1000;
latency4(:,2) = latency4(:,2) * 1000;
latency5(:,2) = latency5(:,2) * 1000;
latency6(:,2) = latency6(:,2) * 1000;
latency7(:,2) = latency7(:,2) * 1000;
latency8(:,2) = latency8(:,2) * 1000;
latency9(:,2) = latency9(:,2) * 1000;
latency10(:,2) = latency10(:,2) * 1000;
latency11(:,2) = latency11(:,2) * 1000;
latency12(:,2) = latency12(:,2) * 1000;

tiledlayout(4,3);

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency1(:,1),latency1(:,2));
ylabel("Latency in Milliseconds");
title("Coordinates - Slow")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency2(:,1),latency2(:,2));
ylabel("Latency in Milliseconds");
title("Coordinates - Fast")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency3(:,1),latency3(:,2));
ylabel("Latency in Milliseconds");
title("Images - Slow")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency4(:,1),latency4(:,2));
ylabel("Latency in Milliseconds");
title("Images - Fast")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency5(:,1),latency5(:,2));
ylabel("Latency in Milliseconds");
title("15fps, 5secs Video - Slow")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency6(:,1),latency6(:,2));
ylabel("Latency in Milliseconds");
title("15fps, 5secs Video - Fast")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency7(:,1),latency7(:,2));
ylabel("Latency in Milliseconds");
title("15fps, 10secs Video - Slow")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency8(:,1),latency8(:,2));
ylabel("Latency in Milliseconds");
title("15fps, 10secs Video - Fast")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency9(:,1),latency9(:,2));
ylabel("Latency in Milliseconds");
title("30fps, 5secs Video - Slow")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency10(:,1),latency10(:,2));
ylabel("Latency in Milliseconds");
title("30fps, 5secs Video - Fast")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency11(:,1),latency11(:,2));
ylabel("Latency in Milliseconds");
title("30fps, 10secs Video - Slow")
hold off;

nexttile;
yyaxis left;
stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
hold;
yyaxis right;
scatter(eLatency12(:,1),latency12(:,2));
ylabel("Latency in Milliseconds");
title("30fps, 10secs Video - Fast")
hold off;
