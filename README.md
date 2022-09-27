# Darts Game
This is a game of darts where the player can determine the size of the dartboard (a rectangle), the polygons that need to be hit to score, and where the darts land.

######Note that all points should be input as fractions, the number of polygons cannot be more than 100, the number of vertices must be between 3 and 20, and the number of darts thrown cannot exceed 10.
1. There will be two points used to create a rectangular dartboard. The user input will be the corner opposite of (0,0)
2. The user should then input how many polygons they would like inside the dartboard. This will be used to calculate the score - if a dart lands in this spot, the player's
score will increase
3. The following lines will include how many vertices the polygon has as well as the vertices input as points
4. Once finished, the player will input how many darts they would like to throw as a whole number
5. Finally, they will continue to enter points where they would like the dart to land until they have thrown as many darts as previously entered

## Example input

(10/1,10/1)<br />
2<br />
3 (0/1,0/1) (3/1,0/1) (2/1,1/1)<br />
4 (5/1,1/1) (8/1,4/1) (5/1,7/1) (2/1,4/1)<br />
1<br />
(4/1,9/2)<br />

## Example output

Score: 50/9
