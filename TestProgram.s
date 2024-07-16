//This is a program that does nothing.
//Its equivalent in C would be
//int main(void){
//    return 0;
//}
//This is a simple function to load
//an immediate into the accumulator.
//MSC DPI 0 puts 0 on the stack.
//MSC DPL pulls the stack onto
//the accumulator.
DPS 0
RST 0
DPS 1
RST 1
DPS 2
RST 2
DPS 3
RST 3
DPS 4
RST 4
DPS 5
RST 5
DPS 6
RST 6
DPS 7
RST 7
//The above instructions are essentially
//clearing registers 1-7 and storing them.
MSC DPL
RST 7
MSC DPL
RST 6
MSC DPL
RST 5
MSC DPL
RST 4
MSC DPL
RST 3
MSC DPL
RST 2
MSC DPL
RST 1
MSC DPL
RST 0
MSC DPI 0
MSC DPL
MSC DPI 0
//The above instructiond push 0 to stack.
//This is a substitute for return 0;
//They also restore the previous values
//of the accumulator.
TER
