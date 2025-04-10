# megamorpion2
Second attempt at making a TUI [super tic-tac-toe game](https://youtu.be/_Na3a1ZrX7c)

## Building
The `build-ncurses.sh` script downloads `ncurses-6.5` and build it from source statically in `ncurses/`. Just run the script:
```bash
./build-ncurses.sh
```
Then you can compile megamporpion2 (which btw is a single translation unit) and link it against ncurses using the build script:
```bash
./build.sh
```

## Extended rules
There are no offical rules, so I just made some up because I find them fun:

1. When being teleported to the next zone, the coordinates of the selector are random
2. If the next zone is blocked, ie. the sub-game is finished, then the player can choose whatever zone to go to
3. If there is a tie on the mega-game, the winner is the one who has won the most sub-games
