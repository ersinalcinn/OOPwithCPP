#ifndef GATE_H //If GATE_H (gate header) is not defined
#define GATE_H //Define GATE_H

#include <iostream>
#include <stdlib.h>
#include <string>

//Define classes to overcome any "not-defined" errors
class GateList;
class GatePort;
class Gate;
class AndGate;
class OrGate;
class NotGate;
class Flipflop;
class Decoder;

class GateList{
    private:
        int numberOfGates; //Number of gates
        int numberOfPorts; //Number of ports
        Gate ** gateList; //List of gates
        GatePort ** portList; //List of ports
    public:
        void executeGates(); //Execute every gate in the list
        Gate * findGateByName(std::string gateName); //Find gate by given name in gates list
        GatePort * findPortByName(std::string portName); //Find port by given name in ports list
        void addPort(GatePort * port); //Add port to the list
        void addGate(Gate * gate); //Add gate to the list
        int getNumberOfGates(); //Return number of gates
        int getNumberOfPorts(); //Return number of ports
        GatePort * getPortAtIndex(int index); //Return port at given index
        Gate * getGateAtIndex(int index); //Return gate at given index
        GateList(); //Constructor
};

class GatePort{
    private:
        bool value;
        std::string name;
    public:
        int getValue(); //Return value
        void setValue(bool newValue); //Update value
        std::string getName(); //Return name
        GatePort(bool value, std::string name); //Constructor
};

class Gate{
    protected:
        GatePort ** input; //Input ports list
        GatePort ** output; //Output ports list
    public:
        virtual void execute() = 0; //Pure virtual execute function
        GatePort ** getOutput(); //Return output port(s)
        Gate(GatePort * port1, GatePort * port2, std::string outputName); //Constructor for two input and one output gates
        Gate(GatePort * port1, GatePort * port2, std::string outputNames[]); //Constructor for two inpurt and multiple output gates
        Gate(GatePort * port1, std::string outputName); //Constructor for one input and one output gates
};

class AndGate : public Gate{
    public:
        void execute(); //Execute function of the gate
        AndGate(GatePort * port1, GatePort * port2, std::string outputName) : Gate(port1, port2, outputName){} //Constructor that uses gate constructor
};

class OrGate : public Gate{
    public:
        void execute(); //Execute function of the gate
        OrGate(GatePort * port1, GatePort * port2, std::string outputName) : Gate(port1, port2, outputName){} //Constructor that uses gate constructor
};

class NotGate : public Gate{
    public:
        void execute(); //Execute function of the gate
        NotGate(GatePort * port1, std::string outputName) : Gate(port1, outputName){} //Constructor that uses gate constructor
};

class Flipflop : public Gate{
    public:
        void execute(); //Execute function of the gate
        Flipflop(GatePort * port1, std::string outputName) : Gate(port1, outputName){} //Constructor that uses gate constructor
};

class Decoder : public Gate{
    public:
        void execute(); //Execute function of the gate
        Decoder(GatePort * port1, GatePort * port2, std::string outputNames[]) : Gate(port1, port2, outputNames){} //Constructor that uses gate constructor
};

#endif
