#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>

class Graph{
	private:
		int G[100][100];
		int m;
		int n;
	public:
		Graph(int m,int n);
		void set_graph();
		void read_graph();
		void disp_graph();
		void readCharFile(string &filePath);
};

#endif