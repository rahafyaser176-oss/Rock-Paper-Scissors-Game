# Rock Paper Scissors Game 🎮

A simple Rock, Paper, Scissors game written in C++, where you play against the computer for a number of rounds you choose.

## Features

- Choose the number of rounds to play (1 to 10)
- Computer randomly picks its move each round
- Displays the result of each round individually
- Changes the console color based on the round winner (Windows only)
- Final summary at the end: total wins, losses, draws, and the overall winner

## How to Play

1. Run the program
2. Choose how many rounds you want to play
3. Each round, pick [1] Rock, [2] Paper, or [3] Scissors
4. The program shows your choice, the computer's choice, and the round winner
5. At the end, you'll see the full game summary

## Game Rules

- Rock beats Scissors
- Scissors beats Paper
- Paper beats Rock

## Note

The program uses `system("color ...")` to change the screen color, which only works on Windows.

## Requirements

- Any C++ compiler (e.g. g++ or Visual Studio)

## Running the Game

```bash
g++ main.cpp -o rps_game
./rps_game
```

(or run it directly from Visual Studio if that's what you're using)

---

This is my first C++ project.
