#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int T, N, M, res;
map<char, queue<pair<int, int>>> doors;
queue<pair<int, int>> startLoc, q;
char Map[101][101];
bool visited[101][101];
set<char> keys;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void openDoors(char key) {
    char tmp = key - 32;
    while (!doors[tmp].empty()) {
        int locsX = doors[tmp].front().first;
        int locsY = doors[tmp].front().second;
        doors[tmp].pop();
        startLoc.push({locsX, locsY});
        Map[locsY][locsX] = '.';
    }
}

void getStartLoc(int x, int y) {
    if (Map[y][x] == '*') {
        return;
    }
    if (Map[y][x] == '.') {
        startLoc.push({x, y});
    } else if (Map[y][x] == '$') {
        res++;
        Map[y][x] = '.';
        startLoc.push({x, y});
    } else if ('a' <= Map[y][x] && Map[y][x] <= 'z') {
        keys.insert(Map[y][x]);
        openDoors(Map[y][x]);
        startLoc.push({x, y});
    } else if ('A' <= Map[y][x] && Map[y][x] <= 'Z') {
        doors[Map[y][x]].push({x, y});
        char key = Map[y][x] + 32;
        if (keys.find(key) != keys.end()) {
            openDoors(key);
        }
    }
}

void BFS() {
    while (!startLoc.empty()) {
        int tmpX = startLoc.front().first;
        int tmpY = startLoc.front().second;
        startLoc.pop();

        q.push({tmpX, tmpY});
        visited[tmpY][tmpX] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
                    continue;
                }
                if (Map[ny][nx] == '*') {
                    continue;
                }
                if (visited[ny][nx]) {
                    continue;
                }

                if ('A' <= Map[ny][nx] && Map[ny][nx] <= 'Z') {
                    char key = Map[ny][nx] + 32;
                    if (keys.find(key) == keys.end()) {
                        //이후에 키를 찾으면 돌아올 수 있도록 로직 추가
                        doors[Map[ny][nx]].push({nx, ny});
                        continue;
                    }
                    Map[ny][nx] = '.';
                } else if ('a' <= Map[ny][nx] && Map[ny][nx] <= 'z') {
                    keys.insert(Map[ny][nx]);
                    //키를 찾았고, 한 번 접근된 문들을 따는 로직 추가
                    openDoors(Map[ny][nx]);
                } else if (Map[ny][nx] == '$') {
                    res++;
                    Map[ny][nx] = '.';
                }
                q.push({nx, ny});
                visited[ny][nx] = true;
            }
        }
    }
}

void Solve() {
    BFS();
    cout << res << '\n';
}

void Init() {
    res = 0;
    doors = map<char, queue<pair<int, int>>>();
    keys = set<char>();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
            visited[i][j] = false;
        }
    }
    string str;
    cin >> str;
    if (str[0] != '0') {
        for (char c: str) {
            keys.insert(c);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char ch = Map[i][j];
            if ('A' <= ch && ch <= 'Z') {
                doors.insert({ch, queue<pair<int, int>>()});
            }
            if (i == 0 || j == 0 || i == N - 1 || j == M - 1) {
                getStartLoc(j, i);
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        Init();
        Solve();
    }
    return 0;
}
