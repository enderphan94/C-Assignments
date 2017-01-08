**Conways Game Of Life**

Programming Language: C++
Platform: Visual Studio 2015
Made by: Ender Phan (Loc Phan)

1. Rules of the Game:

  The game consists of a grid of cells. Each cell is either alive or dead. Every cell interacts with its eight adjacent cells.
  Before the start of the game, the user can select which cells are alive or dead.
  The user can not change the states of the cells while the automation is running.
  Once the game is started, the states of the cells in the next frame are calculated for all cells in the grid based on the following rules:

  If a live cell has fewer than two live neighbours, it dies,
  If a live cell has two or three live neighbours, it lives,
  If a live cell has more than five live neighbours, it dies,
  If a dead cell has three live neighbours, it becomes alive;

  The game calculates and displays new frames until the automation is stopped.

2. The ideas of coding

