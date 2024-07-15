#include <iostream>
#include <fstream>
#include <string>
#include <vector>
int main(void) {
	std::cout << "QCPU 1 Assembler\nBy Best_Archer\nVersion 1.0.1\n-------------------------\nEnter the input assembly file path.\n";
	std::string current_line;
	std::cin >> current_line;
	std::ifstream ifile(current_line);
	std::cout << "Now, enter the output file path.\n";
	std::cin >> current_line;
	std::ofstream ofile(current_line);
	std::vector<std::string> tokens;
	while(!ifile.eof()){
		std::getline(ifile, current_line, ' ');
		tokens.push_back(current_line);
	}
	ifile.close();
	delete(&current_line);
	uint8_t byte = 0, bytes = 0;
	for (unsigned i = 0; i < tokens.size(); ++i) {
		bytes = 1;
		if (tokens[i] == "MSC") {
			byte = 0;
			if (tokens[++i] == "DPI") bytes = 2;
			else if (tokens[i] == "DPL") {
				byte += 0b001;
			}
			else if (tokens[i] == "DPK") {
				byte += 0b010;
			}
			else if (tokens[i] == "RET") {
				byte += 0b011;
			}
			else if (tokens[i] == "NTA") {
				byte += 0b110;
			}
			else if (tokens[i] == "PCM") {
				byte += 0b111;
			}
			else {
				byte += 0b100;
			}
		}
		else if (tokens[i] == "DPS") byte = 0b00001000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "PRF") byte = 0b00010000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "IMM") {
			bytes = 2;
			byte = 0b00011000 + (0b111 & std::stoi(tokens[++i]));
		}
		else if (tokens[i] == "XCH") byte = 0b00100000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "AST") byte = 0b00101000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "RST") byte = 0b00110000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "INC") byte = 0b00111000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "DEC") byte = 0b01000000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "NEG") byte = 0b01001000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "RSH") byte = 0b01010000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "ADD") byte = 0b01011000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "SUB") byte = 0b01100000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "IOR") byte = 0b01101000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "AND") byte = 0b01110000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "XOR") byte = 0b01111000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "BSL") byte = 0b10000000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "BPL") byte = 0b10001000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "BSR") byte = 0b10010000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "BPR") byte = 0b10011000 + (0b00111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "ENT") byte = 0b10100000 + (0b11111 & std::stoi(tokens[++i]));
		else if (tokens[i] == "DMA") {
			byte = 0b11000000;
			if (tokens[i] == "execute");
			else if (tokens[i] == "map_config") byte += 0b001;
			else if (tokens[i] == "map_physical") byte += 0b010;
			else if (tokens[i] == "map_restore") byte += 0b011;
			else if (tokens[i] == "copy") byte += 0b100;
			else if (tokens[i] == "k_off") byte += 0b101;
			else if (tokens[i] == "address_stack_push") byte += 0b110;
			else if (tokens[i] == "address_stack_pull") byte += 0b111;
			else {
				std::cout << "AN ERROR OCCURRED!";
				return 1;
			}
		}
		else if (tokens[i] == "PRT") {
			byte = 0b10101000 + (0b00111 & std::stoi(tokens[++i]));
			bytes = 2;
		}
		else if (tokens[i] == "BRH") {
			byte = 0b10110000 + (0b00111 & std::stoi(tokens[++i]));
			bytes = 2;
		}
		else if (tokens[i] == "JMP") {
			byte = 0b10111000 + (0b00111 & std::stoi(tokens[++i]));
			bytes = 2;
		}
		else if (tokens[i] == "MST") {
			byte = 0b11000000 + (0b01111 & std::stoi(tokens[++i]));
			bytes = 2;
		}
		else if (tokens[i] == "MLD") {
			byte = 0b11110000 + (0b01111 & std::stoi(tokens[++i]));
			bytes = 2;
		}
		else {
			std::cout << "AN ERROR OCCURRED!";
			return 1;
		}
		ofile << byte;
		if (bytes > 1) {
			byte = std::stoi(tokens[++i]);
			ofile << byte;
		}
	}
	ofile.close();
	return 0;
}
