package ultras.src.util;

import inet.mobility.base.MovingMobilityBase;

simple AgentMobility extends MovingMobilityBase
{
    parameters:
        string dynamicsModuleName = default("dynamics");
        double changeInterval = default(0.0);
        double initialX @unit(m) = default(0.0);
        double initialY @unit(m) = default(0.0);
        double initialZ @unit(m) = default(0.0);
        double initialRoll @unit(m) = default(0.0);
        double initialPitch @unit(m) = default(0.0);
        double initialYaw @unit(m) = default(0.0);
        bool initFromDisplayString = default(false); // enables one time initialization from the subject module's display string
//        double speed @unit(mps) = default(0mps); // speed of the host
//        double initialMovementHeading @unit(deg) = default(uniform(0deg, 360deg));
//        double initialMovementElevation @unit(deg) = default(0deg);
        @class(inet::AgentMobility);
}
