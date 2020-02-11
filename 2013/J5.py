from sys import stdin

input = stdin.readline

games = [[1, 2], [1, 3], [1, 4],
         [2, 3], [2, 4], [3, 4]]
points = [0 for i in range(5)]
T = int(input())
G = int(input())


def simulate(gamesLeft, pts, game, w):
    if w == 1:
        pts[game[0]] += 3
    elif w == 0:
        pts[game[0]] += 1
        pts[game[1]] += 1
    elif w == -1:
        pts[game[1]] += 3
    if not gamesLeft:
        for y in range(1, 5):
            if y != T:
                if pts[y]>=pts[T]:
                    return 0
        return 1

    nG = gamesLeft.pop()
    return sum([simulate(list(gamesLeft), list(pts), nG, k)
                for k in range(-1, 2)])


if __name__ == '__main__':
    for _ in range(G):
        A, B, Sa, Sb = map(int, input().split())
        if [A, B] in games:
            games.remove([A, B])
        if Sa>Sb: points[A] += 3
        if Sb>Sa: points[B] += 3
        if Sa == Sb:
            points[A] += 1
            points[B] += 1

    print simulate(games, points, [], 2)
