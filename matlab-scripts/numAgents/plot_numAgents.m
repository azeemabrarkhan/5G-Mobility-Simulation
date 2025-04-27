timeoffset = 25000;
eNumAgents(:,1) = numAgents(:,1) - timeoffset;

stairs(eNumAgents(:,1),numAgents(:,2));
xlabel("Time in Seconds");
ylabel("Number of Agents");
set(gca,"FontSize",17);