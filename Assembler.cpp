#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
int main(void) {
	std::cout << "QCPU 1 Assembler\nBy Best_Archer\nVersion 1.2.0\n-------------------------\nEnter the input assembly file path.\n";
	std::string current_line;
	std::cin >> current_line;
	std::ifstream ifile(current_line);
	std::cout << "Now, enter the output file path.\n";
	std::cin >> current_line;
	std::ofstream ofile(current_line);
	std::vector<std::string> tokens;
	while (!ifile.eof()) {
		while (std::getline(ifile, current_line)) {
			std::istringstream iss(current_line);
			std::string field;
			while (std::getline(iss, field, ' ')) tokens.push_back(field);
		}
	}
	ifile.close();
	uint8_t byte = 0, bytes = 0;
	for (unsigned i = 0; i < tokens.size(); ++i) {
		bytes = 1;
		if (tokens[i] == "MSC") {
			byte = 0;
			if (tokens[++i] == "DPI") bytes = 2;
			else if (tokens[i] == "DPL") byte += 0b001;
			else if (tokens[i] == "DPK") byte += 0b010;
			else if (tokens[i] == "RET") byte += 0b011;
			else if (tokens[i] == "NTA") byte += 0b110;
			else if (tokens[i] == "PCM") byte += 0b111;
			else byte += 0b100;
		}
		else if (tokens[i] == "DPS") { 
			byte = 0b00001000;
			if(std::stoi(tokens[++i]) > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'DPS [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			} 
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "PRF"){
			byte = 0b00010000;
			if(std::stoi(tokens[++i]) > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'PRF [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "IMM") {
			bytes = 2;
			byte = 0b00011000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'IMM [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "XCH") { 
			byte = 0b00100000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'XCH [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "AST") {
			byte = 0b00101000 + (0b00111 & std::stoi(tokens[++i]));
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'AST [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			else byte += std::stoi(tokens[i]);	
		}
		else if (tokens[i] == "RST"){
			byte = 0b00110000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'RST [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "INC"){
			byte = 0b00111000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'INC [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "DEC"){
			byte = 0b01000000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'DEC [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "NEG"){
			byte = 0b01001000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'NEG [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "RSH"){
			byte = 0b01010000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'RSH [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "ADD"){
			byte = 0b01011000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'ADD [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "SUB"){
			byte = 0b01100000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'SUB [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "IOR"){
			byte = 0b01101000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'IOR [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "AND"){
			byte = 0b01110000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'AND [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "XOR"){
			byte = 0b01111000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'XOR [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "BSL"){
			byte = 0b10000000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'BSL [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "BPL"){
			byte = 0b10001000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'BPL [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "BSR"){
			byte = 0b10010000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'BSR [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "BPR"){
			byte = 0b10011000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'BPR [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "ENT"){
			byte = 0b10100000;
			if(std::stoi(tokens[++i] > 0b11111) {
				byte += 0b11111;
				std::cout << "WARNING: 'ENT [num]' <- [num] > 31, [num] ROUNDED DOWN TO 31.\n";
			}
			else byte += std::stoi(tokens[i]);
		}
		else if (tokens[i] == "DMA") {
			byte = 0b11000000;
			if (tokens[++i] == "execute");
			else if (tokens[i] == "map_config") byte += 0b001;
			else if (tokens[i] == "map_physical") byte += 0b010;
			else if (tokens[i] == "map_restore") byte += 0b011;
			else if (tokens[i] == "copy") byte += 0b100;
			else if (tokens[i] == "k_off") byte += 0b101;
			else if (tokens[i] == "address_stack_push") byte += 0b110;
			else if (tokens[i] == "address_stack_pull") byte += 0b111;
			else {
				std::cout << "AN ERROR OCCURRED!\n";
				return 1;
			}
		}
		else if (tokens[i] == "PRT") {
			byte = 0b10101000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'PRT [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
			bytes = 2;
		}
		else if (tokens[i] == "BRH") {
			byte = 0b10110000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'BRH [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
			bytes = 2;
		}
		else if (tokens[i] == "JMP") {
			byte = 0b10111000;
			if(std::stoi(tokens[++i] > 0b111) {
				byte += 0b111;
				std::cout << "WARNING: 'JMP [num]' <- [num] > 7, [num] ROUNDED DOWN TO 7.\n";
			}
			else byte += std::stoi(tokens[i]);
			bytes = 2;
		}
		else if (tokens[i] == "MST") {
			byte = 0b11000000;
			if(std::stoi(tokens[++i] > 0b1111) {
				byte += 0b1111;
				std::cout << "WARNING: 'MST [num]' <- [num] > 15, [num] ROUNDED DOWN TO 15.\n";
			}
			else byte += std::stoi(tokens[i]);
			bytes = 2;
		}
		else if (tokens[i] == "MLD") {
			byte = 0b11110000;
			if(std::stoi(tokens[++i] > 0b1111) {
				byte += 0b1111;
				std::cout << "WARNING: 'MLD [num]' <- [num] > 15, [num] ROUNDED DOWN TO 15.\n";
			}
			else byte += std::stoi(tokens[i]);
			bytes = 2;
		}
		else if (tokens[i] == "CLR") byte = 0b00101000;
		else if (tokens[i] == "FWD") byte = 0b00110000;
		else if (tokens[i] == "LCK") byte = 0b01001000;
		else if (tokens[i] == "ULK") byte = 0b01010000;
		else if (tokens[i] == "END") byte = 0b01011000;
		else if (tokens[i] == "TER") byte = 0b01100000;
		else if (tokens[i] == "LRT") byte = 0b01101000;
		else if (tokens[i] == "NOP") byte = 0b01111000;
		else if (tokens[i] == "JMP(A)") byte = 0b10000000;
		else if (tokens[i] == "CAL(A)") byte = 0b10001000;
		else {
			std::cout << "ERROR: INVALID OPERATION IN FILE AT" << tokens[i] << ' ' << tokens[++i] << '\n';
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
