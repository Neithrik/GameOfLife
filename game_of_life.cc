#include <iostream>

constexpr int SIZE = 12;
constexpr int NUMBER_OF_STEPS = 20;

bool board[SIZE][SIZE] = {false};
bool new_board[SIZE][SIZE] = {false};

void initialize_board() {
  board[5][5] = 1;
  board[5][6] = 1;
  board[5][7] = 1;
}

void copy_board() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      board[i][j] = new_board[i][j];
    }
  }
}

void print_board() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      std::cout << (board[i][j] ? "*" : ".");
    }
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl;
}

int get_neighbour_count(int i, int j) {
  int count = 0;
  for (int di = -1; di <= 1; ++di) {
    for (int dj = -1; dj <= 1; ++dj) {
      if (di == 0 && dj == 0) continue;
      count += board[i + di][j + dj];
    }
  }
  return count;
}

bool is_alive(int i, int j) {
  int neighbour_count = get_neighbour_count(i, j);
  bool is_currently_alive = board[i][j];
  return neighbour_count == 3 || (neighbour_count == 2 && is_currently_alive);
}

void iterate() {
  for (int i = 1; i < SIZE - 1; ++i) {
    for (int j = 1; j < SIZE - 1; ++j) {
      new_board[i][j] = is_alive(i, j);
    }
  }
  copy_board();
}

int main(int argc, char** argv) {
  initialize_board();
  for (int step = 1; step <= NUMBER_OF_STEPS; ++step) {
    print_board();
    iterate();
  }
}
