**Conways Game Of Life**

Programming Language: C++

Platform: Visual Studio 2015

Made by: Ender Phan (Loc Phan)

**1. Rules of the Game:**

   The game consists of a grid of cells. Each cell is either alive or dead. Every cell interacts with its eight adjacent cells.
   
   Before the start of the game, the user can select which cells are alive or dead.
   
   The user can not change the states of the cells while the automation is running.
   
   Once the game is started, the states of the cells in the next frame are calculated for all cells in the grid based on the following rules:

   *If a live cell has fewer than two live neighbours, it dies,*
   
   *If a live cell has two or three live neighbours, it lives,*
   
   *If a live cell has more than five live neighbours, it dies,*
   
   *If a dead cell has three live neighbours, it becomes alive;*

   The game calculates and displays new frames until the automation is stopped.

**2. The ideas of coding**

  Firstly making the window for itself and draw the grid and the size of grid is not larger than the size of window.
  
  Here the size of the windows is width x height = 600 x 600 (it is also grid's size). 
  
  Grid is contain many small of cells, the pixel of the cell will be 15x15 and the quantity of the cell should be 600 devided by 15 is 40. So we have 40 Cells in each row and 40 cells in each column.
  
  Base on the quantity of the cell as well as the pixel of each cell, we can use that to indicate the mouse pressed position. After mouse pressed, it will know exactly where the cell is staying at. 
  
  In order to know the cell is choosen or not choosen, I decided to give a color for it. At the beginning of the game, all cells are dead with the background color. Every mouse pressed it will make the cell alive and change the color as White, and it will make the cell die for the next press.
  
  After players have choose their alive cells, they will hit Enter to execute the game and next Enter to turn on the Edit mode. In the Edit mode, players will be able to delete or chose other alive cells. In during the execution time, the Edit mode will be off, it means players could not edit the cell at all.
  
  The header code cotains 2 classes Grid class and Cell class. Each class will interact with each other, the Cell class will decide the cell is alive or dead, and Grid class will indicate the position of the cell base on the infomation given from Cell class.
  
  Base on the rules of the game, given out the *neightbour values which will be a value for the choosen cell to compare and decide it will die or alive.
  
  
