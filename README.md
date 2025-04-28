# 5G-Mobility-Simulation

**Performance Evaluation of a Handover-Enabled 5G Communication System**

## Overview
This project simulates a handover-enabled 5G network designed for Urban Air Mobility (UAM) scenarios. It evaluates network performance when multiple aerial vehicles (air taxis) move through a 5G network, exchanging different types of data like GPS coordinates, images, and video streams.

The simulation uses:
- **OMNeT++** (v5.6.2)
- **INET Framework** (v4.2.2)
- **Simu5G** (v1.1.0)
- **ULTRAS Simulation Framework**

## Goals
- Model multiple gNBs (5G base stations) and mobile user equipment (air taxis).
- Implement handover-enabled UEs capable of transmitting coordinates, images, and videos.
- Measure network performance based on:
  - Latency
  - Packet Delivery Ratio
  - Handover Success Rate
  - Data Volume Exchanged

## Architecture
- **Mobile Core (UPF)**: Handles user data forwarding and mobility.
- **Radio Access Network (gNBs)**: Provides radio connectivity.
- **Flight Schedule Manager**: Spawns air taxi agents that move across the network.
- **Ground Station**: Receives transmitted data.

The network uses **X2-based handovers** for mobility between gNBs.

## Deployment Model
- **Standalone 5G Deployment (SA)**: Pure 5G setup without 4G fallback.

## Use Cases
Simulated use cases include:
- **Coordinates** (sent at different intervals)
- **Images** (pre-defined drone images encoded in Base64)
- **Videos** (simulated frame transmission)

Different parameters like transmission interval, frames per second (fps), and video length are varied to create multiple traffic scenarios.

## Performance Metrics
- **Average Latency**
- **Packet Delivery Ratio**
- **Total Number of Packets and Bytes**
- **Handover Success Percentage**

## Results Summary
- 5G supports **low latency** even under heavy data load.
- **100% handover success** was achieved.
- Video transmission showed the impact of high traffic on packet delivery ratios.

## Future Extensions
- Vary 5G parameters like numerology index, resource blocks, and carrier aggregation.
- Simulate larger networks with more gNBs and UEs.
- Compare 5G network performance with 4G LTE simulations.

## Project Structure
- `/code`: Updated ULTRAS framework and Simu5G modules.
- `/results`: OMNeT++ simulation outputs.
- `/MatLab`: MATLAB scripts for post-processing and visualization.
- `matlab-scripts/`: This directory contains MATLAB scripts used for data processing, analysis, or visualization.
- `result plots/`: This directory stores generated plots and figures from simulations and data analysis.
- `simu5g-src/src/`: This directory holds the updated source code for the simu5g project.
- `ultras-src/src/`: This directory contains the updated source code for the ULTRAS project.
- `virus Network (Introductory network)/`: This directory contains files and configurations related to an introductory network simulation focused on virus propagation.
- `5gAgentNetwork.ini`: This file is an initialization file (INI format) that configures parameters for a 5G agent network simulation.
- `5gAgentNetwork.ned`: This file defines the network description (NED) for the 5G agent network, used by a network simulation framework OMNeT++.
- `Project_report.pdf`: This file is the project's final report in PDF format.
- `README.md`: This file (the current one) provides a general overview of the project, its structure, and other relevant information.
- `Research_project_presentation.pdf`: This file contains the presentation slides for the research project in PDF format.
- `instructions.txt`: This file contains plain text instructions related to the use the updated libraries.

## References
- [Simu5G Documentation](https://github.com/inet-framework/simu5g)
- [OMNeT++ Official Site](https://omnetpp.org/)
---

Created by **Azeem Abrar Khan**
