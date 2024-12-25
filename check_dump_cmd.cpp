#include <bits/stdc++.h>

using namespace std;

ifstream input("autoexec.cfg");

vector<string> data(string a) {
	vector<string> v, n;
	istringstream izz(a);
	string b;
	while (izz >> b) {
		v.emplace_back(b);
	}
	int s = v.size();
	if (s > 3) {
		int e = 2;
		string c = "";
		while (e < s) {
			c += v[e];
			if (e != s-1)
				c += " ";
			e++;
		}
		n.push_back(v[0]);
		n.push_back(v[1]);
		n.push_back(c);
	}
	else if (s <= 3) {
		n = v;
	}
	return n;
}

int main() {
	
	if (!input.is_open()) {
		cout << "Cant Open!" << endl;
		system("pause");
		return 0;
	}
	
	map<string,int> config;
	map<string,int> all;
	map<string,int> button;
	map<string,int> bind;
	map<string,int> alias;
	map<string,int> command;
	
	string sline;
	
	int line = 0, error = 0;
	bool blacklist = false;
	while (getline(input,sline)) {
		
		line++;
		//============================================================================================================================================
		if (sline.empty()) {
			continue;
		}
		if (sline == "//blacklist") {
			blacklist = !blacklist;
		}
		if (blacklist) {
			continue;
		}
		if (sline[0] == '/') {
			continue;
		}
		//============================================================================================================================================
		if (all.find(sline) != all.end()) {
			cout << "Line " << line << " is the same with line " << all[sline] << "." << endl;
			cout << "     " << sline << endl << endl;
			error++;
			continue;
		}
		else {
			all[sline] = line;
		}
		//============================================================================================================================================		
		vector<string> cmd = data(sline);
		//============================================================================================================================================
		if (cmd[0] == "bind") {
			if (button.find(cmd[1]) != button.end()) {
				cout << "Line " << line << " - Duplicate Button with line " << button[cmd[1]] << "." << endl;
				cout << "     " << cmd[1] << endl << endl;
				error++;
			}
			else {
				button[cmd[1]] = line;
			}
			
			if (bind.find(cmd[2]) != bind.end()) {
				cout << "Line " << line << " - Duplicate Bind with line " << bind[cmd[2]] << "." << endl;
				cout << "     " << cmd[2] << endl << endl;
				error++;
			}
			else {
				bind[cmd[2]] = line;
			}
			continue;
		}
		//============================================================================================================================================
		if (cmd[0] == "alias") {
			if (alias.find(cmd[1]) != alias.end()) {
				cout << "Line " << line << " - Duplicate Alias Name with line " << alias[cmd[1]] << "." << endl;
				cout << "     " << cmd[1] << endl << endl;
				error++;
			}
			else {
				alias[cmd[1]] = line;
			}
			
			if (command.find(cmd[2]) != command.end()) {
				cout << "Line " << line << " - Duplicate Command with line " << command[cmd[2]] << "." << endl;
				cout << "     " << sline << endl << endl;
				error++;
			}
			else {
				command[cmd[2]] = line;
			}
			continue;
		}
		//============================================================================================================================================
		if (config.find(cmd[0]) != config.end()) {
			cout << "Line " << line << " - Conflict Config with line " << config[cmd[0]] << "." << endl;
			cout << "     " << cmd[0] << endl << endl;
			error++;
		}
		else {
			config[cmd[0]] = line;
		}
	}
	cout << "Completed! Error: " << error << endl;
	system("pause");
}
