import inet.visualizer.integrated.IntegratedCanvasVisualizer;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.physicallayer.contract.packetlevel.IRadioMedium;


import inet.node.inet.WirelessHost;
import inet.applications.udpapp.UdpBasicApp;

simple virusApp extends UdpBasicApp
{
    parameters:
        double timeWhenInfected @unit(s) = default(172800.0s);
        double timeWhenSick @unit(s) = default(432000.0s);

        bool hasVirus = default(false);
        double transmit = default(exponential(1));
        double infectedOrHealthy = default(beta(1,2));
        double sickOrRecover = default(cauchy(1, 1));
        double dieOrRecover = default(uniform(0, 1));

        @class(virusApp);
            // this means that we want to use our virusApp C++ class,
            // otherwise UdpBasicApp class would be used by default                
}

network WirelessNetwork
{
    parameters:
        @display("bgb=50,50;bgu=m;i=background/terrain;is=n;bgg=1,,black");
    submodules:
        visualizer: IntegratedCanvasVisualizer {
            @display("p=2,2;is=m");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=4,2;is=m");
        }
        radioMedium: <default("UnitDiskRadioMedium")> like IRadioMedium {
            @display("p=6,2;is=m");
        }
        host1: WirelessHost {
            @display("p=2,5;i=misc/person;is=m");
        }
        host2: WirelessHost {
            @display("p=3,6;i=misc/person;is=m");
        }
        host3: WirelessHost {
            @display("p=4,6;i=misc/person;is=m");
        }
        host4: WirelessHost {
            @display("p=5,6;i=misc/person;is=m");
        }
        host5: WirelessHost {
            @display("p=6,5;i=misc/person;is=m");
        }
        host6: WirelessHost {
            @display("p=7,4;i=misc/person;is=m");
        }
        host7: WirelessHost {
            @display("p=8,4;i=misc/person;is=m");
        }
        host8: WirelessHost {
            @display("p=9,4;i=misc/person;is=m");
        }
        host9: WirelessHost {
            @display("p=10,3;i=misc/person;is=m");
        }
        host10: WirelessHost {
            @display("p=11,3;i=misc/person;is=m");
        }
}
