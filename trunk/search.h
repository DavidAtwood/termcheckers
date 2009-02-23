#ifndef SEARCH_H
#define SEARCH_H

#include "board.h"
#include "timer.h"
#include <vector>

// DEFINE WHAT OPTIMIZATIONS TO USE:
#define SCOUT
#define HISTORY_HEURISTIC

namespace checkers {

	struct SearchResult {
		int nodes;
		int depth;
		int time;
		int value;
		int extendedDepth;
		std::vector<unsigned int> move;
	};

	class Search {
		public:
			Search();
			~Search();

			SearchResult search(Board board, int time);
		private:
			int alphabeta(Board& b, int depth, int alpha, int beta);
			int captureAlphaBeta(Board& b, int depth, int alpha, int beta, unsigned int from);
			bool singleJump(Board b);
			void newBestMove(Board& board, unsigned int from, unsigned int to);
			//inline void sortMovesHeap(unsigned int movelist[], int movevalues[], unsigned int movecount);
			//inline void siftDown(unsigned int movelist[], int movevalues[], int start, int end);
			inline void swap(unsigned int movelist[], int movevalues[], int a, int b);
			inline void insertMove(unsigned int movelist[], int movevalues[], unsigned int from, unsigned int to, int newValue, unsigned int& movecount);

			std::vector<unsigned int>* movement;
			std::vector<unsigned int>* capture_movement;

			timer::Timer* timer;

			int time;
			int maxdepth;
			int nrOfNodes;
			int extendedDepth;
			bool finished_search;
			int time_check;
			int max_time;
#ifdef HISTORY_HEURISTIC
			int history[32][32];
#endif // HISTORY_HEURISTIC

	};
}

#endif // SEARCH_H
