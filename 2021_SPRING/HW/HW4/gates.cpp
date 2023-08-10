#include <iostream>
#include <stdlib.h>
#include <string>

#include "gates.h"  //Header file of gate definitions

void GateList::executeGates(){
    int i=0;
    for(; i<this->numberOfGates; i++) this->gateList[i]->execute(); //Execute all gates in the list
}

Gate * GateList::findGateByName(std::string gateName){
    int i=0;
    //Run for every gate in the list, if names of output ports are equal return the gate. Return NULL if not found.
    for(;i < this->numberOfGates; i++) if(!this->gateList[i]->getOutput()[0]->getName().compare(gateName)) return this->gateList[i];
    return NULL;
}

GatePort * GateList::findPortByName(std::string portName){
    int i=0;
    //Run for every port in the list, if names are equal return the port. Return NULL if not found.
    for(;i < this->numberOfPorts; i++) if(!this->portList[i]->getName().compare(portName)) return this->portList[i];
    return NULL;
}

void GateList::addPort(GatePort * port){
    int i=0;
    bool exists = false; //Flag to be used to track if the port with the same name exists
    for(; i<this->numberOfPorts; i++) if(!port->getName().compare(this->portList[i]->getName())){ //Check names of all the ports
        this->portList[i] = port; //Replace the port found with the same name with the new one to overcome multiple ports with same name problem
        exists = true; //Update flag
    };
    if(!exists){ //If the port with the same name does not exist
        GatePort ** newPortList = new GatePort * [this->numberOfPorts + 1]; //Construct array with required length
        for(i=0; i<this->numberOfPorts; i++) newPortList[i] = this->portList[i]; //Assign elements of the old list to the new list
        newPortList[i] = port; //Add new port as the last element
        delete(this->portList); //Clear old port list memory
        this->portList = newPortList; //Update port list address
        this->numberOfPorts++; //Increase number of ports
    }    
}

void GateList::addGate(Gate * gate){
    Gate ** newGateList = new Gate * [this->numberOfGates + 1]; //Construct array with required length
    int i=0;
    for(; i<this->numberOfGates; i++) newGateList[i] = this->gateList[i]; //Assign elements of the old list to the new list
    newGateList[i] = gate; //Add new gate as the last element
    delete(this->gateList);  //Clear old gate list memory
    this->gateList = newGateList; //Update gate list address
    this->numberOfGates++; //Increase number of gates
    this->addPort(gate->getOutput()[0]); //Add output port of the new gate to the ports list
}

int GateList::getNumberOfGates(){
    return this->numberOfGates; //Return number of gates
}

int GateList::getNumberOfPorts(){
    return this->numberOfPorts; //Return number of ports
}

GatePort * GateList::getPortAtIndex(int index){
    return this->portList[index]; //Return port at given index
}

Gate * GateList::getGateAtIndex(int index){
    return this->gateList[index]; //Return gate at given index
}

GateList::GateList(){
    this->numberOfGates = 0; //Initialize gate list with 0 gates
    this->numberOfPorts = 0; //Initialize gate list with 0 ports
    this->gateList = new Gate * [1]; //Assign temporary array
    this->portList = new GatePort * [1]; //Assign temporary array
}

GatePort::GatePort(bool value, std::string name){
    this->value = value;
    this->name = name;
}

int GatePort::getValue(){
    return this->value; //Return value
}

void GatePort::setValue(bool newValue){
    this->value = newValue; //Update value
}

std::string GatePort::getName(){
    return this->name; //Return name
}

Gate::Gate(GatePort * port1, GatePort * port2, std::string outputName){
    this->input = new GatePort * [2]; //Allocate memory for 2 input ports
    this->input[0] = port1; //Set first port
    this->input[1] = port2; //Set second port

    this->output = new GatePort * [1]; //Allocate memory for 1 output port
    this->output[0] = new GatePort(false, outputName); //Construct output
}

Gate::Gate(GatePort * port1, GatePort * port2, std::string outputNames[]){
    this->input = new GatePort * [2]; //Allocate memory for 2 input ports
    this->input[0] = port1; //Set first port
    this->input[1] = port2; //Set second port

    this->output = new GatePort * [4]; //Allocate memory for 4 output ports
    this->output[0] = new GatePort(false, outputNames[0]); //Construct output 1
    this->output[1] = new GatePort(false, outputNames[1]); //Construct output 2
    this->output[2] = new GatePort(false, outputNames[2]); //Construct output 3
    this->output[3] = new GatePort(false, outputNames[3]); //Construct output 4
}

Gate::Gate(GatePort * port1, std::string outputName){
    this->input = new GatePort * [1]; //Allocate memory for 1 input port
    this->input[0] = port1; //Set port

    this->output = new GatePort * [1]; //Allocate memory for 1 output port
    this->output[0] = new GatePort(false, outputName); //Construct output
}

GatePort ** Gate::getOutput(){
    return this->output; //Return output port
}

void AndGate::execute(){
    this->output[0]->setValue(this->input[0]->getValue() & this->input[1]->getValue()); //Apply and operation to the input values
}

void OrGate::execute(){
    this->output[0]->setValue(this->input[0]->getValue() | this->input[1]->getValue()); //Apply or operation to the input values
}

void NotGate::execute(){
    this->output[0]->setValue(!this->input[0]->getValue()); //Apply not operation to the input
}

void Flipflop::execute(){
    this->output[0]->setValue(this->input[0]->getValue() != this->output[0]->getValue()); //Update output with input and last output value
}

void Decoder::execute(){
    //Update output values with respect to the given tables in the homework
    this->output[0]->setValue(!this->input[0]->getValue() & !this->input[1]->getValue());
    this->output[1]->setValue(!this->input[0]->getValue() & this->input[1]->getValue());
    this->output[2]->setValue(this->input[0]->getValue() & !this->input[1]->getValue());
    this->output[3]->setValue(this->input[0]->getValue() & this->input[1]->getValue());
}
