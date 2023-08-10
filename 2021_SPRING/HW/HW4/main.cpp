#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include "gates.h" //Header file of gate definitions
using namespace std;
int main(){
    string circuitFile = "circuit.txt"; //Circuit construction file
    string inputFile = "input.txt"; //Input values file

    ifstream circuitReader(circuitFile); //File stream for circuit file
    string circuitLine;

    string * inputPorts = new string[1]; //Input port names array
    string * outputPorts = new string[1]; //Output port names array

    int numOutputs = 0; //Number of output ports to be shown at the end
    bool hasDecoder = false; //hasDecoder flag is used to track if the circuit has a decoder component at the end
    GateList * gateList = new GateList();

    while(getline(circuitReader, circuitLine)){ //Read every line of the file and write it to circuitLine
        string component;
        string * components = new string[1]; //Splitted string array
        int numComponents = 0; //Number of splitted strings

        stringstream lineReader(circuitLine); //String stream to split string with white spaces

        while(lineReader >> component){ //Read every word of the line and write it to component
            numComponents++;
            string * newComponents = new string[numComponents]; //Construct new larger array
            int i =0;
            for(i; i < numComponents-1; i++) newComponents[i] = components[i]; //Assign elements
            newComponents[i] = component; //Add new component as the last element
            components = newComponents; //Replace arrays
        }

        if(!components[0].compare("INPUT")){ //If the first word is INPUT, construct input ports
            inputPorts = new string[numComponents-1]; //Construct input port names array with correct length
            for(int i = 1; i<numComponents; i++){
                inputPorts[i-1] = components[i]; //Append port names to input port names array
                GatePort * newPort = new GatePort(false, components[i]); //Construct new port with given name
                gateList->addPort(newPort); //Add port to the ports list
            }
        }

        else if(!components[0].compare("OUTPUT")){ //If the first word is OUTPUT, construct output ports
            outputPorts = new string[numComponents-1]; //Construct output port names array with correct length
            for(int i = 1 ; i<numComponents; i++){
                outputPorts[i-1] = components[i]; //Append port names to output port names array
                GatePort * newPort = new GatePort(false, components[i]); //Construct new port with given name
                gateList->addPort(newPort); //Add port to the ports list
            }
            numOutputs = numComponents - 1; //Update number of output ports
        }

        else if(!components[0].compare("AND")){ //If the first word is AND, construct an And gate
            GatePort * port1 = gateList->findPortByName(components[2]); //Get the port with given first input name
            GatePort * port2 = gateList->findPortByName(components[3]); //Get the port with given second input name
            AndGate * andGate = new AndGate(port1, port2, components[1]); //Construct an And gate with given input ports and set output name to the given name

            gateList->addGate(andGate); //Add And gate to the gates array
        }

        else if(!components[0].compare("OR")){ //If the first word is OR, construct an Or gate
            GatePort * port1 = gateList->findPortByName(components[2]); //Get the port with given first input name
            GatePort * port2 = gateList->findPortByName(components[3]); //Get the port with given second input name
            OrGate * orGate = new OrGate(port1, port2, components[1]); //Construct an Or gate with given input ports and set output name to the given name

            gateList->addGate(orGate); //Add Or gate to the gates array
        }

        else if(!components[0].compare("NOT")){ //If the first word is NOT, construct a Not gate
            GatePort * port1 = gateList->findPortByName(components[2]); //Get the port with given input name
            NotGate * notGate = new NotGate(port1, components[1]); //Construct a Not gate with given input port and set output name to the given name

            gateList->addGate(notGate); //Add Not gate to the gates array
        }

        else if(!components[0].compare("FLIPFLOP")){ //If the first word is FLIPFLOP, construct a Flipflop gate
            GatePort * port1 = gateList->findPortByName(components[2]); //Get the port with given input name
            Flipflop * flipflop = new Flipflop(port1, components[1]); //Construct a Fliflop gate with given input port and set output name to the given name

            gateList->addGate(flipflop); //Add Flipflop gate to the gates array
        }

        else if(!components[0].compare("DECODER")){ //If the first word is DECODER, construct a Decoder gate
            GatePort * port1 = gateList->findPortByName(components[5]); //Get the port with given first input name
            GatePort * port2 = gateList->findPortByName(components[6]); //Get the port with given second input name
            string names[4] = {components[1], components[2], components[3], components[4]}; //Construct output port names array
            Decoder * decoder = new Decoder(port1, port2, names); //Construct a Decoder gate with given input ports and set output names with the given names array

            gateList->addGate(decoder); //Add Decoder gate to the gates array

            hasDecoder = true; //Update hasDecoder flag
        }
    }

    ifstream inputReader(inputFile); //File stream for input values file
    string inputLine;
    
    while(getline(inputReader, inputLine)){  //Read every line of the file and write it to inputLine
        string component;
        int numComponents = 0;

        stringstream lineReader(inputLine); //String stream to split string with white spaces

        while(lineReader >> component){ //Read every word of the line and write it to component
            bool value = stoi(component); //stoi converts string to integer values. Since bool values assume every values but zero is 1, a string can be mapped to bool using this.
            gateList->findPortByName(inputPorts[numComponents])->setValue(value); //Find port by input port names and set values of the inputs
            numComponents++;
        }      
        int i =0;
        gateList->executeGates(); //Execute all the gates in the gateList
        if(!hasDecoder){ //If there is no decoder, check output ports list and print all ports

            for(; i<numOutputs-1; i++) cout << (gateList->findPortByName(outputPorts[i])->getValue()) << " ";
            cout << (gateList->findPortByName(outputPorts[i])->getValue()) << endl;
        }
        else{ //If there is a decoder, print output port values of the decoder
            for( i ; i<3; i++) cout << gateList->getGateAtIndex(gateList->getNumberOfGates() - 1)->getOutput()[i]->getValue() << " ";
            cout << gateList->getGateAtIndex(gateList->getNumberOfGates() - 1)->getOutput()[i]->getValue() << endl;
        }
    }
}
