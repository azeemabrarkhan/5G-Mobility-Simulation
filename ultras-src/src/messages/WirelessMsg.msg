cplusplus{{
    #include "util/DataTypes/StateDataTypes.h" 
    #include "modules/vehicle/CommunicationCoordinator.h"
    
}};

struct StateWithCovariance;


message WirelessMsg
{
   StateWithCovariance VehicleLocation; 
}
